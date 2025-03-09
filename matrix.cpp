#include <iostream>

void destroy_matrix(int** matrix, int r) {
    for (int i = 0; i < r; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

void fill_matrix(int** matrix, int row, int col, int n) {
    matrix[row][col] = (row * n) + col + 1;
}

void print_inverted_pos(int** matrix, int row, int col, int n) {
    int inverted_row = (n-1) - row;
    int inverted_col = (n-1) - col;
    std::cout << 'M' << n << '[' <<  inverted_row << "][" << inverted_col << "] = " << matrix[inverted_row][inverted_col] << std::endl;
}

void traverse_matrix(int** matrix, int n, void (*work)(int**, int, int, int)) {
    int row, col; 
    for (int i = 0; i < n*n; i++) {
        row = (int) (i / n);
        col = i % n;
        work(matrix, row, col, n);
    }
}

void print_matrix(int** matrix, int n) {
    traverse_matrix(matrix, n, print_inverted_pos);
}

int** create_matrix(int n) {
    int** matrix = (int**) malloc((size_t) n * sizeof(int*));
    if (matrix == NULL) {
        throw "No se pudo crear la matriz";
        return NULL;
    }
    for (int i = 0; i < n; i++) {
        matrix[i] = (int*) malloc((size_t) n * sizeof(int));
        if (matrix[i] == NULL) {
            throw "No se pudo crear la matriz";
            destroy_matrix(matrix, i);
            return NULL;
        }
    }
    traverse_matrix(matrix, n, fill_matrix);
    return matrix;
}

int main() {
    int n;
    std::cout << "Ingrese el tamaño de la matriz: ";
    std::cin >> n;
    int** matrix = create_matrix(n);
    print_matrix(matrix, n);
    destroy_matrix(matrix, n); // Libera la memoria de la matriz
    return 0;
}
