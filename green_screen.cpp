#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

#include <stdio.h>
#include <iostream>

using namespace std;
using namespace cv;

/** Global variables */
Mat imgeff;

//First image,Second image
void greenSos(Mat &Fi,Mat &Si)
{
  Mat hsv_image;
  Mat ColTra;
  cvtColor(Fi,hsv_image,COLOR_BGR2HSV);
  //first Scalar(Rlower,Glower,Blower),in second Scalar(Rhigh,Ghigh,Bhigh)
  inRange(hsv_image,Scalar(0,0,0),Scalar(0,255,0),ColTra);
  for(int r=0;r<Fi.rows;r++)
  {
    for(int c=0;c<Fi.cols;c++)
    {
        //if color of the pixel is green it copies the image pixel
      if(ColTra.at<Vec3b>(r,c)==Vec3b(255,255,255))
       {
          Fi.at<Vec3b>(r,c)=Si.at<Vec3b>(r,c);
       }
    }
  }
}

void greenFrame( Mat frame )
{
  resize(imgeff,imgeff,frame.size());
  greenSos(frame,imgeff);
  imshow( "GreenScreen", frame );
}

int main()
{
    imgeff=imread("templateimage.jpg",CV_LOAD_IMAGE_COLOR);
    VideoCapture capture;
    Mat frame;
    capture.open( 0 );
    if ( ! capture.isOpened() )
    {
       printf("--(!)Error opening video capture\n");
       return -1;
    }
    while ( capture.read(frame) )
    {
        if( frame.empty() )
        {
            printf(" --(!) No captured frame -- Break!");
            break;
        }
        greenFrame( frame );
        if( waitKey(10) == 27 )
        {
           break;
        } // escape
    }
    return 0;
}
