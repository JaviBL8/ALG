#include <iostream>
#include <vector>

using namespace std ;

int Max (int n, int M) ;

int main () {
  int M ;
  int n ;

  cout << "Introduce M = " ;
  cin >> M ;
  cout << "Introduce n = " ;
  cin >> n ;

  cout << "Multiplicación máxima alcanzada: " << Max (n, M) << endl ;

 
}

int Max (int n, int M) {
  vector<vector<int> > T ;

  // Creación de la matriz de T(n+1 * M+1).
  T.reserve(n+1) ;
  for (int k = 0 ; k <= n ; k++) T[k].reserve(M+1) ; // O(n)

  // Suma de n naturales que sea igual a 0.
  for (int k = 0 ; k <= n ; k++) T[k][0] = 0 ; // O(n)

  // Suma de 1 natural que sea igual a M.
  for (int c = 1 ; c <= M ; c++) T[1][c] = c ; // O(M)


  for (int k = 2 ; k <= n ; k++) { // O(n*M*M)
    for (int c = 1 ; c <= M ; c++) {
      T[k][c] = 0 ;
      for (int x = 1 ; x <= c ; x++) {
        T[k][c] = max (T[k][c], x * T[k-1][c-x]) ;
      }
    }
  }

  return (T[n][M]) ;
}