#include "Debute.hpp"
#include "Basics.hpp"
#include <string>
#include <vector>

namespace ns_test{
    //answered by below link, keyword VLA(variable length array )
    //https://stackoverflow.com/questions/46011407/how-to-create-c-array-with-different-length-at-run-time/46011437#46011437
    // void Basics::TestArray(int length){
    //      int arr[length];
    //      for(int i=0;i<length;i++){
    //          arr[i] = i;
    //      }
    // }

    void Basics::TestArray(int length){
        /*
        int *ptr;
        int arr[] = {1,3,5};
        ptr = &arr[0];
        double sized = sizeof(arr)/sizeof(int);
        std::string size = std::to_string(sized);
        ns_test::writeline("size of array:");
        ns_test::writeline(size);

        for(int i=0;i<sized;i++){
            ns_test::writeline(*ptr);
            ptr++;
        }
        */

        ns_test::writeline("--test dynamic array size--");
        int *aPtr = new int[length];
        for(int i=0;i<length;i++){
            aPtr[i] = i+1000;
        }

        for(int i=0;i< length;i++){
            ns_test::writeline(aPtr[i]);
        }

        delete [] aPtr;

        ns_test::writeline("--test multi dimensional dynamic array--");
        int **mPtr = new int*[length];
        for(int i=0;i < length;i++){
            mPtr[i] = new int[length];
            for(int j=0;j<length;j++){
                mPtr[i][j] = j+2000;
            }
        }

        for(int i =0;i <length;i++){
            for(int j =0;j< length;j++){
                int val = mPtr[i][j];
                ns_test::writeline(val);
            }
        }

        //delete resources
        for(int i=0;i<length;i++){
            delete [] mPtr[i];
        }

        delete [] mPtr;

    }

    void Basics::TestVector(int length){
        //  std::vector<int> arr(length);
        //  for(int i = 0;i<length;i++){
        //     arr[i] = i+3000;
        //  }

        //  for(int i : arr){
        //      ns_test::writeline(i);
        //  }

         //testing 2 dimension vector
         std::vector<std::vector<int> > arr2(length);
         int rowWidth = 10;
         int count = 9000;
         for(int i=0;i<length;i++){
            std::vector<int> row(rowWidth);
            for(int j =0;j<rowWidth;j++){
                row[j] = count++;
            }
            arr2[i] = row;
            ns_test::writeline(i);
         }

         for(int i =0;i<length;i++){
             auto row = arr2[i];
             for(int i : row){
                 ns_test::writeline(i);
             }
         }


    }

    void Basics::TestWhile(int repeat){
        while(repeat > 0){
            repeat--;
            ns_test::writeline(repeat);
        };

        do{
            repeat--;
            ns_test::writeline(repeat);
        }while(repeat > 0);

    }

    void Basics::TestFor(int repeat){
        for(int i =0; i< repeat;i++){
            ns_test::writeline(i);
        }
    }

}