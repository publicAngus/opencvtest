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

using namespace std;
using namespace ns_test;

using namespace cv;

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
    //testmetods(); 
    //Basics::TestWhile(10);
    //Basics::TestFor(10);
    //Basics::TestArray(100);
    //Basics::TestVector(1);
    //testmetods();
    //testSharePointer();
    //testopencv();
    
    //Ocv::DrawFrameTest();
    //Ocv::ReadPixels();

    char str[] = "./imgs/color1.bmp";
    OcvT1 t1(str);
    t1.Test();
    

    writeline("done testing");
    std::getchar();
}
