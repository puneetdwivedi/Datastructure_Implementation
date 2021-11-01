#include<iostream>
using namespace std;

template <typename T>
class Mystack{
	T *arr;
	int sze;
	int tp;
public:
	Mystack(){
		this->sze=5;  // taking the initial size as 5 can also be taken something else
		this->tp=-1;
		this->arr=new T[this->sze];

	}

	bool empty(){
		return (this->tp==-1)?true:false;  
	}

	int size(){
		return (this->tp+1);
	}

	T top(){
		if(empty()) T(NULL);  // retrun null when stack is empty
		return this->arr[this->tp];
	}
	void push_back(T x){
		this->tp++;

		// if stack is full then double the size
		if(this->tp == this->sze){
			int oldsze=this->sze;
			T * oldarr=new T[oldsze];
			for(int i=0;i<oldsze;i++){
				oldarr[i]=arr[i];
			}
			this->sze*=2;
			this->arr=new T[this->sze];
			for(int i=0;i<oldsze;i++){
				arr[i]=oldarr[i];
			}
		}

		this->arr[this->tp]=x;
	}

	T pop_back(){
		if(empty())return T(NULL); // return null when no element is there to delet
		this->tp--;
		return this->arr[(this->tp)+1];
	}

	void display(){
		for(int i=tp;i>=0;i--){
			cout<<"|  "<<this->arr[i]<<"   |"<<endl;
		}
		cout<<"---------"<<endl<<endl;
	}

};



int main(){

	#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
    Mystack<int>st;
    // cout<<st.empty()<<endl;
    // cout<<st.size()<<endl;
    // cout<<st.top()<<endl;
    st.push_back(56);
    st.push_back(98);
    st.push_back(99);
    st.push_back(97);
    st.push_back(23);
    st.push_back(29);
    st.push_back(90);
    st.push_back(80);
    st.push_back(95);
   cout<<st.size()<<endl;
   st.display();
   st.pop_back();
   cout<<st.size()<<endl;
   st.display();
   cout<<st.top();
	return 0;
}

/*
Stack :: LIFO(Last In First Out)
	  :: FILO(First In Last Out)		
empty() : tell whether stack is empty or not
size()  : return size of the stack 
top()	: return top of the stack
push_back() : push the element in the stack at the top
pop_back() : pop the element from top of the stack
*/