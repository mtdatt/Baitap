/*
* File: main9.cpp
* Author: MAI THANH DAT
* Date: 10/04/2023
* Description: This is file for car
*/

#include<stdio.h>
#include<stdint.h>
#include<math.h>
#include<string.h>

using namespace std;

class Car
{
private:
    char color[10];  
    char type_Engine[10]; // thông số động cơ
    double kilometers;  // số km đã đi
public:
    Car(const char *color, const char* type_Engine, double kilometers);
    double maintenance_Cost();  //maintenance cost calculate
    void check_Km(); // check the number of kilometers traveled
    void Show_Information();
};

/*
*Class: Car
*Constructor: Car
*Describe: This is constructor of class Car
*Input: 
*   color - a character type ;
*   type_Engine - a character type ;
*   kilometers - a double value.
*Output: None
*/
Car::Car(const char* color, const char* type_Engine, double kilometers)
{
    Car::kilometers = kilometers;
    strcpy(Car::color, color);
    strcpy(Car::type_Engine, type_Engine);
}


/*
*Class: Car
*Function: maintenance_Cost 
*Describe: This is the function used to calculate maintenance cost of car
*Input: Dont have input parameters
*Output: maintenance cost of car
*/
double Car::maintenance_Cost()
{
    if(kilometers < 5000) return (uint32_t)50;
    else if(kilometers < 15000) return (uint32_t)100;
    else if(kilometers < 30000) return (uint32_t)200;
    else if(kilometers < 40000) return (uint32_t)350;
    else if(kilometers < 100000) return (uint32_t)500;
    else return (uint32_t)600;
}

/*
*Class: Car
*Function: check_Km 
*Describe: This is the function used to check the number of kilometers traveled
*Input: Don't have input parameters
*Output: Don't have output
*/
void Car::check_Km()
{
    printf("So km da di la: %.1lf km\n", kilometers);
}

/*
*Class: Car
*Function: check_Km 
*Describe: This is the function used to show information of car
*Input: Don't have input parameters
*Output: Don't have output
*/
void Car::Show_Information()
{
    printf("Thong tin xe: \n");
    printf("Color: %s | Type of Engine: %s | Km: %.1lf km\n", color, type_Engine, kilometers);
}

int main(int argc, char const *argv[])
{
    Car car("Red", "Camry", 11200);

    car.Show_Information();
    car.check_Km();
    printf("Chi phi bao duong xe la %.2lf$\n", car.maintenance_Cost());

    return 0;
}
