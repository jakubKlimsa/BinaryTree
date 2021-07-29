#pragma once
#include <vector>
#include <fstream>
#include "Edge.h"

using namespace std;

/*!
	Třída graph je určena pro uložení, a praci s informacemi o binarním stromu.
	Detajlnější popis této třídy a všech jejích funkcí najdete v souboru .cpp.
*/
class Graph
{
private:
	vector<Verticle*> vertices;
	vector<Edge*> edges;

public:
	~Graph();

	Verticle* AddVerticle(int v);
	void RemoveVerticle(Verticle* verticleToRemove);
	Edge* AddEdge(Verticle* verticle1, Verticle* verticle2);
	void RemoveEdge(Edge* edge);
	void ReadTree(ifstream& InputFile);
	void InitializeEdges();
	void InitializeEdgesRec(Verticle* InTree, Verticle* Tested, int index, int floor);
	void TreeWidth();
	void Print();
};
