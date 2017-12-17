#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include "BiNode.hpp"
using namespace cv;
namespace ns_test{
    class BiNodeDraw{
    private:
        char *winName;
        cv::Mat *bmg;
        int labelWidth,labelHeight,parent2childInterval=30,child2childInterval=20,borderWidth=2,nodeMargin=borderWidth;
    public:
        BiNodeDraw(char winName[],int width,int height,int labelWidth,int labelHeight);
        
        template<typename T> void DrawNode(cv::Point &parentPos,BiNode<T> *bNode){
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
        };
        int GetNodeWidth();
        void DrawText(cv::Point &pt,char text[]);
    };
}