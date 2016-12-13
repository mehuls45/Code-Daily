#include<iostream>
#define MAX 100
using namespace std;

int bin_search(int[],int,int);

int main(){

    int arr[MAX],result,n,key;

    cout<<"Enter number of elements: ";
    cin>>n;

    cout<<"\nEnter "<<n<<" elements in sorted order: ";

    for(int i=0;i<n;i++)
        cin>>arr[i];

    cout<<"\nEnter element to search for: ";
    cin>>key;

    result = bin_search(arr,key,n);

    if(result == -1)
        cout<<"\nElement not found\n";

    else
        cout<<"\nElement found at location "<<result+1<<"\n";


}

    int bin_search(int arr[],int key,int n){

        int i,j,mid;

        i = 0;
        j = n-1;
        mid = (i+j) / 2;

        if(arr[mid] == key)
            return mid;

        while(arr[mid] != key && i<=j){

            if(key > arr[mid])
                i = mid + 1;

            else
                j = mid-1;

            mid = (i+j) / 2;


        }

        if(i<=j)
            return mid;
        return -1;


    }

