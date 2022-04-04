#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;


class SortNumbers{
public:
    int isPrime(int N){
        if (N==2){
            return 1;
        }
        for (int k=2;k<N;k++){
            if (N%k==0){
                return 0;
            }
        }
        return 1;

    };
    void shifting(int arr[2][10]){
        int res[2][10];
        int m=0;
        int n=0;
        for (int i=0;i<2;i++){
            for (int j=0;j<10;j++){
                int prime=SortNumbers::isPrime(arr[i][j]);

                if (prime){
                    res[0][m]=arr[i][j];
                    m=m+1;
                }
                else{
                    res[1][n]=arr[i][j];
                    n=n+1;
                }
            }
        }

        for (int p=0;p<2;p++){
            for (int q=0;q<10;q++){
                cout<<res[p][q]<<" ";

            }
            cout<<"\n"<<endl;
        }



    };

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


    /*int n;
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
    print_consecutive(v,n-1,x);*/

    SortNumbers obj1;
    int arr1[2][10]={{17,11,21,41,55,131,74,101,98,139},{89,15,2,59,50,36,125,60,151,180}};
    obj1.shifting(arr1);


}
