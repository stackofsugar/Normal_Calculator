#include <iostream>
#include <algorithm>
#include <limits>
#include <string>
#define hardLimit 2147483647
using namespace std;

void clearbuf(){
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
}

template<typename Ty>
Ty input(Ty floor = 0, Ty ceil = hardLimit){
    Ty buffer;
    while(1){
        if(cin >> buffer){
            if(buffer < floor){
                cout << "Your input was too small! Try again: " << endl;
            } else if(buffer > ceil){
                cout << "Your input was too big! Try again: " << endl;
            } else {
                return buffer;
            }
        } else {
            cout << "Invalid input! Please try again: " << endl;
            clearbuf();
        }
    }
}

int main(){
    cout << "Input your integer: ";
    int testins = input<int>(10,25);
    cout << "Input your floating point: ";
    float testflo = input<float>(5.41, 30.45);
    cout << "Integer: " << testins << "\nFloat: " << testflo << endl;
}