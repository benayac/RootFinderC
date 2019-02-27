#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

clock_t start, end;
double cpu_time_used;

float f(float x);
float derivative(float x);
float newton_iter(float x);
float newton_rhapson(float x);
float rae(float x);

void main(){
	double time = 0;
	double av_time;

	for(int i = 0; i<10; i++){
		start = clock();
		newton_iter(10);
		end = clock();
		cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
		time += cpu_time_used;
	}

	av_time = time / 10;
	printf("Average Running When Running Newton-Raphson Method = %f\n", av_time);
	
}

float f(float x){
	float funct = (pow(1.5, x) - 5);
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