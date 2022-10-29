#include <iostream>
#include <time.h>
#include <string>

using namespace std;

template <typename T>
class dynArr {
    int arrayMultip{ 2 };
    int currSize{ 0 };
    int maxSize{ 1 };
    T* arr;
    T* tempArr;

    union iterable{
        int i;
        float f;
        double d;
    };
public:
    dynArr() {
        arr = new T[maxSize];
    }
    ~dynArr() {
        delete arr;
    }
    void add(T data) {
        if (currSize == maxSize) {
            tempArr = new T[currSize];
            for (int i = 0; i < currSize; i++) {
                tempArr[i] = arr[i];
            }
            delete arr;
            maxSize *= arrayMultip;
            arr = new T[maxSize];
            for (int j = 0; j < currSize; j++) {
                arr[j] = tempArr[j];
            }
            delete tempArr;
        }
        arr[currSize] = data;
        currSize++;
    }
    void get(int index = 0) {
        if (index < 0 || index > maxSize) throw std::out_of_range("array index out of range");

        return arr[index];
    }
    void swapData(int index, T data) {
        if (index < 0 || index > maxSize) throw std::out_of_range("array index out of range");

        arr[index] = data;
    }
    void clean(bool isPOD = false) {
        if (isPOD) {
            for (int j = 0; j < currSize; j++) {
                arr[j] = NULL;
            }
        }
        else {
            return;
        }
    }
    string toString(bool isPOD = false) {
        string info = arrInfo();

        //if(isPOD) info + content()

        return info;
    }

    string arrInfo() {
        string info = "Mnoznik tabeli: " + to_string(arrayMultip) + "\n" + "Aktualny rozmiar tabeli: " + to_string(currSize) + "\n" + "Maksymalny rozmiar tabeli: " + to_string(maxSize) + "\n";

        return info;
    }

    /*
    string content() {
        for (int i = 0; i < currSize; i++) {
            stringstream ss(arr[i]);
        }
        return ss;
    }
    */


    void bubbleSort(bool isPOD = false) {
        if (isPOD) {
            for (int i = 0; i < n - 1; i++){
                for (int j = 0; j < n - i - 1; j++){
                    if (arr[j] > arr[j + 1]){
                       swap(arr[j], arr[j + 1]);
                    }
                }
            }
        } else {
            return;
        }
    }
};

void timeTest() {

}

int main() {
    dynArr<int>* a = new dynArr<int>;

    for (int i = 0; i < 100; i++) {
        a->add(i*2);
    }
    cout << a->toString();

    delete a;

    return 0;
}
