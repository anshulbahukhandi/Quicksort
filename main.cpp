#include"quicksort.h"
#include<pthread.h>
using namespace std;
int main()
{
	random("test1.txt");
	int count;
	float* ptr=new float[MAX_SIZE];
	count=input("test1.txt",ptr);	
	
	struct::data mdata;
	mdata.mptr=ptr;
	mdata.mcount=count;
	clock_t start=clock();
	quicksort(&mdata);
	double time = clock()-start;
	cout<<"Time taken : "<<time<<"\n";
	cout<<"Program Execution Successfull !!!\n";
	output(ptr,count,"test1.out");
	delete[] ptr;
	return 0;
}
