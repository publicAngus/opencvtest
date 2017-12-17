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

    void BiNodeDraw::DrawNode(Point &parentPos){
         Scalar borderColor(100,100,100);
         //parent
         Point pLeft = parentPos;
         Point pRight(pLeft.x+this->labelWidth,pLeft.y + this->labelHeight);
         rectangle(*bmg,pLeft,pRight,borderColor,this->borderWidth);
         Point pTextBottomLeft(pLeft.x,pRight.y);
         this->DrawText(pTextBottomLeft,"ppp");

         //left child
         Point lcLeft(pLeft.x - (this->labelWidth/2 + this->child2childInterval/2) ,pLeft.y + this->labelHeight + this->parent2childInterval);
         Point lcRight(lcLeft.x+this->labelWidth, lcLeft.y + this->labelHeight);
         rectangle(*bmg,lcLeft,lcRight,borderColor,this->borderWidth);
         Point lcTextBottomLeft(lcLeft.x,lcRight.y);
         this->DrawText(lcTextBottomLeft,"lc");
         //right child
         Point rcLeft(pLeft.x + (this->labelWidth/2 + this->child2childInterval/2),pLeft.y + this->labelHeight + this->parent2childInterval);
         Point rcRight(rcLeft.x+this->labelWidth,rcLeft.y+this->labelHeight);
         rectangle(*bmg,rcLeft,rcRight,borderColor,this->borderWidth);
         Point rcTextBottomLeft(rcLeft.x,rcRight.y);
         this->DrawText(rcTextBottomLeft,"rc");
         
         imshow(this->winName,*bmg);
         waitKey(0);
    }

    void BiNodeDraw::DrawText(Point &pt,char text[]){
        double fontScale = 1;
        int fontThickness =1;
        putText(*bmg,text,pt,CV_FONT_NORMAL,fontScale,Scalar::all(100),
        fontThickness,8);
    }

    int BiNodeDraw::GetNodeWidth(){
        return this->child2childInterval+this->labelWidth*2+(this->nodeMargin)*2;
    }

}