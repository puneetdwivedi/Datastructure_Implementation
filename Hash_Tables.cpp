#include<iostream>
#include<math.h>
#include<string>
using namespace std;

template<typename T>
class Node{
public:
	string key;
	T value;
	Node(string key,T value){
		this->key=key;
		this->value=value;
	}
};

template<typename T>
class HashTable{
	int size;
	int maxSize;
	int hashfunction(string key){
		int bi=0;
		for(int i=0;i<key.size();i++){
			int ma=((int)key[i]);
			ma*=(pow(11.0,i));
			ma%=this->maxSize;
			bi+=ma;
		}
		bi%=this->maxSize;
		return bi;
	}
public:
	Node<T>** arr;
	HashTable(){
		this->size=0;
		this->maxSize=5;
		arr=new Node<T>*[this->maxSize];
		for(int i=0;i<this->maxSize;i++){
			this->arr[i]=NULL;
		}
	}

	int Size(){
		return this->size;
	}

	int maxsize(){
		return this->maxSize;
	}

	void insert(string key,T value){
		if(search(key)==-1){
			int bi=hashfunction(key);
			Node<T>* toadd=new Node<T>(key,value);

			if(this->arr[bi]==NULL){
				this->arr[bi]=toadd;
				size++;
			}
			else{
				for(int i=bi+1;i%this->maxSize != bi;i++){
					if(this->arr[i%this->maxSize]==NULL){
						this->arr[i%this->maxSize]=toadd;
						size++;break;
					}
				}
			}
			if(float(this->size)/(this->maxSize) >= 0.8 )rehashing();
			// if( ((float)(this->size))/this->maxSize > 0.7 )rehashing();
		}

	}

	void rehashing(){
		int oldsize=this->maxSize;
		this->maxSize*=2;
		Node<T>** oldarr=this->arr;
		this->size=0;
		this->arr=new Node<T>*[this->maxSize];
		for(int i=0;i<this->maxSize;i++){
            this->arr[i]=NULL;
        }
        for(int i=0;i<oldsize;i++){
        	if(oldarr[i] != NULL){
        		insert(oldarr[i]->key,oldarr[i]->value);
        	}
        }
	}

	int search(string key){
		int bi=hashfunction(key);
		if(this->arr[bi] != NULL &&this->arr[bi]->key == key)return this->arr[bi]->value;
		else{
			for(int i=bi+1;i%this->maxSize != bi;i++){
				if(this->arr[i%this->maxSize] != NULL && this->arr[i%this->maxSize]->key == key){
					return this->arr[i%this->maxSize]->value;
				}
			}
		}
		return -1;
	}

	void delet(string key){
		if(search(key) != -1){
			int bi=hashfunction(key);
			if(this->arr[bi]->key == key) this->arr[bi]=NULL;
			else{
				for(int i=bi+1;i%this->maxSize != bi;i++){
					if(this->arr[i%this->maxSize]->key == key){
						this->arr[i%this->maxSize]=NULL;
					}
				}
			}

		}
	}

	void display(){
		cout<<"***********"<<endl;
		for(int i=0;i<this->maxSize;i++){
			if(this->arr[i]== NULL)
				cout<<endl;
			else
				cout<<"("<<this->arr[i]->key<<","<<this->arr[i]->value<<")"<<endl;
		}
		cout<<"***********"<<endl;

	}

};
int main(){

	HashTable<int>ht;
	ht.insert("Puneet",18);
	ht.insert("m",989);
	ht.insert("pd",456);
	ht.insert("pd1",458);
	ht.insert("p1",458);
	ht.display();
	// ht.delet("pd");
	// ht.display();
	cout<<ht.search("pd")<<endl;

	cout<<"size ==>"<<ht.Size()<<endl;

	return 0;
}



