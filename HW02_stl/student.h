#include <algorithm>
#include <numeric>
#include <memory>
#include <string>
#include <vector>
#include <iostream>

const int SUBJECT_NO = 3;

struct StudentInfo {
    std::string name;
    int scores[SUBJECT_NO];
    int sum;
    double average;
};

std::unique_ptr<StudentInfo> make_student();
void print(const StudentInfo& si);
void print_all(const std::vector<std::unique_ptr<StudentInfo>>& vec);

#ifndef WEEK2_SDF_H
#define WEEK2_SDF_H

#endif //WEEK2_SDF_H