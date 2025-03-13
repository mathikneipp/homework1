#include <iostream>
#include <vector>
using namespace std;

void fill_matrix(vector<vector<int>>& matrix, int row, int col, const int n) {
    matrix[row][col] = (row * n) + col + 1;
}

void print_inverted_pos(vector<vector<int>>& matrix, int row, int col, const int n) {
    int inverted_row = (n-1) - row;
    int inverted_col = (n-1) - col;
    std::cout << 'M' << n << '[' <<  inverted_row << "][" << inverted_col << "] = " << matrix[inverted_row][inverted_col] << std::endl;
}

void traverse_matrix(vector<vector<int>>& matrix, const int n, void (*work)(vector<vector<int>>&, int, int, int)) {
    int row, col; 
    for (int i = 0; i < n*n; i++) {
        row = (int) (i / n);
        col = i % n;
        work(matrix, row, col, n);
    }
}

void print_matrix(vector<vector<int>>& matrix, const int n) {
    traverse_matrix(matrix, n, print_inverted_pos);
}

vector<vector<int>> create_matrix(int n) {
    vector<vector<int>> matrix(n, vector<int>(n));

    traverse_matrix(matrix, n, fill_matrix);
    return matrix;
}

int main() {
    const int n = 3;
    vector<vector<int>> matrix = create_matrix(n);
    print_matrix(matrix, n);
    return 0;
}
