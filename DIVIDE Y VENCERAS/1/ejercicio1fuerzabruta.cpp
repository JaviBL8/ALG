#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <sys/time.h>
#include <vector>

using namespace std;

//Algoritmo de fuerza bruta
int fuerzabruta(vector<int> v){
int n_inversiones = 0;

	for (int i = 0; i < v.size(); i++){
		for(int j = i+1; j < v.size(); j++){
			if(v[i]>v[j])
			n_inversiones++;	
		}
	}
return n_inversiones;
}

//***********************************************//
//Algoritmo DyV(mezcla)
int mergeAndCount(int *v, int begin, int middle, int end){
    int *sorted = new int[(unsigned)(end - begin)];

    int invs = 0, j = middle, i = begin, k = 0;
    
    while(i < middle){
        if(j < end){
            
            if(v[i] <= v[j]){
                sorted[k] = v[i];
                k++; i++;
            }
            
            else{
                sorted[k] = v[j];
                k++;j++;
                invs += (middle -i);
            }
        }
        else{
            sorted[k] = v[i];
            k++; i++;
        }
    }

    while(j < end){
        sorted[k] = v[j];
        k++; j++;
    }

    for(int r = 0; r < end - begin; r++){
        v[r+begin] = sorted[r];
    }
    
    delete [] sorted;

    return invs;
}

int sortAndCount(int *v, int begin, int end){
    int middle = (begin + end) / 2;
    int invs = 0;

    if(middle - begin > 1)
        invs += sortAndCount(v,begin,middle);

    if(end - middle > 1)
        invs += sortAndCount(v,middle,end);

    if(begin < middle && middle < end)
        invs += mergeAndCount(v,begin,middle,end);

    return invs;
}
//**********************************************************//
int main(int argc, char *argv[]){
struct timeval tv1, tv2 , tv3 , tv4;
	double tv_usecs , tv_usecs2;

if(argc < 2){
cout << "Introduce el tamaño del vector" << endl;
}
else{
int tamanio = atoi(argv[1]);
vector<int> v2;

//Rellenar vector de numeros aleatorios
srand(time(0));
int i = 0;

while(i < tamanio){
bool repetido = false;
int aleatorio = rand()%(tamanio+1);
	if(i == 0 && aleatorio != 0){
		v2.push_back(aleatorio);
		i++;
	}
	else{
		for(int j = 0; j < v2.size(); j++){
			if(v2[j] == aleatorio)
			repetido = true;
		}
		if(!repetido && aleatorio != 0){
			v2.push_back(aleatorio);
			i++;
		}
	}
}

/*
cout << "Vector generado: " << endl;
for(int j = 0; j < v2.size(); j++){
	cout << v2[j] << " ";
}

cout << " " << endl;
*/
//cout << "Algoritmo fuerza bruta: " << endl;

    gettimeofday(&tv3,NULL);
	
	cout << tamanio << "\t";
    fuerzabruta(v2)/* << endl*/;

    gettimeofday(&tv4,NULL);
    tv_usecs2= ((tv4.tv_sec -tv3.tv_sec )*1E6 + (tv4.tv_usec-tv3.tv_usec)) / 1000000.0;
    cout << tv_usecs2 << endl;


//cout << "Algoritmo mezcla (Divide y venceras)" << endl;
	//gettimeofday(&tv1,NULL);

	//cout << tamanio << "\t";
	//sortAndCount(&v2[0],0,v2.size())/*<< endl*/;


	//gettimeofday(&tv2,NULL);

	//tv_usecs= ((tv2.tv_sec -tv1.tv_sec )*1E6 + (tv2.tv_usec-tv1.tv_usec)) / 1000000.0;
        //cout << tv_usecs << endl;


}

}

