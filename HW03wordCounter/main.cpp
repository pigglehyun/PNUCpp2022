#include <iostream>
#include <map>
#include <regex>

using namespace std;

int main() {
    string str;

    map<std::string, size_t> strings;


    while (cin >> str && str!="^") {

        string filtered= regex_replace(str, regex("[.|,|:|;| ]"), "");
        auto search = strings.find(filtered);

       if (search != strings.end()){
            strings[filtered]++;
        }
        else{
            strings.insert({filtered, 1});
        }




    }
    cout <<"words: " << strings.size()<< endl;


    string str2;

    while( (cin >> str2) && (str2 != "QUIT") ){

        cout << str2 << ": " << strings[str2]<< endl;
    }


    cout << "Bye!" << endl;



}
