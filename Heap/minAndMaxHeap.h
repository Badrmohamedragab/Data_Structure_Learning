#ifndef ASS_3_DS_MINANDMAXHEAP_H
#define ASS_3_DS_MINANDMAXHEAP_H
#include <iostream>
#include <cmath>
#include <algorithm>
#include <fstream>
#include <map>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <fstream>
#include "Student.h"


using namespace std;
multimap<double, Student> m1;
multimap<double, Student> m2;



void load(vector<double> &arr) {

    int id;
    string name;
    double gpa;
    string department;
    fstream file;
    int numStudent;

    file.open("Users.txt");
    file >> numStudent;
    file.ignore();
    for (int i = 0; i < numStudent; ++i) {
        file >> id;
        file.ignore();
        getline(file, name);
        file >> gpa;
        file.ignore();
        getline(file, department);
        Student s(id,gpa , name, department);
        m1.insert(make_pair(gpa, s));
        m2.insert(make_pair(gpa, s));
        arr.push_back(gpa);
    }
}

//------------------------//Max Heap//-------------------------------//
void maxHeapify(vector<double> &arr, int arrSize, int i) {

    int left = (2 * i) + 1;
    int right = (2 * i) + 2;
    int max = i;

    if (arr[max] < arr[left] && left < arrSize) {
        max = left;
    }
    if (arr[max] < arr[right] && right < arrSize) {
        max = right;
    }
    if (max != i) {
        swap(arr[i], arr[max]);
        maxHeapify(arr, arrSize, max);
    }
}


void buildMaxHeap(vector<double> &arr, int arrSize) {

    for (int i = (arrSize / 2) - 1 /* start from parent */; i >= 0; --i) {
        maxHeapify(arr, arrSize, i);

    }
}


void maxHeapSort(vector<double> &arr, int arrSize) {

    buildMaxHeap(arr, arrSize);
    for (int i = (arrSize - 1) /*Last index*/; i >= 0; --i) {
        swap(arr[0], arr[i]);
        maxHeapify(arr, i, 0);
    }
    reverse(arr.begin(), arr.end());


}


//-------------------------min heap-------------------------//
void minHeapify(vector<double> &arr, int arrSize, int i) {

    int left = (2 * i) + 1;
    int right = (2 * i) + 2;
    int min = i;

    if (arr[min] > arr[left] && left < arrSize) {
        min = left;
    }
    if (arr[min] > arr[right] && right < arrSize) {
        min = right;
    }
    if (min != i) {
        swap(arr[i], arr[min]);
        minHeapify(arr, arrSize, min);
    }
}


void buildMinHeap(vector<double> &arr, int arrSize) {

    for (int i = (arrSize / 2) - 1 /* start from parent */; i >= 0; --i) {
        minHeapify(arr, arrSize, i);

    }
}

void minHeapSort(vector<double> &arr, int arrSize) {

    buildMinHeap(arr, arrSize);
    for (int i = (arrSize - 1) /*Last index*/; i >= 0; --i) {
        swap(arr[0], arr[i]);
        minHeapify(arr, i, 0);
    }
    reverse(arr.begin(), arr.end());


}


void print_min(vector<double> & arr, int arrSize) {
    vector<double> printed ;

    for (int i = 0; i < arrSize; ++i) {
        for (auto const & pair : m1) {
            if (pair.second.getGpa() == arr[i] && count(printed.begin(), printed.end(), pair.second.getId())==0){
                cout<<pair.second ;
                printed.push_back(pair.second.getId());
            }
        }
    }
}void print_max(vector<double> & arr, int arrSize) {
    vector<double> printed ;

    for (int i = 0; i < arrSize; ++i) {
        for (auto const & pair : m2) {
            if (pair.second.getGpa() == arr[i] && count(printed.begin(), printed.end(), pair.second.getId())==0){
                cout<<pair.second ;
                printed.push_back(pair.second.getId());
            }
        }
    }
}

void addStudent_min(vector<double> &arr, int arrSize) {

    int id;
    string name;
    double gpa;
    string department;

    Id:
    cout << "id:";
    cin >> id;
    if (id < 0 || id > 100) {
        cout<<"\nEnter valid id\n"<<endl;
        goto Id;
    }
    for (auto const &itr: m1) {
        if (itr.second.getId() == id) {
            cout << "Id is already exist.\n";
            goto Id;
        }
    }


    cout << "name:";
    cin >> name;
    cout << "gpa:";
    cin >> gpa;
    cout << "department:";
    cin >> department;
    cout << endl;

    Student su(id, gpa, name, department);
    m1.insert({gpa, su});
    arr.push_back(gpa);
}
void addStudent_max(vector<double> &arr, int arrSize) {

    int id;
    string name;
    double gpa;
    string department;

    Id:
    cout << "id:";
    cin >> id;
    if (id < 0 || id > 100) {
        cout<<"\nEnter valid id\n"<<endl;
        goto Id;
    }
    for (auto const &itr: m2) {
        if (itr.second.getId() == id) {
            cout << "Id is already exist.\n";
            goto Id;
        }
    }


    cout << "name:";
    cin >> name;
    cout << "gpa:";
    cin >> gpa;
    cout << "Department:";
    cin >> department;
    cout << endl;

    Student su(id, gpa, name, department);
    m2.insert({gpa, su});
    arr.push_back(gpa);
}
vector<double>vec1;
vector<double>vec2;

void min_Heap_main(){
    load(vec1);
    while(true)
    {
        cout << "\n1. Add student\n"
                "2. Print All (sorted by gpa)\n"
                "3. Return to main menu\n";
        int option;
        cin >> option;
        if (option == 1) {
            addStudent_min(vec1, vec1.size());
            cout<<"\nThe student is added.\n";
        }
        else if (option == 2) {
            cout<<"Print "<<vec1.size() <<" Students.\n";
            minHeapSort(vec1, vec1.size());
            print_min(vec1, vec1.size());
        }
        else if(option == 3)
            break;
    }

}
void max_Heap_main(){
    load(vec2);
    while(true){
        cout << "\n1. Add student\n"
                "2. Print All (sorted by gpa)\n"
                "3. Return to main menu\n";
        int option;
        cin >> option;
        if (option == 1) {
            addStudent_max(vec2, vec2.size());
            cout<<"\nThe student is added.\n";

        } else if (option == 2) {
            cout<<"Print "<<vec2.size() <<" Students.\n";

            maxHeapSort(vec2, vec2.size());
            print_max(vec2, vec2.size());

        } else if (option == 3)
            break;
    }
}









#endif //ASS_3_DS_MINANDMAXHEAP_H
