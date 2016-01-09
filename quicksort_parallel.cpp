#include"quicksort.h"
#include<pthread.h>
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

void* quicksort (void* data)
{	
	struct::data *pdata1=(struct::data*)data;
	struct::data data1=*pdata1;
	if(data1.mcount>1)
	{
		int pivotindex=partition((void*)&data1);
		
		//left data
		pthread_t tid1;
		pthread_attr_t attr;
		pthread_attr_init (&attr);
		struct::data ldata;
		ldata.mcount=pivotindex;
		ldata.mptr=data1.mptr;
		
		struct::data rdata;
		rdata.mcount=(data1.mcount)-pivotindex-1;
		rdata.mptr=data1.mptr + pivotindex+1;
		
		if(ThreadCounter<MAX_THREADS)
		{
			
			if(!pthread_create(&tid1,&attr,quicksort,&ldata)){ ThreadCounter++;	}
		quicksort((void*)&rdata);
		pthread_join(tid1,NULL);		}
		
		else {serialsort((void*)&ldata); serialsort((void*)&rdata);} 
		

}

return NULL;
}
//...will be used when MAXIMUM THREADS EXHAUST
void* serialsort(void* data)
{
	quicksort(data);
	return NULL;
}

int partition ( void* data1)
{
	struct::data * pdata2=(struct::data*)data1;
	struct::data data2=*pdata2;
	int count=data2.mcount;
	float * pnumbers=data2.mptr;
	int tempCounter=0;		//counts how many postions did pivot moved
	int startCounter=0;		//counts how many places did start moved;
	const float pivot=pnumbers[count-1];
	float * temp=&pnumbers[count-1];
	float * unexstart=&pnumbers[0];
	float * unexend=&pnumbers[count-2];
	if(count>1)
	{
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
	}
	
	return (count-tempCounter-1);
}

	
void output( float *numbs  , int count ,const string filename)
{
	ofstream fout; 
	fout.open(filename);
for ( int i=0 ; i< count ; i++)
{	fout<< numbs[i];	fout<<"\n"; }
fout.close();
}






