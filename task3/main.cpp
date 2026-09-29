#include <iostream>
#include <clocale>

struct SafeArray{
    int* data;
    int size;
};

SafeArray createArray(int size) {
    SafeArray arr;
    arr.data = new int[size]{};
    arr.size = size;
    return arr;
}

int& getElement(SafeArray& arr, int index){
    static int stub = 0;

    if(index < 0 || index >= arr.size){
        std::cout << "Ошибка: индекс " << index << " вне диапазона [0, " << (arr.size - 1) << "]" << std::endl;
        return stub;
    }
    return arr.data[index];
}

void printSafe(const SafeArray& arr){
    std::cout << "SafeArray[" << arr.size << "]:";
    for (int i = 0; i < arr.size; i++){
        std::cout << arr.data[i] << " ";
    }
    std::cout << std::endl;
}

void reSizeArray(SafeArray& arr, int M) {
    int N = arr.size;

    int* newData = new int [M]{};

    int copyCount = (N < M) ? N : M;

    for (int i = 0; i < copyCount; i++){
        newData[i] = arr.data[i];
    }
    
    if (M < N) {
        std::cout << "Удаленные элементы: ";
        for (int i = M; i < N; i++){
            std::cout << arr.data[i] << " ";
        }
    }
    
    delete[] arr.data;

    arr.data = newData;
    arr.size = M;
}
int main(){
    setlocale(LC_ALL, "ru_RU.UTF-8");

    SafeArray myArr = createArray(10);

    for(int i = 0; i < myArr.size; i++){
        getElement(myArr, i) = (i + 1) * 10;
    }

    std::cout << "Исходный массив: " << std::endl;
    printSafe(myArr);
    
    std::cout << "Меняем элемент 2 на 999" << std::endl;
    getElement(myArr, 2) = 999;
    printSafe(myArr);

    std::cout << "Пытаемся обратиться к элементу 100:" << std::endl;
    getElement(myArr, 100) = 12345;
    std::cout << "(значение не изменилось — защита работает)" << std::endl;
    printSafe(myArr);

    std::cout << "\nУменьшаем с 10 до 5:" << std::endl;    
    reSizeArray(myArr, 5);
    std::cout << "\n";
    printSafe(myArr);

    std::cout << "\nУвеличиваем с 5 до 8:" << std::endl;
    
    reSizeArray(myArr, 8);
    printSafe(myArr);


    
    delete[] myArr.data;
    myArr.data = nullptr;

    return 0;
}
