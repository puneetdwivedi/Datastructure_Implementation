#include<iostream>
using namespace std;
// array partinoning 
int partition(int arr[],int l,int h){
    int pivot=arr[h];
    int i=l;
    int j=l;
    while(i<h){
        if(arr[i] <= pivot){
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            j++;
            i++;
        }
        else{
            i++;
        }
    }
    int temp=arr[j];
    arr[j]=arr[h];
    arr[h]=temp;
    return (j);
}
// quick sort algorithm
void quicksort(int arr[],int l,int r){
    if(l<r){
        int pivot_index=partition(arr,l,r);
        quicksort(arr,l,(pivot_index-1));
        quicksort(arr,(pivot_index+1),r);
    }
}
int main(){
    int arr[9]={9,8,1,3,7,2,6,4,5};
    // int x=partition(arr,0,8);
    // cout<<x<<endl;
    // for(int i=0;i<9;i++){
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;
    quicksort(arr,0,8);
    for(int k=0;k<9;k++){
        cout<<arr[k]<<" ";
    }
    return 0;
}