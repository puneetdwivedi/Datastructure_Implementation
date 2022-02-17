#include<iostream>
using namespace std;


int main(){
    int arr[7]={1,9,7,3,5,8,0};
    // insertion sort
    for(int i=0;i<7;i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
    }    
    for(int i=0;i<7;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}