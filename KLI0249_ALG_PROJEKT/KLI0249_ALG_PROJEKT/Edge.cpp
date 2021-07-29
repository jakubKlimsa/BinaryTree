#include "Edge.h"
#include <iostream>	

using namespace std;

/*!
	Konstruktor pro objekt edge bere dva parametry typu Verticle \sa Verticle
	\param verticle1 první bod
	\param verticle2 druhý bod
*/
Edge::Edge(Verticle* verticle1, Verticle* verticle2) {
	_verticle1 = verticle1;
	_verticle2 = verticle2;
}

/*!
  Vypíše vztah bodů v edgi
*/
void Edge::Print() {
	cout << _verticle1->GetValue() << "-" << _verticle2->GetValue() << endl;
}

/*!
  Vrátí první bod edge
*/
Verticle* Edge::GetVerticle1() {
	return _verticle1;
}

/*!
  Vrátí druhý bod edge
*/
Verticle* Edge::GetVerticle2() {
	return _verticle2;
}
