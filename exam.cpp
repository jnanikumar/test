 #include <iostream>
using namespace std;
class primeFactor{
    private:
        int num;
        int factors[100];
        int sum=0;
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
            bool prime=primeFactor::isPrime(i);
            if (prime){
                arr[i]=i;
            }
        };

        bool prime=primeFactor::isPrime(k);
        int j=2;
        int prev=0;
        while(!prime){
            if (arr[j]==0){
                j++;
            }
            else if (k%arr[j]==0){
                if (prev!=arr[j]){
                cout<<arr[j]<<" ";
                
                prev=arr[j];
                }
                k=k/arr[j];
                prime=primeFactor::isPrime(k);
                if (prime && prev!=arr[j]){
                    cout<<k<<" "<<endl ;
                    prev=arr[j];
                }

            }
            else if (k%arr[j]!=0){
                j++;
            }


        }

};








        void sumofFactors(){  //sum of the prime factors
            int i=0;
            while (factors[i]!=0){
                sum=sum+factors[i];
                i++;
            }
        }
        
    
};






// int main(){

//     primeFactor arr[15];

//     return 0;
// }



// class point{
//     int x;
//     int y;
// };

// class line{
//     point p1;
//     point p2;
//     int linewidth;

// };

// class Triangle{

// }


#include <iostream>
# include<ctime>
#include<string>
#include <cmath>
using namespace std;

# include<random>
struct point{
    int x;
    int y;
};

struct lineSegment{
    point a;
    point b;
};

class Line{
    private:
        point a;
        point b;
        int lineWidth;
        int lineColor;
    public:
        void printDetailsOfLineSegment(lineSegment line){
            int x1=line.a.x;
            int x2=line.b.x;
            int y1=line.a.y;
            int y2=line.b.y;

    

            cout<<"Q1) : end points of the linesegment are ("<<x1<<","<<y1<<"), ("<<x2<<","<<y2<<")"<<endl;
            cout<<"      length of the line segment is "<<sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1))<<endl;
        }

};

class Triangle{
    private:
        lineSegment p;
        lineSegment q;
        lineSegment r;
        
    public:
    Triangle(lineSegment arr[]){
        p=arr[0];
        q=arr[1];
        r=arr[2];
        
    }
    float lengthOfLine(lineSegment l1){
        float d1=sqrt((l1.b.x-l1.a.x)*(l1.b.x-l1.a.x)+(l1.b.y-l1.a.y)*(l1.b.y-l1.a.y));
        return d1;
    }
    

    float findAreaTriangle(lineSegment p,lineSegment q,lineSegment r){
    
        float d1=Triangle::lengthOfLine(p);
        float d2=Triangle::lengthOfLine(q);
        float d3=Triangle::lengthOfLine(r);
        float s=(d1+d2+d3)/3;
        float area=sqrt(s*(s-d1)*(s-d2)*(s-d3));
        return area;
        
        
    void findPerimeterTriangle(lineSegment p,lineSegment q,lineSegment r){
        float d1=Triangle::lengthOfLine(p);
        float d2=Triangle::lengthOfLine(q);
        float d3=Triangle::lengthOfLine(r);
        float s=(d1+d2+d3)/3
        float perimeter=d1+d2+d3;
        return perimeter;
    }


    void TwoTrianglesArea(point p1,point p2, point p3, point p4,point p5){
        lineSegment l1;
        l1.a=p1;
        l1.b=p2;
        lineSegment l2;
        l2.a=p2;
        l2.b=p3;
        lineSegment l3;
        l3.a=p3;
        l3.b=p1;
        lineSegment l4;
        l4.a=p1;
        l4.b=p4;
        lineSegment l5;
        l5.a=p4;
        l5.b=p5;
        lineSegment l6;
        l6.a=p5;
        l6.b=p1;
        
        cout<<Triangle::findAreaTriangle(l1,l2,l3) + Triangle::findAreaTriangle(l4,l5,l6);
        
        
    }


    
        

};





int main(){
    uniform_int_distribution<> p(0,50);
    
    mt19937 gen(time(0));
    
    Line l;
    point m;
    m.x=p(gen);
    m.y=p(gen);
    point n;
    n.x=p(gen);
    n.y=p(gen);

    lineSegment lineseg;
    lineseg.a=m;
    lineseg.b=n;
    l.printDetailsOfLineSegment(lineseg);
    
    
    


    return 0;
}




