#include <iostream>
#include <cstdio>
#include <string>
#include "./src/ns_test/Debute.hpp"
#include "./src/ns_test/Hodor.hpp"
using namespace std;


ns_test::Hodor getTrueHodor(){
    return ns_test::Hodor(1990);
}

void testmetods(){
    ns_test::writeline("----this the start of main----");
    
    
        ns_test::Hodor hdr = ns_test::Hodor(1985);
        ns_test::writeline(hdr.GetAge());
        // ns_test::Hodor hdr2 = ns_test::Hodor(hdr);
        // ns_test::writeline(hdr2.GetAge());
    
        // ns_test::Hodor hdr3 = ns_test::Hodor(getTrueHodor());
        // ns_test::writeline(hdr3.GetAge());
        
    
        ns_test::writeline("----this the end of main------");
      
}

int main(int i,char* args[]){
    testmetods();
    std::getchar();
}
