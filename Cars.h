#ifndef CARS_H_INCLUDED
#define CARS_H_INCLUDED

#include <string>
#include <iostream>
#include <stdlib.h>

using namespace std;

//Declaring class Car
class Car{
    private:
        string newBrand;        //Declaring variable string - Brand of class Car
        int newYear;            //Declaring variable int - Year of Class Car
        double newPrice;        //Declaring variable double - Price of Class Car

        static int numCars;     //Number of all Cars created
        static double carValue; //Price of all Cars

    public:
        //Default constructor
        Car();
        //Overload constructor
        Car(string, int, double);
        //Copy constructor
        Car(const Car &c);
        //Destructor
        ~Car();
        //Access functions
        string getBrand();      //returns Brand of class
        int getYear();          //returns year of class
        double getPrice();      //returns price of class
        static int getNumcars();//returns number of all cars
        //Mutators
        void setBrand(string);  //Modifies brand
        void setYear(int);      //modifies year
        void setPrice(double);  //modifies price
        static void printGarageInfo(); //prints out number of cars and all cars value

};




#endif // CARS_H_INCLUDED
