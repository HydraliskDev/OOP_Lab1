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

int main(){
    setlocale(LC_ALL, "ru_RU.UTF-8");

    SafeArray myArr = createArray(10);

    std::cout << "Массив создан. Размер: " << myArr.size << std::endl;

    delete[] myArr.data;
    myArr.data = nullptr;

    return 0;
}
