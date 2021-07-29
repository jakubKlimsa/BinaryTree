#pragma once
#include "Verticle.h"

/*!
	Třída verticle je určena pro uložení, a praci s informacemi o relaci mezi uzly binarního stromu.
	Detajlnější popis této třídy a všech jejích funkcí najdete v souboru .cpp.
*/
class Edge
{
Verticle* _verticle1;
Verticle* _verticle2;

public:
	Edge(Verticle* verticle1, Verticle* verticle2);
	void Print();
	Verticle* GetVerticle1();
	Verticle* GetVerticle2();
};
