#include "Hodor.hpp"
#include "./Debute.hpp"
namespace ns_test{
    Hodor::Hodor(int yearBorn){
        ns_test::writeline("normal constructor");
        bornYr = yearBorn;
    };
    
    
    /* //don't define copy constructor if default shallow copy is prefered
    Hodor::Hodor(const Hodor& hdr){
        ns_test::writeline("copying");
        //bornYr = hdr.bornYr;//this works even is bornYr is private
        //bornYr = thisYear - hdr.GetAge();
    };
    */

    /*
    Hodor::Hodor(Hodor&& hdr){
        //Compilers already optimize many cases that formally require a move-construction call in what is known as Return Value Optimization. 
        //Most notably, when the value returned by a function is used to initialize an object. 
        //In these cases, the move constructor may actually never get called.
        ns_test::writeline("move constructor here");
    };
    */
    Hodor::~Hodor(){
        ns_test::writeline("disposing Hodor!!!");
    }

    int Hodor::GetAge() const{
        return thisYear - bornYr;
    }
}