#include<iostream>
using namespace std;

class TollBooth
{
private:
    int totalVehicles;
    double totalRevenue;

public:

    // constructor like reset
    void reset()
    {
        totalVehicles = 0;
        totalRevenue = 0;
    }

    // vehicle entry
    void vehiclePayingToll(int type)
    {
        totalVehicles++;

        if(type==1)        // car
            totalRevenue += 80;
        else if(type==2)   // truck
            totalRevenue += 300;
        else if(type==3)   // bus
            totalRevenue += 350;
    }

    void showVehicles()
    {
        cout<<"Total Vehicles: "<<totalVehicles<<endl;
    }

    void showRevenue()
    {
        cout<<"Total Revenue: "<<totalRevenue<<endl;
    }

    void showAll()
    {
        cout<<"\nVehicles Passed: "<<totalVehicles;
        cout<<"\nRevenue Collected: "<<totalRevenue<<endl;
    }
};

int main()
{
    TollBooth t;
    int ch;

    t.reset();

    do
    {
        cout<<"\n1.Car\n2.Truck\n3.Bus\n4.Show Vehicles\n5.Show Revenue\n6.Show All\n7.Exit";
        cout<<"\nEnter choice: ";
        cin>>ch;

        if(ch==1)
            t.vehiclePayingToll(1);
        else if(ch==2)
            t.vehiclePayingToll(2);
        else if(ch==3)
            t.vehiclePayingToll(3);
        else if(ch==4)
            t.showVehicles();
        else if(ch==5)
            t.showRevenue();
        else if(ch==6)
            t.showAll();

    }while(ch!=7);

    return 0;
}