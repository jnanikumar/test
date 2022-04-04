#include <iostream>
using namespace std;
#include <ctime>
#include <random>

class UserProfile{
    public:
        int userID;
        int age;
        int interests;
        int friends[10]={0};
        int communities[5]={0};
        int date;
    public:
        void setUserProfile(int uid,int Age,int Interests,UserProfile Friends[10],int community[5],int Date){
            userID=uid;
            age=Age;
            interests=Interests;
            // for (int i=0;i<10;i++){
            //     friends[i]=Friends[i];
            // }
            for (int j=0;j<5;j++){
                communities[j]=community[j];
            }
            
            date=Date;
    }

};

// question a

class Memories{
    public:
        UserProfile arr[150];
    Memories(){
        uniform_int_distribution<> uid(10000, 99999);
        uniform_int_distribution<> age(0, 6);
        uniform_int_distribution<> interests(0, 6);
        uniform_int_distribution<> f(0,149);
        uniform_int_distribution<> community(1,20);

        mt19937 gen(time(0));
        int uids[150];
        for (int i=0;i<150;i++){
            uids[i]=uid(gen);
        }
        for (int j=0;j<150;j++){
            int uid=uids[j];
            int Age=age(gen);
            int Interests=interests(gen);
            int communities[5];
            for (int k=0;k<5;k++){
                communities[k]=community(gen);
            }
            UserProfile friends[10];
            for (int l=0;l<10;l++){
                int n=f(gen);
                friends[l]=arr[n];
            }
            int Date=123456;
            arr[j].UserProfile::setUserProfile(uid,Age,Interests,friends,communities,Date);
        }

        
        
    }

    // question b

    void DistintInterest(int id,int interest[10]){
        for (int i=0;i<150;i++){
            if (arr[i].userID==id){
                for (int j=0;j<10;j++){
                    for (int k=0;k<10;k++){
                        for (int l=0;l<10;l++){
                            if (arr[j].interests[0]==interest[l]){
                                cout<<interest[l];
                            }
                        }
                    }
                }
            }
        }
    }

    //question c

    void CommonInterests(int m, UserProfile user){
        for (int i=0;i<10;i++){
            int count=0;
            for (int j=0;j<10;j++){
                for (int k=0;k<10;k++){
                    if (user.interests[j]==user.friends[i].interest[k]){
                            count+=1;
                    }

                }
            }
            if (count>=m){
                cout<<user.friends[i].userID<<endl;
            }
            

        } 

    }

//question d

    void findFriends(UserProfile user,int x){
        if (x==0){
            cout<<"close friends"<<endl;
            for (int i=0;i<10;i++){
                cout<<user.friends[i]<<endl;
            }
        }
    }


// question  e

    void usersWithSpecificInterests(int interest){
        for ( int i=0;i<150;i++){
            for (int j=0;j<10;j++){
                if (arr[i].interests[j]==interest){
                    cout<<arr[i].userID<<endl;
                }
            }
        }
    }

    
};