// Problem Link: 
/* Puneet Dwivedi */

#include<bits/stdc++.h>
using namespace std;
#define loop(i,l,h) for(int i=l;i<h;i++)
#define logarr(arr,a,b)	for(int z=(a);z<(b);z++) cout<<(arr[z])<<" ";cout<<endl;
#define endl "\n"
#define mod  1000000007
typedef long long int ll;
typedef long double ld;

void file_input_output(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif // ONLINE_JUDGE
}

/* ***************************************************** */

class Heap{
	int *arr;
	int el;
	int sz;
public:
	Heap(int n){
		this->el=0;
		this->sz=n;
		this->arr=new int[n];
	}

	int size(){
		return this->el;
	}

	bool empty(){
		if(this->el==0)return true;
		return false;
	}

	void insert(int val){
		if(el>=sz){
			return;			
		}
		else{
			this->arr[el]=val;
		}
		int i=el;
		while(i !=0 && arr[i/2] >arr[i] ){
			swap(arr[i/2],arr[i]);
			i/=2;
		}
		this->el++;
	}

	// return the min element as it is min heap
	int  extract(){
		return this->arr[0];
	}

	void delet(){
		swap(arr[0],arr[el-1]);
		el--;
		minheapify(0);
	}


	void minheapify(int ind){
		if(ind >=el)return;
		int lc=2*ind+1;
		int rc=2*ind+2;
		int sm=ind;
		if(lc < el  && arr[lc] < arr[sm])sm=lc;
		if(rc <el && arr[rc] < arr[sm])sm=rc;
		if(sm != ind){
			swap(arr[sm],arr[ind]);
			minheapify(sm);
		}
	}
	void show(){
		for(int i=0;i<this->el;i++){
			cout<<this->arr[i]<<" ";
		}
		cout<<endl;
	}
};



int main(){
	clock_t begin=clock();
	file_input_output();


	int t=0;
	//cin>>t;t--;
	do{
		
		Heap hp(10);
		hp.insert(50);
		hp.insert(45);
		hp.insert(95);
		hp.insert(68);
		hp.insert(25);
		hp.show();
		cout<<hp.extract()<<endl;
		hp.delet();		
		hp.show();
	}while(t--);



	#ifndef ONLINE_JUDGE
		clock_t end=clock();
		cout<<"\n\nFinished in "<<double(end-begin)/CLOCKS_PER_SEC*1000<<" ms";
	#endif 

	return 0;
}