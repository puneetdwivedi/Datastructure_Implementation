#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node(){
            data=-1;
            next=NULL;
        }
        Node(int x,Node *n){
            data=x;
            next=n;
        }
        Node(int x){
            data=x;
            next=NULL;
        }
};

class SinglyLinkedList{
    Node* head;
    public:
        // constructor
        SinglyLinkedList(){
            head=NULL;
        }
        SinglyLinkedList(Node* n){
            head=n;
        }
        SinglyLinkedList(int headData){
            head->data=headData;
        }

        // Membre function
        void append(int data){
            Node *toAdd=new Node(data);
            Node* ptr=head;
            while(ptr->next != NULL){
                ptr=ptr->next;
            }
            ptr->next=toAdd;
        }

        void prepend(int data){
            Node * toAdd=new Node(data);
            toAdd->next=head;
            head=toAdd;
        }

        void insert(int data,int index){
            if(isEmpty() || index >= size()){
                cout<<"Could not be inserted! Please check the INDEX"<<endl;
            }
            else{
                Node* toAdd=new Node(data);
                Node* ptr=head;
                while(index-->1){
                    ptr=ptr->next;
                }
                toAdd->next=ptr->next;
                ptr->next=toAdd;
            }
        }

        void delet(int index){
            Node* ptr=head;
            while(index-->1){
                ptr=ptr->next;
            }
            Node *ptr2=ptr->next;
            ptr->next=ptr2->next;
            ptr2->next=NULL;
        }

        bool isEmpty(){
            if(head == NULL){
                return true;
            }
            else{
                return false;
            }
        }
        
        int size(){
            Node* ptr=head;
            int s=1;
            while(ptr->next != NULL){
                ptr=ptr->next;
                s++;
            }
            return s;
        }

        void printlist(){
            Node*ptr=head;
            while(ptr->next != NULL){
                cout<<ptr->data<<" ";
                ptr=ptr->next;
            }
            cout<<ptr->data<<endl;
        }

        void reverselist(){
            Node* curr=head;
            Node* prev=NULL;
            Node* next=head->next;
            while(next !=NULL){
                curr->next=prev;
                prev=curr;
                curr=next;
                next=next->next;
            }
            curr->next=prev;
            head=curr;

        }

};


int main(){
    Node puneet;
    // cout<<puneet.data<<endl;
    Node pun(25);
    // cout<<pun.data<<endl;
    SinglyLinkedList l1;
    Node *p=&pun;
    SinglyLinkedList l2(p);
    l2.append(5);
    l2.append(6);
    l2.append(98);
    l2.prepend(100);
    l2.size();
    cout<<endl;
    l2.printlist();
    l2.insert(28,2);
    l2.printlist();
    l2.delet(3);
    l2.printlist();
    cout<<"reversed linkedlist is "<<endl;
    l2.reverselist();
    l2.printlist();
    l2.reverselist();
    l2.printlist();
    
    return 0;
}