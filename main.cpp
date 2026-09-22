#include <iostream>
#include <cstdlib>
#include <ctime>

/**
 * @brief Заполняет массив случайными числами
 *
 * Проходит по всем элементам массива и присваивает
 * каждому случайное число в диапазоне [0, 99].
 *
 * @param arr Ссылка на массив из 10 целых чисел
 */
void fillArray(int (&arr)[10]) {
    for (int i = 0; i < 10; i++) {
        arr[i] = rand() % 100;
    }
}
/**
 * @brief Выводит массив на экран
 *
 * Перебирает все элементы массива с помощью
 * range-based for и выводит их через пробел,
 * затем переводит курсор на новую строку.
 *
 * @param arr Константная ссылка на массив из 10 элементов
 */
void printArray(const int (&arr)[10]) {
    for (auto x : arr) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}
void swapElements(int (&arr)[10], int& i, int& j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
int main() {
    int arr[10];
    srand(time(0));
    
    fillArray(arr);
    printArray(arr);

    int i = 2, j = 5;
    swapElements(arr, i, j);
    printArray(arr);

    return 0;
}