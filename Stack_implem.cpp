/* Stack implementation */

#include<iostream>
#include<cstdlib>
#define MAX 8
using namespace std;

class opr{

public: int stack[MAX];
        int top;

    opr(){

        top = -1;
    }

    void push(int x){

        if(is_full())
            cout<<"\nStack Overflow\n";

        else
            stack[++top] = x;


    }

    void pop(){

        if(is_empty())
            cout<<"\nStack Underflow\n";

        else
            cout<<"\nElement "<<stack[top--]<<" deleted\n";

    }

    void top_elem(){

        if(is_empty())
            cout<<"\nStack Underflow\n";

        else
             cout<<"\nTop element: "<<stack[top]<<"\n";

    }

    int is_full(){

        if(top == MAX-1)
            return 1;
        return 0;

    }

    int is_empty(){

        if(top == -1)
            return 1;
        return 0;

    }



};

int main(){

    opr obj;
    int choice,y;

    do{

        cout<<"\n";
        cout<<"1. Push element\n";
        cout<<"2. Pop element\n";
        cout<<"3. Display top\n";
        cout<<"4. Is stack empty\n";
        cout<<"5. Is stack full\n";
        cout<<"6. Exit\n";
        cout<<"choice: ";
        cin>>choice;

        switch(choice){

        case 1: cout<<"\nEnter data: ";
                cin>>y;
                obj.push(y);
            break;

        case 2: obj.pop();
            break;

        case 3: obj.top_elem();
            break;

        case 4: if(obj.is_empty())
                    cout<<"\nStack is empty\n";
                else
                    cout<<"\nStack is not empty\n";
            break;

        case 5: if(obj.is_full())
                    cout<<"\nStack is full\n";
                else
                    cout<<"\nStack is not full\n";
            break;

        case 6: system("cls");
                cout<<"Exited !\n";
            break;

        default: cout<<"Invalid choice !\n";


        }

    }while(choice != 6);

}
