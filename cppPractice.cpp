
#include <iostream>
using namespace std;
#include <vector>

class jnani{
    static int age;
    string name;
    string father;
    public:
        
    
        jnani(string n,string f){
            name=n;
            father=f;
        }
};

class rohi:private jnani{
    private:
        string name;
        string father;
        
    public:
        void print(){
            cout<<"hello there"<<endl;
        }
        

};







int main(){

    int x=2;
    int &y=x;
    int *z=&x;
    if (z==&x){
        cout<<"True"<<endl;
    }
    cout<<&x<<endl;
    return 0;
}