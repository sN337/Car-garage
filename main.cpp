#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include "Cars.h"
#include <algorithm>



using namespace std;

void readInfo(vector<Car>&);    //Function for reading info from file into a vector
void writeInfo(vector<Car>&);   //Function to update vector after deleting an object

void addCars(vector<Car>&);     //Function to Add new objects from Class Car to a vector
void printCars(vector<Car>&);   //Function to Print all objects stored in the vector
void sortMenu(vector<Car>&);    //Function to show the sorting menu
void modifyCars(vector<Car>&);  //Function to change object's values with setters
void removeCars(vector<Car>&);  //Function to remove objects from vector and destroy them
                                //ALL FUNCTIONS ARE PASSED BY REFERENCE
void failInput(int);            //Function when user makes wrong input @param int = user's input

bool sortBrand(Car a, Car b){   //Function to sort vector by Brand ascending @param (Car a, Car b) - if A is less than B.
    return  a.getBrand() < b.getBrand();
}

bool sortBrandDesc(Car a, Car b){   //Same function, for descending order
    return  a.getBrand() > b.getBrand();
}

bool sortYear(Car a, Car b){        //Same function for Year ascending
    return a.getYear() < b.getYear();
}

bool sortYearDesc(Car a, Car b){    //Same function for Year descending
    return a.getYear() > b.getYear();
}

bool sortPrice(Car a, Car b){       //Same function for Price ascending
    return a.getPrice() < b.getPrice();
}

bool sortPriceDesc(Car a, Car b){   //Same function for price descending
    return a.getPrice() > b.getPrice();
}

int main()
{

    vector<Car> myGarage;   //Initializing a vector of objects of class Car
    readInfo(myGarage);     //Read from file to input into vector (when program is restarted, all info will be saved)

    int chc;                //Declaring an int called "chc" which servers as user's input
    do{                     //Loop to show the main menu of the program
    cout << "\t\tWelcome to your garage!\n" << endl;
    cout << "\t\t1. Enter cars\n";
    cout << "\t\t2. Show cars\n";
    cout << "\t\t3. Show garage info\n";
    cout << "\t\t4. Sort menu\n";
    cout << "\t\t5. Change car info\n";
    cout << "\t\t7. Remove cars\n";
    cout << "\t\t8. Exit\n";
    cout << "\nPlease make a choice (choose a number): ";
    cin >> chc;
    while (cin.fail())      //If user makes a wrong input, is prompted to re-enter until correct
            {
            failInput(chc); //Function for wrong input
            }

    switch(chc){            //Switching user's chc to make selections in the menu
        case 1:
            addCars(myGarage);
        break;
        case 2:
            printCars(myGarage);
        break;
        case 3:
            Car::printGarageInfo();
        break;
        case 4:
            sortMenu(myGarage);
            system("CLS");  //Clearing screen for better visibility
        break;
        case 5:
            modifyCars(myGarage);
        break;
        case 6:
            removeCars(myGarage);
            break;
        case 7:
            removeCars(myGarage);
            writeInfo(myGarage);
            break;
        case 8:
            break;
        default:
            cout << "Invalid choice, try again:" << endl;
            break;

        }

    }while(chc !=8);        //Until the user inputs 8, the menu will be shown, 8 will close the program

    return 0;
}


void readInfo(vector<Car>& newMyGarage){
    string brand;   //Declaring string brand for class Car's object.brand
    int year;       //Same for object.year
    double price;   //Same for object.price
    ifstream fromFile;  //Reading from file
    ofstream toFile;    //Writing to file

    toFile.open("List.txt", ios::app);  //Creating a file "List.txt if there isn't one
    toFile.close();                     //Closing the file


    fromFile.open("List.txt");          //Reading from the file if there is any info so the program can start with what info it had before it closed
    while(true){                        //
        fromFile >> brand;              //Reading brand to use for object.brand
        fromFile >> year;               //Reading year to use for object.year
        fromFile >> price;              //Reading price to use for object.price
        if(fromFile.eof())              //When at end of file, terminate reading
        break;

    Car newCar(brand, year, price);     //Using overload constructor to make objects of class Car from reading the file
    newMyGarage.push_back(newCar);      //Inserting the newly created objects into vector myGarage by reference

    }
    fromFile.close();                   //closing the file
}

void addCars(vector<Car>& newMyGarage){ //Adding objects to vector by reference
    system("CLS");                      //Clearing screen for readability
    int garageSize;                     //Declaring an int so the user can choose how many cars would he like to add
    ofstream toFile;                    //Writing to file declaration

    cout << "How many cars would you like to add?";
    cin >> garageSize;
    while(cin.fail()){
        failInput(garageSize);
    }

    string brand;
    int year;
    double price;

    for(int i = 0; i < garageSize; i++){    //Loop to enter information about Class Car.object, garageSize = how many cars to add at once
    cout << "Car brand: ";
    cin >> brand;
    cout << "Car year: ";
    cin >> year;
    cout << "Car price: ";
    cin >> price;
    cout << endl;

    Car newCar(brand, year, price);         //Using overload constructor
    newMyGarage.push_back(newCar);          //Adding objects to vector from user input

    toFile.open("List.txt", ifstream::app); //Opening List.txt and updating the new information
    if(toFile.is_open()){                   //Writing while file is open and loop hasn't ended
        toFile << brand << " ";
        toFile << year << " ";
        toFile << price;
        toFile << endl;

        }
    toFile.close();
    }

}

void  printCars(vector<Car>& newMyGarage){  //Printing all the information from vector myGarage
    system("CLS");
    int vectorSize = newMyGarage.size();    //Declaring the size of the vector for efficiency in the loop, so it doesn't have to check every iteration
    cout << "\tBRAND\t" << "YEAR\t" << "PRICE\n\n";
    for(int i = 0; i < vectorSize; i++){    //For loop to print all the info to the screen
        cout << "#" << i + 1 << " \t" << newMyGarage[i].getBrand() << "\t";     //using getters to get private info from class Car
        cout << newMyGarage[i].getYear() << "\t";                               //same
        cout << "$" << newMyGarage[i].getPrice() << "\t";                       //same
        cout << endl;
    }
    cout << "-------------------------" << endl;
}

void sortMenu(vector<Car>& newMyGarage){    //Function to sort the vector myGarage by reference
    system("CLS");
    int chc;                                //user input
    do{                                     //Do while loop for main menu
        cout << "\t\tChoose sorting method\n\n";
        cout << "\t\t1. Sort by brand(asc)\n";
        cout << "\t\t2. Sort by brand(desc)\n";
        cout << "\t\t3. Sort by year (asc)\n";
        cout << "\t\t4. Sort by year (desc)\n";
        cout << "\t\t5. Sort by price(asc)\n";
        cout << "\t\t6. Sort by price(desc)\n";
        cout << "\t\t7. Exit\n";
        cin >> chc;

        while(cin.fail()){
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "You can only enter numbers\n";
            cout << "Enter a number: ";
            cin >> chc;
        }
        switch(chc){
        case 1:
            sort(newMyGarage.begin(), newMyGarage.end(), sortBrand);
            system("CLS");
            cout << "DONE" << endl;
        break;
        case 2:
            sort(newMyGarage.begin(), newMyGarage.end(), sortBrandDesc);
            system("CLS");
            cout << "DONE" << endl;
        break;
        case 3:
            sort(newMyGarage.begin(), newMyGarage.end(), sortYear);
            system("CLS");
            cout << "DONE" << endl;
        break;
        case 4:
            sort(newMyGarage.begin(), newMyGarage.end(), sortYearDesc);
            system("CLS");
            cout << "DONE" << endl;
        break;
        case 5:
            sort(newMyGarage.begin(), newMyGarage.end(), sortPrice);
            system("CLS");
            cout << "DONE" << endl;
        break;
        case 6:
            sort(newMyGarage.begin(), newMyGarage.end(), sortPriceDesc);
            system("CLS");
            cout << "DONE" << endl;
        break;
        case 7:
            break;
        default:
            cout << "Invalid choice, try again:" << endl;
            break;
        }
    }while(chc != 7);
}

void modifyCars(vector<Car>& newMyGarage){  //Function to modify info of Class Car.object
    system("CLS");

    string brnd;
    int yr;
    double prc;

    int chngCar;                            //User input for which car to me modified
    int vectorSize = newMyGarage.size();    //Efficiency
    cout << "Which car would you like to change?\n\n";
    cout << "N\tBRAND\t" << "YEAR\t" << "PRICE\n\n";
    for(int i = 0; i < vectorSize; i++){    //For loop to show the user all cars so he can see which he would like to change
        cout << "#" << i + 1 << " \t" << newMyGarage[i].getBrand() << "\t"; //Making it "i + 1" so it prints as object #1 instead of #0
        cout << newMyGarage[i].getYear() << "\t";
        cout << "$" << newMyGarage[i].getPrice() << "\t";
        cout << endl;
    }
    cout << "Select a number: ";
    cin >> chngCar;
    while(cin.fail()){
        failInput(chngCar);
    }
    while(chngCar > vectorSize || chngCar == 0 || chngCar < 0){     //If the user choice is bigger than available objects, equal to 0 or less than zero, will result in an incorrect input
        cout << "Car doesn't exist. Current number of cars is: " << Car::getNumcars() << ".\n"; //Showing the user how many cars are in the garage so he can make a valid choice
        cout << "Select a correct number: ";
        cin >> chngCar;

        while(cin.fail()){
        failInput(chngCar);
        }
    }

    cout << "Enter new brand: ";
    cin >> brnd;                                //string to pass as parameter to setBrand
    cout << "Enter new year: ";
    cin >> yr;                                  //int to pass as parameter to setYear
    cout << "Enter new price: ";
    cin >> prc;                                 //double to pass as parameter to setPrice

    newMyGarage[chngCar - 1].setBrand(brnd);    //Changing the info about the Car.objects with setters
    newMyGarage[chngCar - 1].setYear(yr);       // --
    newMyGarage[chngCar - 1].setPrice(prc);     // --

    ofstream toFile;                            //Writing to file again to update the info
    toFile.open("List.txt");                    //Opening "List.txt"
    for(int i = 0; i < vectorSize; i++){        //For loop to pass all the new information to the file
            toFile << newMyGarage[i].getBrand() << " ";
            toFile << newMyGarage[i].getYear() << " ";
            toFile << newMyGarage[i].getPrice();
            toFile << endl;

    }
    toFile.close();                             //closing file

    cout << "DONE" << endl;                     //Telling user all went well



}

void removeCars(vector<Car>& newMyGarage){      //Function to remove objects from vector and destroying objects
    int vectorSize = newMyGarage.size();        //Efficiency
    if(vectorSize == 0){                        //Telling the user that there are no objects to delete
        system("CLS");
        cout << "There are no cars in your garage!\n\n";
        return;                                 //Returning to main function
    }
    printCars(newMyGarage);                     //If there are objects to delete, showing possible ones

    int chc;                                    //User choice which object to delete

    cout << "Which car would you like to remove?\n\n";
    cin >> chc;
    while(cin.fail()){
        failInput(chc);
    }
    while(chc > vectorSize || chc == 0 || chc < 0){
        cout << "Car doesn't exist. Current number of cars is: " << Car::getNumcars() << ".\n";
        cout << "Select a correct number: ";
        cin >> chc;

        while(cin.fail()){
        failInput(chc);
        }
    }
    newMyGarage.erase(newMyGarage.begin() + (chc - 1));     //Removing the actual object from the vector.
    cout << "\nDONE";                                       //chc - 1 for better readability and so the user can delete at index 0 by choosing 1 ant etc.

}

void writeInfo(vector<Car>& newMyGarage){                   //Function to update file after made changes
    int vectorSize = newMyGarage.size();                    //Efficiency
    ofstream toFile;
    std::remove("List.txt");
    toFile.open("List.txt");

    for(int i = 0; i < vectorSize; i++){                    //For loop to write new info to file

            toFile << newMyGarage[i].getBrand() << " ";
            toFile << newMyGarage[i].getYear() << " ";
            toFile << newMyGarage[i].getPrice();
            toFile << endl;

            }
    toFile.close();
}

void failInput(int i){
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "You can only enter numbers!\n";
        cout << "Select a number: ";
        cin >> i;
}


