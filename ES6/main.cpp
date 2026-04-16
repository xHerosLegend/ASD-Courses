//
// Created by Carmine Andreozzi on 15/04/2026.
//
#include <iostream>
#include <vector>
using namespace std;

int insertin_Sort(int arr[], int size);

int main() {
    int size  = 0;
    int num = 0;
    vector<int> vec;
    cout<<"Add as many elements as you want to the vector: ";
    cin>>size;

    cout<<"Insert "<<size<<" Numbers in the integer vector "<<endl;
    for (int i = 0 ; i < size; i++) {
        cin>>num;
        vec.push_back(num);
    }

    cout<<"Printing of unsorted vectors"<<endl;
    for (int i = 0; i < size;i++) {
        cout<<"Vector ["<<i<<"] : "<<vec.at(i)<<endl;
    }

    insertin_Sort(vec.data(),size);

    cout<<"ImplementationPrinting of sorted vectors"<<endl;
    for (int i = 0; i < size;i++) {
        cout<<"Vector ["<<i<<"] : "<<vec.at(i)<<endl;
    }

    return 0;
}
int insertin_Sort(int arr[], int size) {
  int key,i;
    for (int j = 1 ; j < size;j++) {
        key = arr[j];
        i = j-1;
        while (i >= 0 && arr[i] > key) {
            arr[i+1] = arr[i];
            i--;
        }
        arr[i+1] = key;
    }
    return *arr;
};
