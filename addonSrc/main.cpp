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

ns_test::Hodor getTrueHodor(){
    return ns_test::Hodor(1990);
}

void testmetods(){
        writeline("----this the start of main----");   
        Hodor *hdr = new Hodor(1985);
        writeline(hdr->GetAge());
        delete hdr;
        writeline("----this the end of main------");
}

void testSharePointer(){
    writeline("--start share pointer --");
    for(int i=0;i< 10;i++){
        shared_ptr<Hodor> shdr = make_shared<Hodor>(1990+i);
        writeline(shdr->GetAge());
    }
   
    writeline("---end share pointer ---");
}


void paintNode(BiNode<int> *bnPtr){
    
    if(!bnPtr) return;

    BiNode<int> bn = *bnPtr;
    std::cout << "bnVal:" << bn.Data << std::endl;
    if(bn.Lc){
    std::cout<< "LcVal:" << bn.Lc->Data << std::endl;
    }
    if(bn.Rc){
    std::cout<< "RcVal:" << bn.Rc->Data << std::endl;
    }
}

int main(int i,char* args[]){
   
   
   std::vector<BiNode<int>*> nodes;
   for(int i=0;i< 10;i++){
        BiNode<int>* bnd = new BiNode<int>(i);
        nodes.push_back(bnd);

        bnd->InsertLC(i*100+1);
        bnd->InsertRC(i*100+2);
    
        //this is problematic,all become the last one becoz the address is the same
        //BiNode<int> bndtest(i);
        //printf("address1 == %p, address2 == %p\n",bnd,&bndtest);
        //nodes.push_back(&bnd);

   }
  
   for(std::vector<BiNode<int>*>::iterator it= nodes.begin(); it!=nodes.end();it++){
       //paintNode(*it);
   }


   int labelWidth = 40;
   int labelHeight = 20;
   BiNodeDraw bnd("helloworld",2000,1000,labelWidth,labelHeight);
     BiNode<int> bnode(101);
     bnode.InsertLC(200);
     bnode.InsertRC(400);
     
   cv::Point ptn(0,0);
   int counter = 3;
   int intervalScale = 1;
   for(int i=0;i<counter;i++){
       intervalScale = pow(2,(counter-i -1));
       cv::Point pt = i == 0? ptn: *(bnode.RcPoint);

       cv::Point newPt = bnd.GetRcPointFromParent(pt,intervalScale,intervalScale);
       bnd.DrawNode(newPt,intervalScale,&bnode, i== counter -1 ?0:100);

   }

   bnd.ReleaseWindow();
  

    writeline("done testing");
    std::getchar();
}
