#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <sys/time.h>

using namespace std;

int FuerzaBruta(int *v, int size){
    bool es = false;
    int pos;
    for(int i=0; i< size-1 && !es; i++){
        if(v[i]>v[i+1]){
            pos = i;
            es = true;
        }
    }
    if(es == false)  //Este es el caso en que p se encuentra en la ultima posicion. Si se encontrara en la primera,
        pos = size-1;    // se devolveria en el bucle.
    return pos;
}

int Divideyvenceras(int *v, int principio, int fin){
    bool es = false;
    int medio = (fin+principio)/2;
    if (medio > principio){
        if(v[medio-1] < v[medio] && v[medio] < v[medio+1])
           return Divideyvenceras(v, medio, fin);
        else if(v[medio-1] > v[medio] && v[medio] > v[medio+1])
           return Divideyvenceras(v, principio, medio);    
        else if(v[medio-1]<v[medio] && v[medio] > v[medio-1])
            return medio;
    }
    else{
        if(v[principio] <= v[fin]){
        	return fin;
        }
        else
        	return principio;
    }
}

int main(int argc, char * argv[])
{

  if (argc != 2)
    {
      cerr << "Formato " << argv[0] << " <num_elem>" << endl;
      return -1;
    }

  int n = atoi(argv[1]);

  int * T = new int[n];

srand(time(0));
double u;
u = (double) rand();
u = u/(double)(RAND_MAX+1.0);
int p=1+(int)((n-2)*u);
T[p]=n-1;
for (int i=0; i<p; i++) T[i]=i;
for (int i=p+1; i<n; i++) T[i]=n-1-i+p;

double tv_usecs=0;
// Variables de tiempo
struct timeval tv1, tv2;
//Ejecucion del algoritmo.
gettimeofday(&tv1,NULL);
//int results = FuerzaBruta(T,n);
int results = Divideyvenceras(T,0,n);
gettimeofday(&tv2,NULL);
tv_usecs= ((tv2.tv_sec -tv1.tv_sec )*1E6 + (tv2.tv_usec-tv1.tv_usec)) / 1000000.0;
        cout <<n<<"\t"<< tv_usecs << endl;
}