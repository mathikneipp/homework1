#include "matrix.h"
#include <iostream>
#include <vector>

void fill_matrix(vector<vector<int>>& matrix, const int n) {
    int row, col; 
    for (int i = 0; i < n*n; i++) { // Recorre la matriz hasta n^2
        row = (int) (i / n); // La fila es i / n truncado: 0 es la primera fila, 1 es la segunda, etc...
        col = i % n; // La columna es i mod n.
        matrix[row][col] = i+1; // Inserta i+1 en la pos asi se saltea el 0.
    }
}

void print_matrix(vector<vector<int>>& matrix, const int n) {
    int row, col; 
    for (int i = 0; i < n*n; i++) { // Recorre la matriz hasta n^2
        row = (int) (i / n); // La fila es i / n truncado: 0 es la primera fila, 1 es la segunda, etc...
        col = i % n; // La columna es i mod n.
        int inverted_row = (n-1) - row; // Traspone la fila
        int inverted_col = (n-1) - col; // Traspone la columna
        std::cout << 'M' << n << '[' <<  inverted_row << "][" << inverted_col << "] = " << matrix[inverted_row][inverted_col] << std::endl;
    }
}

vector<vector<int>> create_matrix(int n) {
    vector<vector<int>> matrix(n, vector<int>(n)); // Crea una matriz usando vector
    fill_matrix(matrix, n); // Recorre la matriz asignandole valores en orden del 1 a n
    return matrix;
}

// Compilar y ejecutar con make run_matrix
int main() {
    const int n = 3;
    vector<vector<int>> matrix = create_matrix(n);
    print_matrix(matrix, n);
    return 0;
}
