#include<iostream>
using namespace std;
#include<vector>
#include<map>
#include<set>


class A{
    public:
        int a=3;

};

class B{
    public:
        int a=5;

};

class C:public A,public B {
    public:
        void geta(){
            cout<<A::a<<endl;
        }

};

int main(){

    C c;
    c.geta();
    return 0;
}