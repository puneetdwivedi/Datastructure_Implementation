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
	Node(T val,Node* l,Node* r){
		this->data=val;
		this->left=l;
		this->right=r;
	}

};


// binary search tree class
template <typename T>
class BST{
private:
	Node<T>* findlastright(Node<T>*node){
		if(node->right==NULL)return node;
		return findlastright(node->right);
	}
	Node<T>* helper(Node<T>* node){
		if(node->left ==NULL)return node->right;
		else if(node->right ==NULL)return node->left;
		else{
			Node<T>* lastrightchild=findlastright(node->left);
			lastrightchild->right=node->right;
			return node->left;
		}
	}
public:
	Node<T>* root;
	BST(){
		this->root=NULL;
	}
	BST(T val){
		Node<T>*toadd=new Node<T>(val);
		this->root=toadd;
	}
	BST(Node<T>* n){
		this->root=n;
	}

	// methods
	void insert(T val){
		Node<T>* toadd=new Node<T>(val);
		if(this->root==NULL){
			this->root=toadd;
			return;
		} 
		Node<T>* ptr=this->root;
		while(ptr!= NULL){
			if(ptr->data <val){
				if(ptr->right ==NULL){
					ptr->right=toadd;
					return;
				}
				else ptr=ptr->right;
			}
			else{
				if(ptr->left == NULL){
					ptr->left=toadd;
					return ;
				}
				else ptr=ptr->left;
			}
		}
	}

	bool search(T val){
		if(this->root==NULL)return false;
		Node<T>* ptr=this->root;
		while(ptr != NULL){
			if(ptr->data==val)return true;
			ptr=(ptr->data > val)?ptr->left:ptr->right;
		}
		return false;
	}

	void preorder(Node<T>* r){
		if(r==NULL)return;
		cout<<r->data<<" ";
		preorder(r->left);
		preorder(r->right);
	}

	void inorder(Node<T>* r){
		if(r==NULL)return;
		inorder(r->left);
		cout<<r->data<<" ";
		inorder(r->right);
	}

	void delet(int key){
		if(this->root == NULL)return;
		if(this->root->data == key){
			this->root=helper(root);
		}
		Node<T>* node=root;
		while(node != NULL){
			if(node->data > key){
				if(node->left != NULL && node->left->data==key){
					node->left=helper(node->left);
					break;
				}
				else node=node->left;
			}
			else {
				if(node->right != NULL && node->right->data == key){
					node->right=helper(node->right);
					break;
				}
				else node=node->right;
			}
		}
	}

	int height(Node<T> *node){
		if(node==NULL)return 0;
		int left_height=height(node->left);
		int right_height=height(node->right);
		return 1+(max(left_height,right_height));
	}

	 void printtreein2d(Node<T>* r,int space){
        if(r== NULL)return ;
        space+=gs;
        printtreein2d(r->right,space);
        cout<<endl;
        for(int i=gs;i<=space;i++)cout<<" ";
        cout<<r->data<<endl;
        printtreein2d(r->left,space);
    }
};

template <typename T>
class BSTIterator{
private:
	stack<Node<T>*>st;
	bool forward;
public:
	BSTIterator(Node<T>* root,bool type=true){
		this->forward=type;
		pushall(root);
	}
	bool hasnext(){
		if(st.empty())return false;
		return true;
	}

	Node<T>* next(){
		Node<T>* node=NULL;
		if(hasnext()){
			node=st.top();
			st.pop();
			if(forward) pushall(node->right);
			else pushall(node->left); 
		}
		return node;
	}

private:
	void pushall(Node<T>* node){
		while(node != NULL){
		 	st.push(node);
		 	if(forward)node=node->left;
		 	else node=node->right;
		}
	}
};


int main(){
	clock_t begin=clock();
	file_input_output();


	int t=0;
	//cin>>t;t--;
	do{
		BST<int> mytree;
		mytree.insert(14);
		mytree.insert(7);
		mytree.insert(6);
		mytree.insert(15);
		mytree.insert(12);
		mytree.preorder(mytree.root);
		cout<<endl;
		// mytree.delet(8);
		mytree.preorder(mytree.root);
		cout<<endl;
		mytree.inorder(mytree.root);
		cout<<endl;
		cout<<mytree.search(15)<<endl;
		cout<<mytree.height(mytree.root)<<endl;
		mytree.printtreein2d(mytree.root,5);

		BSTIterator<int> it(mytree.root,false);

		while(it.hasnext()){
			Node<int>* curr=it.next();
			cout<<curr->data<<" ";
		}
	}while(t--);



	#ifndef ONLINE_JUDGE
		clock_t end=clock();
		cout<<"\n\nFinished in "<<double(end-begin)/CLOCKS_PER_SEC*1000<<" ms";
	#endif 

	return 0;
}