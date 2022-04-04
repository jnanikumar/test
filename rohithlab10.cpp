#include <iostream>
using namespace std;

class Matrix{
    public:
    int matrix[9][10]={{2 ,7 ,5 ,11, 17, 9 ,3 ,17, 4, 3},
                {4 ,5, 3, 83, 7 ,8, 4, 3, 7, 9},
                {6 ,6 ,11, 9, 5, 15, 7, 13, 23, 3},
                {3 ,4, 8, 1, 2, 7 ,5 ,9, 4, 6},
                {15, 7, 3, 2, 8, 8, 5 ,6 ,89, 7},
                {8 ,7, 13, 7, 3, 1, 7, 7, 41, 7},
                {3, 97, 7, 6, 4, 7, 11, 6, 2, 3,},
                {5 ,2, 5, 3, 8, 4, 6, 5, 1, 8},
                {2 ,4, 3, 2, 4, 9, 2, 3, 5, 2}

    };
    public:
        int getter(int x,int y){
            return matrix[x][y];
        }

        void setter(int x,int y,int val){
            matrix[x][y]=val;
            cout<<"value updated successfully"<<endl; 
        }


        int isPrime(int N){
        if (N==1){
            return 0;
        }
        if (N==2 ){
            return 1;
        }
        for (int k=2;k<N;k++){
            if (N%k==0){
                return 0;
            }
        }
        return 1;

        };


        void findPattern(){
            for (int i=0;i<9;i++){
                
                
                for (int j=0;j<10;j++){
                    int x1[2]={i,j};
                    int x2[2]={-1,0};
                    int x3[2]={-1,0};
                    int x4[2]={-1,0};
                    int x5[2]={-1,0};
                    if ((i-1)>=0){
                        x2[0]=i-1;
                        x2[1]=j;
                    }
                    if ((i+1)<=8){
                        x4[0]=i+1;
                        x4[1]=j;
                    }
                    if ((j-1)>=0){
                        x3[1]=j-1;
                        x3[0]=i;
                    }
                    if ((j+1)<=9){
                        x5[0]=i;
                        x5[1]=j+1;
                    }
                    if (x2[0]!=-1 && x5[0]!=-1){
                        int val1=matrix[x2[0]][x2[1]];
                        int val3=matrix[x5[0]][x5[1]];
                        int val2=matrix[x1[0]][x1[1]];
                        if (val2==val1+1 && val3==(val1+val2)){
                            cout<<val1<<"--"<<val2<<"--"<<val3<<endl;
                        }
                        else if(val2==val3+1 && val1==(val2+val3)){
                            cout<<val3<<"--"<<val2<<"--"<<val1<<endl;
                        }
                    }
                    if (x5[0]!=-1 && x4[0]!=-1){
                        int val3=matrix[x4[0]][x4[1]];
                        int val1=matrix[x5[0]][x5[1]];
                        int val2=matrix[x1[0]][x1[1]];
                        if (val2==val1+1 && val3==(val1+val2)){
                            cout<<val1<<"--"<<val2<<"--"<<val3<<endl;
                        }
                        else if(val2==val3+1 && val1==(val2+val3)){
                            cout<<val3<<"--"<<val2<<"--"<<val1<<endl;
                        }
                    }
                    if (x4[0]!=-1 && x3[0]!=-1){
                        int val3=matrix[x3[0]][x3[1]];
                        
                        int val1=matrix[x4[0]][x4[1]];
                        int val2=matrix[x1[0]][x1[1]];
                        if (val2==val1+1 && val3==(val1+val2)){
                            cout<<val1<<"--"<<val2<<"--"<<val3<<endl;
                        }
                        else if(val2==val3+1 && val1==(val2+val3)){
                            cout<<val3<<"--"<<val2<<"--"<<val1<<endl;
                        }
                    }
                    if (x2[0]!=-1 && x3[0]!=-1){
                        int val1=matrix[x3[0]][x3[1]];
                        int val3=matrix[x2[0]][x2[1]];
                        int val2=matrix[x1[0]][x1[1]];
                        if (val2==val1+1 && val3==(val1+val2)){
                            cout<<val1<<"--"<<val2<<"--"<<val3<<endl;
                        }
                        else if(val2==val3+1 && val1==(val2+val3)){
                            cout<<val3<<"--"<<val2<<"--"<<val1<<endl;
                        }
                    }
                }
            }
        }


        void findPatternsWithPrimes(){
            for (int i=0;i<9;i++){
                
                
                for (int j=0;j<10;j++){
                    int prime=Matrix::isPrime(matrix[i][j]);
                    if (prime==1){ 
                    int x1[2]={i,j};
                    int x2[2]={-1,0};
                    int x3[2]={-1,0};
                    int x4[2]={-1,0};
                    int x5[2]={-1,0};
                    if ((i-1)>=0){
                        x2[0]=i-1;
                        x2[1]=j;
                    }
                    if ((i+1)<=8){
                        x4[0]=i+1;
                        x4[1]=j;
                    }
                    if ((j-1)>=0){
                        x3[1]=j-1;
                        x3[0]=i;
                    }
                    if ((j+1)<=9){
                        x5[0]=i;
                        x5[1]=j+1;
                    }
                    if (x2[0]!=-1 && x5[0]!=-1 ){
                        int val1=matrix[x2[0]][x2[1]];
                        int val3=matrix[x5[0]][x5[1]];
                        int val2=matrix[x1[0]][x1[1]];
                        if (Matrix::isPrime(val1)&&Matrix::isPrime(val3)){
                            if ((val1<val2 && val2<val3)){
                                cout<<val1<<"--"<<val2<<"--"<<val3<<endl;
                                }
                            else if ((val1>val2 && val2>val3)){
                                cout<<val3<<"--"<<val2<<"--"<<val1<<endl;
                            }
                        }
                    }
                    if (x5[0]!=-1 && x4[0]!=-1){
                        int val3=matrix[x4[0]][x4[1]];
                        int val1=matrix[x5[0]][x5[1]];
                        int val2=matrix[x1[0]][x1[1]];
                        if (Matrix::isPrime(val1)&&Matrix::isPrime(val3) ){
                            if ((val1<val2 && val2<val3)){
                                cout<<val1<<"--"<<val2<<"--"<<val3<<endl;
                                }
                            else if ((val1>val2 && val2>val3)){
                                cout<<val3<<"--"<<val2<<"--"<<val1<<endl;
                            }
                        }
                    }
                    if (x4[0]!=-1 && x3[0]!=-1){
                        int val3=matrix[x3[0]][x3[1]];
                        
                        int val1=matrix[x4[0]][x4[1]];
                        int val2=matrix[x1[0]][x1[1]];
                        if (Matrix::isPrime(val1)&&Matrix::isPrime(val3) ){
                            if ((val1<val2 && val2<val3)){
                                cout<<val1<<"--"<<val2<<"--"<<val3<<endl;
                                }
                            else if ((val1>val2 && val2>val3)){
                                cout<<val3<<"--"<<val2<<"--"<<val1<<endl;
                            }
                            
                        }
                    }
                    if (x2[0]!=-1 && x3[0]!=-1){
                        int val1=matrix[x3[0]][x3[1]];
                        int val3=matrix[x2[0]][x2[1]];
                        int val2=matrix[x1[0]][x1[1]];
                        if (Matrix::isPrime(val1)&&Matrix::isPrime(val3) ){
                            if ((val1<val2 && val2<val3)){
                                cout<<val1<<"--"<<val2<<"--"<<val3<<endl;
                                }
                            else if ((val1>val2 && val2>val3)){
                                cout<<val3<<"--"<<val2<<"--"<<val1<<endl;
                            }
                        }
                    }
                }
                }
            }
        }
        
};

int main(){
    Matrix obj1;
    cout<<"question-2"<<endl;

    cout<<obj1.getter(1,1)<<endl;
    cout<<"question 3 -------------------------------------------------------------------------------"<<endl;

    obj1.findPattern();
    cout<<"question 4"<<endl;
    cout<<obj1.isPrime(10)<<endl;
    cout<<"question 5 -------------------------------------------------------------------------------"<<endl;
    obj1.findPatternsWithPrimes();
    
    return 0;
}

 


