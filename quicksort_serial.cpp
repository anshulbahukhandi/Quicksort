#include"quicksort.h"
using namespace std;

void random (const string filename)
{
	ofstream fout;
	fout.open(filename);
	srand(time(NULL));
	
	for ( int i=0 ; i< MAX_NUM -1; i++)
	{
	fout<<rand()<<"\n";	
	}
	fout<<rand();
	fout.close();
}
int input(const std::string filename,float*pnumbers )
{
	int counter=0;
	ifstream fin ; 
	fin.open(filename);
	float num;
	while(!fin.eof())
	{
		fin>>num;
		*pnumbers=num;
		pnumbers++;
		counter++;
	}
	pnumbers=pnumbers-counter;
	fin.close();
	return counter;
	
}

//swap function  will be used while sorting 
void swap (float &a , float &b) 
{
	float temp ; 
	temp=a;
	a=b;
	b=temp;
}

void quicksort( float * pnums , int count)
{
if(count>1)
{
	int index;
	index=count-partition(pnums , count )-1;
	//partitoning left side 
	quicksort(pnums, index);		//sorting left sub array 
	quicksort(pnums+index+1 , count-index-1);  //sorting right subarray	
}
}

int partition (float * pnumbers ,int count)
{
	int tempCounter=0;		//counts how many postions did pivot moved
	int startCounter=0;		//counts how many places did start moved;
	const float pivot=pnumbers[count-1];
	float * temp=&pnumbers[count-1];
	float * unexstart=&pnumbers[0];
	float * unexend=&pnumbers[count-2];
	while(unexstart!=unexend  )
	{
		if(*unexstart>=pivot)
			{
				swap(*unexstart,*unexend);
				swap(*temp, * unexend);
				unexend--;	
				temp--;
				tempCounter++;
		}
		else 		{unexstart++; startCounter++;}
		
		}
	if(*unexend>pivot) {swap(*unexend,*temp); temp--; tempCounter++;}
	return tempCounter;				//returns the pivot after partitioning
	//Resetting the pointers 
	//quicksort(temp+1,tempCounter);
	
	/*float * unexstart1= temp-(count-(tempCounter+1));
	float * unexend1=temp-1;
	int count1=count-(tempCounter+1);
	float * unexstart2=temp+1;
	float * unexend2=temp+tempCounter;
	int count2 = tempCounter;*/
	/*cout<<"start 1 :"<<*unexstart1<<endl;
		cout<<"end 1 :"<<*unexend1<<endl;
			cout<<"start 2 :"<<*unexstart2<<endl;
				cout<<"end 2 :"<<*unexend2<<endl;*/
}









