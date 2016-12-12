/* Bubble Sort */

#include<iostream>
#include<cstdlib>
#define MAX 100000
#define N 10000
using namespace std;

class opr{

public: int arr[MAX];
        int i,j,temp;

    void input(){

        for(i=0;i<N;i++)
            arr[i] = rand()%1000;

    }

    void bubble(){

        for(i=1;i<N;i++){

            for(j=0;j<N-i;j++){

                if(arr[j] > arr[j+1]){

                    temp = arr[j+1];

                    arr[j+1] = arr[j];

                    arr[j] = temp;
                }


            }
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
    obj.bubble();
    obj.display();

}
