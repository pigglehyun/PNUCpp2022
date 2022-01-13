#include <iostream>
#include <algorithm>
#include <limits>

using namespace std;

int main() {
    static int intnum =0;
    static int longnum =0;
    static int floatnum =0;
    static int doublenum =0;
    string cmd = "";

    while(cin >> cmd){
        transform(begin(cmd), end(cmd), begin(cmd), [](unsigned char c){ return std::tolower(c); });
        if( cmd == "int"){
            cout << numeric_limits<int>::max() <<"\t"<< numeric_limits<int>::min() << endl;
            intnum++;
        }
        else if( cmd == "long"){
            cout << numeric_limits<long long>::max() <<"\t"<< numeric_limits<long long>::min() << endl;
            longnum++;
        }
        else if( cmd == "float") {
            cout << numeric_limits<float>::max() <<"\t"<< numeric_limits<float>::min() << endl;
            floatnum++;
        }
        else if( cmd == "double") {
            cout << numeric_limits<double>::max() <<"\t"<< numeric_limits<double>::min() << endl;
            doublenum++;
        }
        else if ( cmd == "quit" ){
            break;
        }
        else {
            cout << "Invalid Command" << endl;
        }
    }
    cout << "=== the number of types ===" << endl;
    cout << "int: " << intnum << endl;
    cout << "long: " << longnum << endl;
    cout << "float: " << floatnum << endl;
    cout << "double: " << doublenum << endl;
}
