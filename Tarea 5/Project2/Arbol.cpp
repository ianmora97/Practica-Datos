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
void Arbol::insertar_postfija(std::string s){

	std::stack<Nodo*> s;

	Nodo* aux = this->root;
	Nodo* prev = nullptr;
	/*
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
	*/
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
bool Arbol::buscar(int key) {
	if (buscar(root, key) != nullptr)
		return true;
	return false;
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
		std::cout << actual->valor << " "; //raiz
		PreOrden(actual->left); //izquierda
		PreOrden(actual->right); //derecha
	}
}
void Arbol::EnOrden(Nodo* actual) {
	if (actual != nullptr) {
		EnOrden(actual->left); //izquierda
		std::cout << actual->valor << " ";//raiz
		EnOrden(actual->right);//derecha
	}
}
void Arbol::PosOrden(Nodo* actual) {
	if (actual != nullptr) {
		PosOrden(actual->left);//izquierda
		PosOrden(actual->right); //derecha
		std::cout << actual->valor << " ";//raiz
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


void Arbol::orden_por_nivel(Nodo* root) {
	int level = altura(root) + 1;

	for (int i = 1; i <= level; i++) {
		imprimir_orden_nivel(root, i);
	}
}

void Arbol::imprimir_orden_nivel(Nodo* root, int level){
	if (root == nullptr)
		return;
	if (level == 1)
		std::cout << root->valor << " ";
	else {
		imprimir_orden_nivel(root->left, level - 1);
		imprimir_orden_nivel(root->right, level - 1);
	}
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
Nodo* Arbol::buscar(Nodo* actual, int key) {
	if (actual == nullptr)
		return nullptr;

	if (actual->valor == key)
		return actual;

	Nodo* tmp = buscar(actual->left, key);

	if (tmp != nullptr)
		return tmp;
	else
		return buscar(actual->right, key);
}

Nodo* Arbol::nodo_mas_profundo() {
	if (root == nullptr)
		return nullptr;

	std::queue<Nodo*> cola;
	Nodo* tmp = nullptr;

	cola.push(root);
	while (!cola.empty()) {
		tmp = cola.front();
		cola.pop();
		if (tmp->left != nullptr)
			cola.push(tmp->left);
		if (tmp->right != nullptr)
			cola.push(tmp->right);
	}
	return tmp;
}

void Arbol::borrar_arbol(Nodo* actual) {
	if (actual != nullptr) {
		borrar_arbol(actual->left);
		borrar_arbol(actual->right);
		delete actual;
	}
}

void Arbol::eliminar_nodo(int llave) {

	Nodo* tmp = buscar(root, llave);

	if (tmp == nullptr)
		return;

	Nodo* ultimo = nodo_mas_profundo();

	if (root == ultimo) {
		delete root;
		root = nullptr;
		return;
	}

	if (tmp != ultimo)
		tmp->valor = ultimo->valor;
	
	std::queue<Nodo*> cola;
	cola.push(root);
	while (!cola.empty()) {
		tmp = cola.front();
		cola.pop();
		if (tmp->left != nullptr) {
			if (tmp->left == ultimo) {
				delete ultimo;
				tmp->left = nullptr;
				return;
			}
			cola.push(tmp->left);
		}
		if (tmp->right != nullptr) {
			if (tmp->right == ultimo) {
				delete ultimo;
				tmp->right = nullptr;
				return;
			}
			cola.push(tmp->right);
		}
	}
}

void Arbol::sucesor_antecesor_hermano(Nodo* root, int key){
	
	bool e = buscar(root, key);
	std::cout << "\nNodo encontrado : " << std::boolalpha << e;

	int level = altura(root);
	int nivelDeHermanos = 1;
	for (int i = 1; i <= level; i++) {
		if (buscar_nodo_por_nivel(root, i, key) == true) {
			nivelDeHermanos = i;
			i = level + 1;
		}
	}
	std::cout << "\nHermanos: ";
	imprimir_orden_nivel(root, nivelDeHermanos);
}

bool Arbol::buscar_nodo_por_nivel(Nodo* root, int level, int key){
	if (root == nullptr)
		return false;
	if (level == 1) {
		//std::cout << root->valor << " ";
		if (root->valor == key) {
			return true;
		}
		//return false;
	}
	else {
		buscar_nodo_por_nivel(root->left, level - 1, key);
		buscar_nodo_por_nivel(root->right, level - 1, key);
	}
}

bool Arbol::son_arboles_iguales(Arbol* a1, Arbol* a2){
	if (a1->cantidad_nodos(a1->root) == a2->cantidad_nodos(a2->root)) {

		std::queue<Nodo*> recorrer;
		std::queue<Nodo*> cola1;
		std::queue<Nodo*> cola2;

		Nodo* temp;

		cola1.push(a1->root);
		cola2.push(a2->root);

		recorrer.push(a1->root);
		while (!recorrer.empty()) {
			temp = recorrer.front();
			recorrer.pop();
			if (temp->left) {
				recorrer.push(temp->left);
				cola1.push(temp->left);
			}
			if (temp->right) {
				recorrer.push(temp->right);
				cola1.push(temp->right);
			}
		}
		recorrer.push(a2->root);
		while (!recorrer.empty()) {
			temp = recorrer.front();
			recorrer.pop();
			if (temp->left) {
				recorrer.push(temp->left);
				cola2.push(temp->left);
			}
			if (temp->right) {
				recorrer.push(temp->right);
				cola2.push(temp->right);
			}
		}
		while (!cola2.empty() && !cola1.empty()) {
			if ((cola2.front()->valor) != cola1.front()->valor) {
				return false;
			}
			cola1.pop();
			cola2.pop();
		}
		return true;
	}

	return false;
}

bool Arbol::compara_bst(Arbol* a){

	std::stack<Nodo*> pila;
	std::stack<Nodo*> pilaM;

	Nodo* temp = a->root;
	do {
		if (!pila.empty() && temp == nullptr) {
			temp = pila.top();
			pilaM.push(temp); //ingreso
			pila.pop();
			temp = temp->right;
		}
		if (temp != nullptr) {
			pila.push(temp);

			temp = temp->left;
		}

	} while (!pila.empty() || temp != nullptr);
	Nodo* aux;
	int top;
	while (!pilaM.empty()) {
		//std::cout << pilaM.top()->valor << " ";
		aux = pilaM.top();
		pilaM.pop();
		if (!pilaM.empty()) {
			top = pilaM.top()->valor;
		}
		else {
			return true;
		}
		if (!(aux->valor > top)) {
			return false;
		}
		
	}return true;
}
