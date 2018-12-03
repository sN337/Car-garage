#include "Cars.h"

int Car::numCars = 0;
double Car::carValue = 0.0;



Car::Car(){
    newYear = 0;
    newPrice = 0.0;
    numCars++;

}

Car::Car(string brand, int year, double price){
    newBrand = brand;
    newYear = year;
    newPrice = price;
    numCars++;
    carValue += newPrice;
}

Car::Car(const Car &c){
    newBrand = c.newBrand;
    newYear = c.newYear;
    newPrice = c.newPrice;
    numCars++;
    carValue += c.newPrice;
}

Car::~Car(){
    numCars--;
    carValue -= newPrice;
}

string Car::getBrand(){
    return newBrand;
}

int Car::getYear(){
    return newYear;
}

double Car::getPrice(){
    return newPrice;
}

int Car::getNumcars(){
    return numCars;
}

void Car::setBrand(string brand){
    newBrand = brand;
}

void Car::setYear(int year){
    newYear = year;
}

void Car::setPrice(double price){
    carValue -= newPrice;
    newPrice = price;
    carValue += newPrice;

}

void Car::printGarageInfo(){
    system("CLS");
    cout << "Number of cars: " << numCars << endl;
    cout << "Garage value: $" << carValue << endl;
    cout << "-----------------------------" << endl;

}

