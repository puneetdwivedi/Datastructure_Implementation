#include<iostream>
using namespace std;
void merge(int arr[],int l,int m,int h){
    int i=l;
    int j=m+1;
    int k=l;
    int temp[h+1];
    while(i<=m && j<=h){
        if(arr[i]<arr[j]){
            temp[k]=arr[i];
            k++;
            i++;
        }
        else{
            temp[k]=arr[j];
            j++;
            k++;
        }
    }
    while(i<=m){
        temp[k]=arr[i];
        k++;
        i++;
    }
    while(j<=h){
       temp[k]=arr[j];
        j++;
        k++; 
    }
    for(int p=l;p<=h;p++){
        arr[p]=temp[p];
    }

}
void mergesort(int arr[],int l,int h){
    if(l<h){
        int m=(l+h)/2;
        mergesort(arr,l,m);
        mergesort(arr,m+1,h);
        merge(arr,l,m,h);
    }
}

int  main(){
    int arr[10]={2,5,7,3,5,8,2,1,7,9};
    mergesort(arr,0,9);
    for(int i=0;i<10;i++){
        cout<<arr[i]<<" ";
    }

    // int arr[10]={1,5,3,7,9,2,4,6,8,10};
    // merge(arr,1,2,3);
    // for(int i=0;i<10;i++){
    //     cout<<arr[i]<<" ";
    // }

    

    return 0;
}