#define BiNodePos(T) BiNode<T>*
namespace ns_test{

    template<typename T> struct BiNode{
    public:
        BiNodePos(T) Parent; BiNodePos(T) Lc= NULL; BiNodePos(T) Rc= NULL;
        T Data;
        BiNode(T data,BiNodePos(T) parent = NULL){
          Data = data;
        };

        BiNodePos(T) InsertLC(T const&);
        BiNodePos(T) InsertRC(T const&);
    };


    template<typename T> 
    BiNodePos(T) BiNode<T>::InsertLC(T const& data){
        Lc = new BiNode(data,this);
        return Lc;
    }

    template<typename T>
    BiNodePos(T) BiNode<T>::InsertRC(T const& data){
        Rc = new BiNode(data,this);
        return Rc;
    }

}