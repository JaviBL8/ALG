#include <iostream>
#include <set>
#include <stdlib.h>

using namespace std;

set<int> NumeroDiasAperturaAleatorio(int dias_a_abrir)
{
	set<int> dias_apertura;
	int numero_aleatorio;
	set<int>::iterator it;

	while(dias_apertura.size() < dias_a_abrir)
	{	
		numero_aleatorio=1+rand()%(32-1); //aleatorio entre 1 y 31
		dias_apertura.insert(numero_aleatorio);
	}

	return dias_apertura;
	
}

int ConsumoMaximo()
{
	return 1+rand()%(14-1);
	
}

void DiasAacudir(set<int> dias_apertura,int duracion)
{
	set<int> resultado;
	int d=duracion;

	set<int>::iterator it=dias_apertura.begin();
	set<int>::iterator a=dias_apertura.begin();
	a++;


	for(int i=1;i<=31 && it!=dias_apertura.end();i++)
	{
		if(duracion < *it)
		{
			cout << "NO SOLUCION" << endl;
			i=32;
		}

		else if( (duracion>=*it) && ( duracion < *a ) )
		{
			cout << "El granjero va a la tienda el día " << *it << endl;
			duracion=*it+d;
			
		}

		else if(i==31)
		{
			if(duracion==31)
				cout << "El granjero va a la tienda el último día del mes" << endl;
		}
		a++;
		it++;
		
	}

	
	return resultado;
}

int main(int argc, char *argv[])
{

	if(argc < 1){
		cout << "Introduce el numero de días que quiere que abra la tienda" << endl;
		return 0;
	}

	int tamanio = atoi(argv[1]);
	int r=ConsumoMaximo();
	set<int> prueba=NumeroDiasAperturaAleatorio(tamanio);

	set<int> resultado;
	set<int>::iterator it;

	DiasAacudir(prueba,r);




}