#include "stdafx.h" 
#include <iostream> 
#include <fstream> 
#include <iomanip>
#include <cstdlib> 
#include <string> 
#include <stdlib.h> 
#include <time.h> 
#include "Nodos.h" 

using namespace std;
 
// D e c l a r a c i o n   d e   P u n t e r o s  
 #pragma region Punteros
Nodos *I,*T,*F,*A,*temp;
 #pragma endregion 
 // D e c l a r a c i o n   d e   v a r i a b l e s 
 #pragma region Variables 
 int id;
 string nombre; 
 clock_t t_Ini, t_Fin; 
 double sec;
 int pos;
#pragma endregion
 // D e l a r a c i o n   d e   M e t o d o s 
#pragma region Metodos
void leerArchivo(string a); 
void Agregar();
void Recorrer();
void eliminarUltimo();
#pragma endregion
 
int main()
 { 
	t_Ini = clock();
 	leerArchivo("ejemplo240MIL.txt"); 
 	t_Fin = clock(); 
	eliminarUltimo();
	//Recorrer();
	sec = (double)(t_Fin - t_Ini) / CLOCKS_PER_SEC;
	cout<< (sec * 1000)<<"\t Milisegundos"<<endl;
	cout << pos << " Registros" << endl;
	system("pause");
    return 0;
 } 
 
 #pragma region Metodos
void Agregar()
 {  
	temp = I;
 	T = new Nodos();
	T->id =id;
  	T->nombre = nombre;
 	T->sig =  NULL;
 	if (I == NULL)  
 	{ 
  		I = T;
 		F = T; 
    } 
 	else   
  	 { 
		A = F;
		F->sig = T;
		F = T;
	} 
 }
void eliminarUltimo()
{
	T = A;
	T->sig = NULL;
	F = T;
}
void Recorrer() {
 	T = I; 
 	while (T != NULL) {
 	 	//cout << T->id<<endl;
 	 	//cout << T->nombre<<endl;
		pos++;
 	 	T = T->sig;
 	 } 
 } 
void leerArchivo(string a)  
{ 
	fstream leer( a, ios::in); 
 	if (!leer) 
	{
 		cout << "Error"; 
 	} 
 	string nombres,ids; 
 	while (!leer.eof()) 
	{
 		getline(leer, ids);
 		getline(leer, nombres);
 		id = atoi(ids.c_str());
		nombre = nombres; 
		Agregar(); 
	}
	leer.close();
} 
#pragma endregion