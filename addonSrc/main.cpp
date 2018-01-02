#include <iostream>
#include <cstdio>
#include <string>
#include <memory>
#include <sstream>
#include "./src/ns_test/Debute.hpp"
#include "./src/ns_test/Hodor.hpp"
#include "./src/ns_test/Basics.hpp"
#include "./src/ns_test/Ocv.hpp"
#include "./src/ns_test/OcvT1.hpp"
#include "./src/ns_test/Algor.hpp"
#include "./src/ns_test/BiNode.hpp"
#include "./src/ns_test/BiNodeDraw.hpp"

using namespace std;
using namespace ns_test;

using namespace cv;

#define macroTest(p)(p*p*99)

void drawNode(cv::Point ptn,int counter,BiNodeDraw bnd, BiNode<int> *bnode){
        cv::Point *nodePt;
        nodePt = &ptn;
        int nodeInterval;
        int powerIndex = counter;
        nodeInterval = 3*pow(2,powerIndex - 3) -1;
        if(counter == 2) nodeInterval = 1;
        bnd.DrawNode(*nodePt,nodeInterval,bnode,30);
        
        if(counter > 2){
            if(bnode->RcPoint){
                BiNode<int> *nBn = new BiNode<int>(counter-1);
                nBn->InsertLC(counter+1000);
                nBn->InsertRC(counter+2000);
                drawNode(*(bnode->RcPoint),counter-1,bnd,nBn);
            }

            if(bnode->LcPoint){
                BiNode<int> *nBnL = new BiNode<int>(counter-1);
                nBnL->InsertLC(counter+3000);
                nBnL->InsertRC(counter+4000);
                drawNode(*(bnode->LcPoint),counter-1,bnd,nBnL);
            }

        }
}

int main(int i,char* args[]){
   

   int labelWidth = 3;
   int labelHeight = 3;
   BiNodeDraw bnd("helloworld",2000,1000,labelWidth,labelHeight);
     BiNode<int> bnode(101);
     bnode.InsertLC(200);
     bnode.InsertRC(400);
     
   cv::Point ptn(800,0);
   
   drawNode(ptn,8,bnd,&bnode);
   waitKey(0);

   
   bnd.ReleaseWindow();
  

    writeline("done testing");
    std::getchar();
}
