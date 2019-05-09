#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

void initVideoStream(cv::VideoCapture &cap)
{
    if (cap.isOpened())
        cap.release();

    cap.open(0); // open the default camera
    // TODO: Add path to video
//    cap.open("Path/to/video");
}

int main()
{
    cout << "Hello World!" << endl;

    VideoCapture cap; // open the default camera
    initVideoStream(cap);
    if(!cap.isOpened())  // check if we succeeded
        return -1;

    namedWindow("frame", cv::WINDOW_NORMAL);

    for(;;) {
        Mat frame;
        cap >> frame; // get a new frame from camera

        if (frame.empty()) {
            std::cout << "Could not query frame. Trying to reinitialize." << std::endl;
            initVideoStream(cap);
            cv::waitKey(1000); // Wait for one sec.
            continue;
        }

        // TODO: put code here

        imshow("frame", frame);
        if(waitKey(30) >= 0) break;
    }
    // the camera will be deinitialized automatically in VideoCapture destructor

    return 0;
}
