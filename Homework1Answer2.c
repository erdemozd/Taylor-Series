#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define PI 3.14159
int fact(int);
int cosApprox(double, double);
int main()
{
	double degree ,radians ,tolerance ,approxCos=0; 
	int k,i; //i is iterator for loop and k is result of cosApprox function
	printf("Enter your desired degree for cosine calculation : \n");
	scanf("%lf",&degree);
	
	radians = degree*(PI/180); //converting degrees to radians
	
	printf("Enter your desired error tolerance for calculation : \n");
	scanf("%lf",&tolerance);
	
    
    printf("Angle in degree %.5lf: \n",degree); //getting the term number from the function
    printf("Angle in radians %.5lf: \n",radians); //printing the radians
    printf("Error tolerance: %.5lf \n",tolerance); //printing the tolerance
    
    k = cosApprox(degree,tolerance); //getting the total number of elements of calculation for desired error percentage.
    
    printf("Real value of cosine %.5lf : \n",cos(radians)); //printing the real value of cos(x)
    for(i=0;i<k;i++) 
    {
    	approxCos = approxCos + (pow(-1,i)*(pow(radians,2*i)/fact(2*i))); //calculating the APPROXIMATE value of cosx with for loop
	}
	
    printf("Approximate value: %.5lf \n",approxCos); //printing the approximate value
	printf("Number of terms: %d \n",k); 
	
	
	return 0;
}


int cosApprox(double x, double e) //function takes x as degrees and e is the error tolerance
{
	double approxValue=0; // definining the approximate value of cos(x) 
	int n=0; //n is iterator of the while loop
	x = x*(PI/180);
	while(fabs(cos(x)-approxValue)>e)  //if the absolute difference between real and approximate value is bigger than error tolerance, while loop will calculate Taylor series. since taylor series of cosx gets smaller every step,
	{ //it will get closer to real value with each step.
		approxValue = approxValue + (pow(-1,n)*(pow(x,2*n)/fact(2*n))); //it calculates the taylor series of cosx 
		n++;
	}
	return n;
}


int fact(int z) //defining a factorial function since we need it for calculating taylor series of cos(x).
{
	if(z==0)
	return 1;
	else
	return z * fact(z-1); 
}
