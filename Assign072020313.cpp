#include <iostream>
using namespace std;
#include <ctime>
#include <random>

class Vehicle
{
public:
    int make;
    int color;
    int year;
    string Fuel;
    float Engine;

public:
    void setVehicleConfigs(int m, int k, int y, string f, float e)
    {
        make = m;
        color = k;
        year = y;
        Fuel = f;
        Engine = e;
    }
    bool isClimbUpHill()
    {
        if (Engine > 1.5)
        {
            return true;
        }
        return false;
    }
    int getNumSeats();
    int getAccelate()
        {
    int time = rand() % 5;
    int velocity ;
    if (Fuel == "petrol")
    {
        
        velocity = 100 * Engine ;    
    }
    else if ( Fuel == "diesel")
    {
        velocity  = 200 * Engine;

 
    }
    int accerleration = ( velocity / time);
    return accerleration;
}
    
    void populateArrayOfVehicles()
    {
        uniform_int_distribution<> year(2010, 2021);
        uniform_int_distribution<> make(0, 6);
        uniform_int_distribution<> color(0, 4);
        uniform_int_distribution<> Engine(1, 3);
        uniform_int_distribution<> ni(5, 20);
        mt19937 gen(time(0));
        int n = ni(gen);
        Vehicle arr[5];
        for (int i = 0; i < n; i++)
        {

            int y = year(gen);
            int m = make(gen);
            int c = color(gen);
            int e = Engine(gen);
            arr[i].Vehicle::setVehicleConfigs(m, c, y, "desiel", e);
        }
    }
    void detailsOfVehicle(){
        cout<<"Brand "<<make<<" color "<<color<<" year "<<year<<" Fuel "<<Fuel<<" Engine "<<Engine;
    }
};

class Truck : public Vehicle
{
public:
    int doors;
    int sittingCapacity;
    int loadCapacity;

public:
    void setTruckConfigs(int d, int s, int l, int m, int k, int y, string f, float e)
    {
        doors = d;
        sittingCapacity = s;
        loadCapacity = l;
        Truck::setVehicleConfigs(m, k, y, f, e);
    }
    void populateArrayOfTruck()
    {
        uniform_int_distribution<> year(2010, 2021);
        uniform_int_distribution<> make(0, 6);
        uniform_int_distribution<> color(0, 4);
        uniform_int_distribution<> Engine(1, 3);
        uniform_int_distribution<> ni(5, 20);
        uniform_int_distribution<> doors(2, 4);
        uniform_int_distribution<> sittingCapacity(2, 4);
        uniform_int_distribution<> loadCapacity(10, 20);
        mt19937 gen(time(0));
        int n = ni(gen);
        Truck arr[5];
        for (int i = 0; i < n; i++)
        {
            int door = doors(gen);
            int sitting_capacity = sittingCapacity(gen);
            int load_capacity = loadCapacity(gen);
            int y = year(gen);
            int m = make(gen);
            int c = color(gen);
            int e = Engine(gen);
            arr[i].Truck::setTruckConfigs(door, sitting_capacity, load_capacity, m, c, y, "desiel", e);
        }
    }
    void detailsOfTruck(){
        cout<<"Brand "<<make<<" color "<<color<<" year "<<year<<" Fuel "<<Fuel<<" Engine "<<Engine<<" doors "<<doors<<" sittingCapacity "<<sittingCapacity<<" loadCapacity "<<loadCapacity<<endl;
    }
};

class LMV : public Vehicle
{
public:
    int tires;
    

public:
    void setLMVConfigs(int t, int m, int k, int y, string f, float e)
    {
        tires = t;
        
        LMV::setVehicleConfigs(m, k, y, f, e);
    }
    void populateArrayOfTruck()
    {
        uniform_int_distribution<> year(2010, 2021);
        uniform_int_distribution<> make(0, 6);
        uniform_int_distribution<> color(0, 4);
        uniform_int_distribution<> Engine(1, 3);
        uniform_int_distribution<> ni(5, 20);
        uniform_int_distribution<> tire(4, 10);
        
        mt19937 gen(time(0));
        int n = ni(gen);
        LMV arr[5];
        for (int i = 0; i < n; i++)
        {
            int tires = tire(gen);
            
            int y = year(gen);
            int m = make(gen);
            int c = color(gen);
            int e = Engine(gen);
            arr[i].LMV::setLMVConfigs(tires,  m, c, y, "desiel", e);
        }
    }
    void detailsOfTruck(){
        cout<<"Brand "<<make<<" color "<<color<<" year "<<year<<" Fuel "<<Fuel<<" Engine "<<Engine<<" tires "<< tires <<endl;
    }
};

class Car : public LMV
{
public:
    int doors;
    int sittingCapacity;
    
public:
    void setCarConfigs(int d, int s, int m, int k, int y, string f, float e)
    {
        doors = d;
        sittingCapacity = s;
        
        LMV::setVehicleConfigs(m, k, y, f, e);
    }
    void populateArrayOfTruck()
    {
        uniform_int_distribution<> year(2010, 2021);
        uniform_int_distribution<> make(0, 6);
        uniform_int_distribution<> color(0, 4);
        uniform_int_distribution<> Engine(1, 3);
        uniform_int_distribution<> ni(5, 20);
        uniform_int_distribution<> doors(2, 4);
        uniform_int_distribution<> sittingCapacity(2, 4);
        uniform_int_distribution<> loadCapacity(10, 20);
        mt19937 gen(time(0));
        int n = ni(gen);
        Car arr[5];

        for (int i = 0; i < n; i++)
        {
            int door = doors(gen);
            int sitting_capacity = sittingCapacity(gen);
            // int load_capacity = loadCapacity(gen);
            int y = year(gen);
            int m = make(gen);
            int c = color(gen);
            int e = Engine(gen);
            arr[i].Car::setCarConfigs(door, sitting_capacity, m, c, y, "desiel", e);
        }
    }
    void detailsOfTruck(){
        cout<<"Brand "<<make<<" color "<<color<<" year "<<year<<" Fuel "<<Fuel<<" Engine "<<Engine<<" doors "<<doors<<" sittingCapacity "<<sittingCapacity<<endl;
    }
};


int main()
{


    return 0;
}