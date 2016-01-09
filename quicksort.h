// Serial code to sort items using Quicksort Algorithm 
//Input : file with numbers 
//Output: file with numbers sorted in ascending order
#include<random>
#include<iostream>
#include<fstream>
#include<string>
#include<ctime>
#define MAX_NUM 10000			//change this to the size of input file
#define MAX_SIZE MAX_NUM					//change this to increase the maximum storage capacity
#define MAX_THREADS 1
//data structure to store the extracted info from the input file
struct data
{
	float * mptr;
	int mcount ; 
};
 static int ThreadCounter =1; 
//function to generate the random numbers file
void random ( const std::string);
//function to take input from file 
int input(const std::string ,  float* );
//function to store the output 
void output( float *  , int , const std::string);
//takes struct:: data with all the info as the input
//...function to configure the process 
void cofigure ( struct::data* );
void* quicksort( void* );
//................partition function 
int partition ( void* );
//function to swap the values of a and b
void swap(float & , float &);
// serial sort algorithm ..wil be used when maximum threads reach
void* serialsort(void*);