# ifndef BST_DATA_H
# define BST_DATA_H
# include <iostream>
# include <map>
# include <vector>
# include <fstream>
# include "Student.h"
#include"AVL.h"
#include"BST.h"

using namespace std ;
AVL avl;
BST bst;

class Data {
private:
    map<int, Student> Students ;
    map<string, int> Departments;

public:
    void loadFromFile(){
        fstream File ;
        File.open("Users.txt") ;

        string output ;
        getline(File, output) ;

        while (File.peek() != EOF){
            Student student ;

            getline(File, output) ;
            student.setId(stoi(output)) ;

            getline(File, output) ;
            student.setName(output) ;

            getline(File, output) ;
            student.setGpa(stod(output)) ;

            getline(File, output) ;
            student.setDepartment(output) ;

            if (!Departments.contains(output)){
                Departments.insert({output, 1}) ;
            }
            else{
                ++Departments[output] ;
            }

            Students.insert({student.getId(), student}) ;
        }
        File.close();
    }

    bool addStudent(const Student & s){
        if (!Students.contains(s.getId())) {
            Students.insert({s.getId(), s});
            string Dep = s.getDepartment();

            transform(Dep.begin(), Dep.end(), Dep.begin(), [](char c) { return std::toupper(c);});
            Students[s.getId()].setDepartment(Dep) ;

            if (!Departments.contains(Dep)){
                Departments.insert({Dep, 1}) ;
            }
            else{
                ++Departments[Dep] ;
            }
        }
        else{
            return false ;
        }
        return true ;
    }

    void removeStudent(int Id){
        if (Students.contains(Id)) {
            if (Departments[Students[Id].getDepartment()] != 1){
                --Departments[Students[Id].getDepartment()] ;
            }
            else{
                Departments.erase(Students[Id].getDepartment());
            }
            Students.erase(Id);
            return;
        }
    }

    void printStudent(int Id){
        cout << '[' << Students[Id].getId() << ", "
        << Students[Id].getName() << ", " << Students[Id].getGpa()
        << ", " << Students[Id].getDepartment() << "]\n" ;
    }

    void printDepartments(){
        cout << "\nStudents per Departments:\n" ;
        for (const auto & iterator : Departments) {
            cout << iterator.second << ' ' << iterator.first << " Students\n" ;
        }
    }
};


#endif //BST_DATA_H