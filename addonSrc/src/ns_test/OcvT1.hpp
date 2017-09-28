#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/objdetect.hpp>
#include <stdio.h>

namespace ns_test{
    class OcvT1{
    public:
        OcvT1(char*);
        void SayHello();
        void Test();
        static void OnMouse(int Event,int x,int y,int flags,void* param);
        static std::string type2str(int);
        static void detectAndDraw(cv::Mat& img,cv::CascadeClassifier& cascade,
            cv::CascadeClassifier& nestedCascade,
            double scale, bool tryflip );
        void TestHistogram();
        void TestFaceDetect();
        void TestColorPick();
    private:
        char*  _t1FilePath;
        char*  _t1MonWindow;
        char*  _t1RawWindow;
        char*  _t1ColorWindow;
        cv::Mat _t1RawImg;
        cv::Point _t1DownPoint;
        cv::Point _t1UpPoint;
        bool _isMouseDown = false;
    };
}