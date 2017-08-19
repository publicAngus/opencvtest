#include <iostream>
#include <cstdio>
#include <string>
#include "./src/ns_test/Debute.hpp"
#include "./src/ns_test/Hodor.hpp"
using namespace std;
int main(int i,char* args[]){

    ns_test::writeline();

    ns_test::Hodor hdr = ns_test::Hodor();
    std::cout << hdr.GetAge();

    std::getchar();
}