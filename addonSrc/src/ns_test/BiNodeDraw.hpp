#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

namespace ns_test{
    class BiNodeDraw{
    private:
        const char *winName;
        cv::Mat *bmg;
    public:
        BiNodeDraw(const char winName[]);
        void DrawNode(cv::Point parentPos);
    };
}