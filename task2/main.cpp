#include <iostream>
#include <clocale> 
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

    delete[] arr;
    arr = nullptr;

    return 0;

    

}