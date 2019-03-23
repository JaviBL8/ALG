#include <iostream>
#include <ctime>
#include <sys/time.h>
#include <stdlib.h>
#include <vector>

using namespace std;

int fuerza_bruta(vector<int> &v,int TAM){
	for (int i = 1; i < TAM; ++i)
	{
		if(v[i]==i){
			return i;
		}
	}
	
	return 0;
}
int localizaV2(vector<int> &v, int primero, int ultimo){
  
  if (primero == ultimo)
  {
  	if (v[primero]==primero)
  	{
  		return primero;
  	}
  	else 
  		return 0;
  }
  else{
  	int i=(primero+ultimo)/2;
  	if (v[i]==i)
  	{
  		return i;
  	}
  	else
  	{
  		if(ultimo == primero +1){
  			return localizaV2(v,ultimo,ultimo);
  		}
  		else{
	  		int res = localizaV2(v,primero,i-1);
	  		if(res != 0){
	  			return res;
	  		}
	  		else{	
	  			return localizaV2(v,i+1,ultimo);
	  		}
	  	}
  	}
  }
}

int localiza(vector<int> &v, int primero, int ultimo){ 
  
  if (primero==ultimo)
  {
  	if (v[primero]==primero)
  	{
  		return primero;
  	}
  	else 
  		return 0;
  }
  else{
  	int i=(primero+ultimo)/2;
  	if (v[i]==i)
  	{
  		return i;
  	}
  	else if (v[i]>i)
  	{
  		return localiza(v,primero,i-1);
  	}
  	else
  	{
  		return localiza(v,i+1,ultimo);	
  	}
  }
}

int main(int argc, char *argv[])
{
	if(argc < 2){
		cout << "Introduce el tamaño del vector." << endl;
		return 0;
	}
	
	struct timeval tv1, tv2;
	double tv_usecs;
	
	
	int tamanio = atoi(argv[1]);
	vector<int> v; 
		
	for(int i = 0; i < tamanio*0.752; i++)
		v.push_back(i-1);
		
	v.push_back(tamanio*0.752);
	
	for(int i = (tamanio*0.752)+1; i < tamanio; i++)
		v.push_back(i+1);
	
	
	gettimeofday(&tv1,NULL);
	fuerza_bruta(v,v.size());     //FUERZA BRUTA
	gettimeofday(&tv2,NULL);
	tv_usecs= ((tv2.tv_sec -tv1.tv_sec )*1E6 + (tv2.tv_usec-tv1.tv_usec)) / 1000000.0;
        cout << tamanio << "\t" << tv_usecs << endl;
	
	/*
	gettimeofday(&tv1,NULL);
	localiza(v,1,v.size()-1);  //SIN REPETIDOS
	gettimeofday(&tv2,NULL);
	tv_usecs= ((tv2.tv_sec -tv1.tv_sec )*1E6 + (tv2.tv_usec-tv1.tv_usec)) / 1000000.0;
        cout << tamanio << "\t" << tv_usecs << endl;
	*//*
	gettimeofday(&tv1,NULL);
	localizaV2(v,1,v.size()-1); //CON REPETIDOS
	gettimeofday(&tv2,NULL);
	tv_usecs= ((tv2.tv_sec -tv1.tv_sec )*1E6 + (tv2.tv_usec-tv1.tv_usec)) / 1000000.0;
        cout << tamanio << "\t" << tv_usecs << endl;
    */
}
