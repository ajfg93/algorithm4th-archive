#include <iostream>
#include "RandomBag.h"
using namespace std;
using namespace ythlearn;

int main(int argc, char *argv[]){   
    RandomBag<int> rb;
    for(int i = 0; i < 10; i++){
        rb.add(i);
    }

    for(auto &s: rb){
        cout << "|" << s;
    }
    
    cout << endl;

    for(auto &s: rb){
        cout << "|" << s;
    }
    
    cout << endl;

    for(auto &s: rb){
        cout << "|" << s;
    }
    
    cout << endl;

    return 0;
}