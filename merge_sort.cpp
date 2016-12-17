/* Merge Sort */

#include<iostream>
#include<cstdlib>
#define MAX 100000
#define N 10000
using namespace std;

    void merge_sort(int[],int,int);

    void merge(int[],int,int,int);

int main(){

    int arr[MAX];

    for(int i=0; i<N; i++)
        arr[i] = rand() % 1000;

    merge_sort(arr,0,N-1);

    for(int i=N-1; i>=0 ; i--)
        cout<<arr[i]<<" ";

    cout<<"\n";

}

    void merge_sort(int arr[],int i,int j){

        int k;

        if(i < j){

            k = (i+j) / 2;

            merge_sort(arr,i,k);

            merge_sort(arr,k+1,j);

            merge(arr,i,k,j);
        }

    }

    void merge(int arr[],int lb,int m,int ub){

        int c[MAX];

        int i,j,k;

        i = lb;
        j = m+1;
        k = 0;

        while(i <= m && j<= ub){

            if(arr[i] < arr[j]){

                c[k] = arr[j];
                j++;
                k++;
            }
            else{

                c[k] = arr[i];
                k++;
                i++;
            }


        }

        while(i <= m){

            c[k] = arr[i];
            k++;
            i++;


        }

        while(j <= ub){

            c[k] = arr[j];
            k++;
            j++;


        }

        for(i=lb, j=0; i<=ub; i++, j++)
            arr[i] = c[j];

    }
