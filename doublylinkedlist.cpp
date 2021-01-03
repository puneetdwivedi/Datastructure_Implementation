#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* previous;
        Node(){
            data=-1;
            next=NULL;
            previous=NULL;
        }
        Node(int x){
            data=x;
            next=NULL;
            previous=NULL;
        }
        Node(int x,Node* n,Node* p){
            data=x;
            next=n;
            previous=p;
        }

};
class DoublyLinkedlist{
    Node* head;
    public:
        DoublyLinkedlist(){
            head=NULL;
        }
        DoublyLinkedlist(Node * ptr){
            head=ptr;
        }
        DoublyLinkedlist(int x){
            head->data=x;
            head->previous=NULL;
            head->next=NULL;
        }

        void printlist(){
            Node * ptr=head;
            while(ptr != NULL){
            cout<<ptr->data<<" ";
                ptr=ptr->next;
            }
        }
        void printinreverse(){
            Node* ptr=head;
            while(ptr->next !=NULL){
                ptr=ptr->next;
            }
            while(ptr != NULL){
                cout<<ptr->data<<" ";
                ptr=ptr->previous;
            }
        }

        void append(int x){
            Node* toAdd=new Node(x);
            Node* ptr=head;
            while(ptr->next != NULL){
                ptr=ptr->next;
            }
            ptr->next=toAdd;
            toAdd->previous=ptr;
        }
        void preppend(int x){
            Node * toAdd=new Node(x);
            toAdd->next=head;
            head->previous=toAdd;
            toAdd->previous=NULL;
            head=toAdd;
        }
        void insert(int index,int value){
            Node * toAdd=new Node(value);
            Node* ptr=head;
            if(index == 0){
                toAdd->next=ptr;
                ptr->previous=toAdd;
                toAdd->previous=NULL;
                head=toAdd;
            }
            else{
                while(index-->1){
                    ptr=ptr->next;
                }
                Node * insertnext=ptr->next;
                ptr->next=toAdd;
                toAdd->previous=ptr;
                toAdd->next=insertnext;
                insertnext->previous=toAdd;
            }
        }

        void delet(int position){
            if(position >= size()){
                cout<<"INDEX OUT OF BOUND";
            }
            else{
                Node* ptr1=head;
                while(position-->1){
                    ptr1=ptr1->next;
                }
                Node* ptr2=ptr1->next;
                ptr1->next=ptr2->next;
                ptr2->previous=NULL;
                ptr2->next->previous=ptr1;
                ptr2->next=NULL;
            }
        }

        bool isEmpty(){
            if(head ==NULL){
                return true;
            }
            else{
                return false;
            }
        }

        int size(){
            int len=0;
            Node* ptr=head;
            while(ptr != NULL){
                ptr=ptr->next;
                len++;
            }
            return len;
        }
};

int main(){
    Node* n=new Node(25);

    DoublyLinkedlist l1(n);
    l1.append(5);
    l1.append(4);
    l1.append(9);
    l1.printlist();
    cout<<endl;
    // l1.printinreverse();
    l1.insert(0,35);
    l1.preppend(6);
    l1.append(54);
    l1.printlist();
    cout<<endl;
    l1.printinreverse();
    l1.delet(3);
    cout<<endl;
    l1.printlist();
    cout<<endl<<l1.isEmpty()<<endl;
    cout<<l1.size()<<endl;
    l1.delet(6);
    return 0;
}