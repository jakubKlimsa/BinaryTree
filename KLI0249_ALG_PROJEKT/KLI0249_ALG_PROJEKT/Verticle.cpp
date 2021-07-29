#include "Verticle.h"
#include <iostream>

using namespace std;

/*!
	Konstruktor pro objekt verticle bere jeden parametr typu int
	\param v hodnota bodu
*/
Verticle::Verticle(int v) {
	this->value = v;
	this->floor = 1;
}

/*!
  Vypíše bod
*/
void Verticle::Print() {
	cout << "(" << value << ")" << " floor:" << floor << endl;
}

/*!
  Vrátí hodnotu bodu
*/
int Verticle::GetValue() {
	return value;
}

/*!
  Nastaví bodu patro stromu
  \param f patro stromu
*/
void Verticle::SetFloor(int f)
{
	this->floor = f;
}

/*!
  Vrátí patro stromu na kterém se nachází bod
*/
int Verticle::GetFloor()
{
	return floor;
}