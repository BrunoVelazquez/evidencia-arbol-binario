/* 
 * Alumno: Bruno Levi Velázquez Sánchez
 * Grupo: DS-DEDA-2002-B1-003
 * Semestre: 2002-B1
 * Fecha: jueves, 3 de septiembre de 2020
 * Docente: Jazmín Pérez Méndez
*/

#include<iostream>
#include<stdlib.h>

using namespace std;

struct Nodo {
	int dato;
	Nodo *der;
	Nodo *izq;
};

void menu();
Nodo *crearNodo(int);
void insertarNodo(Nodo *&, int);
void mostrarArbol(Nodo *, int);
void imprimir(Nodo *);
void preOrden(Nodo *);
void inOrden(Nodo *);
void posOrden(Nodo *);

Nodo *arbol = NULL;

int main() {
	menu();
	return 0;
}

void menu(){
	int dato, opcion, contador = 0;

	do{
		cout << endl;
		cout << endl;
		cout << "Menú" << endl;
		cout << "[1] Para insertar un nuevo nodo" << endl;
		cout << "[2] Mostrar arbol completo" << endl;
		cout << "[3] Mostrar pre-orden" << endl;
		cout << "[4] Mostrar in-orden" << endl;
		cout << "[5] Mostrar pos-orden" << endl;
		cout << "[6] Salir del programa" << endl;
		cout << "Seleccione tarea: ";
		
		cout << endl;
		cout << endl;
		cin >> opcion;

		switch(opcion){
			case 1:
				cout << "Ingrese el valor: ";
				cin >> dato;
				insertarNodo(arbol, dato);
				cout << endl;
				break;
			case 2:
				cout << "Mostrar arbol" << endl;
				mostrarArbol(arbol, contador);
				break;
			case 3:
				preOrden(arbol);
				break;
			case 4:
				inOrden(arbol);
				break;
			case 5:
				posOrden(arbol);
				break;
			
		}
	}while(opcion != 6);
}

Nodo *crearNodo(int n){
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo->dato = n;
	nuevo_nodo->izq = NULL;
	nuevo_nodo->der = NULL;

	return nuevo_nodo;

}

void insertarNodo(Nodo *&arbol, int n){
	if(arbol == NULL){
		Nodo *nuevo_nodo = crearNodo(n);
		arbol = nuevo_nodo;
	}
	else{
		int valorRaiz = arbol->dato;
		if(n <= valorRaiz){
			insertarNodo(arbol->izq, n);
		}
		else{
			insertarNodo(arbol->der, n);
		}
	}
}

void mostrarArbol(Nodo *arbol, int cont){
	if(arbol == NULL){
		return;
	}
	else {
		mostrarArbol(arbol->der, cont+1);
		for(int i = 0;i < cont;i++){
			cout << "   ";
		}
		cout << arbol->dato << endl;
		mostrarArbol(arbol->izq, cont+1);
	}
}

void imprimir(Nodo *nodo){
	if(nodo != NULL){
		cout << nodo->dato;
	}
}

void preOrden(Nodo *raiz){
	if(raiz != NULL){
		imprimir(raiz);
		preOrden(raiz->izq);
		preOrden(raiz->der);
	}
}

void inOrden(Nodo *raiz){
	if(raiz != NULL){
		inOrden(raiz->izq);
		imprimir(raiz);
		inOrden(raiz->der);
	}
}

void posOrden(Nodo *raiz){
	if(raiz != NULL){
		posOrden(raiz->izq);
		posOrden(raiz->der);
		imprimir(raiz);
	}
}
