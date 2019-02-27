#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

clock_t start, end;
double cpu_time_used;

float f(float x);
float secant(float x1, float x0);
float rae_sec(float x1, float x0);
float secant_iter(float x1, float x0);

void main(){
	double time = 0;
	double av_time;

	for (int i = 0; i< 10; i++){
		start = clock();
		secant_iter(10, 8);
		end	= clock();
		cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
		time += cpu_time_used;
	}

	av_time = time / 10;
	printf("Average Running When Running Secant Method = %f\n", av_time);
	
}

float f(float x){
	float funct = (pow(1.5, x) - 5);
	return funct;
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