#include <iostream>
#include <string.h>

using namespace std;

class Car 
{
public:
	int speed;
	char color[32];
	
	void setSpeed(int s);
	int getSpeed(void);
	void setColor(char *c);
	char *getColor(void); //캐릭터 배열을 리턴
};
//함수원형을 구현하겠다	
void Car::setSpeed(int s)
{
	speed = s;
}
	
int Car::getSpeed(void)
{
	return speed;
}
	
void Car::setColor(char *c)
{
	strcpy(color, c);
}

char *Car::getColor(void)
{
	return color;
}

int main(void)
{
	Car c = Car(); // 생성자
	
	c.setSpeed(180);
	cout << "speed = " << c.getSpeed() << endl;
	
	c.setColor("blue");
	cout << "color = " << c.getColor() << endl;
	
	
	
	return 0;
}
