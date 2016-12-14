#include<iostream>
#include<cstdlib>
#define MAX 100000
#define N 10000
using namespace std;

 void insertion_sort(int[]);


int main(){

    int arr[MAX];

    for(int i=0; i<N; i++)
        arr[i] = rand() % 1000;

    insertion_sort(arr);

    for(int i=0; i<N; i++)
        cout<<arr[i]<<" ";

    cout<<"\n\n";

}

    void insertion_sort(int arr[]){

        int i,j,temp;

        for(i=1; i<N; i++){

            temp = arr[i];

            for(j=i-1; j>=0 && arr[j]>temp; j-- )

                arr[j+1] = arr[j];

            arr[j+1] = temp;
        }

    }
