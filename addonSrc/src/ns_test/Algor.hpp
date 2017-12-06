
namespace ns_test{
    class Algor{
    public:
        static void TestBubbleSort();
        static void TestQuickSort();
        static void TestBinarySearch();
    private:
        static int _Partition(int arr[],int leftIndex,int rightIndex);
        static int _QuickSort(int arr[],int leftIndex,int rightIndex);
        static void _Exchange(int arr[],int a,int b);
        static int _BinSearch(int arr[],int length, int target);
    };
}