#include <iostream>
#include <clocale> 
/**
 * @brief Обрабатывает динамический массив
 * 
 * Находит первый отрицательный эелемент. Если он есть,
 * создаёт новый динамический массив с элементами до
 * отрицательного, освобождает старую память.
 * 
 * @param arr Ссылка на указатель (может быть изменён)
 * @param size Размер массив
 */
void process(int*& arr, int size){
    int firstNegIdx = -1;
    for (int i = 0; i < size; i++){
        if (arr[i] < 0){
            firstNegIdx = i;
            break;
        }
    }

if (firstNegIdx == -1){
    std::cout << "Отрицательные элементы не найдены" << std::endl;
    return;
}

int newSize = firstNegIdx;

int* newArr = new int[newSize]{};

for (int i = 0; i < newSize; i++){
    newArr[i] = arr[i];
}

delete[] arr;

arr = newArr;

std::cout << "Новый размер массива: " << newSize << std::endl;
}
/**
 * @brief Точка входа в программу
 * 
 * Демонстрирует работу с динамическим массивом:
 * ввод, обработка, вывод результата, безопасное
 * особождение памяти.
 * 
 * @return 0 при успешном завершении
 */
int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    int N;
    std::cout << "Введите размер массива N: ";
    std::cin >> N;

    int* arr = new int[N]{};

    std::cout << "Введите " << N << " чисел : ";
    for(int i = 0; i < N; i++){
        std::cin >> arr[i];
    }
    
    std::cout << "Исходный массив: ";
    for (int i = 0; i < N; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    int newSize = N;
    for (int i = 0; i < N; i++){
        if (arr[i] < 0){
            newSize = i;
            break;
        }
    }

    process(arr, N);

    std::cout << "Результат: ";
    for (int i = 0; i < newSize; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    delete[] arr;
    arr = nullptr;

    if (arr == nullptr){
        std::cout << "Указатель обнулен - безопасно" << std::endl;
    }
    else{
        std::cout << *arr << std::endl;
    }

    return 0;

    

}