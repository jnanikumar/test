#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;



class SortNumbers{
public:
    bool isPrime(int N){
        for (int k;k<N;k++){
            if (N%k==0){
                return false;
            }
        }
        return true;

    }
    int shifting(int arr[][]){
        res[2][10]={{}};
        int m=0;
        int n=0;
        for (int i=0;i<2;i++){
            for (int j;j<10;j++){
                if isPrime(arr[i][j]){
                    arr[0][m]=arr[i][j];
                    m=m+1;
                }
                else{
                    arr[1][n]=arr[i][j];
                    n=n+1;
                }
            }
        }

        return res

    }

};




void print(vector<int>&v,int i)
{
    if(i==0)
    {
        cout<<v[i]<<' ';
        return;
    }
    print(v,i-1);
    cout<<v[i]<<' ';

}




void print_consecutive(vector<int>&v,int i,int x)
{
    if(i==0)
    {
        return;
    }
    print_consecutive(v,i-1,x);
    if(v[i]+v[i-1]>x)
    {
        cout<<v[i-1]<<' '<<v[i]<<endl;
    }
}




int main()
{


    int n;
    cout<<"enter n value"<<endl;
    cin>>n;
    cout<<"enter the elements of list"<<endl;
    vector<int>v;
    int x=0;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        x+=a;
        v.push_back(a);
    }
    x=x/n;
    cout<<"answer for 1a random number genrator"<<endl;
    cout<<v[rand()%n]<<endl;

    cout<<"answer for 1b"<<endl;
    print(v,n-1);
    cout<<"answer for 1c"<<endl;
    print_consecutive(v,n-1,x);

}
