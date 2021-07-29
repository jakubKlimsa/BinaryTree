#pragma once

/*!
	Třída verticle je určena pro uložení, a praci s informacemi o uzlu binarního stromu.
	Detajlnější popis této třídy a všech jejích funkcí najdete v souboru .cpp.
*/
class Verticle
{
private:
	int value;
	int floor;

public:
	Verticle(int v);
	void Print();
	int GetValue();
	void SetFloor(int f);
	int GetFloor();
};
