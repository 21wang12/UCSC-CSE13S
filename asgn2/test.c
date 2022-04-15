#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <math.h>

#define EPSILON 1e-10

static inline double Abs(double x) {
    return x < 0 ? -x : x;
}

double my_pow(double a,double b){




}

double arcSin(double x){
    double a = x, b, sum = a;
	int i = 0;
	
	
    while(Abs(b-a) > EPSILON){
    	b = a;
    	++i;
	    a *= ((my_pow(2*i-1, 2)*my_pow(x, 2)) / ((2*i)*(2*i+1)));
	    sum += a; 
    }

    return sum;
}


int main(int argc, char **argv){
	for (double i = -1; i <= 1; i += 0.1) {
		printf("%7.4lf %16.8lf\n",i, arcSin(i));
    }
}
