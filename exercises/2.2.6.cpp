#include <iostream>
#include <vector>
#include <random>
#include "mergesortTop.h"
#include <chrono>
using namespace std::chrono;
using namespace std;
 
random_device rd;
mt19937 e(rd());
uniform_int_distribution<int> dist(INT16_MIN, INT16_MAX);

int main(){
	// cout << "i\t" << "cnt\t" << "6NlgN\t" << endl;
	for(int i = 500; i <= 2097152; i += 2500){
		vector<int> a(i);
		vector<int> aux(i);
		unsigned TopDownCnt = 0;
		// unsigned BottomUpCnt = 0;

		for(int j = 0; j < i ; j++){
			a[j] = dist(e);
		}

		auto start = high_resolution_clock::now();
		MergeTopDown::sort(a, aux, TopDownCnt);
	    auto stop = high_resolution_clock::now(); 
	    auto duration = duration_cast<microseconds>(stop - start); 
		cout <<  duration.count() << endl; 
;
	}
	return 0;
}