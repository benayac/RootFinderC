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
	newton_iter(5);
	secant_iter(5, 7);
}

float f(float x){
	//float funct = (pow(1.5, x) - 5);
	float funct = 0.5 * pow(x, 3) - 4 * pow(x, 2) + 6 * x - 2;
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
	float re = ((newton_rhapson(x) - x) / newton_rhapson(x));
	if(re < 0){
		re *= -1;
	}
	return re;
}

float newton_iter(float x){
	printf("\nNewton-Rhapson Method\n\n");
	printf("============================================================\n");
	printf("|| i ||    x0        ||       x1         ||       RAE     ||\n");
	printf("============================================================\n");
	float e;
	int counter=1;
	do{
		printf("|| %d ||", counter);
		e = rae(x);
		if(x > 9){
			printf(" %.5f     ||    ", x);
		} else
		printf(" %f     ||    ", x);
		x = newton_rhapson(x);
		printf("%f      ||   ", x);
		printf(" %f   ||\n", e);
		counter++;
	}while(e > 0.0001);
	printf("============================================================\n");

	return newton_rhapson(x);
}

float secant(float x1, float x0){
	return (x1 - (f(x1) * (x1 - x0)) / (f(x1) - f(x0)));
}

float rae_sec(float x1, float x0){
	float e;
	e = ((secant(x1, x0) - x0) / secant(x1, x0));
	if (e < 0){
		e *=-1;
	}
	return e;
}

float secant_iter(float x1, float x0){

	printf("\nSecant Method\n\n" );
	printf("==============================================================================\n");
	printf("|| i ||    x0        ||       x1         ||       x2       ||       RAE     ||\n");
	printf("==============================================================================\n");
	float x2, rae;
	int counter=1;
	do{
		printf("|| %d ||", counter);
		rae = rae_sec(x1, x0);
		if(x1 > 9){
			printf("    %.5f  ||", x1);	
		}else
		printf("    %f  ||", x1);
		x2 = x0;
		x0 = secant(x1, x0);
		printf("     %f     ||", x2);
		printf("    %f    ||", x0);
		printf("    %f   ||\n", rae);
		x1 = x2;
		counter++;
	}while (rae > 0.0001);
	printf("==============================================================================\n");
	return x0;
}