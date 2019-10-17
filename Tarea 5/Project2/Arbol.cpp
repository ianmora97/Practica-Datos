#include "Arbol.h"

Arbol::Arbol() : root(nullptr) {}
Arbol::~Arbol(){}
void Arbol::insertar(int v){
	std::queue<Nodo*> cola;

	Nodo* tmp;
	Nodo* nuevo = new Nodo;

	nuevo->valor = v;
	nuevo->left = nullptr;
	nuevo->right = nullptr;

	if (root == nullptr) {
		root = nuevo;
		return;
	}

	cola.push(root); //insertar
	while (!cola.empty()) {
		tmp = cola.front(); //posicionar al principio
		cola.pop(); //eliminar
		if (tmp->left != nullptr)
			cola.push(tmp->left); //inserta a la izquierda
		else {
			tmp->left = nuevo;
			return;
		}
		if (tmp->right != nullptr)
			cola.push(tmp->right); //inserta a la derecha
		else {
			tmp->right = nuevo;
			return;
		}
	}
}
void Arbol::insertar_bst(int val) {
	root = insertar_bst(root, val);
}
Nodo* Arbol::insertar_bst(Nodo* actual, int key) {
	if (actual == nullptr) {
		actual = new Nodo(key);
	}
	else {
		if (key < actual->valor)
			actual->left = insertar_bst(actual->left, key);
		else if (key > actual->valor)
			actual->right = insertar_bst(actual->right, key);
	}
	return actual;
}
//este metodo lo busque en internet solo para mostrar el arbol bonito xd
void Arbol::mostrar_arbol(Nodo* r, int cont) {//contador ayuda a separar un nodo del otro
	if (r == nullptr) {
		return;
	}
	else {
		mostrar_arbol(r->right, cont + 1);
		int i;
		for (i = 0; i < cont; i++) {
			std::cout << "   ";
		}
		std::cout << r->valor << std::endl;
		mostrar_arbol(r->left, cont + 1);
	}
}


//antes de ingresar el nodo de la izquierda, imprimo la raiz
//luego ingreso el de la izquierda y asi sucesivamente hasta
//llegar al nodo de la derecha y luego lo imprimo
void Arbol::pre_orden(Nodo* a){ //raiz, izquierda, derecha
	std::stack<Nodo*> pila;
	
	Nodo* temp = a;	
	do {
		if (temp != nullptr) { //si no esta vacio sigue con el izquierdo
			std::cout << temp->valor << " ";
			pila.push(temp);
			temp = temp->left;
		}
		else if( !pila.empty()) { //si esta vacio voy por el derecho
			temp = pila.top();
			pila.pop();
			temp = temp->right;
		}
			
	} while (!pila.empty() || temp != nullptr);

}

void Arbol::post_orden(Nodo* a){

	std::stack<Nodo*> s;

	Nodo* aux = this->root;
	Nodo* prev = nullptr;

	s.push(aux);

	while (!s.empty()) {
		Nodo* current = s.top();
		if (prev == nullptr || (prev->left == current || prev->right == current)) {
			if (current->left != nullptr) s.push(current->left);
			else if (current->right != nullptr) s.push(current->right);
		}
		else if (prev == current->left) {
			if (current->right != nullptr) s.push(current->right);
		}
		else {
			std::cout << current->valor << " ";
			s.pop();
		}

		prev = current;
	}

}
//meto en la pila los nodos hasta llegar al nodo de la izquierda mas profundo
//luego cuando llego lo imprimo y automaticamente lo saco
//imprimo la raiz y luego la derecha y lo imprimo
void Arbol::in_orden(Nodo* a){ //izquierda, raiz, derecha
	std::stack<Nodo*> pila;

	Nodo* temp = a;
	do{
		if (!pila.empty() && temp == nullptr) {
			std::cout << pila.top()->valor << " ";
			temp = pila.top();
			pila.pop();
			temp = temp->right;
		}
		if (temp != nullptr) {
			pila.push(temp);
			temp = temp->left;
		}
		
	}while (!pila.empty() || temp != nullptr);
}
int Arbol::suma_nodos(Nodo* a) {
	int suma = 0;
	std::stack<Nodo*> pila;

	Nodo* temp = a;
	do {
		if (temp != nullptr) { //si no esta vacio sigue con el izquierdo
			suma += temp->valor;//suma
			pila.push(temp);
			temp = temp->left;
		}
		else if (!pila.empty()) { //si esta vacio voy por el derecho
			temp = pila.top();
			pila.pop();
			temp = temp->right;
		}

	} while (!pila.empty() || temp != nullptr);

	return suma;
}
bool Arbol::vacio(){
	return (root == nullptr);
}
void Arbol::PreOrden(Nodo* actual) {
	if (actual != nullptr) {
		std::cout << actual->valor << " ";
		PreOrden(actual->left);
		PreOrden(actual->right);
	}
}
void Arbol::EnOrden(Nodo* actual) {
	if (actual != nullptr) {
		EnOrden(actual->left);
		std::cout << actual->valor << " ";
		EnOrden(actual->right);
	}
}
void Arbol::PosOrden(Nodo* actual) {
	if (actual != nullptr) {
		PosOrden(actual->left);
		PosOrden(actual->right);
		std::cout << actual->valor << " ";
	}
}
void Arbol::orden_nivel(Nodo* root) {
	std::queue<Nodo*> q;
	Nodo* temp;

	q.push(root);
	
	while (!q.empty()) {
		temp = q.front();
		q.pop();
	
		std::cout << temp->valor << " ";
		
		if (temp->left)
			q.push(temp->left); 
		if (temp->right)
			q.push(temp->right);
	}
}
void Arbol::orden_nivel_reves(Nodo* a) {

	std::stack<Nodo*> pila;
	std::stack<Nodo*> pilaM;

	Nodo* temp = a;
	do {
		if (!pila.empty() && temp == nullptr) {
			temp = pila.top();
			pilaM.push(temp);
			pila.pop();
			temp = temp->right;
		}
		if (temp != nullptr) {
			pila.push(temp);

			temp = temp->left;
		}

	} while (!pila.empty() || temp != nullptr);
	while (!pilaM.empty()) {
		std::cout << pilaM.top()->valor << " ";
		pilaM.pop();
	}
}


void Arbol::levelOrderTraversal(Nodo* root) {
	int level = altura(root);

	while (printLevel(root, level)) {
		
		level++;
		
	}
}

bool Arbol::printLevel(Nodo* root, int level)
{
	if (root == nullptr)
		return false;

	if (level == 1)
	{
		std::cout << root->valor << " ";

		return true;
	}

	bool left = printLevel(root->left, level - 1);
	bool right = printLevel(root->right, level - 1);

	return left || right;
}

int Arbol::altura(Nodo* node) {
	if (node == NULL)
		return 0;
	else{
		int lheight = altura(node->left);
		int rheight = altura(node->right);

		if (lheight > rheight)
			return(lheight + 1);
		else return(rheight + 1);
	}
}
int Arbol::nodo_mayor(Nodo* root) {
	int v = 0;
	std::queue<Nodo*> q;
	Nodo* temp;

	q.push(root);

	while (!q.empty()) {
		temp = q.front();
		q.pop();

		if (temp->valor > v) {
			v = temp->valor;
		}

		if (temp->left)
			q.push(temp->left);
		if (temp->right)
			q.push(temp->right);
	}

	return v;
}

//Utilizo el metodo para buscar a lo profundo
//esto me funciona por que el pop solo lo hace una vez por nodo
//entonces uso un contados por las veces que haga pop
int Arbol::cantidad_nodos(Nodo* a){
	if (root == nullptr)
		return 0;

	std::queue<Nodo*> cola;
	Nodo* tmp = nullptr;
	int cont = 0;
	cola.push(root);
	while (!cola.empty()) {
		tmp = cola.front();
		cola.pop();
		cont++;
		if (tmp->left != nullptr)
			cola.push(tmp->left);
		if (tmp->right != nullptr)
			cola.push(tmp->right);
	}
	return cont;
}
//El metodo de post orden no funcionaba, solo mostraba las hojas del arbol
//entonces aproveche el bug xd
int Arbol::cantidad_hojas(Nodo* a){
	std::stack<Nodo*> pila;

	Nodo* temp = a;
	int cont = 0;
	do {
		if (temp == nullptr && !pila.empty()) {
			cont++;
			pila.pop();
		}
		if (temp != nullptr) {
			pila.push(temp);
			temp = temp->left;
		}

		else if (!pila.empty()) {
			temp = pila.top();
			pila.pop();
			temp = temp->right;
		}
	} while (!(pila.empty()) || temp != nullptr);
	return cont;
}

bool Arbol::es_espejo(Arbol* r1, Arbol* r2) {
	return espejos(r1->root, r2->root);
}

void Arbol::convierte_espejo(Nodo* a){
	if (a == nullptr)
		return;
	else {
		Nodo* aux;
		convierte_espejo(a->left);
		convierte_espejo(a->right);

		aux = a->left;
		a->left = a->right;
		a->right = aux;
	}
}

Nodo* Arbol::ancestro(Arbol *arbol, int b, int c){
	while (arbol->root != nullptr) {
		if (arbol->root->valor > b && arbol->root->valor > c)
			arbol->root = arbol->root->left;

		else if (arbol->root->valor < b && arbol->root->valor < c)
			arbol->root = arbol->root->right;

		else break;
	}
	return arbol->root;
}
bool Arbol::espejos(Nodo* a, Nodo* b) {
	if (a == nullptr && b == nullptr)
		return true;

	if (a == nullptr || b == nullptr)
		return false;

	return  a->valor == b->valor && espejos(a->left, b->right) && espejos(a->right, b->left);
}
Nodo* Arbol::Buscar(Nodo* actual, int key) {
	if (actual == nullptr)
		return nullptr;

	if (actual->valor == key)
		return actual;

	Nodo* tmp = Buscar(actual->left, key);

	if (tmp != nullptr)
		return tmp;
	else
		return Buscar(actual->right, key);
}