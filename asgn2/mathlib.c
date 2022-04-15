#include "mathlib.h"
#include <math.h>
#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#define EPSILON 1e-10

static inline double Abs(double x) {
    return x < 0 ? -x : x;
}

double POW( double x, int y){  //quick power: return x^y
    if(x==0) return 0;  //if x is zero
    if(y==0) return 1;  //if y is zero
    if(y==1) return x;
    if(y<0)  return 1.0 / POW(x, -y);  //if y is negtive
    double temp = POW(x, y>>1);  //recursion
    double res = temp * temp;
    return y % 2 == 0 ? res : res * x; //if y is even
}

//calculate the next term in talor series
double next(double a, double x, int i){
    return a*((POW(2*i-1, 2)*POW(x, 2)) / ((2*i)*(2*i+1)));
}


double arcSin(double x){
	
    double a = x, sum = a;
	int i = 0;
	
	double l = -1*M_PI;
	double r = M_PI;
	double m = 0.0;
	

	if(Abs(x)>0.75){
		//inverse method	
		double diff = sin(m) - x;
		while(  Abs(diff) > pow(EPSILON,M_PI) ){
			if(diff>0){
				r = m;
			}else{
				l = m;
			}
			m = (r+l)/2;
			diff = sin(m)-x;
		}
		sum = m;
	}else{
	
		do{
			a = next(a, x, ++i);  //save the next term
			sum += a;  //add them
		}while (Abs(a) > EPSILON);
	}
    return sum;
}



double arcCos(double x){
    double a = (M_PI / 2) - arcSin(x);
    return a;
}

double Sqrt(double x) {
    double y = 1.0;
    assert(x >= 0);
    for (double guess = 0.0; Abs(y - guess) > EPSILON; y = (y + x / y) / 2.0) {
        guess = y;
    }
    return y;
}
//cited from piazza note@143

double arcTan(double x){
    double a = arcSin(x / (Sqrt(x * x + 1)));
    return a;
}

double Exp(double x) {
    double term = 1, sum = 1;
    for (int k = 1; Abs(term) > EPSILON; k += 1) {
        term *= x / k;
        sum += term;
    }
    return sum;
}
//cited from piazza note@69

double Log(double x){
    double a = 1.0;
    double b = Exp(a);
    while (Abs(b - x) > EPSILON) {
        a = a + (x - b) / b;
        b = Exp(a);
    }
    return a;
}
//cited from 4/9/2021 lecture ppt
