#include "Arbol.h"

int main() {

	Arbol* arbol = new Arbol;
	Arbol* arbolB = new Arbol;
	
	arbol->insertar(8);
	arbol->insertar(9);
	arbol->insertar(4);
	arbol->insertar(5);
	arbol->insertar(0);
	arbol->insertar(3);
	arbol->insertar(2);
	arbol->insertar(1);
	arbol->insertar(11);

	arbolB->insertar(8);
	arbolB->insertar(9);
	arbolB->insertar(4);
	arbolB->insertar(5);
	arbolB->insertar(0);
	arbolB->insertar(3);
	arbolB->insertar(2);
	arbolB->insertar(1);
	arbolB->insertar(11);

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
	arbol->orden_por_nivel(arbol->root);
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
	std::cout << "Sucesor Antecesor Hermanos : ";
	arbol->sucesor_antecesor_hermano(arbol->root, 3);
	std::cout << std::endl;
	std::cout << "Son Arboles iguales : ";
	std::cout << std::boolalpha << arbol->son_arboles_iguales(arbol, arbolB);
	std::cout << std::endl;
	

	std::cout << "El espejo del arbol es  : ";
	arbol->convierte_espejo(arbol->root);
	std::cout << std::endl;
	arbol->mostrar_arbol(arbol->root, 0);
	std::cout << std::endl;

	Arbol* arbol2 = new Arbol;

	arbol2->insertar_bst(8);
	arbol2->insertar_bst(9);
	arbol2->insertar_bst(4);
	arbol2->insertar_bst(5);
	arbol2->insertar_bst(0);
	arbol2->insertar_bst(3);
	arbol2->insertar_bst(2);
	arbol2->insertar_bst(1);
	arbol2->insertar_bst(11);

	std::cout << std::endl;
	std::cout << "Arbol 'bonito' " << std::endl;
	arbol2->mostrar_arbol(arbol2->root, 0);
	std::cout << std::endl;
	std::cout << "El arbol es BST : ";
	std::cout << std::boolalpha << arbol2->compara_bst(arbol2);
	std::cout << std::endl;
	std::cout << "El arbol 1 y arbol 2 son espejo : ";
	std::cout<<std::boolalpha << arbol->es_espejo(arbol,arbol2);

	std::cout << std::endl;
	system("pause");
	//std::cin.get();
	return 0;
}