#include<iostream>
#include<cstdlib>
#define MAX 8
using namespace std;

class opr{

public: int rear,front;
        int queue[MAX];

    opr(){

        front = rear = -1;

    }

    void enqueue(int x){

        if(is_full())
            cout<<"\nQueue is full\n";

        else{

            if(is_empty()){

                front = rear = 0;

                queue[rear] = x;
            }

            else{ /* Move elements to the right*/

            int i;

            i = rear;

            while(x > queue[i]){

                queue[(i+1)%MAX] = queue[i];

                i = (i-1+MAX) % MAX;  /* i traverses anti-clockwise in circular queue */

                if(front == ((i+1) % MAX))
                    break;
            }

            i = (i+1) % MAX;

            queue[i] = x;  /* Insert data */

            rear = (rear+1) % MAX;  /* Adjusting rear value */

            }

            cout<<"\nElement "<<x<<" was added in the priority queue\n";

        }

    }

    void dequeue(){

        if(is_empty())
            cout<<"\nQueue is empty\n";

        else{

            int temp;

            if(front == rear){

                temp = queue[front];

                front = rear = -1;

            }

            else{

                temp = queue[front];

                front = (front+1) % MAX;
            }

            cout<<"\nElement "<<temp<<" removed from priority queue\n";
        }

    }

    int is_empty(){

        if(rear == -1)
            return 1;
        return 0;

    }

    int is_full(){

        if(front == (rear+1)%MAX)
            return 1;
        return 0;

    }

    void display_front(){

        if(is_empty())
            cout<<"\nQueue is empty\n";

        else
            cout<<"\nPriority element: "<<queue[front]<<"\n";

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

            i = front;

            cout<<"\nPriority queue elements: ";

            while(i != rear){

                    cout<<queue[i]<<" ";

                    i = (i+1) % MAX;
            }

            cout<<queue[i]<<"\n";  /* Displays rear element */

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
        cout<<"3. Is Queue empty\n";
        cout<<"4. Is Queue full\n";
        cout<<"5. Display front\n";
        cout<<"6. Display rear\n";
        cout<<"7. Display all elements\n";
        cout<<"8. Exit\n";
        cout<<"choice: ";
        cin>>choice;

        switch(choice){

        case 1: cout<<"\nEnter data to add in priority queue: ";
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

        }


    }while(choice != 8);

}
