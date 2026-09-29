#include <iostream>
#include <locale>

int** allocateMatrix(int rows, int cols){
    int** matrix = new int*[rows];
    for(int i = 0; i < rows; i++) {
        matrix[i] = new int[cols]{};
    }
    return matrix;
}

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");

    int rows = 3;
    int cols = 4;

    int** matrix = allocateMatrix(rows, cols);

    std::cout << "Матрица " << rows << "x" << cols << " создана" << std::endl;

    for(int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    return 0;
}