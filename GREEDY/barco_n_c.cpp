/* 
Se tiene un buque mercante cuya capacidad de carga es de K toneladas y un conjunto de
contenedores c1 , . . . , cn cuyos pesos respectivos son p1 , . . . , pn (expresados también en
toneladas).
Teniendo en cuenta que la capacidad del buque es menor que la suma total de los pesos
de los contenedores:
Diseñamos un algoritmo que maximice el número de contenedores cargados. Demostrar su optimalidad.
*/

//COMPILACION: g++ numerodetoneladascargados.cpp -o num -std=gnu++0x

#include <iostream>
#include <vector>
#include <set>
#include <cstdlib>
#include <chrono>
using namespace std;

//Entrada: vector de contenedores y la capacidad maxima del barco.
//Devuelve un vector con los contenedores del barco.
vector<int> llenaBarcoContenedores(multiset<int, less<int> > c ,int peso_max, int &peso_actual) {
    vector<int> s;
    int peso_contenedor;
    int num_contenedor;
    peso_actual = 0;
    bool lleno = false;

    while( !c.empty() && !lleno ) {         
        peso_contenedor = *(c.begin());//Seleccionamos el contenedor más ligero.

        if((peso_actual + peso_contenedor) <= peso_max) { //Funcion de factibilidad
            s.push_back(peso_contenedor);       //Introducimos el contenedor 
            peso_actual += peso_contenedor;     //en el barco.

            c.erase(c.begin());  //Eliminamos el contenedor de la lista.
        }
        else
            lleno = true;
    }
    return s;
}

//Genera un vector de tamaños aleatorios entre 1 y 100;
multiset<int, less<int> > genera(int n) {
    multiset<int, less<int> > c;
    srand(time(0));

    for(int i=0; i < n; i++) 
        c.insert( (rand()%100)+1 );

    return c;
}




int main(int argc, char *argv[]) {
    if(argc != 2) {
        cerr << "Formato " << argv[0] << " <numero contenedores>" << "\n";
        return -1;
    }

    std::chrono::high_resolution_clock::time_point tantes, tdespues;
    std::chrono::duration<double> transcurrido;

    int n = atoi(argv[1]);
    int peso_actual = 0;
    int peso_max = 30*n;   //Tamaño de los contenedores en funcion del nuemero de contenedores

    multiset<int, less<int> > contenedores;
    contenedores = genera(n);
    vector <int> barco;

    tantes = std::chrono::high_resolution_clock::now();     //Tiempo antes de la operación
    barco = llenaBarcoContenedores(contenedores,peso_max, peso_actual);
    tdespues = std::chrono::high_resolution_clock::now();   //Tiempo después de la operación
    transcurrido = std::chrono::duration_cast<std::chrono::duration<double>>(tdespues - tantes);

    cout << "Tiempo: " << transcurrido.count() << endl;
    cout << "\nPara " << n << " contenedores y una carga maxima de " << peso_max << endl;
    cout << "en el barco sobran " << peso_max - peso_actual << " unidades de peso." << endl;
    cout << "Contenedores cargados: " << barco.size() << endl;

    cout << "\nCarga del barco: " << endl;
    for(int i=0; i < barco.size(); i++)
    	cout << "[" << i+1 << "]" << barco[i] << "\t";
    cout << endl;

    cout << "\nContenedores a cargar: " << endl;
    for(auto it = contenedores.begin(); it != contenedores.end(); it++)
        cout << *it << " - ";
    cout << endl;
}
