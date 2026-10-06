#include <iostream>
#include <clocale>
#include <cstdlib>
#include <ctime>
#include <string>

/**
 * @brief Выделяет память под двумерный массив
 * 
 * Создает массив указателей, затем для каждой строки
 * выделяет отдельный массив чисел, обнуленый.
 * 
 * @param rows Количество строк 
 * @param cols Количество столбцов
 * @return Указатель на двумерный массив
 */
int** allocateMatrix(int rows, int cols){
    int** matrix = new int*[rows];
    for(int i = 0; i < rows; i++) {
        matrix[i] = new int[cols]{};
    }
    return matrix;
}
/**
 * @bried Заполняет матрицу случайными числами
 * @param matrix Указатель на двумерный массив
 * @param rows Количество строк
 * @param cols Количество столбцов
 */
void fillMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 100;
        }
    }
}
/**
 * @brief Выводит матрицу на экран
 * 
 * Если showBorders  == true, выводит рамку из символов '*'
 * вокруг матрицы и заголовок.
 * 
 * @param matrix Указатель на двумерный массив
 * @param rows Количество строк
 * @param cols Количество столбцов
 * @param showBorders Показывать рамку (по умолчанию true)
 * @param title Заголовок матрицы (по умолчанию "Matrix")
 */
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
/**
 * @brief Освобождает память двумерного массива
 *
 * Сначала удаляет вложенные массивы (строки),
 * затем массив указателей.
 *
 * @param matrix Указатель на двумерный массив
 * @param rows Количество строк
 */
void freeMatrix(int**matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
/**
 * @brief Точка входа в программу
 *
 * @return 0 при успешном завершении
 */
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

    freeMatrix(matrix, rows);

    return 0;
}