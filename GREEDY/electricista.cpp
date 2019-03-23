#include<iostream>
#include<stdlib.h>
#include<vector>
#include <algorithm>
using namespace std;

//Funcion para n electricistas
void varioselectricistas(vector<vector<int> > trabajo,vector<int> clientes, int nelectricistas){
int contador = 0;

trabajo.reserve(nelectricistas);
sort(clientes.begin(), clientes.end());

//A cada vector del vector de vectores se le va añadiendo tareas segun los electricistas que se metan
for(int i = 0; i < clientes.size(); i++){
	if(contador < nelectricistas){
		trabajo[contador].push_back(clientes[i]);
		contador++;
	}
	else{
		contador = 0;
		i--;
	}
}

}

int main(){
int nclientes = 10;
vector<int> clientes;
int suma = 0;
int consumido = 0;
vector<vector<int> > trabajo;
int nelectricistas = 3;

clientes.push_back(1);
clientes.push_back(4);
clientes.push_back(2);
clientes.push_back(3);
clientes.push_back(4);
clientes.push_back(9);
clientes.push_back(1);
clientes.push_back(7);
clientes.push_back(10);
clientes.push_back(9);

sort(clientes.begin(),clientes.end());
//Mostrar el vector:
cout << "Lista de tiempos asignados a los clientes: " << endl;
for (int i = 0; i < clientes.size(); i++){
	suma += clientes[i];
	cout << clientes[i] << endl;
}
cout << "\nTiempo total para atender clientes: " << suma << " min" << endl;

//Atender a clientes
for(int i = 0; i < clientes.size(); i++){
int restante = 0;
	consumido+=clientes[i];
	restante = suma - consumido;
	cout << "Cliente n" << i << ": electricista ha consumido " << consumido << " min, para terminar le quedan" << restante << " min" << endl; 
}

}
