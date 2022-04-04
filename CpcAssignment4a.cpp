#include <iostream>
using namespace std;
int power(int x,int m){
    if (x==0){
        return 0;
    }
    if (m==0){
        return 1;
    }
    int res=power(x,m/2);
    res=res*res;
    if ((m%2)==1){
        return x*res;
    }
    else{
        return res;
    }
    
}


int main()
{

    cout<<power(2,5)<<endl;
    
    return 0;
}
