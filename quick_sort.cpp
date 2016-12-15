/* Quicksort */

#include<iostream>
#include<cstdlib>
#define MAX 100000
#define N 100000
using namespace std;

void quick_sort(int[],int,int);

int partition(int[],int,int);

int main(){

    int arr[MAX];

    for(int i=0; i<N; i++)
        arr[i] = rand() % 1000;

    quick_sort(arr,0,N-1);

    for(int i=0; i<N; i++)
        cout<<arr[i]<<" ";

    cout<<"\n";



}

    void quick_sort(int arr[],int lb,int ub){

        int j;

        if(lb < ub){

            j = partition(arr,lb,ub);

            quick_sort(arr,lb,j-1);

            quick_sort(arr,j+1,ub);


        }

    }

    int partition(int arr[],int lb,int ub){

        int pivot,i,j,temp;

        i = lb;

        j = ub+1;

        pivot = arr[lb];

        do{

            do
                i++;

            while(arr[i] < pivot &&  i<=ub);

            do
                j--;

            while(pivot < arr[j]);

            if(i<j){

                temp = arr[i];

                arr[i] = arr[j];

                arr[j] = temp;
            }


        }while(i < j);

        arr[lb] = arr[j];

        arr[j] = pivot;

        return j;


    }
