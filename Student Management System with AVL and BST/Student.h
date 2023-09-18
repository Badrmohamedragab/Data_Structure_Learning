#ifndef ASS_3DS_STUDENT_H
#define ASS_3DS_STUDENT_H
#include<iostream>
#include<Map>
#include <utility>
using namespace std;
//#include "AVL.h"
class Student {
private:
    string name;
    int id;
    string department;
    double GPA;
    map<int, Student> m;
    friend ostream & operator << (ostream &os,const Student &s){
        os << "["<<s.id << ", " << s.name << ", " << s.GPA << ", " << s.department<<"]"<<endl;
        return os;
    }

public:
    Student(){}
    Student(string name, int id, string department, double gpa) :
    name(std::move(name)), id(id),
    department(std::move(department)), GPA(gpa) {
    }

    const string &getDepartment() const {
            return department;
    }

    void setName(const string &name) {
        Student::name = name;
    }

    void setId(int id) {
        Student::id = id;
    }

    void setDepartment(const string &department) {
        Student::department = department;
    }

    void setGpa(double gpa) {
        GPA = gpa;
    }

    void setM(const map<int, Student> &m) {
        Student::m = m;
    }

    const string &getName() const {
        return name;
    }

    int getId() const {
        return id;
    }

    double getGpa() const {
        return GPA;
    }

    const map<int, Student> &getM() const {
        return m;
    }
};


#endif //ASS_3DS_STUDENT_H
