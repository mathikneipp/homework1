#include <iostream>
#include <vector>
using namespace std;

/*
 * Recorre la matriz en orden desde la primera posicion hasta la ultima, y la va llenando con numeros desde 1 a n^2 en orden.
 */
void fill_matrix(vector<vector<int>>& matrix, const int n);

/*
 * Imprime la posicion opuesta de la que pasan, asi imprimo la matriz desde el ultimo lugar hasta la primera.
 */
void print_matrix(vector<vector<int>>& matrix, const int n);

/*
 * Crea una matriz y llama a la funcion fill_matrix, para luego devolver la matriz.
 */
vector<vector<int>> create_matrix(int n);
