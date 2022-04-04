#include <iostream>
using namespace std;
#include <ctime>
#include <random>
#include <string>

class datagrid
{

    int data[7][7] = {{1, 41, 3, 52, 7, 22, 8},
                      {4, 17, 5, 65, 8, 12, 7},
                      {22, 26, 9, 5, 71, 62, 14},
                      {17, 18, 44, 33, 5, 38, 16},
                      {6, 59, 67, 11, 30, 46, 17},
                      {8, 12, 14, 18, 15, 35, 19},
                      {11, 32, 14, 15, 19, 16, 20}};

public:
    int isMultipleOf3(int n)
    {
        if (n % 3 == 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    void adjacentSumOfThreeMultiple()
    {
        for (int i = 1; i < 6; i++)
        {
            for (int j = 1; j < 6; j++)
            {
                if (isMultipleOf3(data[i][j]) == 1)
                {
                    cout << data[i][j] << " (" << data[i - 1][j] << "+" << data[i + 1][j] << "+" << data[i][j - 1] << "+" << data[i][j + 1] << " = " << data[i - 1][j] + data[i + 1][j] + data[i][j - 1] + data[i][j + 1] << " )" << endl;
                    ;
                }
            }
        }
    }
};

class Flat
{
public:
    string flatno;
    string Owner;
    int type;
    int area;
    bool parking;
    int floor;

public:
    void setValueOfFlat(string fno, string own, int typ, int A, bool park, int floorno)
    {
        flatno = fno;
        Owner = own;
        type = typ;
        parking = park;
        floor = floorno;
    }

    void SearchFlats(string flatno, Flat flats[10])
    {

        for (int i = 0; i < 10; i++)
        {
            if (flats[i].flatno == flatno)
            {
                cout << "the flat exists with flat no = " << flatno << endl;
                return;
            }
        }
        cout << "the flat doesnot exists" << endl;
    }
    void SearchFlats(int type, Flat flats[10])
    {
        cout << "below you will find the flats with type = " << type << endl;
        for (int i = 0; i < 10; i++)
        {
            if (flats[i].type == type)
            {
                cout << flats[i].flatno << endl;
                return;
            }
        }
        cout << "the flat with this type doesnot exists" << endl;
    }
    void SearchFlats(bool parking, Flat flats[10])
    {
        cout << "below you will find the flats with parking = " << parking << endl;
        for (int i = 0; i < 10; i++)
        {
            if (flats[i].parking == parking)
            {
                cout << flats[i].flatno << endl;
                return;
            }
        }
        cout << "the flat doesnot exists" << endl;
    }
};

class OtherProperties
{
    int nbeds = 2;
    int nbath;
    bool status;
};

class BHK2 : public Flat
{

    int nbeds = 2;
    int nbath; //[1,2]
    bool status;

public:
    void setValueOfBHK2()
    {
    }
};
class BHK3 : public Flat
{

    int nbeds = 3;
    int nbath; //[1,3]
    bool status;

public:
    void setValueOfBHK3()
    {
    }
};

class PentHouse : public Flat
{

    int nbeds = 4;
    int nbath; //[1,5]
    bool status;

public:
    void setValueOfPentHouse()
    {
    }
};

int main()
{
    string alphabets[5] = {"A", "B", "C", "D", "E"};
    uniform_int_distribution<> flatno(100, 999);
    uniform_int_distribution<> flatnoalpha(0, 4);
    uniform_int_distribution<> type(0, 3);

    uniform_int_distribution<> area(2000, 3000);
    uniform_int_distribution<> parking(0, 1);
    uniform_int_distribution<> floor(1, 14);
    mt19937 gen(time(0));

    cout << "Question 1" << endl;
    datagrid obj1;
    obj1.adjacentSumOfThreeMultiple();
    cout << "Question 2" << endl;

    Flat flats[10];
    cout << "details of the flat" << endl;
    for (int i = 0; i < 10; i++)
    {
        int intflat = flatno(gen);

        string flatno = alphabets[flatnoalpha(gen)] + to_string(intflat);
        string owner = "Jnani";
        int typ = type(gen);
        int Area = area(gen);
        int park = parking(gen);
        int floorno = floor(gen);
        flats[i].setValueOfFlat(flatno, owner, typ, Area, park, floorno);
        cout << "flat number " << flatno << " :"
             << "owner is " << owner << " type of flat :" << typ << " Area of the flat " << Area << " about parking " << park << "floor number " << floorno << endl;
    }

    Flat flat;
    flat.SearchFlats(1, flats);

    return 0;
}
