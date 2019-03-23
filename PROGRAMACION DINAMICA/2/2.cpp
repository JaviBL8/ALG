#include<iostream>
#include <vector>
using namespace std;

vector<vector<int> > Maxima_anchura();

int main(){
//llamamos a la funcion Maxima_anchura la cual
//tiene dentro la matriz de anchuras entre islas
//y la salida que nos da este problema es la matriz con
//la maxima anchura entre unas islas y otras
//El resultado lo guardamos en la matriz M:
vector<vector<int> > M = Maxima_anchura();
//Mostramos por pantalla por ejemplo el camino más optimo entre
//0 y 3
cout << M[0][3] << endl;
}
//funcion
vector<vector<int> > Maxima_anchura(){
int aux=0;
//Creación de la matriz anchura A
	vector<vector<int> > A;
	
	A.reserve(4);

	for(int i= 0; i < 4; i++)
	A[i].reserve(4);

	A[0].push_back(-1);
	A[0].push_back(2);
	A[0].push_back(0);
	A[0].push_back(3);
	A[1].push_back(2);
	A[1].push_back(-1);
	A[1].push_back(1);
	A[1].push_back(4);
	A[2].push_back(0);
	A[2].push_back(1);
	A[2].push_back(-1);
	A[2].push_back(2);
	A[3].push_back(3);
	A[3].push_back(4);
	A[3].push_back(2);
	A[3].push_back(-1);

//Creación de la matriz M
	vector<vector<int> > M;

	M.reserve(4);

	for(int i=0;i<4;i++)
	M[i].reserve(4);

	M[0].push_back(-1);
	M[0].push_back(2);
	M[0].push_back(0);
	M[0].push_back(3);
	M[1].push_back(2);
	M[1].push_back(-1);
	M[1].push_back(1);
	M[1].push_back(4);
	M[2].push_back(0);
	M[2].push_back(1);
	M[2].push_back(-1);
	M[2].push_back(2);
	M[3].push_back(3);
	M[3].push_back(4);
	M[3].push_back(2);
	M[3].push_back(-1);

	for(int k=0; k<4; k++)
	{
		for(int i=0; i<4; i++)
		{
			for(int j=0;j<4; j++)
			{
				if(M[i][k] < M[k][j])
				{
					aux=M[i][k];
				}
				
				else
					aux=M[k][j];

				if( (M[i][j] < aux) && (i!=j) )
					M[i][j]=aux;
			}
		}
	}


	return M;

}

