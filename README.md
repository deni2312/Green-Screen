This is a simple example of green screen with openCV(https://opencv.org/).

**DEPENDECIES**

OpenCV:https://github.com/opencv/opencv

**COMPILING**

To compile it type(on Linux):
`g++ -std=c++11 green_screen.cpp`\`pkg-config --libs --cflags opencv\`` -o green_screen`

**HOW TO CHOOSE THE RANGE OF THE COLOR**

To choose the range of green or other colors you need to change the line 21(`inRange(hsv_image,Scalar(0,0,0),Scalar(0,255,0),ColTra);`)
with: first `Scalar(R-lower,G-lower,B-lower`, in second `Scalar(R-high,G-high,B-high)`

**HOW TO CHOOSE THE BACKGROUND IMAGE**

In line 42 change `templateimage.jpg` with the name of the image that you use.
