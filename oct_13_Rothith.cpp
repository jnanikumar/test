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
    // float getAccelerate(){

    // }
    int getNumSeats();
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
};

class Truck : public Vehicle
{
public:
    int doors;
    int sittingCapacity;
    int loadCapacity;

public:
    setTruckConfig(int d, int s, int l, int m, int k, int y, string f, float e)
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
        Vehicle arr[5];
        for (int i = 0; i < n; i++)
        {
            int door = doors(gen);
            int sitting_capacity = sitting_capacity(gen);
            int load_capacity = loadCapacity(gen);
            int y = year(gen);
            int m = make(gen);
            int c = color(gen);
            int e = Engine(gen);
            arr[i].Truck::setTruckConfig(door, sitting_capacity, load_capacity, m, c, y, "desiel", e);
        }
    }
};

int main()
{

    return 0;
}