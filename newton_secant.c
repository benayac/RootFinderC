#include <math.h>
#include <stdio.h>
#include <stdlib.h>

float f(float x);
float derivative(float x);
float newton_iter(float x);
float newton_rhapson(float x);
float rae(float x);

float secant(float x1, float x0);
float rae_sec(float x1, float x0);
float secant_iter(float x1, float x0);

void main(){
	newton_iter(3.5);
	//secant_iter(10, 8);
}

float f(float x){
	float funct = (0.95 * pow(x, 3)) - (5.9 * pow(x, 2)) + (10.9 * x) - 6;
	return funct;
}

float derivative(float x){
	double h = 0.0006;
	return ((f(x+h) - f(x)) / h);
}

float newton_rhapson(float x){
	return (x - f(x) / derivative(x));
}

float rae(float x){
	return ((x - newton_rhapson(x)) / x);
}

float newton_iter(float x){
	printf("x0 -------------- x1 -------------- RAE\n");
	while (rae(x) > 0.0001) {
		printf("%.5f ------ ", x);
		x = newton_rhapson(x);
		printf("%f ------ ", newton_rhapson(x));
		printf("%f\n", rae(x));
	}

	return newton_rhapson(x);
}

float secant(float x1, float x0){
	return (x1 - (f(x1) * (x1 - x0)) / (f(x1) - f(x0)));
}

float rae_sec(float x1, float x0){
	float e;
	e = (secant(x1, x0) - x0) / secant(x1, x0);
	if (e < 0){
		e *=-1;
	}
	return e;
}

float secant_iter(float x1, float x0){
	float x2;
	while (rae_sec(x1, x0) > 0.01){
		/*x2 = x0;
		x0 = secant(x1, x0);
		x1 = x2;
		printf("%f\n", secant(x1, x0));*/
	}
	return x0;
}