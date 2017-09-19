#include "OcvT1.hpp"
#include "Debute.hpp"
#include <string>
using namespace cv;

namespace ns_test{

    OcvT1::OcvT1(char str[]){
      _t1FilePath = str;
      _t1RawImg = imread(_t1FilePath);
      _t1MonWindow = "MonWindow";
      namedWindow(_t1MonWindow,WINDOW_AUTOSIZE);
      moveWindow(_t1MonWindow,800,0);

      _t1RawWindow = "RawWindow";
      namedWindow(_t1RawWindow,WINDOW_AUTOSIZE);
      moveWindow(_t1RawWindow,0,0);

    }

    void OcvT1::SayHello(){
        ns_test::writeline("Hello fucker");
    }

    void OcvT1::Test(){
        ns_test::writeline("Test Start:");
        
        imshow(_t1RawWindow,_t1RawImg);
        setMouseCallback(_t1RawWindow,OnMouse,this);
        //imshow(_t1MonWindow,img);
        
        waitKey(0);

    }

    void OcvT1::OnMouse(int Event,int x,int y,int flags,void* param){
        //ns_test::writeline(flags);
        OcvT1* inst; 
        inst = (OcvT1*)param;

        switch(Event){
            case EVENT_LBUTTONDOWN:
            {       
                inst->_isMouseDown = true;
                inst->_t1DownPoint = Point(x,y);
                //Rect roi(inst->_t1DownPoint.x,inst->_t1DownPoint.y,100,100);
                //Mat img = inst->_t1RawImg(roi);
                //imshow(inst->_t1MonWindow,img);
                ns_test::writeline(std::to_string(x)+","+std::to_string(y));
            }
            break;
            case EVENT_MOUSEMOVE:
            {
                if(inst->_isMouseDown){
                Point currentPt(x,y);
                Mat rawClone = inst->_t1RawImg.clone();
                rectangle(rawClone,inst->_t1DownPoint,currentPt,Scalar(188));
                imshow(inst->_t1RawWindow,rawClone);
                }
            }
            break;
            case EVENT_LBUTTONUP:
            {
                inst->_isMouseDown = false;
                inst->_t1UpPoint= Point(x,y);
                Rect roi(inst->_t1DownPoint,inst->_t1UpPoint);
                Mat imgSelected = inst->_t1RawImg(roi);
                imshow(inst->_t1MonWindow,imgSelected);

                /*
                Mat olay = Mat::zeros(imgSelected.rows,imgSelected.cols,CV_8UC3);
                addWeighted(imgSelected,0.1,olay,0.9,0.0,olay);
                imshow(inst->_t1MonWindow,olay);
                imshow("ttt",imgSelected);
                */

            }
            break;
            default:
            break;
        }
       

    }

}