#include "student.h"

#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

unique_ptr<StudentInfo> make_student(){

    StudentInfo student;
    cin >> student.name >> student.scores[0] >>student.scores[1]
    >>student.scores[2] ;
    student.sum = 0 ;
    for(int i : student.scores){
        student.sum += i;
    }
    student.average = (double)student.sum / 3 ;

    unique_ptr<StudentInfo> studentInfo(new StudentInfo(student));
    return studentInfo;
}

void print(const StudentInfo& si) {
    cout << si.name << "\t" <<si.scores[0] << "\t" <<si.scores[1] <<
    "\t" <<si.scores[2] << "\t"  <<
    si.sum << "\t" << si.average << endl;
}

void print_all(const vector<unique_ptr<StudentInfo>>& vec) {
    for(auto&& it : vec){
       print(*it);
    }
}