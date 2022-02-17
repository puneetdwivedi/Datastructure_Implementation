#include<iostream>
using namespace std;

int main(){
    int searchingnum=90;
    int index=-1;
    // Linear Search
    int arr[8]={5,6,7,2,3,11,4,55};
    for(int i=0;i<8;i++){
        if(arr[i] == searchingnum){
            index=i;
            break;
        }
    }
    //Binary Search
    int myarr[8]={34,56,67,68,76,78,89,90};
    int left=0,right=7;
    while(left <= right){
        int mid=(left+right)/2;
        if(myarr[mid]==searchingnum){
            index=mid;
            break;
        }
        else if(myarr[mid] < searchingnum){
            left=mid+1;
        }
        else{
            right=mid-1;
        }
    }
    cout<<myarr[index]<<" is at index "<<index;
    return 0;
}