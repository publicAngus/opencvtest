#include "Hodor.hpp"

namespace ns_test{
    Hodor::Hodor(){
        bornYr = 1900;
    };
    int Hodor::GetAge(){
        return 2017 - bornYr;
    }
}