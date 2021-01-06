#include<iostream>
using namespace std;

class Stack{
    int size;
    int *ptr=new int [size];
    int top;
    public:
        Stack(int s){
            size=s;
            top=-1;
        }

        bool isEmpty(){
            if(top==-1){
                return true;
            }
            else{
                return false;
            }
        }
        bool isFull(){
            if(top == (size-1)){
                return true;
            }
            else{
                return false;
            }
        }
        void push(int val){
            if(isFull()){
                cout<<"This is overflow condition ";
            }
            else{
                top++;
                ptr[top]=val;
            }
        }

        int pop(){
            if(isEmpty()){
                cout<<"This is underflow condition ";
                return -1;
            }
            else{
                int el=ptr[top];
                ptr[top]=0;
                top--;
                return el;
            }
        }

        int peek(int index){
            return ptr[index];
        }

        int count(){
            return (top+1);
        }
        void display(){
            for(int i=top;i>=0;i--){
                cout<<ptr[i]<<endl;
            }
        }

        void change(int index,int value){
            if(index>=size){
                cout<<"index out of bond exception";
            }
            else{
                ptr[index]=value;
            }
        }
};

int main(){
    Stack s(5);
    cout<<s.isEmpty()<<endl;
    s.push(3);
    s.push(5);
    s.push(6);
    s.push(9);
    s.push(10);
    cout<<s.isFull()<<endl;
    s.display();
    s.pop();
    cout<<s.count()<<endl;
    s.change(1,9);
    return 0;
}