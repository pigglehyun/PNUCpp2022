#include <iostream>
#include "student.h"

using namespace std;



int main() {

    int cnt = 0; cin >> cnt;

    vector<unique_ptr<StudentInfo>> vec;

    while(cnt-->0)

         vec.emplace_back(make_student());

    print_all(vec);

    return 0;

}