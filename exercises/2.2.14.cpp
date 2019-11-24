#include <iostream>
#include <vector>
#include <random>
#include <cmath>
#include <cassert>
#include "insertionSortTemplate.h"
#include "queue_resizing_array.h"
#include "mergeSortTopTemplate.h"
using namespace std;
 
random_device rd;
mt19937 e(rd());
uniform_int_distribution<int> dist(INT16_MIN, INT16_MAX);

int main(){
	Queue<int> a = {-3,2,1,-99};
	Queue<int> b = {7,33,8,-32};

	Queue<char> e = {'z', 'a', 'c', 'b'};
	Queue<char> f = {'m', 'q', 'g', 'i'};

	// Queue<char> g = InsertionSort::sortArrayQueue(e,f);
	
	// a.enqueue(-3).enqueue(2).enqueue(1).enqueue(-99);
	// b.enqueue(7).enqueue(33).enqueue(8).enqueue(-32);

	unsigned count;
	Queue<int> c = MergeTopDown::sort(a, b, count);

	// while(!g.empty()){
	// 	cout << g.dequeue() << "|";
	// }

		while(!c.empty()){
		cout << c.dequeue() << "|";
	}
	cout << endl;
	return 0;
}