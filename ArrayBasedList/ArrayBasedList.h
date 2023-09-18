# ifndef ARRAYBASEDLIST_ARRAYBASEDLIST_H
# define ARRAYBASEDLIST_ARRAYBASEDLIST_H
# include <iostream>
using namespace std ;

template<class datatype>
class ArrayBasedList {
private:
    datatype *arr;
    int maxSize;
    int length;

public:
    explicit ArrayBasedList(int len) {
        if (len < 0) {
            len = 10;
        } else {
            maxSize = len;
        }
        length = 0;
        arr = new datatype[maxSize];

    }

    bool isEmpty() {
        return (length == 0);
    }

    bool isFull() {
        return (length == maxSize);
    }

    int listSize() {
        return length;
    }

    int maxListSize() {
        return maxSize;
    }


    void insert(datatype element) {
        if (isFull()) {
            cout << "Can't insert because array is full!!!" << endl;
        } else {
            arr[length] = element;
            length++;
        }
    }

    void insertAt(datatype element, int index) {
        if (isFull()) {
            cout << "Can't insert because array is full!!!" << endl;
        } else if (index < 0 || index > length) {
            cout << "Can't insert error in index!!!" << endl;
        } else {
            for (int i = length; i > index; --i) {
                arr[i] = arr[i - 1];
            }
            length++;
            arr[index] = element;
        }

    }

    datatype retrieveAt(int index) {
        if (index < 0 || index >= length) {
            cout << "Can't retrieve At error in index!!!" << endl;
        } else {
            return arr[index];
        }
    }

    void removeAt(int index) {
        if (isEmpty()) {
            cout << "Can't remove because array is already Empty!!!" << endl;
        } else if (index < 0 || index > length) {
            cout << "Can't remove error in index!!!" << endl;
        } else {
            for (int i = index; i < length; ++i) {
                arr[i] = arr[i + 1];
            }
            length--;

        }

    }

    void replaceAt(datatype newElement, int index) {
        if (index < 0 || index >= length) {
            cout << "Can't remove error in index!!!" << endl;
        } else {
            arr[index] = newElement;
        }

    }

    bool isItemAtEqual(datatype element, int index) {
        return (arr[index] == element);
    }


    void clear() {
        length = 0;
    }

    void print() {
        for (int i = 0; i < length; ++i) {
            cout << arr[i] << " ";

        }
        cout << '\n' ;
    }

    virtual ~ArrayBasedList() {
        delete[]arr;

    }
};

# endif //ARRAYBASEDLIST_ARRAYBASEDLIST_H