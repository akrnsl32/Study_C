#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define SCHOOL_NAME 24
#define PERSON_NAME 28

typedef struct __person
{
	int age;
	char name[PERSON_NAME];
} person;


typedef struct __score
{
	int math;
	int english;
	int physics;
} score;


typedef struct __school
{
	person *p;
	score s;
	char name[SCHOOL_NAME];

} school;

school *init_struct(void)
{
	school *tmp = (school *)malloc(sizeof(school));
	//동적할당시 school 구조체만큼 메모리 할당후 주소로 연결
	tmp->p = (person *)malloc(sizeof(person));
	// school 안 person또한 포인터로 되어있기에 메모리 할당후 주소로 연결
	tmp->p->age = 20;	
	strcpy(tmp->p->name, "juhwan");
////////////////////////////////////////////////////////////////
	
	tmp->s.math = 70;
	tmp->s.english = 80;
	tmp->s.physics = 20;
	
	strcpy(tmp->name, "Juhwan Univ ");
	
	return tmp;
}

void print_struct(school *s)
{
	printf("School Name = %s\n", s->name);
	printf("Student Name = %s\n", s->p->name);
	printf("Age = %d\n", s->p->age);
	
	printf("Student Score\n");
	printf("Math - %d, English - %d, Physics - %d \n",
		s->s.math, s->s.english , s->s.physics);

}

int main(void)
{
	school *s = NULL;
	
	s = init_struct();
	print_struct(s);

	free(s->p);
	free(s);
	return 0;
}


