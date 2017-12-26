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
        int GetNodeWidth();
        void DrawText(cv::Point &pt,const char text[]);
        void DrawText(cv::Point &pt,int intVal);
        void DrawLine(cv::Point pt1,cv::Point pt2);
        cv::Point GetLabelBottomRight(cv::Point topLeft);
        void ReleaseWindow();
        Point GetLcPointFromParent(Point parentPoint, int xShiftScale,int yShiftScale);
        Point GetRcPointFromParent(Point parentPoint, int xShiftScale,int yShiftScale);

        template<typename T> void DrawNode(cv::Point &parentPos,int p2cXYInterval, BiNode<T> *bNode,int waitTime){
         if(!bNode) return;

         Scalar borderColor(100,100,100);
         //parent
         Point pLeft = parentPos;
         Point pRight(pLeft.x+this->labelWidth,pLeft.y + this->labelHeight);
         rectangle(*bmg,pLeft,pRight,borderColor,this->borderWidth);
         Point pTextBottomLeft(pLeft.x,pRight.y);
         this->DrawText(pTextBottomLeft,bNode->Data);

         //left child
         if(bNode->Lc){

            Point lcLeft = GetLcPointFromParent(pLeft,p2cXYInterval,p2cXYInterval);
            Point lcRight = GetLabelBottomRight(lcLeft); //(lcLeft.x+this->labelWidth, lcLeft.y + this->labelHeight);
            rectangle(*bmg,lcLeft,lcRight,borderColor,this->borderWidth);
            Point lcTextBottomLeft(lcLeft.x,lcRight.y);
            this->DrawText(lcTextBottomLeft,bNode->Lc->Data);
            line(*bmg,Point(lcRight.x,lcRight.y- this->labelHeight),Point(pLeft.x,pLeft.y+this->labelHeight),borderColor,1);

            bNode->LcPoint = new Point(lcLeft.x,lcLeft.y);
         }
         
         //right child
         if(bNode->Rc){
            
            Point rcLeft = GetRcPointFromParent(pLeft,p2cXYInterval,p2cXYInterval);
            Point rcRight = GetLabelBottomRight(rcLeft); //(rcLeft.x+this->labelWidth,rcLeft.y+this->labelHeight);
            rectangle(*bmg,rcLeft,rcRight,borderColor,this->borderWidth);
            Point rcTextBottomLeft(rcLeft.x,rcRight.y);
            this->DrawText(rcTextBottomLeft,bNode->Rc->Data);
            line(*bmg,rcLeft,pRight,borderColor,1);
            bNode->RcPoint = new Point(rcLeft.x,rcLeft.y);

         }

         imshow(this->winName,*bmg);
         waitKey(waitTime);
        };
       
    };
}