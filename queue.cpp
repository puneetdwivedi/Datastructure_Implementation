#include<iostream>
using namespace std;

class queue{
    int arr[5];
    int front;
    int rear;
    public:
        queue(){
            front=-1;
            rear=-1;
        }
        bool empty(){
            if(rear==-1){
                return true;
            }
            else{
                return false;
            }
        }
        
        bool full(){
            if(size() == 4){
                return true;
            }
            else{
                return false;
            }
        }

        int first(){
            if(empty()){
                return -1;         
            }
            else{
                return arr[front];
            }
        }
        int last(){
            if(empty()){
                return -1;         
            }
            else{
                return arr[rear];
            }
        }
        int size(){
            if(empty()){
                return 0;
            }
            else{
                return ((rear-front)+1);
            }
        }
        void push(int x){
            if(empty()){
                rear=0;
                front=0;
            }
            else if(rear == 4){
                cout<<"Overflow condition";
                return;
            }
            else{
                rear++;
            }
            arr[rear]=x;
            
        }
        void pop(){

            if(size() == 0){
                cout<<"underflow condition";
                return;
            }
            else{
                arr[front]=-1;
                front++;;
            }
        }
};

int main(){
    queue q1;
    int x=4;
    cout<<"Enter the value you want to enter"<<endl;
    while(x-->0){
        int y;
        cin>>y;
        q1.push(y);
    }
    
    q1.pop();
    cout<<q1.size()<<endl;
    cout<<q1.first()<<endl<<q1.last()<<endl;
    cout<<q1.full();
    return 0;
}