/* Queue implementaion */

#include<iostream>
#include<cstdlib>
#define MAX 8
using namespace std;

class opr{

public: int front,rear;
        int queue[MAX];

    opr(){

        front = rear = -1;

    }

    void enqueue(int x){

        if(is_full())
            cout<<"\nQueue is full\n";

        else{

            if(is_empty())
                front++;

            queue[++rear] = x;

        }

    }

    void dequeue(){

        if(is_empty())
            cout<<"\nQueue empty\n";

        else{

            int temp;

            if(front == rear){

                temp = queue[front];
                front = rear = -1;

            }

            else{

                temp = queue[front++];
            }

            cout<<"\nElement "<<temp<<" deleted from Queue\n";
        }

    }

    void front_elem(){

        if(is_empty())
            cout<<"\nQueue is empty\n";

        else
            cout<<"\nFront element: "<<queue[front]<<"\n";

    }

    void rear_elem(){

        if(is_empty())
            cout<<"\nQueue is empty\n";

        else{

            cout<<"\nRear element: "<<queue[rear]<<"\n";
        }

    }

    int is_full(){

        if(rear == MAX-1)
            return 1;
        return 0;

    }

    int is_empty(){

        if(front == -1 && rear == -1)
            return 1;
        return 0;

    }


};

int main(){

    opr obj;
    int choice,y;

    do{

        cout<<"\n";
        cout<<"1. Enqueue\n";
        cout<<"2. Dequeue\n";
        cout<<"3. Display front\n";
        cout<<"4. Display rear\n";
        cout<<"5. Is Queue full\n";
        cout<<"6. Is Queue empty\n";
        cout<<"7. Exit\n";
        cout<<"choice: ";
        cin>>choice;

        switch(choice){

        case 1: cout<<"\nEnter data to add: ";
                cin>>y;
                obj.enqueue(y);
            break;

        case 2: obj.dequeue();
            break;

        case 3: obj.front_elem();
            break;

        case 4: obj.rear_elem();
            break;

        case 5: if(obj.is_full())
                    cout<<"\nQueue is full\n";
                else
                    cout<<"\nQueue is not full\n";
            break;

        case 6: if(obj.is_empty())
                    cout<<"\nQueue is empty\n";
                else
                    cout<<"\nQueue is not empty\n";
            break;

        case 7: system("cls");
                cout<<"Exited !\n";
            break;

        }

    }while(choice != 7);

}
