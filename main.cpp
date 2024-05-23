#include <iostream>
#include <stdexcept>

template<typename T, int N>
class Array {
private:
    T data[N];

public:
    Array();

    Array(const T& value);

    T& operator[](int index);

    int size() const noexcept;

};


template<typename T, int N>
Array<T, N>::Array() = default;

template<typename T, int N>
Array<T, N>::Array(const T& value) {
    for (int i = 0; i < N; ++i) {
        data[i] = value;
    }
}


template<typename T, int N>
T& Array<T, N>::operator[](int index) {
    if (index < 0 || index >= N)
        throw std::out_of_range("Index out of range");
    return data[index];
}


template<typename T, int N>
int Array<T, N>::size() const noexcept {
    return N;
}

int main() {
    Array<int, 5> arr(42); 

    for (int i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
