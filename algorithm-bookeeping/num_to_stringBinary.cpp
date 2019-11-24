/*
Source: Algorithm 4th, Book
        Execrise 1.19

Introduction: Convert a integer to binary into a string.

*/

#include "num_to_stringBinary.h"
using namespace std;

namespace ythlearn{
    string int_to_stringBinary(int N){
        string s = "";
        while(N > 0){
            s += to_string(N % 2);
            N /= 2;
        }
        reverse(s.begin(), s.end());
        return s;
    }
}
