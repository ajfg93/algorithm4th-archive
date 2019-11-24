/*
Source: Algorithm 4th, Book

Introduction: Use Newton's method to calculate a square root of a number.

Related reading:
https://www.zhihu.com/question/297275046
https://cs.stackexchange.com/questions/98152/condition-of-square-root-algorithm-newtons-method
*/

#include <cmath>
#include "square_root.h"
using namespace std;

namespace ythlearn{
	double sqrt(double c){
		// if(c < 0) throw some exception
		double err = 1e-15;
		double t = c;
		while(abs(t - c/t) > err * t)
			t = (c/t + t) / 2.0;
		return t;
	}
}
