#include<iostream>
#include<stdlib.h>
#include<unistd.h>

using namespace std;

class player{
    string pname;
    int age;
    int noOfMatches;
    static int x;
    string players[40]={"Virat Kohli","Rohit Sharma","KL Rahul","Shreyas Iyer","Rishabh Pant","Rahul Dravid","Yuvraj Singh","Gautham Gambhir","Virendar Sehwag","Sachin Tendulkar","Suresh Raina","MS Dhoni","Bhuvaneshwar Kumar","M SHAMI","R Ashwin","Deepak Chahar","Varun Chakravarthy","Yuzvendra Chahal","Hardik Pandya","M Siraj","Kane Willaimson","David Warner","Johnny Bairstow","Ben Stokes","Jofra Archer","Eoin Morgan","Trent Bolt","Dale Steyn","Ricky Pointing","Brett Lee","Kumar Sangakara","JayaSurya","Chris Gayle","Dwayne Bravo","Bradd Hogg","David Miller","Steve Smith","Joe Root","Macus Stoinis","AB Devilliers"};
    int ages[40]={33,34,29,26,24,48,39,40,43,48,34,40,31,31,35,29,30,31,28,27,31,35,32,30,26,35,32,38,46,45,44,52,42,38,50,32,32,30,32,37}; 

    public:
        player(){
            pname=players[x];
            age=ages[x];
            if(x==39){
                x=0;
            }
            else{
                x++;
            }

        }
        string getPname(){
            return pname;
        }
        int getAge(){
            return age;
        }
        int getNoOfMatches(){
            return noOfMatches;
        }
};

int player::x=0;

class team1{
    protected:
    player p[11];
    int status[11];//0-out,1-notout,2-not played
    int runs[11];
    int totalScore;
    int wickets2[11];
    int totalWickets;
    string teamName;
    bool winOrLose;//0-lose,1-win
    public:
        team1(){
            for(int i=0;i<11;i++){
                int r=0;
                while(r=0){
                    status[i]=rand()%3;
                    if(status[i]==1){
                        int p=0;
                        for(int j=0;j<=i;j++){
                            if(status[j]==1){
                                p++;
                            }
                        }
                        if(p>2){
                            r=0;
                        }
                        else{
                            r=1;
                        }
                    }
                }
            }
            for(int i=0;i<11;i++){
                if(status[i]==0 || status[i]==1){
                    runs[i]=1+rand()%110;
                }
                else{
                    runs[i]=0;
                }
                totalScore+=runs[i];
            }
            for(int i=0;i<11;i++){
                if(status[i]==0){
                    totalWickets++;
                }
            }
        }
};

class team2{
    protected:
    player p[11];
    int status[11];//0-out,1-notout,2-not played
    int runs[11];
    int totalScore;
    int wickets1[11];
    int totalWickets;
    string teamName;
    bool winOrLose;//0-lose,1-win
    public:
        team2(){
            for(int i=0;i<11;i++){
                int r=0;
                while(r=0){
                    status[i]=rand()%3;
                    if(status[i]==1){
                        int p=0;
                        for(int j=0;j<=i;j++){
                            if(status[j]==1){
                                p++;
                            }
                        }
                        if(p>2){
                            r=0;
                        }
                        else{
                            r=1;
                        }
                    }
                }
            }
            for(int i=0;i<11;i++){
                if(status[i]==0 || status[i]==1){
                    runs[i]=1+rand()%110;
                }
                else{
                    runs[i]=0;
                }
                totalScore+=runs[i];
            }
            for(int i=0;i<11;i++){
                if(status[i]==0){
                    totalWickets++;
                }
            }
        }
};
string name[]={"Chennai Super Kings","Royal Challengers Bangalore","Kolkata Knight Riders","Mumbai Indians","Delhi Capitals","Rajasthan Royals","Sunrisers Hyderabad","Punjab Kings","Deccan Chargers","Pune Warriors India","Gujarat Lions","Kochi Tuskers"};
class match:public team1,public team2{
    class dat{
        public:
        int getDate(){
            
            return 0;
        }
    };
    dat d;
    int date=d.getDate();
    string name[4]={"IPL","BBL","PPL","CPL"};
    string trophyName;
    string venues[2]={"hello","hi"};
    string place;
    string manOfMatch;
    public:
        match(){
            team1::winOrLose=(team1::totalScore>team2::totalScore)?1:0;
            if(team1::winOrLose==0){
                team2::winOrLose=1;
            }
            else if(team1::winOrLose==1){
                team2::winOrLose=0;
            }
            int k=rand()%12;
            team1::teamName=::name[k];
            while(team1::teamName!=team2::teamName){
                k=rand()%12;
                team2::teamName=::name[k];
            }
            trophyName=name[rand()%4];

        }
        void isCentury(){
            cout<< "players who scored more than 100 from team1 " << endl;
            for (int i = 0; i < 11; i++){
                if (team1::runs[i] >= 100){
                    cout << team1::p[i].getPname()<< endl;
                }
            }
            cout << "players who scored more than 100 from team2 " << endl;

            for (int i = 0; i < 11; i++){
                if (team2::runs[i] >= 100){
                    cout << team2::p[i].getPname()<< endl;
                }
            }
        }
        void maxWickets(){
            int max_ = 0;
            string playerName;
            for (int i = 0; i < 11; i++){
                if (team1::wickets2[i] >= max_){
                    max_ = team1::wickets2[i];
                    playerName = team1::p[i].getPname();
                }
            }

            for (int i = 0; i < 11; i++){
                if (team2::wickets1[i] >= max_){
                    max_ = team2::wickets1[i];
                    playerName = team2::p[i].getPname();
                }
            }
            cout << "player who took maximum number of wickets is " << playerName << "with " << max_ << " wickets" << endl;
        }
        void findManOfMatch(){
        
        }
        void display();
};

void match :: display(){
    cout<<"Overall Statistics of " << team1::teamName << "are" <<endl;
    cout.width(20);
    cout<<"PLAYER NAME ";
    cout.width(50);
    cout<<"AGE";
    cout.width(20);
    cout<<"RUNS";
    cout.width(20);
    cout<<"WICKETS" <<endl;

    for(int i =0;i<11;i++){
        cout.width(50);
        cout<<team1::p[i].getPname();
        cout.width(20);
        cout<<team1::p[i].getAge();
        cout.width(20);
        cout<<team1::runs[i];
        cout.width(10);
        cout<<team1::status[i];
        cout<<endl;    
    }
    cout<<"*********"<<endl;
    cout<<endl;
    cout<<"Overall Statistics of " << team2::teamName << "are" <<endl;
    cout.width(20);
    cout<<"PLAYER NAME ";
    cout.width(50);
    cout<<"AGE";
    cout.width(20);
    cout<<"RUNS";
    cout.width(20);
    cout<<"WICKETS" <<endl;

    for(int i =0;i<11;i++){
        cout.width(50);
        cout<<team2::p[i].getPname();
        cout.width(20);
        cout<<team2::p[i].getAge();
        cout.width(20);
        cout<<team2::runs[i];
        cout.width(10);
        cout<<team2::status[i];
        cout<<endl;    
    }
    cout<<endl;
    //cout<< teamname << "Won the Match" << endl;
}

int main(int argc,char* argv[]){
    int n=1;
    n=(argc>1)?atoi(argv[1]):n;

    srand((unsigned int)getpid());
    match *m=new match[n];
    for(int i=0;i<n;i++){
        m[i]=match();
        m[i].display();
    }

    return 0;
}