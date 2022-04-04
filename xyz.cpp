#include<iostream>
#include<stdlib.h>

using namespace std;

class player{
    public:
        string name;
        int age;
        int noofmatches;
    public:
        player(){
            
        }
};
class team1{
    public:
        player p[11];
        int runs[11];
        int totalScore;
        int wickets1[11];
        int totalWickets;
        string teamname;
        bool winorlose;
    public:
        team1(){

        }
};

class team2{
    public:
        player p[11];
        int runs[11];
        int totalScore;
        int wickets2[11];
        int totalWickets;
        string teamname;
        bool winorlose;
    public:
        team2(){

        }
};

class match:public team1,public team2{
    class dat{
        public:
        int getDate(){
            
            return 0;
        }
    };
    dat d;
    
    int date=d.getDate();
    string torphyName;
    string place;
    string manOfMatch;
    int max_=0;
    string playerName;
    public:
        match(){

        }
        void isCentury(){
            cout<<"players who scored more than 100 from team1 "<<endl;
            for (int i=0;i<11;i++){
                if (team1::runs[i]>=100){
                    cout<<team1::p[i].name<<endl;
                }
            }
            cout<<"players who scored more than 100 from team2 "<<endl;

            for (int i=0;i<11;i++){
                if (team2::runs[i]>=100){
                    cout<<team2::p[i].name<<endl;
                }
            }
            
        }
        void maxWickets(){
           
            
            for (int i=0;i<11;i++){
                if (team1::wickets1[i]>=max_){
                    max_=team1::wickets1[i];
                    playerName=team1::p[i].name;
                }
            }

            for (int i=0;i<11;i++){
                if (team2::wickets2[i]>=max_){
                    max_=team2::wickets2[i];
                    playerName=team2::p[i].name;
                }
            }

            
            cout<<"player who took maximum number of wickets is "<<playerName<<"with "<<max_<<" wickets"<<endl;


        }
        void manOfTheMatch(){
            int max_runs=0;
            string maxRunsPlayerName;
            if (max_>=5){
                cout<<"man of the match is "<<playerName<<endl;
            }
            else if(team1::winorlose){
                for (int j=0;j<11;j++){
                    if (team1::runs[j]>max_runs){
                        max_runs=team1::runs[j];
                        maxRunsPlayerName=team1::p[j].name;
                    }
                }

            }
            else if(team2::winorlose){
                for (int j=0;j<11;j++){
                    if (team2::runs[j]>max_runs){
                        max_runs=team2::runs[j];
                        maxRunsPlayerName=team2::p[j].name;
                    }
                }

            }

        }
        void display();
};

void match :: display(){
    
}

int main(int argc,char* argv[]){
    int n=1;
    n=(argc>1)?atoi(argv[1]):n;

    match *m=new match[n];
    for(int i=0;i<n;i++){
        m[i]=match();
    }

    return 0;
}