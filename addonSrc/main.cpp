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

void drawNode(cv::Point ptn,int levelCount,BiNodeDraw bnd, BiNode<int> bnode){
        cv::Point *nodePt;
        nodePt = &ptn;
        int counter = levelCount;
        int nodeInterval;
        int powerIndex;
        for(int i=0;i<counter;i++){
            powerIndex = (counter -i);
            
            nodeInterval = 3*pow(2,powerIndex - 3) -1;
            if(nodeInterval <= 1) nodeInterval = 1;
            
            if(i != counter -1){
                    bnd.DrawNode(*nodePt,nodeInterval,&bnode, i == counter -2?0:100);
            }
            nodePt  = bnode.RcPoint;

            if((counter - 1) >= 2)
            drawNode(*bnode.LcPoint,counter -1,bnd,bnode);

        }
}

int main(int i,char* args[]){
   

   int labelWidth = 20;
   int labelHeight = 20;
   BiNodeDraw bnd("helloworld",2000,1000,labelWidth,labelHeight);
     BiNode<int> bnode(101);
     bnode.InsertLC(200);
     bnode.InsertRC(400);
     
   cv::Point ptn(800,0);
   
   drawNode(ptn,5,bnd,bnode);

   /*
   cv::Point *nodePt;
   nodePt = &ptn;
   int counter = 2;
   int nodeInterval = 1;
   int nextNodeInterval = 0;
   int powerIndex = 0;
   for(int i=0;i<counter;i++){
       powerIndex = (counter -i);
       
        nodeInterval = 3*pow(2,powerIndex - 3) -1;
        if(nodeInterval <= 1) nodeInterval = 1;
       
       std::cout << "nodeInterval:" << nodeInterval << std::endl;
       if(i != counter -1){
            bnd.DrawNode(*nodePt,nodeInterval,&bnode, i == counter -2?0:100);
       }
       nodePt  = bnode.RcPoint;
   }
    */
   bnd.ReleaseWindow();
  

    writeline("done testing");
    std::getchar();
}
