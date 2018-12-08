#include <iostream>
#include <string.h>

using namespace std;

class Person
{
public:
	char name[20];
	int age;
	char job[30];
	
	void set_name(char *n);
	char *get_name(void);

	void set_age(int i);
	int get_age(void);
	
	void set_job(char *j);
	char *get_job(void);	
};

void Person::set_name(char *n)
{
	strcpy(name,n);
}
char *Person::get_name(void)
{
	return name;
}

void Person::set_age(int i)
{
        age = i;
}
int Person::get_age(void)
{
        return age;
}

void Person::set_job(char *j)
{
        strcpy(job,j);
}
char *Person::get_job(void)
{
        return job;
}


int main(void)
{

	Person p = Person();

	char data[32] = "나바보";
	
	p.set_name("leejuhwan");

	p.set_age(26);
	
	p.set_job("student");
	
	cout << "name = " << p.get_name() << endl;

	cout << "age = " << p.get_age() << endl;

	cout << "job = " << p.get_job() << endl;

	strcpy(p.name,data);
	strcpy(p.job,"바보");

	cout << "name = " << p.get_name() << endl;

        cout << "age = " << p.get_age() << endl;

        cout << "job = " << p.get_job() << endl;


	return 0;	

}
