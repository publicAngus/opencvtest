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



int main(int i,char* args[]){
    
    BiNode<int> bn(10);
    std::cout << bn.val <<std::endl;
    
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
  
    
    //char str[] = "./imgs/color1.bmp";
    //OcvT1 t1(str);
    //t1.Test();
    
    
    

    writeline("done testing");
    std::getchar();
}
