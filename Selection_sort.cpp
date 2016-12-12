#include<iostream>
#include<cstdlib>
#define MAX 100000
#define N 100000
using namespace std;

class opr{

public: int arr[MAX];
        int i,j,min,temp;


    void input(){

        for(i=0;i<N;i++)
            arr[i] = rand()%1000;

    }

    void selection(){

        for(i=0;i<N-1;i++){

            min = i;

            for(j=i+1;j<N;j++){

                if(arr[min] > arr[j])
                    min = j;
            }

            temp = arr[min];

            arr[min] = arr[i];

            arr[i] = temp;

        }

    }

    void display(){

        for(i=0;i<N;i++)
            cout<<arr[i]<<" ";

        cout<<"\n\n";

    }



};

int main(){

    opr obj;

    obj.input();
    obj.selection();
    obj.display();

}
