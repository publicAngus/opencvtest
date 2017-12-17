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

        //this is problematic,all become the last one
        //BiNode<int> bnd(i);
        //nodes.push_back(&bnd);

   }
  
   for(std::vector<BiNode<int>*>::iterator it= nodes.begin(); it!=nodes.end();it++){
       paintNode(*it);
   }


   int labelWidth = 80;
   int labelHeight = 20;
   BiNodeDraw bnd("helloworld",1000,800,labelWidth,labelHeight);
     BiNode<int> bnode(101);
   for(int i=1;i<5;i++){
       cv::Point ptn(i*bnd.GetNodeWidth(),100);
       bnd.DrawNode(ptn,&bnode);
   }

    //std::cout << bnd.GetNodeWidth() << std::endl;
    //std::cout<< bn.Lc->Data << bn.Rc->Data << std::endl;

    //int arr[] = {1,2,3};
    //int length = sizeof(arr)/sizeof(int);
    //ns_test::writeline(length);
    //ns_test::writeline(sizeof(arr));
    //ns_test::writeline(sizeof(int));
    /*
    BiNode<int> bn(10);
    std::cout << bn.Data <<std::endl;

    BiNode<int>* lcPtr = bn.InsertLC(20);
    std::cout << lcPtr->Data << std::endl;

    BiNode<int>* rcPtr = bn.InsertRC(30);
    std::cout << rcPtr->Data << std::endl;
    */


    //testmetods(); 
    //Basics::TestWhile(10);
    //Basics::TestFor(10);
    //Basics::TestArray(100);
    //Basics::TestVector(1);
    //Basics::TestOperatorPole();
    //Basics::TestBinaryShift();
    //testmetods();
    //testSharePointer();
    //testopencv();

    /*
    typedef int* intPtr;
    int ii = 1001;
    intPtr ptr = &ii;
    std::cout << *ptr <<std::endl;

    int q = 10;
    int qRet = macroTest(q);
    std::cout << qRet << std::endl;

    Basics bsc;
    Basics bsc2;

    bool ret = bsc ==bsc2;
    std::cout << ret << std::endl;
    */

    //Ocv::DrawFrameTest();
    //Ocv::ReadPixels();
    //Algor::TestBubbleSort();
    //Algor::TestQuickSort();
    //Algor::TestBinarySearch();
  
    
    //char str[] = "./imgs/color1.bmp";
    //OcvT1 t1(str);
    //t1.Test();
    
    
    

    writeline("done testing");
    std::getchar();
}
