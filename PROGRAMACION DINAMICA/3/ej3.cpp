//Compilar con: g++ ej3.cpp -o ej3 -std=gnu++0x

#include <iostream>
#include <vector>
#include <set>
#include <cstdlib>
using namespace std;

set<int> hayReparto(const vector<int> &p){  //El vector viene inicializado con una componente mas, la 0 q no usaremos
	int D = 0;
	int n = p.size() - 1;
	set<int> C;
	bool S[500][500];
	bool marca[500][500];
	for(int i = 1; i <= n; i++)
		D = D + p[i];


	for(int k = 0; k <= n; k++)
		S[0][k] = true;

	for(int m = 1; m <= D/2; m++)
		S[m][0] = false;

	for(int k = 1; k <= n; k++){
		for(int m = 1; m <= D/2; m++){
			if(m < p[k]){
				S[m][k] = S[m][k-1];
				marca[m][k] = false;
			}
			else if( S[m-p[k]][k-1] ){
				S[m][k] = S[m-p[k]][k-1];
				marca[m][k] = true;
			}
			else{
				S[m][k] = S[m][k-1];
				marca[m][k] = false;
			}

			cout << "S[" << m << "][" << k << "(" << p[k] << ")] = " << S[m][k] << "/" << marca[m][k] << endl;
		}
		cout << endl;
	}

	if( S[D/2][n] ){
		int i = D/2;
		int j = n;

		while (j > 0){
			if( marca[i][j] ){
				C.insert(j);
				i = i - p[j];	
			}

			j = j - 1;
		}
	}

	return C;
}



int main(){

	set<int> C;
	vector<int> p;

	p.push_back(0); //0

	p.push_back(2); //1
	p.push_back(2); //2
	p.push_back(1); //3
	p.push_back(5); //4
	p.push_back(2); //5

	C = hayReparto(p);

	for(auto it = C.begin(); it != C.end(); it++)
		cout << *it << endl;

}