#include<iostream>
#include<cstdlib>
using namespace std;

struct node{

    struct node *next;
    struct node *prev;
    int data;

};

class dcll{

public: node *hn,*ln,*cn; //ln points to last node

    dcll(){

        hn = NULL;
        ln = NULL;

    }

    void insert(){

        node *nn;
        nn = new node;
        nn->next = NULL;
        nn->prev = NULL;

        cout<<"\nEnter data: ";
        cin>>nn->data;

        if(hn == NULL){

            hn = nn;
            ln = nn;
            hn->prev = hn->next = hn;

        }

        else{

            cn = hn;

            while(cn->next != hn)
                cn = cn->next;

            nn->prev = cn;
            nn->next = hn;
            cn->next = nn;
            hn->prev = nn;

            ln = nn;
        }

    }

    void display(){

        if(hn == NULL)
            cout<<"\nNo nodes present\n";

        else{

        cn = hn;

        cout<<"\nNodes in the list: ";

        while(cn->next != hn){

            cout<<cn->data<<" ";
            cn = cn->next;
        }

        cout<<cn->data<<"\n\n";

        }

    }

    void search(){

        if(hn == NULL)
            cout<<"\nNo nodes present\n";


        else{

            int flag=0,sd;

            cout<<"\nEnter data to search: ";
            cin>>sd;

            cn = hn;

            while(cn->next != hn){

                if(cn->data == sd){

                    flag = 1;
                    break;
                }

                else
                    cn = cn->next;
            }

            if(cn->data == sd){ // checking the data in the last node
                flag = 1;
            }

            if(flag == 1)
                cout<<"\nData present\n";
            else
                cout<<"\nData not found\n";
        }

    }

    int size(){

        if(hn == NULL){

            cout<<"\nNo nodes present\n";
            return 0;
        }

        else{

            int count=1;

            cn = hn;

            while(cn->next != hn){

                count++;
                cn = cn->next;
            }

            return count;

        }


    }

    void delete_data(){

        if(hn == NULL)
            cout<<"\nNo nodes present\n";

        else{

            int dd,flag=0; // flag is to check whether data is successfully deleted

            cout<<"\nEnter data to delete: ";
            cin>>dd;

            if(size() == 1 && hn->data == dd){

                hn = NULL;
                ln = NULL;
                flag = 1;
            }

            else{

            if(hn->data == dd ){

                (hn->next)->prev = ln;
                 ln->next = hn->next;

                hn = hn->next;
                flag = 1;

            }

            else if(ln->data == dd){

                (ln->prev)->next = hn;
                 hn->prev = ln->prev;

                 ln = ln->prev;

                 flag = 1;
            }

            else{

                cn = hn;

                while(cn->next != hn){

                    if(cn->data == dd){

                        (cn->prev)->next = cn->next;
                        (cn->next)->prev = cn->prev;

                         flag = 1;
                         break;

                    }
                    else
                        cn = cn->next;
                }
            }

        }

            if(flag == 1)
                cout<<"\nData deleted\n";
            else
                cout<<"\nData not found\n";


        }

    }

    void insert_after(){

        if(hn == NULL)
            cout<<"\nNo nodes present\n";

        else{

            int id,flag=0;

            node *nn;
            nn = new node;

            nn->next = NULL;
            nn->prev = NULL;

            cout<<"\nEnter data to insert: \n";
            cin>>nn->data;

            cout<<"\nEnter data after which node is to be inserted: ";
            cin>>id;

             if(ln->data == id){

                ln->next = nn;
                nn->next = hn;
                hn->prev = nn;
                nn->prev = ln;

                ln = nn;

                flag = 1;

            }

            else{

                cn = hn;

                while(cn->next != hn && cn->data != id)
                    cn = cn->next;

                if(cn->data == id){

                    (cn->next)->prev = nn;
                     nn->next = cn->next;
                     cn->next = nn;
                     nn->prev = cn;

                     flag = 1;
                }


            }

            if(flag == 1)
                cout<<"\nData inserted\n";
            else
                cout<<"\nData not found\n";
        }

    }

    void reverse(){


        if(hn == NULL)
            cout<<"\nNo nodes present\n";

        else{

            cn = ln;

            cout<<"\nNodes in reverse: ";

            while(cn->prev != ln){

                cout<<cn->data<<" ";
                cn = cn->prev;
            }

            cout<<cn->data<<"\n";
        }

    }

};

int main(){

    dcll obj;
    int choice;

    do{
    cout<<"\n";
    cout<<"1. Insert node\n";
    cout<<"2. Display nodes\n";
    cout<<"3. Search data\n";
    cout<<"4. Delete data\n";
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

    case 4: obj.delete_data();
        break;

    case 5: obj.insert_after();
        break;

    case 6: obj.reverse();
        break;

    case 7: if(obj.size() != 0)
                cout<<"\nSize of list: "<<obj.size()<<"\n\n";
        break;

    case 8: system("cls");
            cout<<"Exited !\n";
        break;

    default:  cout<<"\nInvalid choice !\n";

    }

    }while(choice != 8);

}

