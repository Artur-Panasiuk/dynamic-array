#include <iostream>
#include <time.h>
#include <string>
#include <sstream>

using namespace std;

template <typename T>
class dynArr {
    int arrayMultip{ 2 };
    int currSize{ 0 };
    int maxSize{ 1 };
    T* arr;
    T* tempArr;

public:
    dynArr() {
        arr = new T[maxSize];
    }
    ~dynArr() {
        delete[] arr;
    }
    void add(T data) {
        if (currSize == maxSize) {
            maxSize *= arrayMultip;
            T* temp = new T[maxSize];
            for (int j = 0; j < currSize; j++) {
                temp[j] = arr[j];
            }
            delete[] arr;
            arr = temp;
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

        if (isPOD) info += content();

        return info;
    }

    string arrInfo() {
        string info = "Mnoznik tabeli: " + to_string(arrayMultip) + "\n" + "Aktualny rozmiar tabeli: " + to_string(currSize) + "\n" + "Maksymalny rozmiar tabeli: " + to_string(maxSize) + "\n";

        return info;
    }


    string content() {
        string temp;

        int customSize = (currSize < 100) ? currSize : 100;

        for (int i = 0; i < customSize; i++) {
            temp += to_string(arr[i]);
            temp += "\n";
        }
        return temp;
    }


    void bubbleSort(bool isNum = false) {
        if (isNum) {
            int n = arr.lenght;
            for (int i = 0; i < n - 1; i++) {
                for (int j = 0; j < n - i - 1; j++) {
                    if (arr[j] > arr[j + 1]) {
                        swap(arr[j], arr[j + 1]);
                    }
                }
            }
        }
        else {
            return;
        }
    }
};

void dynArrTimeTest(int loopSize) {
    clock_t t1, t2, t3, t4, t5;
    dynArr<int>* a = new dynArr<int>;
    srand(time(NULL));

    double worst = 0, now = 0;
    t1 = clock();
    for (int i = 0; i < loopSize; i++) {
        t4 = clock();
        a->add(i*(rand() % 100));
        t5 = clock();
        now = (t5 - t4) / (double) CLOCKS_PER_SEC;
        if (now > worst) {
            cout << "iteracja nr.: " << i << " jest aktualnie najwolniejsza (czas w sekundach): " << now << endl;
            worst = now;
        }
    }
    t2 = clock();

    cout << a->toString(true);

    t3 = clock();

    cout << "TIME TABLE IN SECONDS" << endl;
    cout << endl << (double)(t2 - t1) / CLOCKS_PER_SEC << " :To create loopSize dynamic array" << endl;
    cout << endl << (double)(t3 - t2) / CLOCKS_PER_SEC << " :To write information on screen" << endl;
    cout << endl << (double)(t3 - t1) / CLOCKS_PER_SEC << " :From Start to Finish." << endl;

    delete a;
}

int main() {
    dynArrTimeTest(1000000);

    return 0;
}
