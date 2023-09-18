# include "Sortlib.h"
using namespace Sortlib;

int main() {
    {
        int Array[10] = {-1, 5, 10, 4, 0, 50, 40, 1, 4, 10};
        Print(Array, 10);
        cout << "InsertionSort -> ";
        insertionSort(Array, 10);
        Print(Array, 10);
        cout << endl ;
    }
//-------------------------------------------------------
    {
        float Array[10] = {-1.5, 5.1, 10.5, 4.9, 0, 50.7, 40.2, 1.7, 4.0, 10.5};
        Print(Array, 10);
        cout << "SelectionSort -> ";
        selectionSort(Array, 10);
        Print(Array, 10);
        cout << endl ;
    }
//-------------------------------------------------------
    {
        double Array[10] = {8.101, 9.01, 7, -1.6, 1, 2, 10, 6.4, 6.50, .01};
        Print(Array, 10);
        cout << "BubbleSort -> ";
        bubbleSort(Array, 10);
        Print(Array, 10);
        cout << endl ;
    }
//-------------------------------------------------------
    {
        int Array[10] = {-1, 5, 10, 4, 0, 50, 40, 1, 4, 10};
        Print(Array, 10);
        cout << "ShellSort -> ";
        shellSort(Array, 10);
        Print(Array, 10);
        cout << endl ;
    }
//-------------------------------------------------------
    {
        float Array[10] = {4.5, 8.10, 8.101, 9.4, .7, 0.1, 7, 9, 10, 2.5};
        Print(Array, 10);
        cout << "QuickSort -> ";
        quickSort(Array, 0, 9);
        Print(Array, 10);
        cout << endl ;
    }
//-------------------------------------------------------
    {
        double Array[10] = {7., 80.8, 70.4, 9.1, 7.1, 2.40, 3.4, 3.2, 6.4, .8};
        Print(Array, 10);
        cout << "MergeSort -> ";
        mergeSort(Array, 0, 9);
        Print(Array, 10);
        cout << endl ;
    }
//-------------------------------------------------------
    {
        int Array[10] = {10, 5, 10, 4, 7, 50, 40, 1, 4, 10};
        Print(Array, 10);
        cout << "CountSort -> ";
        countSort(Array, 10);
        Print(Array, 10);
        cout << endl ;
    }
    return 0;
}