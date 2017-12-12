#include "BiNodeDraw.hpp"
using namespace cv;
namespace ns_test{
    BiNodeDraw::BiNodeDraw(const char winName[]){
        this->winName = winName;
        std::cout << this->winName << std::endl;
        
        Mat baseImg = Mat::zeros(400,400,CV_8UC3);
        bmg = &baseImg;
        namedWindow(winName,WINDOW_AUTOSIZE);
        moveWindow(winName, 0,0);
        imshow(winName,*bmg);
        waitKey(0);
    }

    void BiNodeDraw::DrawNode(Point parentPos){
        
    }


}