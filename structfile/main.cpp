# include<ctime>
#include <iostream>
#include<string>
# include<random>
#include<cmath>
using namespace std;

struct center{
        int x;
        int y;
        };
class Circle{
private:

    center c;
    float radius;
    int n;


public:

    Circle(){

    uniform_int_distribution<> n_val(10,20);
    uniform_int_distribution<> coord(0, 10);
    uniform_real_distribution<> radius(1,3);
    mt19937 gen(time(0));
    n=n_val(gen);
    Circle circles[n];
    for (int i=0;i<n;i++){
        int x=coord(gen);
        int y=coord(gen);
        float r=2.3;
        Circle cir(x,y,r);
        circles[i]=cir;
        cout<<cir.c.x<<endl;
    }


    }

    Circle(int a,int b,float r){
        c.x=a;
        c.y=b;
        radius=r;
        cout<<"circle created"<<endl;

    }
    void printDetails(Circle circle){
        cout<<"printDetails"<<endl;
        cout<<"radius of the circle is "<<circle.radius<<endl;
        cout<<"center of the circle is ("<<circle.c.x<<","<<circle.c.y<<")"<<endl;




    }
    void findCircles(Circle circle,center  mincoord,center maxcoord){

        cout<<"findCircles"<<endl;
        int x1=mincoord.x;
        int x2=maxcoord.x;
        int y1=mincoord.y;
        int y2=maxcoord.y;


        if (circle.c.x<x2 && circle.c.x>x1 && circle.c.y<y2 && circle.c.y>y1){
            cout<<"radius of the circle is "<<circle.radius<<endl;
            cout<<"center of the circle is ("<<circle.c.x<<","<<circle.c.y<<")"<<endl;
        }




    }


    float distance(int x1,int x2,int y1,int y2){

    float dist=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));

    return dist;

    }

    void findOTCCircles(Circle circle, int n){
    uniform_int_distribution<> n_val(10,20);
    uniform_int_distribution<> coord(0, 10);
    uniform_real_distribution<> radius(1,3);
    mt19937 gen(time(0));
    int x=circle.c.x;
    int y=circle.c.y;
    float r=circle.radius;

    for (int i=0;i<n;i++){
        int x_gen=coord(gen);
        int y_gen=coord(gen);
        float r_gen=2.3;
        int dist_bt_cen=distance(x,x_gen,y,y_gen);
        float rad_sum=r+r_gen;
        if (dist_bt_cen<rad_sum){
            cout<<"("<<x<<","<<y<<") ("<<x_gen<<","<<y_gen<<") "<<"intersecting"<<endl;
        }
        else if (dist_bt_cen==rad_sum){
                cout<<"("<<x<<","<<y<<") ("<<x_gen<<","<<y_gen<<") "<<"touching"<<endl;
        }

        if (x==x_gen&&y==y_gen){
            cout<<"("<<x<<","<<y<<") ("<<x_gen<<","<<y_gen<<") "<<"concentric"<<endl;

        }

    }




    }









};



int main(){
        uniform_int_distribution<> n_val(10,20);
        uniform_int_distribution<> coord(0, 10);
        uniform_real_distribution<> radius(1,3);
        mt19937 gen(time(0));

        int n=n_val(gen);
        int x=coord(gen);
        int y=coord(gen);
        float r=2.3;
        Circle cir(x,y,r);

        cir.printDetails(cir);
        center midcoord;
        midcoord.x=5;
        midcoord.y=5;
        center maxcoord;
        maxcoord.x=10;
        maxcoord.y=10;

        cir.findCircles(cir,midcoord,maxcoord);
        cir.findOTCCircles(cir,10);




return 0;
}






















/*class Factors{

public:
    bool isPrime(int N){
        if (N==2){
            return true;
        }
        for (int k=2;k<N;k++){
            if (N%k==0){
                return false;
            }
        }
        return true;

    };

    void computePrimeFactors(int k){
        int arr[k]={0};
        for (int i=2;i<k;i++){
            bool prime=Factors::isPrime(i);
            if (prime){
                arr[i]=i;
            }
        };

        bool prime=Factors::isPrime(k);
        int j=2;
        while(!prime){
            if (arr[j]==0){
                j++;
            }
            else if (k%arr[j]==0){
                cout<<arr[j]<<" ";
                k=k/arr[j];
                prime=Factors::isPrime(k);
                if (prime){
                    cout<<k<<" "<<endl ;
                }
            }
            else if (k%arr[j]!=0){
                j++;
            }


        }





};





int evenFactors(int num){
    int sum=0;
    cout<<"even factors of n are"<<endl;
    for(int l=1;l<num;l++){
        if (num%l==0 && l%2==0){
            cout<<l<<" ";
            sum=sum+l;

        }


    };
    cout<<" "<<endl;
    cout<<"sum of even factors of n is:"<<endl;
    return sum;

}






};


bool isPrime(int N){
        if (N==2){
            return true;
        }
        for (int k=2;k<N;k++){
            if (N%k==0){
                return false;
            }
        }
        return true;

    };

int isPalindrome(int A){
    string val=to_string(A);
    int len=val.length();

    int i=0;
    int j=len-1;
    for (int k=0;k<(len/2);k++){
        if (val[i]!=val[j]){
            return false;
            break;
        }
        else{
            i=i+1;
            j=j-1;
        }

    }

    return true;


};


void findPrimePalindromes(int k, int m){

    for (int i=k;i<m;i++){
        bool palindrome=isPalindrome(i);
        bool prime=isPrime(i);
        if (palindrome && prime){
            cout<<i<<" ";
        }
    }




};



void printKGrams(char str[28]){
int n=28;
for(int i=0;i<n-4;i++){
if(str[i]>str[i+1] && str[i+2] >str[i+1] )
cout<<str[i]<<str[i+1]<<str[i+2]<<endl;
}
};





int main(){

uniform_int_distribution<> dis(0, 1000);
mt19937 gen(time(0));

Factors obj1;
cout<<"prime factors of n are:"<<endl;
obj1.computePrimeFactors(121);

cout<<obj1.evenFactors(12);

cout<<" "<<endl;



cout<<" "<<endl;


int rand1=dis(gen);
int rand2=dis(gen);
int m;
int k;
if (rand1>rand2){
    m=rand1;
    k=rand2;
}
else if (rand1==rand2){
    cout<<"randomly generated k and m values are same try running again"<<endl;
}
else{
    k=rand1;
    m=rand2;


}
cout<<"prime palindromes between "<<k<<" and "<<m<<" are:"<<endl;
cout<<"if nothing prints ,it means there are no prime palindromes \n exists in the given range try running again"<<endl;
cout<<" "<<endl;
findPrimePalindromes(k,m);

cout<<" "<<endl;
cout<<"printKGrams :"<<endl;

char arr[28]={'B','A','Y',' ','O','F',' ','B','E','N','G','A','L',' ','I','S',' ','V','E','R','Y',' ','S','C','E','N','I','C'};
printKGrams(arr);


return 0;
}*/


/*int  max_four(int a,int b,int c,int d){
    if(a>b&&a>c&&a>d){
        return a;
    }

    else if(b>c&&b>d){
        return b;
    }
    else if(c>d){
        return c;
    }

    else{
        return d;





}

}
*/

/*int first(int a,int b){

    if (a>b){
        return a;
    }
    else if (b>a){
        return b;
    }
    else{
        return 0;
    }


}*/



/*int main()
{

  int val=max_four(1,2,3,4);
  max_four(10,11,12,13);

 return 0;



}
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

    SortNumbers obj1;
    int arr1[2][10]={{17,11,21,41,55,131,74,101,98,139},{89,15,2,59,50,36,125,60,151,180}};
    obj1.shifting(arr1);


}*/
