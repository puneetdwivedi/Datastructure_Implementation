#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        data = -1;
        next = NULL;
    }
    Node(int x, Node *n)
    {
        data = x;
        next = n;
    }
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class SinglyLinkedList
{
    Node *head;

public:
    // constructor
    SinglyLinkedList()
    {
        head = NULL;
    }
    SinglyLinkedList(Node *n)
    {
        head = n;
    }
    SinglyLinkedList(int headData)
    {
        head->data = headData;
    }

    // Membre function
    void append(int data)
    {
        Node *toAdd = new Node(data);
        Node *ptr = this->head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = toAdd;
    }
    int search(int data){
        Node* ptr=this->head;
        while(ptr != NULL){
            if(ptr->data == data){
                return 1;
            }
            ptr=ptr->next;
        }
        return -1;
    }
    void prepend(int data)
    {
        Node *toAdd = new Node(data);
        toAdd->next = this->head;
        this->head = toAdd;
    }

    void insert(int data, int index)
    {
        if (this->isEmpty() || index >= this->size())
        {
            cout << "Could not be inserted! Please check the INDEX" << endl;
        }
        else
        {
            Node *toAdd = new Node(data);
            Node *ptr = this->head;
            while (index-- > 1)
            {
                ptr = ptr->next;
            }
            toAdd->next = ptr->next;
            ptr->next = toAdd;
        }
    }

    void delet(int index)
    {
        Node *ptr = this->head;
        while (index-- > 1)
        {
            ptr = ptr->next;
        }
        Node *ptr2 = ptr->next;
        ptr->next = ptr2->next;
        ptr2->next = NULL;
    }

    bool isEmpty()
    {
        if (this->head == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int size()
    {
        Node *ptr = this->head;
        int s = 1;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
            s++;
        }
        return s;
    }

    void printlist()
    {
        Node *ptr = head;
        while (ptr->next != NULL)
        {
            cout << ptr->data << " -> ";
            ptr = ptr->next;
        }
        cout << ptr->data <<" -> NULL" << endl;
    }

    void reverselist()
    {
        Node *curr = this->head;
        Node *prev = NULL;
        Node *next = this->head->next;
        while (next != NULL)
        {
            curr->next = prev;
            prev = curr;
            curr = next;
            next = next->next;
        }
        curr->next=prev;
        this->head = curr;
    }
    void remove_duplicate_form_sorted_ll()
    {
        Node *ptr = this->head;
        while (ptr->next->next != NULL)
        {
            if (ptr->data == ptr->next->data)
            {
                ptr->next = ptr->next->next;
            }
            else
            {
                ptr = ptr->next;
            }
        }
        if(ptr->data == ptr->next->data){
            ptr->next=NULL;
        }
    }

    void selection_sort(){
        Node* ptr1=this->head;
        Node *ptr2;
        while(ptr1 ->next != NULL){
            ptr2=ptr1->next;
            while(ptr2 != NULL){
                if(ptr1->data > ptr2->data){
                    int temp=ptr1->data;
                    ptr1->data=ptr2->data;
                    ptr2->data=temp;
                }
                ptr2=ptr2->next;
            }
            ptr1=ptr1->next;
        }
    }
    
};

int main()
{
    Node puneet;
    // cout<<puneet.data<<endl;
    Node pun(25);
    // cout<<pun.data<<endl;
    SinglyLinkedList l1;
    Node *p = &pun;
    SinglyLinkedList l2(p);
    l2.append(5);
    l2.append(5);
    l2.append(6);
    l2.append(6);
    l2.append(6);
    l2.append(6);
    l2.append(98);
    l2.append(98);
    l2.append(98);
    l2.append(98);
    l2.printlist();
    // l2.reverselist();
    // l2.printlist();
    // l2.insert(55,2);
    // l2.delet(0);
    l2.selection_sort();
    l2.printlist();


    return 0;
}