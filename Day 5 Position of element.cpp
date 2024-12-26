#include <iostream>
using namespace std;

int main(){

    
    int n,k;
    cin>>k;
    cin>>n;
    int arr[n];

    for(int i=0;i<n;i++){

        cin>>arr[i];
    }
    
     int count=0;

     for(int j=0;j<n;j++){
         if(arr[j]==k){
             count++;
          }

     }
    cout<<count;
    return 0;
} 
