#include<iostream>
using namespace std;

int main(){
    int arr[5]={1,2,5,6,9};
    int arr1[7]={4,5,6,8,9,11,12};
    int i=0,j=0,k=0;
    int temp[12];
    while(i<5 && j<7){
        if(arr[i] < arr1[j]){
            temp[k]=arr[i];
            k++;
            i++;
        }
        else{
            temp[k]=arr1[j];
            j++;
            k++;
        }
    }
    while(i<5){
        temp[k]=arr[i];
        k++;
        i++;
    }
    while(j<7){
        temp[k]=arr1[j];
        k++;
        j++;
    }
    for(int p=0;p<12;p++){
        cout<<temp[p]<<" ";
    }
    return 0;
}