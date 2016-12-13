#include<iostream>
#define MAX 1000
using namespace std;

int fib(int);

int fib_search(int[],int,int,int,int);

int main(){

    int p,q,k,mid,key,result,n;
    int arr[MAX];

    cout<<"Enter number of elements: ";
    cin>>n;

    cout<<"\nEnter "<<n<<" elements in sorted order: ";

    for(int i=0;i<n;i++)
        cin>>arr[i];

    cout<<"\nEnter element to search for: ";
    cin>>key;

    for(k=1;fib(k)<=n;k++);

    p = fib(k-2);

    q = fib(k-3);

    mid = n-p+1;

    result = fib_search(arr,p,q,mid,key);

    if(result == -1)
        cout<<"\nElement not found\n";

    else
        cout<<"\nElement found at location "<<result<<"\n";



}

    int fib(int n){

        if(n == 0)
            return 0;

        if(n == 1)
            return 1;

            return fib(n-1)+fib(n-2);

    }

    int fib_search(int arr[],int p,int q,int mid,int key){

        if(key == arr[mid-1])
            return mid;

        if(key > arr[mid-1]){

            if(p == 1)
                return -1;

            mid = mid+q;

            p = p-q;
            q = q-p;

            return fib_search(arr,p,q,mid,key);
        }

        else{  /* key < arr[mid-1]*/

            int temp;

            if(q == 0)
                return -1;

            mid = mid-q;
            temp = p-q;
            p = q;
            q = temp;

            return fib_search(arr,p,q,mid,key);


        }

    }
