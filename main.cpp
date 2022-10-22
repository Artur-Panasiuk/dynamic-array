#include <iostream>

using namespace std;

template <typename T>
class dynArr{
    double arrayMultip {2};
    int currSize {0};
    int maxSize {1};
    T* arr;
    T* tempArr;

    dynArr(){
        arr = new T[maxSize];
    }
    ~dynArr(){
        clean();
        delete arr;
    }
public:
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
                arr[j] = temp[j];
            }
            delete temp;
        }else{
            arr[currSize + 1] = data;
        }
    }
    void get(int index = 0){
        if(index < 0 || index > maxSize) return;

        return arr[index];
    }
    void swapData(int index, T data){
        if(index < 0 || index > maxSize) return;
    }
    void clean(bool isObjectType){
        if(isObjectType){
            for(int i = 0; i < currSize; i++){
                delete arr[i];
            }
        }else{
            for(int j = 0; j < currSize; j++){
                arr[i] = NULL;
            }
        }
    }
    string toString(){

    }
    void bubbleSort(bool isObjectType){
        if(isObjectType){

        }else{

        }
    }
};

int main()
{


    return 0;
}
