#include <iostream>

using namespace std;

class Test
{
	int data;
	
public:
	Test(void);	
	void print(void);
	friend void setData(Test& t, int data); // 외부함수를 친구를 데리고 클래스안에 접근
						//t 의 주소를 넘기는 이유는 t. 이렇게 사용하려고
						// * t 하려면 t-> 이렇게 써야하니까
};
	
Test::Test(void)
{
	cout << "Test called" << endl;
}

void Test::print(void)
{
	cout <<"data = " << data << endl;
}
	
void setData(Test& t, int data)
{
	t.data = data;
}

int main(void)
{
	Test t; // 주소 1000 , 값 ?
	t.print();
	setData(t, 2018);
	t.print();
	
	return 0;
}
