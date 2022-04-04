#include <vector>
using namespace std;
#include <iostream>



vector<int> bubblesort(vector<int> &arr){
    int noOfSwapsInAnIteration=1;
    int n=arr.size();
    while (noOfSwapsInAnIteration!=0){
        noOfSwapsInAnIteration=0;
        for (int i=0;i<n-1;i++){
            if (arr[i]>arr[i+1]){
                int temp=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
                noOfSwapsInAnIteration+=1;
            }

        }

    }
    return arr;
}

int main(){
    vector<int> arr={8,9,3,4,6,5,1};
    vector<int> a=bubblesort(arr);
    for (int i:a){
        cout<<i<<" ";
    }

    return 0;
}