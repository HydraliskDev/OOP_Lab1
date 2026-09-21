#include <iostream>
#include <cstdlib>
#include <ctime>

void fillArray(int (&arr)[10]) {
    for (int i = 0; i < 10; i++) {
        arr[i] = rand() % 100;
    }
}

int main() {
    int arr[10];
    srand(time(0));
    
    fillArray(arr);
    
    for (int x : arr) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    
    return 0;
}