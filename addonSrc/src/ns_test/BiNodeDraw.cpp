#include "BiNodeDraw.hpp"
using namespace cv;
namespace ns_test{
    BiNodeDraw::BiNodeDraw(char winName[],int width,int height,int labelWidth,int labelHeight){
        this->labelWidth = labelWidth;
        this->labelHeight = labelHeight;
        this->winName = winName;
        bmg = new Mat(Mat::zeros(height,width,CV_8UC3));
        namedWindow(this->winName,WINDOW_AUTOSIZE);
        moveWindow(this->winName, 0,0);
    }

    Point BiNodeDraw::GetLcPointFromParent(Point parentPointLeft, int xShiftScale,int yShiftScale){
          int shiftX = xShiftScale*this->labelWidth;
          int shiftY = yShiftScale*this->labelHeight;
          Point lcLeft(parentPointLeft.x - shiftX ,parentPointLeft.y + this->labelHeight + shiftY);
          return lcLeft;
    }

    Point BiNodeDraw::GetRcPointFromParent(Point parentPointLeft, int xShiftScale,int yShiftScale){
          int shiftX = xShiftScale*this->labelWidth;
          int shiftY = yShiftScale*this->labelHeight;
          Point rcLeft(parentPointLeft.x + shiftX,parentPointLeft.y + this->labelHeight + shiftY);
          return rcLeft;
    }

    void BiNodeDraw::DrawText(cv::Point &pt,int intVal){
        this->DrawText(pt,std::to_string(intVal).c_str());
    }

    void BiNodeDraw::DrawText(Point &pt,const char text[]){
        double fontScale = 1;
        int fontThickness =1;
        putText(*bmg,text,pt,CV_FONT_NORMAL,fontScale,Scalar::all(100),
        fontThickness,8);
    }

    cv::Point BiNodeDraw::GetLabelBottomRight(cv::Point topLeft){
         return Point(topLeft.x+this->labelWidth, topLeft.y + this->labelHeight);
    }

    int BiNodeDraw::GetNodeWidth(){
        return this->child2childInterval+this->labelWidth*2+(this->nodeMargin)*2;
    }

    void BiNodeDraw::DrawLine(cv::Point pt1,cv::Point pt2){
        line(*bmg,pt1,pt2,Scalar::all(100),1);
    }

    void BiNodeDraw::ReleaseWindow(){
        cvDestroyWindow(this->winName);
    }

}