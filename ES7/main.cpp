//
// Created by Carmine Andreozzi on 16/04/2026.
//
#include <iostream>
using namespace std;

template <typename Auto>
void quicksort(Auto [],int ,int );
template <typename Auto>
int partition(Auto [],int ,int);


int main() {
    int choose,size;
    cout<<"How many elements you want to insert: ";
    cin>>size;
    cout<<"Select Tipe :"<<endl<<"0 = Int"<<endl<<"1 = Float"<<endl<<"2 = Double"<<endl;
    cin>>choose;

    switch (choose) {
        case 0: {
            vector<int> vec(size);
            cout <<"Insert: "<<size<<" Integer"<<endl;
            for (int i = 0; i < size;i++) {cin>>vec[i];}
            quicksort(vec.data(),0,vec.size()-1);
            for (int x : vec ) cout<<x<<" ";
            break;;
        }
        case 1: {
            vector<float>vec(size);
            cout <<"Insert: "<<size<<" Float"<<endl;
            for (int i = 0; i < size;i++) {cin>>vec[i];}
            quicksort(vec.data(),0,vec.size()-1);
            for (float x : vec ) cout<<x<<" ";
            break;;
        }
        case 2: {
            vector<double> vec(size);
            cout <<"Insert: "<<size<<" Double"<<endl;
            for (int i = 0; i < size;i++) {cin>>vec[i];}
            quicksort(vec.data(),0,vec.size()-1);
            for (double x : vec ) cout<<x<<" ";
            break;;
        }

    }
    return 0;
};

template <typename Auto>
void quicksort(Auto a[],int p,int r) {
    int q = 0;
    if (p<r) {
        q = partition(a,p,r);
        quicksort(a,p,q-1);
        quicksort(a,q+1,r);
    }
};
template<typename Auto>
int partition(Auto a[], int p, int r) {
    Auto x;
    int i = 0;
    x = a[r];
    i = p-1;
    for (int j = p; j < r;j++) {
        if (a[j] <= x) {
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[r]);
    return i+1;
}
