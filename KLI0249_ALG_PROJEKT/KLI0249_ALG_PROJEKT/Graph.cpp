#include "Graph.h"
#include <queue>
#include <iostream>
#include <string>

using namespace std;

/*!
	Destruktor pro objekt graph projde dva vektory. 
	Jeden pro Edge a druhý pro Verticle. <br>
	A smaže všechny jejich položky.
*/
Graph::~Graph() 
{
	for (Verticle* verticle : vertices) 
	{
		delete verticle;
	}

	for (Edge* edge : edges) 
	{
		delete edge;
	}
}

/*!
	Vytvoří bod,přidá jej do vektoru a vrací na něj odkaz.
	\param v hodnota bodu
*/
Verticle* Graph::AddVerticle(int v) 
{
	Verticle* verticle = new Verticle(v);
	vertices.push_back(verticle);
	return verticle;
}

/*!
	Smaže první všechny edge obsahující bod a následne bod samotný.
	\param verticleToRemove hodnota bodu
*/
void Graph::RemoveVerticle(Verticle* verticleToRemove) 
{
	for (Edge* edge : edges) 
	{
		if (edge->GetVerticle1() == verticleToRemove || edge->GetVerticle2() == verticleToRemove) 
		{
			RemoveEdge(edge);
		}
	}

	for (auto it = vertices.begin(); it != vertices.end(); ) 
	{
		if (*it == verticleToRemove) 
		{
			it = vertices.erase(it);
		}
		else 
		{
			++it;
		}
	}
}

/*!
	Vytvoří edge,přidá jej do vektoru a vrací na něj odkaz.
	\param verticle1 hodnota prvního bodu edge
	\param verticle2 hodnota druhého bodu edge
*/
Edge* Graph::AddEdge(Verticle* verticle1, Verticle* verticle2) 
{
	Edge* edge = new Edge(verticle1, verticle2);
	edges.push_back(edge);
	return edge;
}

/*!
	Smaže edge.
	\param edgeToRemove odkaz na edge
*/
void Graph::RemoveEdge(Edge* edgeToRemove) 
{
	for (auto it = edges.begin(); it != edges.end(); ) 
	{
		if (*it == edgeToRemove) 
		{
			it = edges.erase(it);
		}
		else 
		{
			++it;
		}
	}
}

/*!
	Načte body stromu ze souboru.
	\param InputFile objekt třídy ifstream
*/
void Graph::ReadTree(ifstream& InputFile)
{
	string s;

	while(getline(InputFile, s)) 
	{
		this->AddVerticle(stoi(s));
	}
}

/*!
	Vytvoří edge tak aby "strom" splňoval vlastnosti binárního rozhodovacího stromu.
*/
void Graph::InitializeEdges()
{
	this->AddEdge(this->vertices.front(), this->vertices.at(1));
	this->vertices.at(1)->SetFloor(2);
	this->InitializeEdgesRec(this->vertices.front(), this->vertices.at(2),2,2);
}

/*!
	Rekurzivní funkce volaná funkcí InitializeEdges a sama sebou.
	\param InTree bod polde kterého rozhodujeme jaký edge vytvořit
	\param ToBeAdded testovaný bod
	\param index index bodu ve vektoru
	\param floor patro stromu
*/
void Graph::InitializeEdgesRec(Verticle* InTree, Verticle* Tested, int index, int floor)
{
	if (Tested->GetValue() > InTree->GetValue()) {
		for (int i = 0; i < edges.size(); i++)
		{
			if (edges.at(i)->GetVerticle1()->GetValue() == InTree->GetValue() && edges.at(i)->GetVerticle2()->GetValue() > InTree->GetValue())
			{
				floor++;
				this->InitializeEdgesRec(edges.at(i)->GetVerticle2(), Tested, index, floor);
				return;
			}
		}
	}
	else
	{
		for (int i = 0; i < edges.size(); i++)
		{
			if (edges.at(i)->GetVerticle1()->GetValue() == InTree->GetValue() && edges.at(i)->GetVerticle2()->GetValue() < InTree->GetValue())
			{
				floor++;
				this->InitializeEdgesRec(edges.at(i)->GetVerticle2(), Tested, index, floor);
				return;
			}
		}
	}

	this->AddEdge(InTree, Tested);
	Tested->SetFloor(floor);
	
	if (Tested != this->vertices.back())
	{
		index++;
		this->InitializeEdgesRec(this->vertices.front(), this->vertices.at(index), index, 2);
	}
}

/*!
	Vypočítá a vypíše nejširší patro stromu a jeho šířku
*/
void Graph::TreeWidth()
{
	int max = 0;

	for (Verticle* verticle : vertices) 
	{
		if(verticle->GetFloor() > max)
		{
			max = verticle->GetFloor();
		}
	}

	int* arr = new int[max];

	for (int i = 0; i < max; i++)
	{
		arr[i] = 0;
	}

	for (Verticle* verticle : vertices) 
	{
		arr[verticle->GetFloor()-1]++;
	}

	int floor = 1;
	int width = 1;

	for (int i = 0; i < max;i++) 
	{

		if (arr[i] > width)
		{
			width = arr[i];
			floor = i+1;
		}
	}

	cout << "\nWidest floor of the tree is: " << floor << " with: " << width << " nodes" << endl;
}

/*!
	Vypíše body a edge stromu
*/
void Graph::Print() {
	cout << "\nVerticles: " << endl;
	for (Verticle* verticle : vertices) 
	{
		verticle->Print();
	}

	cout << "\nEdges: " <<endl;

	for (Edge* edge : edges) 
	{
		edge->Print();
	}
}