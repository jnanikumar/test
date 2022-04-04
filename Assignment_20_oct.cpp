#include <iostream>
using namespace std;
#include <ctime>
#include <random>


class Account{
    public:
        string name;
        int cif;
        int year;
        string type;
        int listacs[7]={0};
    public:
    Account(){
        uniform_int_distribution<> amount(100, 1000);
        mt19937 gen(time(0));
        for(int i=0;i<7;i++){
            listacs[i]=amount(gen);
        }
        
    }
    string brand_names[7]={"Tata","Ford", "BMW", "Rolls-Royce", "Benz", "Leyland", "Isuzu"};
    string types[2]={"Resident" ,"Non-Resident"};
    void getBalance(int cat){
        cout<<"your account balance is in category of "<<cat <<" "<<listacs[cat]<<endl;
    }
    void getInterestRate(){
        cout<<"you interest rate is "<<"3%"<<endl;
    }
    void getNetAmount(){
        cout<<"net Account balance is "<<listacs[0]+listacs[1]+listacs[2]+listacs[4]-listacs[3]-listacs[5]-listacs[6]<<endl;
    }
    
    void setAccountConfigs(int y, int c, int b, int t)
    {
        name=brand_names[b];
        cif=c;
        type=types[t];
        year=y;

    }
    void populateArrayOfAccounts()
    {
        uniform_int_distribution<> year(2010, 2021);
        uniform_int_distribution<> cif(0, 6);
        uniform_int_distribution<> brand(0, 6);
        uniform_int_distribution<> type(0,1);
        mt19937 gen(time(0));
        int n = 5;
        Account arr[5];
        for (int i = 0; i < n; i++)
        {

            int y = year(gen);
            int c = cif(gen);
            int b = brand(gen);
            int t = type(gen);
            arr[i].Account::setAccountConfigs(y,c,b,t);
        }
    }



    void printDetails(){
        cout<<"brand is "<<name<<" cif number is "<<cif<<" type is "<<type<<" year in which the account is created "<<year<<endl;
    }



};




class savings:public Account{
    private:
        string acc_type="savings";
    public:
    void setAccountConfig(int y, int c, int b, float t)
    {
        
        Account::setAccountConfigs(y,c,b,t);
    }
};
class current:public Account{
    private:
        string acc_type="current";
    public:
    void setAccountConfig(int y, int c, int b, float t)
    {
        
        Account::setAccountConfigs(y,c,b,t);
    }
    
};
class deposite:public Account{
    private:
        string acc_type="desposite";
    public:
    void setAccountConfig(int y, int c, int b, float t)
    {
        
        Account::setAccountConfigs(y,c,b,t);
    }
    
};
class overdraft:public deposite{
    public:
    void setAccountConfig(int y, int c, int b, float t)
    {
        
        deposite::setAccountConfigs(y,c,b,t);
    }
    
};
class loan:public Account{
    private:
        string acc_type="loan";
        int HouseLoan;
        int CarLoan;
        int EducationLoan;
        int PersonalLoan;
        int GoldLoan;

    public:
    void setAccountConfig(int y, int c, int b, float t)
    {
        
        Account::setAccountConfigs(y,c,b,t);
    }

    loan(int HL,int CL,int EL,int PL,int GL){
        HouseLoan=HL;
        CarLoan=CL;
        EducationLoan=EL;
        PersonalLoan=PL;
        GoldLoan=GL;


    }

    void printLoanDetails(){
        cout<<"your loan details are "
        <<"Carloan "<<CarLoan<<" , "
        <<"EducationLoan "<<EducationLoan<<" , "
        <<"PersonalLoan "<<PersonalLoan<<" , "
        <<"GoldLoan "<<GoldLoan<<endl;
        cout<<"total summation of loans are "<<HouseLoan+CarLoan+EducationLoan+PersonalLoan+GoldLoan;
    }
    
};
class funds:public Account{
    private:
        string acc_type="funds";
    public:
    void setAccountConfig(int y, int c, int b, float t)
    {
        
        Account::setAccountConfigs(y,c,b,t);
    }
    
};
class others:public Account{
    private:
        string acc_type="others";
    public:
    void setAccountConfig(int y, int c, int b, float t)
    {
        
        Account::setAccountConfigs(y,c,b,t);
    }
    
};


class shortten:public deposite{
    public:
    void setAccountConfig(int y, int c, int b, float t)
    {
        
        deposite::setAccountConfigs(y,c,b,t);
    }
    
};


class mediumterm:public deposite{
    public:
    void setAccountConfig(int y, int c, int b, float t)
    {
        
        deposite::setAccountConfigs(y,c,b,t);
    }
    
};


class longterm : public deposite{
    public:
    void setAccountConfig(int y, int c, int b, float t)
    {
        
        deposite::setAccountConfigs(y,c,b,t);
    }
    
};


int main(){
    Account obj1;
    obj1.setAccountConfigs(2020,100,2,0);
    obj1.getBalance(2);
    obj1.getInterestRate();
    obj1.getNetAmount();
    obj1.printDetails();
    
return 0;
}




