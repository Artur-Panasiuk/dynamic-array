#include <iostream>
#include <time.h>

using namespace std;

template <typename T>
class dynArr{
    double arrayMultip {2};
    int currSize {0};
    int maxSize {1};
    T* arr;
    T* tempArr;
public:
    dynArr(){
        arr = new T[maxSize];
    }
    ~dynArr(){
        //clean(false);
        delete arr;
    }
    void add(T data){
        if(currSize == maxSize){
            tempArr = new T[currSize];
            for(int i = 0; i < currSize; i++){
                tempArr[i] = arr[i];
            }
            delete arr;
            maxSize  *= arrayMultip;
            arr = new T[maxSize];
            for(int j = 0; j < currSize; j++){
                arr[j] = tempArr[j];
            }
            delete tempArr;
        }
            arr[currSize] = data;
            currSize++;
    }
    void get(int index = 0){
        if(index < 0 || index > maxSize) return;

        return arr[index];
    }
    void swapData(int index, T data){
        if(index < 0 || index > maxSize) return;
    }
    void clean(bool isPOD = false){
        if(isPOD){
            for(int j = 0; j < currSize; j++){
                arr[j] = NULL;
            }
        }else{
            return;
        }
    }
    void toString(){
        for(int i = 0; i < currSize; i++){
            cout<< i << "-" << arr[i]<<endl;
        }
        cout<<"Max size: "<<maxSize<<endl;
    }
    void bubbleSort(bool isPOD = false){
        if(isPOD){

        }else{
            return;
        }
    }
};

void printString(string text){

}

void timeTest(){

}

int main()
{
    dynArr<int>* a = new dynArr<int>;

    for(int i = 0; i < 100; i++){
        a->add(i);
    }
    a->toString();

    delete a;

    return 0;
}
