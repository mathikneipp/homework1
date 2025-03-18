#include <iostream>
#include <vector>
using namespace std;

void fill_matrix(vector<vector<int>>& matrix, int row, int col, const int n) {
    matrix[row][col] = (row * n) + col + 1; // para las posiciones de la matriz, les asigna un numero que van en orden del 1 al n
}

void print_inverted_pos(vector<vector<int>>& matrix, int row, int col, const int n) {
    /*
     * Imprime la posicion opuesta de la que pasan, asi imprimo la matriz desde el ultimo lugar hasta la primera.
     */
    int inverted_row = (n-1) - row;
    int inverted_col = (n-1) - col;
    std::cout << 'M' << n << '[' <<  inverted_row << "][" << inverted_col << "] = " << matrix[inverted_row][inverted_col] << std::endl;
}

void traverse_matrix(vector<vector<int>>& matrix, const int n, void (*work)(vector<vector<int>>&, int, int, int)) {
    /*
     * Recorre la matriz en orden desde la primera posicion hasta la ultima
     * Por cada lugar le aplico la funcion work que le paso por parametro
     */
    int row, col; 
    for (int i = 0; i < n*n; i++) {
        row = (int) (i / n);
        col = i % n;
        work(matrix, row, col, n);
    }
}

void print_matrix(vector<vector<int>>& matrix, const int n) {
    traverse_matrix(matrix, n, print_inverted_pos); // Imprime la matriz completa en orden inverso
}

vector<vector<int>> create_matrix(int n) {
    vector<vector<int>> matrix(n, vector<int>(n)); // Crea una matriz usando vector

    traverse_matrix(matrix, n, fill_matrix); // recorre la matriz asignandole valores en orden del 1 a n
    return matrix;
}

int main() {
    const int n = 3;
    vector<vector<int>> matrix = create_matrix(n);
    print_matrix(matrix, n);
    return 0;
}
