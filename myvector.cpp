#include<iostream>
using namespace std;

template<typename T>
class Myvector{
    int last=-1;
    int size;
    int *arr;
    // public membres
    public:
    Myvector(){
        this->size=5;
        this->arr=new int[this->size];
        this->last=0;
        for(int i=0;i<this->size;i++){
            arr[i]=char(0);
        }
    }
    Myvector(int n){
        this->size=n;
        this->arr=new int[this->size];
        this->last=0;
        for(int i=0;i<this->size;i++){
            this->arr[i]=char(0);
        }
    }
    Myvector(int n,T val){
        this->size=n;
        this->arr=new int[this->size];
        this->last=0;
        for(int i=0;i<this->size;i++){
            this->arr[i]=val;
        }
    }
    // empty() method to check whether the vector is empty or not
    bool empty(){
        if(this->last==0)return true;
        return false;
    }

    // back()  
    T back(){
        return this->arr[this->last-1];
    }

    // size()
    int length(){
        return this->last;
    }

    // maxsize()
    int maxsize(){
        return this->size;
    }
    // push_back() add at last
    void push_back(T x){
        if(this->last >= this->size ){
            int oldsize=this->size;
            this->size*=2;
            int old_arr[oldsize];
            for(int i=0;i<oldsize;i++){
                old_arr[i]=this->arr[i];
            }
            this->arr=new int[size];
            for(int i=0;i<oldsize;i++){
                this->arr[i]=old_arr[i];
            }
            // cout<<"Size increased after addition of "<<x<<endl;
        }
        this->arr[this->last]=x;
        last++;
    }

    // removes the last element
    void pop_back(){
        if(last==0)return;
        this->arr[this->last-1]=char(0);
        last--;
    }

    // insert()
    void insert(T val,int ind){
        if(this->last >= this->size){
            int oldsize=this->size;
            this->size*=2;
            int old_arr[oldsize];
            for(int i=0;i<oldsize;i++){
                old_arr[i]=this->arr[i];
            }
            this->arr=new int[size];
            for(int i=0;i<oldsize;i++){
                this->arr[i]=old_arr[i];
            }
        }
        for(int i=last;i>ind;i--){
            this->arr[i]=this->arr[i-1];
        }
        this->arr[ind]=val;
        this->last++;
    }

    // erase()  
    void erase(int ind){
        for(int i=ind;i<last-1;i++){
            this->arr[i]=this->arr[i+1];
        }
        this->arr[last-1]=char(0);
        this->last--;
    }

    // clear()

    void clear(){
        for(int i=0;i<this->last;i++){
            this->arr[i]=char(0);
        }
        this->last=0;
    }
    // print the vector
    void print(){
        for(int i=0;i<this->last;i++){
            cout<<this->arr[i]<<" ";
        }
        cout<<endl;
    }

};
int main(){
    Myvector<int>mv;

    mv.push_back(50);
    mv.push_back(5);
    mv.push_back(98);
    mv.push_back(47);
    mv.push_back(37);
    mv.push_back(50);
    mv.push_back(5);
    mv.push_back(98);
    mv.push_back(47);
    mv.push_back(37);
    mv.print();
    cout<<"The current size of the mv is "<<mv.length()<<endl;
    mv.pop_back();
    mv.insert(999,2);
    cout<<"The current size of the mv is "<<mv.length()<<endl;
    mv.insert(999,3);
    // mv.erase(3);
    mv.print();
    cout<<"The current size of the mv is "<<mv.length()<<endl;
    mv.clear();
    cout<<"The current size of the mv is "<<mv.length()<<endl;

    return 0;
}