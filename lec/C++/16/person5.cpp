#include <iostream>
#include <string.h>

using namespace std;

class Person
{
private:
	char name[20];
	int age;
	char job[30];

public:
	Person(void);	
	Person(char *n, int a, char *j); 
	void set_name(char *n);
	char *get_name(void);

	void set_age(int i);
	int get_age(void);
	
	void set_job(char *j);
	char *get_job(void);	
};

Person::Person(void)
{


}


Person::Person(char *n, int a, char *j)
{
	cout << " 난 생성자 2 야 " << endl;
	strncpy(name,n,strlen(n));
	age = a;
	strncpy(job,j,strlen(j));
}

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

	Person p2 = Person();
	
	char name[30] = "김아무개";
	char job[30] = "백수";

	Person p3 = Person("김아무개",18,"백수");
	
        cout << "name = " << p2.get_name() << endl;

        cout << "age = " << p2.get_age() << endl;

        cout << "job = " << p2.get_job() << endl;

        cout << "name = " << p3.get_name() << endl;

        cout << "age = " << p3.get_age() << endl;

        cout << "job = " << p3.get_job() << endl;


	return 0;	

}
