#ifndef ARBOL_H
#define ARBOL_H

#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <sstream>
#include <iomanip>

struct Nodo {
	int valor;
	Nodo* left;
	Nodo* right;
	Nodo() {}
	Nodo(int val, Nodo* izq = nullptr, Nodo* der = nullptr) 
		: valor(val), left(izq), right(der) {}
};

class Arbol{
public:
	Nodo* root;

	Arbol();
	~Arbol();

	void insertar(int v);
	void insertar_bst(int);
	Nodo* insertar_bst(Nodo*, int);
	void mostrar_arbol(Nodo* arbol, int cont);

	void pre_orden(Nodo* a);
	void post_orden(Nodo* a);
	void in_orden(Nodo* a);
	int suma_nodos(Nodo* a);
	int nodo_mayor(Nodo*);
	int cantidad_nodos(Nodo* a);
	int cantidad_hojas(Nodo* a);
	bool es_espejo(Arbol* r1, Arbol* r2);
	bool espejos(Nodo* a, Nodo* b);
	void convierte_espejo(Nodo* a);
	Nodo* ancestro(Arbol *arbol, int b, int c);
	void orden_nivel(Nodo* a);
	void orden_nivel_reves(Nodo* root);
	int altura(Nodo* a);
	Nodo* Buscar(Nodo*,int);
	bool printLevel(Nodo* root, int level);
	void levelOrderTraversal(Nodo* root);

	//PARA PROBAR
	void PreOrden(Nodo*);
	void EnOrden(Nodo*);
	void PosOrden(Nodo*);
	//!PARA PROBAR

private:
	bool vacio();
	
};

#endif // !ARBOL_H