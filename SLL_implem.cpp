/* SLL implementation with C++*/

#include<iostream>
#include<cstdlib>
using namespace std;

struct node{

    struct node *next;
    int data;

};

class sll{

    public: node *hn,*cn;

    sll(){
        hn = NULL;
    }

    void insert(){

        node *nn;
        nn = new node;
        nn->next = NULL;

        cout<<"\nEnter data: ";
        cin>>nn->data;

        if(hn == NULL)
            hn = nn;

        else{

            cn = hn;

            while(cn->next != NULL)
                cn = cn->next;

            cn->next = nn;
        }


    }

    void display(){

        if(hn == NULL)
            cout<<"\nNo nodes present !\n";

        else{

            cn = hn;

            cout<<"\nNodes in the list: ";

            while(cn != NULL){

                cout<<cn->data<<" ";
                cn = cn->next;
            }

            cout<<"\n\n";
        }

    }

    void search(){

        if(hn == NULL)
            cout<<"\nNo nodes present !\n";

        else{

            int flag=0,sd;

            cout<<"\nEnter data to search: ";
            cin>>sd;

            cn = hn;

            while(cn != NULL){

                if(cn->data == sd){
                    flag = 1;
                    break;
                }

                cn = cn->next;
            }

            if(flag == 1)
                cout<<"\nData present \n";
            else
                cout<<"\nData not present\n";
        }

    }

    void del(){

        if(hn == NULL)
            cout<<"\nNo nodes present !\n";

        else{

            int flag=0,dd;

            node *temp;

            cout<<"\nEnter data to delete: ";
            cin>>dd;


            if(hn->data == dd){

                hn = hn->next;
                cout<<"\nNode with data "<<dd<<" deleted \n";
            }

            else{

            cn = hn;

            while(cn != NULL){

                if(cn->data != dd){

                    temp = cn;
                    cn = cn->next;
                }

                else
                    break;

            }

            if(cn == NULL && flag == 0)
                cout<<"\nData not found !\n";

            else {

                temp->next = cn->next;
                cout<<"\nNode with data "<<dd<<" deleted \n";

            }

        }
      }

    }

    void insert_after(){

        int id,after_data;

        if(hn == NULL)
            cout<<"\nNo nodes present !\n";

        else{

            int flag=0;

            node *nn;
            nn = new node;
            nn->next = NULL;

            cout<<"\nEnter data: ";
            cin>>nn->data;

            cout<<"\nEnter data after which node is to be inserted: ";
            cin>>after_data;

            cn = hn;

            while(cn != NULL){

                if(cn->data == after_data){

                    nn->next = cn->next;
                    cn->next = nn;
                    flag = 1;
                    break;
                }

                cn = cn->next;
            }

            if(flag == 1)
                cout<<"\nNode inserted \n";
            else
                cout<<"\nData not found !\n";
        }

    }

    void reverse(node *cn){

        if(cn->next != NULL)
            reverse(cn->next);

        cout<<cn->data<<" ";

    }

    void display_size(){

        if(hn == NULL)
            cout<<"\nNo nodes present !\n";

        else{

            int count=0;

            cn = hn;

            while(cn != NULL){

                count++;
                cn = cn->next;
            }

            cout<<"\nSize of list: "<<count<<"\n";
        }
    }

};

int main(){

    sll obj;

    int choice;
    do{
    cout<<"\n";
    cout<<"1. Insert node\n";
    cout<<"2. Display nodes\n";
    cout<<"3. Search for node\n";
    cout<<"4. Delete node\n";
    cout<<"5. Insert after\n";
    cout<<"6. Display Reverse\n";
    cout<<"7. Display Size\n";
    cout<<"8. Exit\n";
    cout<<"choice: ";
    cin>>choice;

    switch(choice){

    case 1: obj.insert();
        break;

    case 2: obj.display();
        break;

    case 3: obj.search();
        break;

    case 4: obj.del();
        break;

    case 5: obj.insert_after();
        break;

    case 6: cout<<"\nReverse order: ";obj.reverse(obj.hn);
            cout<<"\n\n";
        break;

    case 7: obj.display_size();
        break;

    case 8: system("cls");
            cout<<"Exited !\n";
        break;

    default:
        cout<<"Invalid choice !\n";

    }
    }while(choice != 8);

}
