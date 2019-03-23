#include <iostream>
#include <stdlib.h>
#include <sys/time.h>
#include <vector>
#include <fstream>
#include <algorithm>
#include <ctime>

using namespace std;

std::vector<int> mezcla_y_elimina(std::vector<int> a,std::vector<int> b){
	std::vector<int> a_devolver;
	int final_A=a.size();
	int final_B=b.size();
	int indice_a=0;
	int indice_b=0;

	while(indice_a<final_A && indice_b<final_B){
		if(a[indice_a] < b[indice_b]){
			a_devolver.push_back(a[indice_a]);
			indice_a++;
		}
		else if(a[indice_a] > b[indice_b]){
			a_devolver.push_back(b[indice_b]);
			indice_b++;
		}
		else if( a[indice_a] == b[indice_b] ){
			a_devolver.push_back(b[indice_b]);
			indice_a++;
			indice_b++;
		}
	}

	if(indice_a==final_A){
		while(indice_b<final_B){	
			a_devolver.push_back(b[indice_b]);
			indice_b++;
		}

	}

	if(indice_b==final_B){
		while(indice_a<final_A){	
			a_devolver.push_back(a[indice_a]);
			indice_a++;
		}
	}
	return a_devolver;
}

vector<int> EliminarDuplicados( vector<int> v )
{
	int mitad = v.size() / 2;
	std::vector<int> a;
	std::vector<int> b;
	std::vector<int> a_devolver;
	
	if(v.size()==1)
		return v;

	for(int i=0;i<mitad;i++)
   	{
   		a.push_back(v[i]);	
   	}


   	for(int j=mitad;j<v.size();j++)
   	{
   		b.push_back(v[j]);	
   	}
   	
	a=EliminarDuplicados(a);
	b=EliminarDuplicados(b);
	v=mezcla_y_elimina(a,b);

    return v;
}

vector<int> FuerzaBruta(std::vector<int> v)
{
	std::vector<int> x;
		
	sort(v.begin(),v.end());

	x.push_back(v[0]);
	int k=0;
	 for(int i=1;i<v.size();i++)
	 {
	 	if(v[i] != x[k])
	 	{
	 		k++;
	 		x.push_back(v[i]);
	 	}
	 }

	 return x;
}

int main(int argc, char *argv[])
{
	if(argc < 2){
		cout << "Introduce el tamaño de la entrada." << endl;
		return 0;
	}

	struct timeval tv1, tv2;
	double tv_usecs;

	int tamanio = atoi(argv[1]);
	vector<int> v; 
	
	srand(time(0));
	for(int i = 0; i < tamanio; i++){
		v.push_back(rand()%(tamanio/2));
	}
	/*
	gettimeofday(&tv1,NULL);
	FuerzaBruta(v);             
	gettimeofday(&tv2,NULL);
	tv_usecs= ((tv2.tv_sec -tv1.tv_sec )*1E6 + (tv2.tv_usec-tv1.tv_usec)) / 1000000.0;
	cout << tamanio << "\t" << tv_usecs << endl;
*/
	gettimeofday(&tv1,NULL);
	EliminarDuplicados(v);     
	gettimeofday(&tv2,NULL);
	tv_usecs= ((tv2.tv_sec -tv1.tv_sec )*1E6 + (tv2.tv_usec-tv1.tv_usec)) / 1000000.0;
	cout << tamanio << "\t" << tv_usecs << endl;
}
