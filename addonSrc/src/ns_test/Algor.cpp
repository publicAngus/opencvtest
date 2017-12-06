#include "Debute.hpp"
#include "Algor.hpp"
#include <cmath>

namespace ns_test{
    void Algor::TestBinarySearch(){
        int arr[] = {2,3,4,5,6};
        int length = sizeof(arr)/sizeof(int);
        int index = _BinSearch(arr,length,6);
        std::cout << "result index:"<< index << std::endl;
    }

    int Algor::_BinSearch(int arr[],int length, int target){
        int low,high,mid,midVal;
        low = 0; 
        high = length;
        std::cout << low << "," << high <<";" << std::endl;
        while(low<high){
            mid = std::floor(high + low)/2;
            midVal = arr[mid];
            std::cout << low << "l,"<< mid <<"m,"<< high <<"h," <<midVal <<"mv,"<< target << std::endl;
            if(midVal==target){
                return mid;
            }else{
                if(target < midVal){
                    high = mid;
                }else{
                    low = mid+1;
                }
            }
        }
     
        return -1;
    }

    void Algor::_Exchange(int arr[],int a,int b){
        int tmp = arr[a];
        arr[a] = arr[b];
        arr[b] = tmp;
    }
    
    int Algor::_QuickSort(int arr[],int leftIndex,int rightIndex){
          if(leftIndex>=rightIndex) return 1;
          int partIndex  = _Partition(arr,leftIndex,rightIndex);
          _QuickSort(arr,leftIndex,partIndex);
          _QuickSort(arr,partIndex+1,rightIndex);
    }

    int Algor::_Partition(int arr[],int leftIndex,int rightIndex){
       rightIndex++;
        int partValIndex = leftIndex;
       int partVal = arr[leftIndex];
       int high = rightIndex;
     
       std::cout<< "partVal of "<< leftIndex << " is "<< partVal << std::endl;
       //
    
       while(true){
            while(arr[++leftIndex] < partVal){
                if(leftIndex == high) break;
            }

            while(arr[--rightIndex] > partVal){
                if(rightIndex == partValIndex) break;
            }

            if(leftIndex>rightIndex) break;
            
            _Exchange(arr,leftIndex,rightIndex);
        }

        _Exchange(arr,partValIndex,rightIndex);
        return rightIndex;


    }
    void Algor::TestQuickSort(){
        int arr[] = {5,3,4,9,8,0,1,2,100,4,7};
        int length = sizeof(arr)/sizeof(int);
        std::cout<<"array length == "<< length << std::endl;
        //int partIndex =  _Partition(arr,0,length -1);
        _QuickSort(arr,0,length-1);
        
        for(int i : arr){
            std::cout << i << ",";
        }
        std:: cout<< std::endl;
    }

    void Algor::TestBubbleSort(){
        int arr[] = {2,6,3,9,7,1,8,3,100,200,120,150,199};
    
        int length = sizeof(arr)/sizeof(int);
        int tmp=0;
        /* this sorts the array, but not the bubble sort implementation
        for(int i =0;i < length;i++){
            for(int k = i; k < length;k++){
                if(arr[i]>arr[k]){
                    tmp = arr[i];
                    arr[i] = arr[k];
                    arr[k] = tmp;
                }
            }
        }
        */
       
        
        while(length >= 0){
            for(int i =0;i < length - 1;i++){
                if(arr[i]> arr[i+1]){
                    tmp = arr[i];
                    arr[i] = arr[i+1];
                    arr[i+1] = tmp;
                }
            }
            length--;
        }
        
        ns_test::writeline("show array values:");
        for(int i : arr){
            ns_test::writeline(i);
        }

    }

}