#include<iostream>
#include<cstdlib>
#define MAX 100000
#define N 100000
using namespace std;

    void mergesort(int[],int,int);

    void merge(int[],int,int,int);

int main(){

    int arr[MAX];

    for(int i=0; i<N; i++)
        arr[i] = rand() % 1000;

        mergesort(arr,0,N-1);

        for(int i=0; i<N; i++)
            cout<<arr[i]<<" ";

        cout<<"\n";

}

    void mergesort(int arr[],int i,int j){

        int k;

        if(i < j){

            k = (i+j) / 2;

            mergesort(arr,i,k);

            mergesort(arr,k+1,j);

            merge(arr,i,k,j);


        }

    }

    void merge(int arr[],int lb,int m,int ub){

        int i,j,k;

        int c[MAX];

        i = lb;
        j = m+1;

        k = 0;

        while(i <= m && j <= ub ){

            if(arr[i] < arr[j]){

                c[k] = arr[i];
                k++; i++;
            }

            else{

                c[k] = arr[j];
                k++; j++;
            }


        }

        while(i <= m){

            c[k] = arr[i];
            k++; i++;


        }

        while(j <= ub){

            c[k] = arr[j];
            k++; j++;

        }

        for(i=lb,j=0; i<=ub; i++,j++)
            arr[i] = c[j];

    }
