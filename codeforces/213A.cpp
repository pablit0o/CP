#include <iostream>
using namespace std;
 
int main() {
    long long problems;
    cin >> problems;
 
    long long Petya, Vasya, Tonya;
 
    long long solved_problems = 0;
 
    for (long long i = 0; i < problems; i++) {
        cin >> Petya >> Vasya >> Tonya;
        if ((Petya == 1 && Vasya == 1) || (Petya == 1 && Tonya == 1) || (Vasya == 1 & Tonya == 1)) {
            solved_problems += 1;
        }
    }
    cout << solved_problems;
}