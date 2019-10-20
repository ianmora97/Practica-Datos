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

	//insertar
		//binario normal
	void insertar(int v);
	void insertar_postfija(std::string s);
		//binario busqueda
	void insertar_bst(int);
	Nodo* insertar_bst(Nodo*, int);
	//!insertar

	//recorridos
		//iterativos
	void pre_orden(Nodo* a);
	void post_orden(Nodo* a);
	void in_orden(Nodo* a);
	void orden_nivel(Nodo* a);
		//recursivos
	void PreOrden(Nodo*);
	void EnOrden(Nodo*);
	void PosOrden(Nodo*);
	void imprimir_orden_nivel(Nodo* root, int level);
	void orden_por_nivel(Nodo* root);
	//!recorridos

	void mostrar_arbol(Nodo* arbol, int cont);
	bool buscar(int);
	Nodo* buscar(Nodo*,int);
	
	int suma_nodos(Nodo* a);
	int nodo_mayor(Nodo*);
	int cantidad_nodos(Nodo* a);
	int cantidad_hojas(Nodo* a);
	bool es_espejo(Arbol* r1, Arbol* r2);
	bool espejos(Nodo* a, Nodo* b);
	void convierte_espejo(Nodo* a);
	Nodo* ancestro(Arbol *arbol, int b, int c);
	void orden_nivel_reves(Nodo* root);
	int altura(Nodo* a);
	Nodo* nodo_mas_profundo();
	void borrar_arbol(Nodo* actual);
	void eliminar_nodo(int llave);
	void sucesor_antecesor_hermano(Nodo*,int);
	bool buscar_nodo_por_nivel(Nodo*, int, int);
	bool son_arboles_iguales(Arbol* a1, Arbol* a2);
	bool compara_bst(Arbol* a1);


private:
	bool vacio();
	
};

#endif // !ARBOL_H