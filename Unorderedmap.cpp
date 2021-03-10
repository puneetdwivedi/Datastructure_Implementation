#include<iostream>
#include<math.h>
#include<string>
using namespace std;
#define ll long long int

template<typename T>
class Node{
public:
    string key;
    T value;
    Node* next;
    Node(string key,T value){
        this->key=key;
        this->value=value;
        this->next=NULL;
    }
};

template<typename T>
class HashTable{
    int size;
    int maxsize;
public:
    Node<T> **arr;
    HashTable(){
        size=0;
        maxsize=2;
        arr=new Node<T>*[this->maxsize];
        for(int i=0;i<this->maxsize;i++){
            arr[i]=NULL;
        }
    }
    int size(){
        return this->size;
    }
    int maxsize(){
        return this->maxsize;
    }
    int hashfunction(string key){
        int bi=0;
        for(int i=0;i<key.size();i++){
            int ma=pow(13.0,float(i));
            ma%=this->maxsize;
            bi+=ma;
        } 
        bi%=this->maxsize;
        return bi;
    }

    void rehashing(){
        int oldsize=this->maxsize;
        this->maxsize=2*oldsize;
        Node<T>** old_arr=this->arr;
        this->arr=new Node<T>*[this->maxsize];
        for(int i=0;i<this->maxsize;i++){
            this->arr[i]=NULL;
        }
        for(int i=0;i<oldsize;i++){
            Node<T>* ptr=old_arr[i];
            while(ptr != NULL){
                insert(ptr->key,ptr->value);
                ptr=ptr->next;
            }
        }
    }
    void insert(string key,T value){
        int bi=hashfunction(key);
        Node<T>* ptr=this->arr[bi];
        Node<T>* toAdd=new Node<T>(key,value);
        if(arr[bi] == NULL){
            arr[bi]=toAdd;
        }
        else{
            toAdd->next=arr[bi];
            arr[bi]=toAdd;
        }
        size++;
        if(float(this->size)/(this->maxsize) >= 0.8 ){
            rehashing();
        }
    }
    T search(string key){
        int bi=hashfunction(key);
        Node<T>* ptr=this->arr[bi];
        while(ptr != NULL){
            if(ptr->key == key){
                return ptr->value;
            }
            ptr=ptr->next;
        }
        return -1;
    }
    void delet(string key){
        if(search(key) != -1){
            int bi=hashfunction(key);
            Node<T>* ptr=this->arr[bi];
            if(ptr->key == key){
                this->arr[bi]=ptr->next;
            }
            else{
                while(ptr->next->key != key){
                    ptr=ptr->next;
                }
                ptr->next=ptr->next->next;
            }
        }
    }
    void display(){
        for(int i=0;i<this->maxsize;i++){
            if(this->arr[i] == NULL){
                cout<<"\n";
            }
            else{
                Node<T>* ptr=this->arr[i];
                while(ptr != NULL){
                    cout<<"("<<ptr->key<<","<<ptr->value<<")->";
                    ptr=ptr->next;
                }
                cout<<endl;
            }
        }
    }

};

int main(){
    HashTable<int> ht;
    ht.insert("apple",50);
    ht.insert("puneet",49);
    ht.insert("dwivedi",25);
    ht.insert("nikhil",275);
    ht.insert("ape",65);
    ht.insert("neet",49);
    ht.insert("dvedi",285);
    ht.insert("bla bla ",5);
    // cout<<ht.search("appe");
    ht.display();
    // cout<<ht.maxsize<<endl;
    // cout<<ht.size<<endl;
    ht.delet("ape");
    cout<<"After deleting\n";
    ht.display();
    return 0;
}