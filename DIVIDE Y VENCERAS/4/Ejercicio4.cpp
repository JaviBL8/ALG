#include <iostream>
#include <stdlib.h>
#include <sys/time.h>
#include <vector>
#include <fstream>
#include <algorithm>
#include <list>

using namespace std;



std::vector<int> MezclaVectoresOrdenados(std::vector<int> a,std::vector<int> b){
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
			a_devolver.push_back(a[indice_a]);
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

//El número de vectores debe de ser potencia de 2

vector< vector<int> > MezclaVectores( vector < vector<int> > v )
{
	vector< vector<int> > a_devolver;
	vector < vector<int> > aux;
	int j=0;

	if(v.size()==1)
		return v;
	
	for( int i=v.size();i>1;i/=2)
	{	
		a_devolver.push_back(MezclaVectoresOrdenados(v[j],v[j+1]));
		j=j+2;
	}  
	
	v=MezclaVectores(a_devolver); 

	return v;	
}

std::vector<int> FuerzaBruta( vector < vector<int> > v )
{
	std::vector<int> aux=v[0];
	for(int i=1; i<v.size();i++)
	{
		aux=MezclaVectoresOrdenados(aux,v[i]);
	
	}

	return aux;

}

int main(int argc, char *argv[])
{

	if(argc < 3){
		cout << "Introduce el tamaño del vector y el número de vectores que desea que debe ser potencia de 2" << endl;
		return 0;
	}

	struct timeval tv1, tv2;
	double tv_usecs;

	int tamanio = atoi(argv[1]);
	int n_vectores = atoi(argv[2]);
	vector<int> v; 
	vector< vector< int > > vector_de_vectores;
	
	srand(time(0));
	for(int i = 0; i < n_vectores; i++)
	{
		for(int j=0;j< tamanio;j++)
		{
			v.push_back(rand()%(tamanio/2));
		}

		sort(v.begin(),v.end());
		vector_de_vectores.push_back(v);
		v.clear();
	}

	
	gettimeofday(&tv1,NULL);
	FuerzaBruta(vector_de_vectores);             
	gettimeofday(&tv2,NULL);
	tv_usecs= ((tv2.tv_sec -tv1.tv_sec )*1E6 + (tv2.tv_usec-tv1.tv_usec)) / 1000000.0;
	cout << tamanio << "\t" << tv_usecs << endl;

/*	
	gettimeofday(&tv1,NULL);
	MezclaVectores(vector_de_vectores);     
	gettimeofday(&tv2,NULL);
	tv_usecs= ((tv2.tv_sec -tv1.tv_sec )*1E6 + (tv2.tv_usec-tv1.tv_usec)) / 1000000.0;
	cout << tamanio << "\t" << tv_usecs << endl; 

*/


}
