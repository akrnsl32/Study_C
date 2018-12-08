#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <math.h>


using namespace std;

class Sample
{
public:
	float time[256];
	float velocity[256];

public:
	Sample(void);
	Sample(int *, int *);
	void setTime(void);
	void setVel(void);
	void printData(void);
//	friend inte(Sample& s,int& r);
};

Sample::Sample(void)
{
	int i;
	for(i = 0; i < 256; i++)
        {
                this->time[i] = 0;
                this->velocity[i] = 0;
        }

}

void Sample::setTime(void)
{
	
	int i;
	
	for(i =0; i < 256;i++)
	{ 
		this->time[i] = pow(10,-3);
	}
}

void Sample::setVel(void)
{
	
	int i;
	
	for(i =0; i < 256;i++)
	{ 
		this->velocity[i] = (rand() % 201) - 100;

	}
}

void Sample::printData(void)
{
	int i ;
	for(i = 0; i < 256; i++)
	{
		cout << "tiem[" << i << "]  = " << this->time[i] << endl;
		cout << "velocity[" << i << "]  = " << this->velocity[i] << endl;

	}
}
/*void inte(Sample& s, int& result)
{
	int i ;
	for(i = 0; i < 256; i++)
	{
		result[i] = s.time[i];
	}
i 
 */

int main(void)
{
	int i;
	Sample s;
	
	float shift[256];
	float sum = 0.0f;

	srand(time(NULL));
	
	s.setTime();
	s.setVel();
	
	s.printData();
	

	for(i = 0; i < 256; i++)
	{
		sum += s.time[i] * s.velocity[i];
	}
	cout<< "sum = " << sum << endl;
	
	return 0;

}

