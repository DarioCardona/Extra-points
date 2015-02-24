#include <ctime>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include <cstdio>

using namespace std;

int main(int argc, char* argv[]){

	srand(time(0));

	int numa, numb;
	cout << "Numero de palabras para la columna A: ";
	cin  >> numa;
	cout << "Numero de Respuestas correctas  ";
	cin  >> numb;

	char** palabras = new char*[numa];
	char** respuestas= new char*[numb];
	char cadena[80];
	

	for (int i=0; i<numa; i++){
		cout << "Ingrese Palabra " << i+1 << ": ";
		cin  >> cadena;
		palabras[i] = new char[strlen(cadena)+1];
		strcpy(palabras[i], cadena);//creacion de las palabras
	}

	for (int i=0; i<numb; i++){
		cout << "Ingrese las respuestas  " << i+1 << ": ";
		cin  >> cadena;
		respuestas[i] = new char[strlen(cadena)+1];
		strcpy(respuestas[i], cadena);// creacion de las respuestas // creacion de las respuestas
	}

	cout << setw(10) << "Palabras"<<endl; // impresion de las palabras
	for (int i=0; i<numa; i++)
		cout << setw(10) << "["<<palabras[i]<<"]"<<" posicion "<<i<< endl;
	
	cout << setw(10) << "Respuestas"<<endl; // impresion de las respuestas
	for (int i=0; i<numb; i++)
		cout << setw(10) << "["<<respuestas[i]<<"]"<<" posicion "<<i<< endl;
	int num;
	if (numb>numa)
	{
		num=numa;
	}else{
		num=numb;
	}
	int matri [num][2];
	
	for (int f= 0; f < numb; f++) // creacion de matriz de respuestas de numeros
	{
		for (int c = 0; c < 2; ++c)
		{
			if (c==0)
			{
				cout<<"Ingrese numero posicion de la palabras "<<f+1<<endl;
				cin>>matri[f][c];
			}else{
				cout<<"Ingrese numero posicion de la respuestas "<<f+1<<endl;
				cin>>matri[f][c];
			}
			
			
		}
	}


	for (int f= 0; f < numb; f++)// impresion de respuestas de numeros
	{
		for (int c = 0; c < 2; ++c)
		{
			cout<<"["<<matri[f][c]<<"]";
		}
		cout<<endl;
	}

	char** palabras2 = new char*[numa];
	char** respuestas2= new char*[numb];

	for (int i=0; i<numa; i++){
		
		palabras2[i] = new char[strlen(palabras[i])+1];
		strcpy(palabras2[i], palabras[i]); // crea el 2do arreglo de palabras
	}


	for (int i=0; i<numb; i++){
		
		respuestas2[i] = new char[strlen(respuestas[i])+1];
		strcpy(respuestas2[i], respuestas[i]);// creacion 2do arreglo de las respuestas
	}
	 
	 char* cadena2;
	 char* cadena3;
	 int x;
	
	for (int i=0; i<numa; i++){ // desordenar la matriz palabras
		
		x=rand()%numa+0;
		cadena3=palabras2[i];
		cadena2= palabras2[x];
		palabras2[i] = new char[strlen(cadena2)+1];
		strcpy(palabras2[i], cadena2);
		palabras2[x] = new char[strlen(cadena3)+1];
		strcpy(palabras2[x], cadena3);
		
	}

	 int y;
	
	for (int i=0; i<numb; i++){ // desordenar la matriz respuestas
		
		y=rand()%numa+0;
		cadena3=respuestas2[i];
		cadena2= respuestas2[y];
		respuestas2[i] = new char[strlen(cadena2)+1];
		strcpy(respuestas2[i], cadena2);
		respuestas2[y] = new char[strlen(cadena3)+1];
		strcpy(respuestas2[y], cadena3);
		
	}



	cout << setw(10) << "Palabras2"<<endl;  // impresion del 2do arreglo de palabra desordenada
	for (int i=0; i<numa; i++)
		cout << setw(10) << "["<<palabras2[i]<<"]"<<" posicion "<<i<< endl;

	cout << setw(10) << "Respuestas"<<endl; // impresion del 2d0 arreglo de respuestas desordenado
	for (int i=0; i<numb; i++)
		cout << setw(10) << "["<<respuestas2[i]<<"]"<<" posicion "<<i<< endl;

	/*int matri2 [num][2];

	for (int f= 0; f < numb; f++) // creacion de la  matriz2 de respuestas de numeros
	{
		for (int c = 0; c < 2; ++c)
		{
			if (c==0)
			{
				cout<<"Ingrese numero posicion de la palabras "<<f+1<<endl;
				cin>>matri2[f][c];
			}else{
				cout<<"Ingrese numero posicion de la respuestas "<<f+1<<endl;
				cin>>matri2[f][c];
			}
			
			
		}
	}
	*/
	char resp='S';
	int cont=0;

	while (resp=='S'){
		int ans1,ans2;
		cout<<"Ingrese posicion para la respuesta de la columna A (Palabra)"<<endl;
		cin>>ans1;
		
		cout<<"Ingrese posicion para la respuesta  de la columna B (Respuestas)"<<endl;
		cin>>ans2;
		for (int f= 0; f < num; ++f)
		{
			
				if (strcmp(palabras2[ans1],palabras[matri[f][0]])==0 && strcmp(respuestas2[ans2],respuestas[matri[f][1]])==0) 
				{
					cont++;
				}
		}
		cout<<"Desea seguir ingresando respuestas: "<<endl;
		cin>>resp;
		resp=toupper(resp);
	}

	int porcen=(cont*100)/num;

	cout<<"Su porcentaje de haciertos es de: "<<porcen<<" %"<<endl;
	
	// liberar la memoria
	for (int i=0; i<numa; i++)
		delete[] palabras[i];
	delete[] palabras;

	for (int i=0; i<numb; i++)
		delete[] respuestas[i];
	delete[] respuestas;

	for (int i=0; i<numa; i++)
		delete[] palabras2[i];
	delete[] palabras2;

	for (int i=0; i<numb; i++)
		delete[] respuestas2[i];
	delete[] respuestas2;
	
	return 0;
}