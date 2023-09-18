#include <iostream>
#include "Student.h"
#include "AVL.h"
#include <fstream>
#include <string>
#include <Map>
#include<vector>

using namespace std;
map<int, Student> student_map;
AVL Tree;
map<string, int> department_map;


    void loadFile()
    {

        fstream infile;
        infile.open("Student.txt");
        int num_students;
        infile >> num_students;
        infile.ignore();
        string line;

        for (int i = 0; i < num_students; i++) {
            int id;
            string name, department;
            double gpa;

            getline(infile, line);
            id = stoi(line);
            Tree.insert(id);

            getline(infile, name);
            infile >> gpa;

            infile.ignore();
            getline(infile, department);
            if(!department_map.contains(department))
            {
                department_map.insert({department, 1});
            }
            else
            {
                department_map.find(department)->second +=1;
            }


            Student s (name , id, department, gpa);
            student_map.insert({id, s});
        }
        infile.close();
    }
void display()
{
    cout<<"1. Add student "<<endl;
    cout<<"2. Remove student"<<endl;
    cout<<"3. Search student"<<endl;
    cout<<"4. Print All (sorted by id)"<<endl;
    cout<<"-1. Exit"<<endl;
}

int main() {
    loadFile();
    int check;
    here:
    display();
    cin >> check;
    int id;
    string department;
    string name;
    double gpa;

    while(check !=-1){

        if (check == 1) {
            id:
            cout << "Enter id: ";
            cin >> id;
            if (id <= 0 || id > 100) {
                goto id;
            }
            if (Tree.Search(Tree.root, id) != 0) {
                cout << "This id is exist before" << endl;
                goto id;
            }

            Tree.insert(id);
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter GPA: ";
            cin >> gpa;
            cout << "Enter Department: ";
            cin >> department;
            Student s(name, id, department, gpa);
            if(!department_map.contains(department))
            {
                department_map.insert({department, 1});
            }
            else
            {
                department_map.find(department)->second +=1;
            }
            student_map.insert({id, s});
            cout << "The student is added." << endl;
            goto here;
        }

        else if (check == 2) {
            cout << "Enter id: ";
            cin >> id;
            if (Tree.Search(Tree.root, id) != 0) {
                cout << "Student is found." << endl;
                cout << student_map.find(id)->second;
                if(department_map.find(student_map.find(id)->second.getDepartment())->second == 1) {
                    department_map.erase(student_map.find(id)->second.getDepartment());
                }
                else
                {
                    department_map.find(student_map.find(id)->second.getDepartment())->second -= 1;
                }
                Tree.Delete(id);
                student_map.erase(id);

                cout << "Student is deleted." << endl;
            } else {
                cout << "Student is not found." << endl;
            }
            goto here;

        }

        else if (check == 3) {
            cout << "Enter id: ";
            cin >> id;
            if (Tree.Search(Tree.root, id) != 0) {
                cout << "Student is found." << endl;
                cout << student_map.find(id)->second;
            }
            else {
                cout << "Student is not found." << endl;
            }
            goto here;

        }

        else if (check == 4) {
            cout << "print " << student_map.size() << " students" << endl;
            Tree.inorder(Tree.root, student_map);
            cout<<endl<<"Students per Departments:"<<endl;
            for (const auto& i : department_map) {
                cout<<i.first<<" "<<i.second<<" Students"<<endl;
            }
            goto here;
        }

        else {
            cerr << "Enter correct number" << endl;
            goto here;
        }
    }

    return 0;
}
