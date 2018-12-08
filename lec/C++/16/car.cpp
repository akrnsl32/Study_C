#include <iostream>
#include <string.h>

using namespace std;

class Car 
{
private:
	int speed;
	char color[32];

public:
	Car(void);
	Car(int speed, char *c);
	void setSpeed(int s);
	int getSpeed(void);
	void setColor(char *c);
	char *getColor(void); //캐릭터 배열을 리턴
};
//함수원형을 구현하겠다	

Car::Car(void)
{
	cout << "I'm Car  Default Constructor!!!"<< endl;

}

Car::Car(int s,char *c)
{
	cout << "I'm Car  Default Constructor too !!!"<< endl;
	speed = s;
	strncpy(color,c,strlen(c)); // 변수, 인자 , 인자길이
}


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
	
	char color[32] = "빨강";
	Car c2 = Car(200,color);
	cout << "speed = " << c2.getSpeed() << endl;
	cout << "color = " << c2.getColor() << endl;	
	
	return 0;
}
