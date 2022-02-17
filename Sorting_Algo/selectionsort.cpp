#include<iostream>
using namespace std;

void selectionsort(int arr[]){
    int len=7;
    for(int i=0;i<len-1;i++){
        for(int j=i+1;j<len;j++){
            if(arr[i] > arr[j]){
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
}

int main(){
    int arr[7]={5,6,7,4,11,8,2};
    selectionsort(arr);
    for(int i=0;i<7;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}