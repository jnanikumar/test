#include <vector>
#include <iostream>
// #include <bits/stdc++.h>
using namespace std;

int shortDistanceInGrid(vector<vector<int>> &a)
{
    int n=a.size();
    int m=a[0].size();
    vector<vector<int>> dp;
    for (int i=1;i<n;i++){
        a[i][0]+=a[i-1][0];

    }

    for (int j=1;j<m;j++){
        a[0][j]+=a[0][j-1];
    }

    for (int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if (a[i-1][j]<a[i][j-1]){
                a[i][j]+=a[i-1][j];
            }
            else{
                a[i][j]+=a[i][j-1];
            }
        }
    }

    return a[n-1][m-1];


    

    
}




int main(){

    vector<vector<int>> a={{1, 2, 3},
                                    {4, 5, 6}};

    cout<<shortDistanceInGrid(a)<<endl;



}
