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
#define gs 5

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


template <typename T>
class Node{
public:
	T data;
	Node* left;
	Node* right;
	Node(){
		this->left=NULL;
		this->right=NULL;
	}
	Node(T val){
		this->data=val;
		this->left=NULL;
		this->right=NULL;
	}
	Node(Node<T>* n){
		this->data=n->data;
		this->left=n->left;
		this->right=n->right;
	}
};

template <typename T>
class AVLTree{
private:
	int getBalancedFactor(Node<T>* node){
		if(node==NULL)return 0;
		int lh=height(node->left);
		int rh=height(node->right);
		return lh-rh;
	}

	Node<T>* rightRotate(Node<T>* node){
		Node<T>* y=node;
		Node<T>* x=node->left;
		Node<T>* t2=node->left->right;

		x->right=y;
		y->left=t2;
		return x;
	}

	Node<T>* leftRotate(Node<T>* node){
		Node<T>* x=node;
		Node<T>* y=node->right;
		Node<T>* t2=node->right->left;

		y->left=x;
		x->right=t2;
		return y;
	}
	int getmin(Node<T>* node){
		while(node->left != NULL){
			node=node->left;
		}
		return node->data;
	}
public:
	Node<T> *root;
	AVLTree(){
		root=NULL;
	}
	AVLTree(Node<T> *n){
		this->root=n;
	}
	AVLTree (int val){
		Node<T> *n=new Node<T>(val);
		this->root=n;
	}

	int height(Node<T>* node){
		if(node==NULL)return 0;
		int lh=height(node->left);
		int rh=height(node->right);
		return 1+max(lh,rh);
	}


	Node<T>* insert(Node<T>* node,T val){
		if(node==NULL){
			Node<T> *toadd=new Node<T>(val);
			return toadd;
		}
		if(val > node->data){
			node->right=insert(node->right,val);
		}
		else if(val < node->data){
			node->left=insert(node->left,val);
		}
		

		int bf=getBalancedFactor(node);
		if(bf>1 && val < node->left->data){
			node=rightRotate(node);
		}
		else if(bf < -1 && val > node->right->data){
			node=leftRotate(node);
		}
		else if(bf>1 && val > node->left->data){
			node->left=leftRotate(node->left);
			node=rightRotate(node);
		}
		else if(bf<-1 && val< node->right->data){
			node->right=rightRotate(node->right);
			node=leftRotate(node);
		}
		return node;
	}

	Node<T>* delet(Node<T>* node,T key){
		if(node==NULL)return NULL;
		if(key > node->data){
			node->right=delet(node->right,key);
		}
		else if(key < node->data){
			node->left=delet(node->left,key);
		}		
		else{
			if(node->left == NULL && node->right==NULL)return NULL;
			else if(node->left == NULL)return node->right;
			else if(node->right==NULL)return node->left;
			else{
				int mn=getmin(node->right);
				node->data=mn;
				node->right=delet(node->right,mn);
			}
		}

		int bf=getBalancedFactor(node);
		if(bf==2 && getBalancedFactor(node->left) >=0 ){
			node=rightRotate(node);
		}
		else if(bf==2 && getBalancedFactor(node->left)==-1){
			node->left=leftRotate(node->left);
			node=rightRotate(node);
		}
		else if(bf==-2 && getBalancedFactor(node->right) <=0){
			node=leftRotate(node);
		}
		else if(bf==-2 && getBalancedFactor(node->right)==1){
			node->right=rightRotate(node->right);
			node=leftRotate(node);
		}
		return node;
	}

	bool search(Node<T>* node,T key){
		if(node==NULL)return false;
		if(node->data == key)return true;
		else if(node->data > key)return search(node->left,key);
		else return search(node->right,key);
	}

};
 void printtreein2d(Node<int>* r,int space){
        if(r== NULL)return ;
        space+=gs;
        printtreein2d(r->right,space);
        cout<<endl;
        for(int i=gs;i<=space;i++)cout<<" ";
        cout<<r->data<<endl;
        printtreein2d(r->left,space);
    }






int main(){
	clock_t begin=clock();
	file_input_output();


	int t=0;
	//cin>>t;t--;
	do{
		AVLTree<int>mytree;
		// mytree.height(mytree.root);	
		mytree.root=mytree.insert(mytree.root,30);
		mytree.root=mytree.insert(mytree.root,20);
		mytree.root=mytree.insert(mytree.root,10);
		mytree.root=mytree.insert(mytree.root,40);
		mytree.root=mytree.insert(mytree.root,50);
		mytree.root=mytree.delet(mytree.root,10);

		cout<<mytree.search(mytree.root,100)<<endl;
		printtreein2d(mytree.root,5);
	}while(t--);



	#ifndef ONLINE_JUDGE
		clock_t end=clock();
		cout<<"\n\nFinished in "<<double(end-begin)/CLOCKS_PER_SEC*1000<<" ms";
	#endif 

	return 0;
}