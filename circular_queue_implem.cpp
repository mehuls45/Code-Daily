#include<iostream>
#include<cstdlib>
#define MAX 8
using namespace std;

class opr{

public: int queue[MAX];
        int front,rear;

    opr(){

        front = rear = -1;

    }

    void enqueue(int x){

        if(is_full())
            cout<<"\nQueue is full\n";

        else{

            if(is_empty())
                front = (front+1)%MAX;

            rear = (rear+1)%MAX;

            queue[rear] = x;

            cout<<"\nElement "<<x<<" is added to the queue\n";


        }


    }

    void dequeue(){

        if(is_empty())
            cout<<"\nQueue is empty\n";

        else{

            int temp;

            if(front == rear){

                temp = front;
                front = rear = -1;

            }

            else{

                temp = front;
                front = (front + 1)%MAX;
            }

            cout<<"\nElement "<<queue[temp]<<" removed from queue\n";
        }
    }

    int is_empty(){

        if(front == -1 && rear == -1)
            return 1;
        return 0;

    }

    int is_full(){

        if(front  == (rear + 1)%MAX)
            return 1;
        return 0;

    }

    void display_front(){

        if(is_empty())
            cout<<"\nQueue is empty\n";

        else
            cout<<"\nFront element: "<<queue[front]<<"\n";

    }

    void display_rear(){

        if(is_empty())
            cout<<"\nQueue is empty\n";

        else
            cout<<"\nRear element: "<<queue[rear]<<"\n";

    }

    void display_all(){

        if(is_empty())
            cout<<"\nQueue is empty\n";

        else{

            int i;

            cout<<"\nElements int the queue: ";

            for(i=front;i!=rear;i=(i+1)%MAX)
                cout<<queue[i]<<" ";

            cout<<queue[rear];

            cout<<"\n\n";

        }

    }


};

int main(){

    opr obj;
    int choice,y;

    do{

    cout<<"\n";
    cout<<"1. Enqueue\n";
    cout<<"2. Dequeue\n";
    cout<<"3. Is queue empty\n";
    cout<<"4. Is queue full\n";
    cout<<"5. Display front\n";
    cout<<"6. Display rear\n";
    cout<<"7. Display elements\n";
    cout<<"8. Exit\n";
    cout<<"choice: ";
    cin>>choice;

    switch(choice){

    case 1: cout<<"\nEnter data to add in queue: ";
            cin>>y;
            obj.enqueue(y);
        break;

    case 2: obj.dequeue();
        break;

    case 3: if(obj.is_empty())
                cout<<"\nQueue is empty\n";
            else
                cout<<"\nQueue is not empty\n";
        break;

    case 4: if(obj.is_full())
                cout<<"\nQueue is full\n";
            else
                cout<<"\nQueue is not full\n";
        break;

    case 5: obj.display_front();
        break;

    case 6: obj.display_rear();
        break;

    case 7: obj.display_all();
        break;

    case 8: system("cls");
            cout<<"Exited !\n";
        break;

        default: cout<<"\nInvalid choice !\n";

    }

    }while(choice != 8);

}
