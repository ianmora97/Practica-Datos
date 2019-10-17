#include "Arbol.h"

int main() {

	Arbol* arbol = new Arbol;

	arbol->insertar_bst(8);
	arbol->insertar_bst(9);
	arbol->insertar_bst(4);
	arbol->insertar_bst(5);
	arbol->insertar_bst(0);
	arbol->insertar_bst(3);
	arbol->insertar_bst(2);
	//arbol->insertar(1);
	//arbol->insertar(11);

	std::cout<<"Arbol 'bonito' " << std::endl;
	arbol->mostrar_arbol(arbol->root, 0);
	std::cout << std::endl;


	std::cout << "Recorrido PreOrden : ";
	arbol->pre_orden(arbol->root);
	std::cout << std::endl;
	std::cout << "Recorrido InOrden : ";
	arbol->in_orden(arbol->root);
	std::cout << std::endl;
	std::cout << "Recorrido PostOrden : ";
	arbol->post_orden(arbol->root);
	std::cout << std::endl;
	std::cout << "Recorrido Por Nivel : ";
	arbol->orden_nivel(arbol->root);
	std::cout << std::endl;
	std::cout << "Recorrido Por Nivel al reves : ";
	arbol->orden_nivel_reves(arbol->root);
	std::cout << std::endl;

	std::cout << "Cantidad de Nodos : ";
	std::cout<<arbol->cantidad_nodos(arbol->root);
	std::cout << std::endl;
	std::cout << "Cantidad de Hojas : ";
	std::cout << arbol->cantidad_hojas(arbol->root);
	std::cout << std::endl;
	std::cout << "Suma de los nodos : ";
	std::cout << arbol->suma_nodos(arbol->root);
	std::cout << std::endl;
	std::cout << "El nodo mayor es : ";
	std::cout << arbol->nodo_mayor(arbol->root);
	std::cout << std::endl;
	std::cout << "La altura del arbol es : ";
	std::cout << arbol->altura(arbol->root);
	std::cout << std::endl;

	std::cout << "El espejo del arbol es  : ";
	arbol->convierte_espejo(arbol->root);
	std::cout << std::endl;
	arbol->mostrar_arbol(arbol->root, 0);
	std::cout << std::endl;
	

	//std::cout << "El nodo mayor es : ";
	arbol->levelOrderTraversal(arbol->root);
	std::cout << std::endl;

	Arbol* arbol2 = new Arbol;

	arbol2->insertar(8);
	arbol2->insertar(9);
	arbol2->insertar(4);
	arbol2->insertar(5);
	arbol2->insertar(0);
	arbol2->insertar(3);
	arbol2->insertar(2);
	arbol2->insertar(1);
	arbol2->insertar(11);

	std::cout << "El arbol 1 y arbol 2 son espejo : ";
	std::cout<<std::boolalpha << arbol->es_espejo(arbol,arbol2);

	std::cout << std::endl;
	system("pause");
	//std::cin.get();
	return 0;
}