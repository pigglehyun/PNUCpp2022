#include "shape.h"
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

bool comparerec(const unique_ptr<Rectangle> & a , const unique_ptr<Rectangle>& b){
    return a->area > b->area;
}
bool comparecir(const  unique_ptr<Circle>& a , const unique_ptr<Circle>& b){
    return a->area < b->area;
}

int main() {
    vector<unique_ptr<Rectangle>> rvec;
    vector<unique_ptr<Circle>> cvec;
    while(true) {

        string cmd; cin >> cmd;
        transform(begin(cmd), end(cmd), begin(cmd),  [](char& c){return tolower(c);});
        Command c = getCommand(cmd);
        switch(c){
            case RECT:
                rvec.emplace_back(make_rectangle());
                break;

            case CIRCLE:
                cvec.emplace_back(make_circle());
                break;

            case CLEAR:
                rvec.clear();
                cvec.clear();
                break;

            case PRINT:
                for_each(rvec.begin(), rvec.end(),[](auto& rec){
                    cout << "Rectangle: " << "\t";
                    cout << rec->width << "\t";
                    cout << rec->height << "\t";
                    cout << rec->area << endl;
                });
                for_each(cvec.begin(), cvec.end(),[](auto& cir){
                    cout << "Circle: " << "\t";
                    cout << cir->radius << "\t";
                    cout << cir->area << endl;
                });


                break;

            case SORT:
                sort(rvec.begin(),rvec.end(), comparerec);
              //  sort(cvec.begin(),cvec.end(), comparecir);
                break;

            case SUM:
            {

                vector<double> rarea ;
                for_each(rvec.begin(), rvec.end(),[&rarea](auto& rec){
                    rarea.push_back(rec->area);
                });
                vector<double> carea;
                for_each(cvec.begin(), cvec.end(),[&carea](auto& cir){
                    carea.push_back(cir->area);
                });
//                for(auto&it : rvec){
//                    rarea.push_back(it->area);
//                }
//
//                for(auto&it : cvec){
//                    carea.push_back(it->area);
//                }

                double sum1 = accumulate(rarea.begin(),rarea.end(),0);
                double sum2 = accumulate(carea.begin(), carea.end(),0);
                double sum = sum1 + sum2 ;

                cout << sum << endl;
            }


                break;

            case QUIT:
                return 0;

            case INVALID:
                cout << "Invalid Command" << '\n';
                break;


        }



    }

}
