#include<iostream>
#define gs 8
using namespace std;
template<typename T>
class Node{
    public:
    T data;
    Node<T>* left;
    Node<T>* right;
    Node(){
        this->left=NULL;
        this->right=NULL;
    }
    Node(int x){
        this->data=x;
        this->left=NULL;
        this->right=NULL;
    }
    Node(T x,Node<T>* left,Node<T>* right){
        this->data=x;
        this->left=left;
        this->right=right;
    }
};

template<typename T>
class Tree{
    public:
    Node<T>* root;
    Tree(){
        this->root=NULL;
    }
    Tree(T x){
        this->root->data=x;
        this->root->left=NULL;
        this->root->right=NULL;
    }
    Tree(Node<T> * n){
        this->root=n;
    }

    // to check whether the tree is empty or not 
    bool isEmpty(){
        if(root ==NULL) return true;
        return false;
    }
    // if insertion is successful then return true if duplicate entries are present then rtrn falseand do not insert
    bool insert(T x){
        if(this->root==NULL){
            Node<T> * toAdd=new Node<T>(x);
            this->root=toAdd;
            return true;
        }
        Node<T>* ptr=this->root;
        Node<T> * toAdd=new Node<T>(x);
        while(ptr != NULL){
            if(ptr->data ==x){
                return false;
            }
            else if(ptr->data > x && ptr->left == NULL ){
                ptr->left=toAdd;
                return true;
            }
            else if(ptr->data >x){
                ptr=ptr->left;
            }
            else if(ptr->data < x && ptr->right == NULL){
                ptr->right=toAdd;
                return true;
            }
            else{
                ptr=ptr->right;
            }
        }
        return true;
    }
    //DFS
    // preorder traversal (NLR)
    void preorder_traversal(Node<T> *r){
        if(r ==NULL)return;
        cout<<r->data<<" ";
        preorder_traversal(r->left);
        preorder_traversal(r->right);
    }

    // postorder traversal (LRN)
    void postorder_traversal(Node<T> *r){
        if(r== NULL) return ;
        postorder_traversal(r->left);
        postorder_traversal(r->right);
        cout<<r->data<<" ";
    }

    // inorder traversal (LNR)
    void inorder_traversal(Node<T> *r){
        if(r== NULL) return ;
        inorder_traversal(r->left);
        cout<<r->data<<" ";
        inorder_traversal(r->right);
    }

    Node<T> * searchintree(T x){
        if(this->root == NULL)return NULL;
        Node<T>* ptr=root;
        while(ptr != NULL){
            if(ptr->data== x)return ptr;
            else if(ptr->data > x){
                ptr=ptr->left;
            }
            else{
                ptr=ptr->right;
            }
        }
        return NULL;
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

    int height(Node<T>* r){
        if(r == NULL)return -1;
        int lh=height(r->left);
        int rh=height(r->right);
        if(lh > rh){
            return lh+1;
        }
        else{
            return rh+1;
        }
    }
};

int main(){
    Node<int>n;
    n.data=90;
    Tree<int>mytree;
    for(int i=0;i<10;i++){
        int x;cin>>x;
        mytree.insert(x);
    }
    // mytree.preorder_traversal(mytree.root);
    // cout<<endl;
    // mytree.postorder_traversal(mytree.root);
    // cout<<endl;
    /*
    if(mytree.searchintree(5)== NULL){
        cout<<-1;
    }
    else{
        cout<<5;
    }
    cout<<endl;
    */
   mytree.printtreein2d(mytree.root,10);
   cout<<endl;
   cout<<mytree.height(mytree.root);
    return 0;
}