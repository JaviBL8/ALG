#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std ;

int Max (int n, int M) ;

int main () {
  int M ;
  int n ;

  cout << "Introduce M = " ;
  cin >> M ;
  cout << "Introduce n = " ;
  cin >> n ;

  cout << "Multiplicación mayor es: " << Max (n, M) << endl ;

}

int Max (int n, int M) {
  //Nada más que siguiendo la declaración recurrente que aparecía junto al problema.
 
  // Si el numero a encontrar es 0, y la serie de numeros empleados es mayor o igual que 0
  //Como M es 0, no existe ninguna suma de numeros naturales que sumen 0, por lo tanto la función tendrá que devolver 0
  if (M == 0 && n >= 0) return 0 ;
  //Si nada más que se puede emplear un número natural para obtener el número M, la función obligatoriamente deberá devolver
  //como resultado el número M
  // Suma de un natural igual a M.
  if (n == 1 && M > 0) return M ;


  if (n > 1 && M > 0) {
    int max = 0 ;
    for (int x = 1 ; x <= M ; x++) {
      // Llamada recursiva para todas las posibles combinaciones de números naturales que existan hasta llegar a M
      int auxiliar = x * Max (n - 1, M - x) ;
      // Máximo con el nuevo elemento.
      if (max < auxiliar)  max= auxiliar ;
    }
    return max ;
  }
}
