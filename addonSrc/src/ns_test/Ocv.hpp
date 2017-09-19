#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <stdio.h>


namespace ns_test{
    class Ocv{
    public:
        static cv::Scalar randomColor(cv::RNG& rng);
        static int DrawDemo();
        static int DrawTest();
        static int DrawFrameTest();
        static int ReadPixels();
        static void onMouse(int,int,int,int,void*);
    };
}