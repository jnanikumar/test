#include <iostream>
using namespace std;
#include <ctime>
#include <random>

class player{
    public:
        string name;
        int runs;
        int wickets;
        int num_of_overs;
        
    public:
    void playerData(string n,int r,int w,int o){
        name=n;
        runs=r;
        wickets=w;
        num_of_overs=o;
    }
};

class Team{
    public:
        string teamname;
        player arr[11];
    void addPlay(player p,int index){
        arr[index]=p;
    }

};

class MatchDetails{
    public:
        string date;

        Team team1;
        Team team2;
        string place;
        string winners;
        string man_of_the_match[2];
        int won_by;
        string Trophy_name;
    public:
        void matchdetails(string d,Team name1,Team name2,string p,string winner,string manOfTheMatch[2],int w_by,string name_trophy){
            date=d;
            team1=name1;
            team2=name2;
            place=p;
            winners=winner;
            man_of_the_match[0]=manOfTheMatch[0];
            man_of_the_match[1]=manOfTheMatch[1];


        }



};


class SeriesDetails{
    public:
        string man_of_the_series;
        MatchDetails allMatchDetails[3];
    

};


int main(){
    cout<<"available options"<<endl;
    cout<<"for Entering Series Details press 1"<<endl;
    


    return 0;
}