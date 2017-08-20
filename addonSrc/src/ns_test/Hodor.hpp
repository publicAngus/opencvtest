#include <iostream>

namespace ns_test{
    class Hodor{
    public:
        Hodor(int yearBorn);
        //Hodor(const Hodor& hdr);
        //Hodor(Hodor&& hdr);
        ~Hodor();
        int GetAge() const;

    private:
        int bornYr;
        int thisYear = 2017;
    };
    
}