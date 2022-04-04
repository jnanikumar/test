// #include <iostream>
// using namespace std;


// class base{

//     public:
//         virtual void print(){
//             cout<<"print from base class"<<endl;
//         }
//         void show(){
//             cout<<"show from base class"<<endl;
//         }

// };
// class derived:public base{

//     public:
//         void print(){
//             cout<<"print from derived class"<<endl;
//         }
//         void show(){
//             cout<<"show from derived class"<<endl;
//         }

// };



// class A{

//     public:

//         A(){
//             cout<<"constructor function  from class A"<<endl;
//         }

// };
// class B{

//     public:
//         B(){
//             cout<<"constructor function a from class B"<<endl;
//         }

// };


// class C : public A, public B{

//     public:
//         C(){
//             cout<<"constructor function a from class C"<<endl;
        
//         }

// };





//int main(){
    // base obj1;
    // derived obj2;
    // base *ptr;
    // ptr=&obj1;
    // ptr->print();
    // ptr->show();
    // ptr=&obj2;
    // ptr->print();
    // ptr->show();
    // int a=3;
    // int *ptr;
    // ptr=&a;
    // cout<<ptr<<endl;
    // cout<<*ptr<<endl;

   // C c;





//}


#include<iostream>
#include<stdlib.h>
// #include<unistd.h>
#include<set>
#include<iterator>
#include<math.h>

using namespace std;

class player{
    string pname;
    int age;
    int noOfMatches;
    static int x;
    set<int> s;
    set<int>::iterator itr;
    string players[40]={"Virat Kohli","Rohit Sharma","KL Rahul","Shreyas Iyer","Rishabh Pant","Rahul Dravid","Yuvraj Singh","Gautham Gambhir","Virendar Sehwag","Sachin Tendulkar","Suresh Raina","MS Dhoni","Bhuvaneshwar Kumar","M SHAMI","R Ashwin","Deepak Chahar","Varun Chakravarthy","Yuzvendra Chahal","Hardik Pandya","M Siraj","Kane Willaimson","David Warner","Johnny Bairstow","Ben Stokes","Jofra Archer","Eoin Morgan","Trent Bolt","Dale Steyn","Ricky Pointing","Brett Lee","Kumar Sangakara","JayaSurya","Chris Gayle","Dwayne Bravo","Bradd Hogg","David Miller","Steve Smith","Joe Root","Macus Stoinis","AB Devilliers"};
    int ages[40]={33,34,29,26,24,48,39,40,43,48,34,40,31,31,35,29,30,31,28,27,31,35,32,30,26,35,32,38,46,45,44,52,42,38,50,32,32,30,32,37}; 

    public:
        player(){
            /*if(x<22){
                pname=players[*itr];
                age=ages[*itr];
                noOfMatches=5+rand()%75;
                itr++;
                x++;
            }
            else{
                x=0;
                s.clear();
                while(s.size()<=22){
                    s.insert(rand()%40);
                }
                itr=s.begin();
                pname=players[*itr];
                age=ages[*itr];
                noOfMatches=5+rand()%75;
                itr++;
                x++;
            }*/
            if(x<22){
                pname=players[x];
                age=ages[x];
                x++;
                noOfMatches=5+rand()%75;
            }
            else{
                x=0;
                pname=players[x];
                age=ages[x];
                noOfMatches=5+rand()%75;
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
        string captain;
        bool toss;
        int status[11]={0};//0-out,1-notout,2-not played
        int runs[11]={0};
        int totalScore=0;
        int wickets2[11]={0};
        int totalWickets=0;
        string teamName;
        bool winOrLose;//0-lose,1-win
    public:
        team1(){
            int k=rand()%11;
            captain=p[k].getPname();
            
            for(int i=0;i<11;i++){
                int r=0;
                while(r==0){
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
                    else{
                        r=1;
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
        string captain;
        bool toss;
        int status[11]={0};//0-out,1-notout,2-not played
        int runs[11]={0};
        int totalScore=0;
        int wickets1[11]={0};
        int totalWickets=0;
        string teamName;
        bool winOrLose;//0-lose,1-win
    public:
        team2(){
            int k=rand()%11;
            captain=p[k].getPname();
            
            for(int i=0;i<11;i++){
                int r=0;
                while(r==0){
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
                    else{
                        r=1;
                    }
                }
            }
            for(int i=0;i<11;i++){
                if(status[i]==0 || status[i]==1){
                    runs[i]=1+rand()%90;
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
            int k=1+rand()%12;
            int p;
            if(k==2){
                p=1+rand()%28;
            }
            else if((k<8 && k%2==1) || (k>=8 && k%2==0)){
                p=1+rand()%31;
            }
            else{
                p=1+rand()%30;
            }
            int q=2000+rand()%21;
            return p*pow(10,6)+k*pow(10,4)+q;
        }
    };
    dat d;
    int date=d.getDate();
    string name[4]={"IPL","BBL","PPL","CPL"};
    string trophyName;
    string venues[12]={"Delhi","Ahmedabad","Mumbai","Chennai","Bangaluru","Hyderabad","Kochi","Vishakapatnam","Mohali","Goa","Jaipur","Kanpur"};
    string place;
    public:
        match(){
            team1::winOrLose=(team1::totalScore>team2::totalScore)?1:0;
            if(team1::winOrLose==0){
                team2::winOrLose=1;
            }
            else if(team1::winOrLose==1){
                team2::winOrLose=0;
            }
            
            team1::toss=rand()%2;
            if(team1::toss==1){
                team2::toss=0;
            }
            else{
                team2::toss=1;
            }
            
            int k=rand()%12;
            team1::teamName=::name[k];
            do{
                k=rand()%12;
                team2::teamName=::name[k];  
            }while(team1::teamName==team2::teamName);
            
            for(int i=0;i<team2::totalWickets;i++){
                k=rand()%11;
                team1::wickets2[k]++;
            }
            for(int i=0;i<team1::totalWickets;i++){
                k=rand()%11;
                team2::wickets1[k]++;
            }
            
            trophyName=name[rand()%4];
            place=venues[rand()%12];
        }
        void isCentury(){
            cout<< "from Team1:" << endl;
            for (int i = 0; i < 11; i++){
                if (team1::runs[i] >= 100){
                    cout <<"\t"<<team1::p[i].getPname()<< endl;
                }
            }
            
            cout << "from Team2:" << endl;
            for (int i = 0; i < 11; i++){
                if (team2::runs[i] >= 100){
                    cout <<"\t"<<team2::p[i].getPname()<< endl;
                }
            }
        }
        void maxWickets(){
            int max = 0;
            string playerName;
            for (int i = 0; i < 11; i++){
                if (team1::wickets2[i] >= max){
                    max = team1::wickets2[i];
                    playerName = team1::p[i].getPname();
                }
            }

            for (int i = 0; i < 11; i++){
                if (team2::wickets1[i] >= max){
                    max = team2::wickets1[i];
                    playerName = team2::p[i].getPname();
                }
            }
            cout << "Player who took maximum number of wickets is " << playerName << " with "<<max<<" wickets"<<endl;
        }
        void findManOfMatch(){
            int max=0;
            string playerName;
            for(int i=0;i<11;i++){
                if(team1::wickets2[i]>=max){
                    max=team1::wickets2[i];
                    playerName=team1::p[i].getPname();
                }
            }
            for(int i=0;i<11;i++){
                if(team2::wickets1[i]>=max){
                    max=team2::wickets1[i];
                    playerName=team2::p[i].getPname();
                }
            }
            
            int maxRuns=0;
            string maxRunsPlayerName;
            if (max>=5){
                cout<<"Man of the Match is "<<playerName<<endl;
            }
            else if(team1::winOrLose==1){
                for (int j=0;j<11;j++){
                    if (team1::runs[j]>maxRuns){
                        maxRuns=team1::runs[j];
                        maxRunsPlayerName=team1::p[j].getPname();
                    }
                }
                cout<<"Man of Match is "<<maxRunsPlayerName<<endl;

            }
            else if(team2::winOrLose==1){
                for (int j=0;j<11;j++){
                    if (team2::runs[j]>maxRuns){
                        maxRuns=team2::runs[j];
                        maxRunsPlayerName=team2::p[j].getPname();
                    }
                }
                cout<<"Man of Match is "<<maxRunsPlayerName<<endl;
            }

        }
        void display();
};

void match :: display(){
    cout<<"Match Details:"<<endl;
    cout<<"\tDate:"<<date<<endl;
    cout<<"\tTrophy Name:"<<trophyName<<endl;
    cout<<"\tVenue:"<<place<<endl<<endl;
    
    cout<<"Team1:"<<team1::teamName<<endl;
    cout<<"\tCaptain:"<<team1::captain<<endl;
    cout<<"\tToss:";
    if(team1::toss==1){
        cout<<"won"<<endl<<"\n";
    }
    else{
        cout<<"lost"<<endl<<"\n";
    }
    cout<<"Player Details:"<<endl;
    cout.width(20);
    cout<<"Player Name ";
    cout.width(20);
    cout<<"Age";
    cout.width(20);
    cout<<"Runs";
    cout.width(10);
    cout<<"Status";
    cout.width(25);
    cout<<"WicketsTaken by player"<<endl;

    for(int i =0;i<11;i++){
        cout.width(20);
        cout<<team1::p[i].getPname();
        cout.width(20);
        cout<<team1::p[i].getAge();
        cout.width(20);
        cout<<team1::runs[i];
        cout.width(10);
        cout<<team1::status[i];
        cout.width(10);
        cout<<team1::wickets2[i];
        cout<<endl;    
    }
    cout<<"\nTotal Score:"<<team1::totalScore<<endl;
    cout<<"Total Wickets fallen:"<<team1::totalWickets<<endl;
    
    cout<<endl;
    cout<<"Team2:"<<team2::teamName<<endl;
    cout<<"\tCaptain:"<<team2::captain<<endl;
    cout<<"\tToss:";
    if(team2::toss==1){
        cout<<"won"<<endl;
    }
    else{
        cout<<"lost"<<endl;
    }
    cout<<"Player Details:"<<endl;
    cout.width(20);
    cout<<"Player Name";
    cout.width(20);
    cout<<"Age";
    cout.width(20);
    cout<<"Runs";
    cout.width(10);
    cout<<"Status";
    cout.width(25);
    cout<<"WicketsTaken by player"<<endl;

    for(int i =0;i<11;i++){
        cout.width(20);
        cout<<team2::p[i].getPname();
        cout.width(20);
        cout<<team2::p[i].getAge();
        cout.width(20);
        cout<<team2::runs[i];
        cout.width(10);
        cout<<team2::status[i];
        cout.width(10);
        cout<<team2::wickets1[i];
        cout<<endl;    
    }
    cout<<"Total Score:"<<team2::totalScore<<endl;
    cout<<"Total Wickets fallen:"<<team2::totalWickets<<endl;
    cout<<endl;
    
    if(team1::winOrLose==1){
        cout<<"Team 1:"<<team1::teamName<<" Won!!"<<endl;
    }
    else{
        cout<<"Team2:"<<team2::teamName<<" Won!!"<<endl;
    }
    
    cout<< "Players who scored more than 100 runs"<<endl;
    isCentury();
    maxWickets();
    findManOfMatch();
}

/*class series{
    int n;
    match *m[n];
    public:
        series(){

        }
        series(int p){
            n=p;
            for(int i=0;i<n;i++){
                m[i]= new match();
                m[i].display();
            }
        }
};*/

int main(int argc,char* argv[]){
    int n=1;
    n=(argc>1)?atoi(argv[1]):n;

    // srand((unsigned int)getpid());
    //series s(n);
    match *m=new match[n];
    for(int i=0;i<n;i++){
        m[i]=match();
        m[i].display();
    }

    return 0;
}