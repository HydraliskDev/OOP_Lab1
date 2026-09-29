#include <iostream>
#include <clocale>
#include <cstdlib>
#include <ctime>
#include <string>

int** allocateMatrix(int rows, int cols){
    int** matrix = new int*[rows];
    for(int i = 0; i < rows; i++) {
        matrix[i] = new int[cols]{};
    }
    return matrix;
}
void fillMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 100;
        }
    }
}

void printMatrix(int** matrix, int rows, int cols, bool showBorders = true, std::string title = "Matrix") {
    if (showBorders) {
        std::cout << "*** "<< title << " ***" << std::endl;
    } else {
        std::cout << title << std::endl;
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++){
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    
    if (showBorders) {
        std::cout << "**************" << std::endl;
    }

}
int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    srand(time(0));
    
    int rows = 3;
    int cols = 4;

    int** matrix = allocateMatrix(rows, cols);
    fillMatrix(matrix, rows, cols);

    std::cout << "Матрица " << rows << "x" << cols << " создана" << std::endl;

    std::cout << "--- Вызов 1: без параметров ---" << std::endl;
    printMatrix(matrix, rows, cols);

    
    std::cout << "\n--- Вызов 2: с заголовком ---" << std::endl;
    printMatrix(matrix, rows, cols, true, "My Matrix");

    std::cout << "\n--- Вызов 3: без рамки ---" << std::endl;
    printMatrix(matrix, rows, cols, false, "No Borders");

    for(int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    return 0;
}