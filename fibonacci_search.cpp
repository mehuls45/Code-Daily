#include<iostream>
#define MAX 100
#define N 10
using namespace std;

    int fib(int);

    int fib_search(int[],int,int,int,int);

int main(){

    int key,k,mid,p,q,result;

    int arr[MAX];

    cout<<"Enter "<<N<<" elements in sorted order: ";

    for(int i=0; i<N; i++)
        cin>>arr[i];

    cout<<"\nEnter element to search: ";
    cin>>key;

    for(k=1;fib(k)<=N;k++);

     p = fib(k-2);

     q = fib(k-3);

     mid = N-p+1;

     result = fib_search(arr,mid,p,q,key);

        if(result == -1)
            cout<<"\nElement not found\n";
        else
            cout<<"\nElement found\n";

}

    int fib(int n){

        if(n == 0)
            return 0;

        if(n == 1)
            return 1;

        return fib(n-1)+fib(n-2);

    }

    int fib_search(int arr[],int mid,int p,int q,int key){

        if(key == arr[mid-1])
            return mid;

        if(key > arr[mid-1]){

            if(p == 1)
                return -1;

            mid = mid+q;

            p = p-q;

            q = q-p;

                return fib_search(arr,mid,p,q,key);
        }

        else{   /* key < arr[mid-1]*/

                if(q == 0)
                    return -1;

            int temp;

            mid = mid - q;

            temp = p-q;

            p = q;

            q = temp;


                return fib_search(arr,mid,p,q,key);


        }

    }
