#include <iostream>
#include <fstream>
#include <string>
#include "Verticle.h"
#include "Edge.h"
#include "Graph.h"

using namespace std;

int main()
{
	Graph* graph = new Graph();
	
	ifstream InputFile("Tree2.txt");
	
	graph->ReadTree(InputFile);

	InputFile.close();

	graph->InitializeEdges();

	graph->Print();

	graph->TreeWidth();

	delete graph;

	return 0;
}

/*!\mainpage Šířka binárního stromu
 *
 * \section Úvod Úvod
 * <b>Autor:</b> Jakub Klimša<br>
 * <b>Číslo zadání:</b> 2
 * 
 * \section Problém Problém
 * Máte dán binární strom<SUP>2</SUP>. <br>
 * Na binárním stromu můžeme definovat mnoho pojmů, například hloubka uzlu. 
 * Hloubka uzlu 𝑥 je definována jako vzdálenost uzlu 𝑥 od kořene stromu 𝑟. Vzdálenost měříme počtem hran na cestě od kořene 𝑟 k uzlu 𝑥. <br> 
 * Kořen 𝑟 má tedy hloubku 0, jeho přímí potomci mají hloubku 1 a tak dále. Uzly binárního stromu, které mají stejnou hloubku nazveme patrem stromu. <br>
 * Počet uzlů v každém patře nazveme šířkou patra. A konečně maximum ze všech šířek jednotlivých pater nazveme šířkou stromu. <br>
 * Vaším úkolem je implementovat funkci, která pro daný binární strom určí jeho šířku. <br>
 * 
 * \image html image.jpg "Příklad binarního stromu"
 * 
 * \section Řešení Řešení problému
 * Řešení celkového problému je rozloženo ve 3 hlavních funkcích. <br>
 * 
 * <ul>
 *		<li>
 *			<h2> Funkce ReadTree </h2>
 *			Funkce načíta strom ze zadaného souboru.
 *			<ol>
 *				<li>Z parametru funkce zjistí soubor ze kterého se má strom načítat.</li>
 *				<li>Za pomoci cyklu while načte řádek ze souboru.</li>
 *				<li>Funkce zavolá funkci "AddVerticle" do jejíž parametru předá načtený řádek.</li>
 *				<li>String v parametru fce je ještě převeden na int pomocí funkce "stoi".</li>
 *				<li>Cyklus se opakuje dokud funkce nedojde na konec souboru.</li>
 *			</ol>
 *		</li>
 *		
 *		<li>
			<h2> Funkce InitializeEdges </h2>
			Funkce vytvoří edge tak aby výsledný "strom" splňoval vlastnosti binárního rozhodovacího stromu.
 *			<ol>
 *				<li>Zavolaná funkce přidá první edge z kořenu stromu na první načtený bod a přiřadí bodu patro.</li>
 *				<li>Funkce zavolá rekurznivní funkci které předá kořen, druhý bod, parametr udávající pozici bodu ve vektoru a patro bodu.</li>
 *				<li>Zavolaná funkce zkontroluje zda je hodnota bodu větší než hodnota kořene(případně jiným bodem stromu) a podle toho rozhodne kterou větev podmínky porjít.</li>
 *				<li>Nasleduje cyklus for který projde všechny edge. A pokud se najde nějaký edge kořene(případně jiným bodem stromu) a zároveň je vetší/menší tak se proměna patro inkrementuj. Nakonec se ješte rekuzivní funkce zavolá znovu</li>
 *				<li>Pokud se takovýto edge nenajde tak se přidá nový edge mezi kořenem(případně jiným bodem stromu) a porovnávaným bodem.</li>
 *				<li>Dále následuje podmínka která kontroluje zda sme již nedošli na konec vektrou tedy poslednímu bodu grafu.</li>
 *				<li>Pokud se podmínka splní pozice ve vektrou se inkrementuje a zavolá se rekurzivní funkce. Parametry funkce budou kořen stromu, další bod ve vektoru, jeho pozice a patro.</li>
 *				<li>Tato rekurzivní funkce se volá tak dlouho dokud nedojdeme na konec vektrou pak se sama ukončí.</li>
 *			</ol>
 *		</li>
 * 
 *		<li>
 *			<h2> Funkce TreeWidth </h2></li>
 * 			Finální funkce nám spočítá šířku pater a vypíše to nejširší.
 *			<ol>
 *				<li>Jako první funkce pomocí cyklu for each projde vektor vertices a zjistí počet pater stromu.</li>
 *				<li>Dále si vytvoří dynamické pole s velikostí danou počtem pater.</li>
 *				<li>Následuje další cyklus který inicalizuje hodnoty v poly na nuly.</li>
 *				<li>Poté další cyklus for each který spočíta jednotlivé body na patře.</li>
 *				<li>Poslední cyklus pak zjistí nejvetší hodnotu v poli a na jakém místě se nachází.</li>
 *				<li>Funkce nakonec vypíše nejširší patro a jeho šířku.</li>
 *			</ol>
 *		</li>
 * </ul>
 */
