#include <iostream>

using namespace std;


struct student{

    string name;
    int roll;
    int clas;
    struct student * book;

};


void fun(struct student *prt){

    cout<<prt->name<<prt->roll<<prt->clas<<endl;

}

int main(){

    struct student  student1;
    student1.name="jnani";
    student1.roll=12;
    student1.clas=11;
    struct student *prt =&student1;
    fun(prt);



return 0
}
