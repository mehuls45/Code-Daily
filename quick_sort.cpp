/* Quick Sort */

#include<iostream>
#include<cstdlib>
#define MAX 100000
#define N 100000
using namespace std;

    void quicksort(int[],int,int);

    int partition(int[],int,int);


int main(){

    int arr[MAX];

    for(int i=0; i<N; i++)
        arr[i] = rand() % 1000;

    quicksort(arr,0,N-1);

    for(int i=0; i<N; i++)
        cout<<arr[i]<<" ";

    cout<<"\n\n";

}

    void quicksort(int arr[],int lb,int ub){

        int j;

        if(lb < ub){

            j = partition(arr,lb,ub);

            quicksort(arr,lb,j-1);

            quicksort(arr,j+1,ub);



        }

    }

    int partition(int arr[],int lb,int ub){

        int pivot,i,j,temp;

        pivot = arr[lb];

        i = lb;

        j = ub+1;

        do{

            do
                i++;

            while(pivot > arr[i] && i<=ub);

            do
                j--;

            while(arr[j] > pivot );

            if(i < j){

                temp = arr[i];

                arr[i] = arr[j];

                arr[j] = temp;

            }


        }while(i < j);

            arr[lb] = arr[j];

            arr[j] = pivot;

            return j;

    }

