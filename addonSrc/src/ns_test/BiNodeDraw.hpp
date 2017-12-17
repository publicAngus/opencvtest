#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

namespace ns_test{
    class BiNodeDraw{
    private:
        char *winName;
        cv::Mat *bmg;
        int labelWidth,labelHeight,parent2childInterval=30,child2childInterval=20,borderWidth=2,nodeMargin=borderWidth;
    public:
        BiNodeDraw(char winName[],int width,int height,int labelWidth,int labelHeight);
        void DrawNode(cv::Point &parentPos);
        int GetNodeWidth();
        void DrawText(cv::Point &pt,char text[]);
    };
}