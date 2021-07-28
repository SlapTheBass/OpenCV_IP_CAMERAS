#include <stdlib.h>
#include "opencv2/opencv.hpp"
#include "gst/gst.h"

int main(int, char**)
{
cv::VideoCapture cap1("rtspsrc location=rtsp://admin:Twister26@192.168.88.65:554 latency=0 ! queue ! rtph264depay ! h264parse ! omxh264dec ! nvvidconv ! video/x-raw, width=(int)640, height=(int)360,format=(string)BGRx ! queue max-size-buffers=1 leaky=downstream ! videoconvert ! appsink max-buffers=1 drop=true sync=false", cv::CAP_GSTREAMER);
cv::VideoCapture cap2("rtspsrc location=rtsp://admin:Twister26@192.168.88.66:554 latency=0 ! queue ! rtph264depay ! h264parse ! omxh264dec ! nvvidconv ! video/x-raw, width=(int)640, height=(int)360,format=(string)BGRx ! queue max-size-buffers=1 leaky=downstream ! videoconvert ! appsink max-buffers=1 drop=true sync=false", cv::CAP_GSTREAMER);
cv::VideoCapture cap3("rtspsrc location=rtsp://admin:Twister26@192.168.88.64:554 latency=0 ! queue ! rtph264depay ! h264parse ! omxh264dec ! nvvidconv ! video/x-raw, width=(int)640, height=(int)360,format=(string)BGRx ! queue max-size-buffers=1 leaky=downstream ! videoconvert ! appsink max-buffers=1 drop=true sync=false", cv::CAP_GSTREAMER);

if(!cap1.isOpened() || !cap2.isOpened() || !cap3.isOpened())
    return -1;

cv::namedWindow("IP CAMERA1",1);
cv::namedWindow("IP CAMERA2",1);
cv::namedWindow("IP CAMERA3",1);
while(true)
{
    cv::Mat frame1, frame2, frame3;
    cap1 >> frame1; // get a new frame from camera
    cap2 >> frame2;
    cap3 >> frame3;
    cv::imshow("IP CAMERA1", frame1);
    cv::imshow("IP CAMERA2", frame2);
    cv::imshow("IP CAMERA3", frame3);
    if(cv::waitKey(33) >= 0){
        cv::destroyAllWindows();
        break;
    }
}
// the camera will be deinitialized automatically in VideoCapture destructor
return 0;
}
