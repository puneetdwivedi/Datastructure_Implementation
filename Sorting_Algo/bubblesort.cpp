#include<iostream>
using namespace std;

int main(){
    int arr[7]={3,11,8,7,2,4,1};
    for(int i=0;i<6;i++){
        for(int j=0;j<6-i;j++){
            if(arr[j] > arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    for(int i=0;i<7;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}