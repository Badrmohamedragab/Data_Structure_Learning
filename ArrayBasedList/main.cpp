# include "ArrayBasedList.h"

int main() {
    ArrayBasedList<int> Arr(5) ;

    Arr.insert(0) ;
    Arr.insertAt(10, 1) ;
    Arr.insertAt(20, 2) ;
    Arr.insert(30) ;
    Arr.insert(40) ;
    Arr.print() ;

    Arr.removeAt(0) ;
    Arr.removeAt(Arr.listSize() - 1) ;
    Arr.print() ;

    cout << Arr.retrieveAt(2) << endl ;
    cout << Arr.listSize() << endl ;

    Arr.replaceAt(0, 0) ;
    Arr.replaceAt(1, 1) ;
    Arr.replaceAt(2, 2) ;
    Arr.print() ;

    return 0;
}
