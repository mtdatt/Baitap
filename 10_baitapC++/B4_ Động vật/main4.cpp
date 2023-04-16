/*
* File: main4.cpp
* Author: MAI THANH DAT
* Date: 10/04/2023
* Description: This is file for animal
*/

#include<stdio.h>
#include<stdint.h>
#include<math.h>
#include<string.h>
#include <stdarg.h>

using namespace std;

class Animal
{
private:
    char name[20];
    int age;
    double weight;
    double height;

public:
    Animal(){}
    Animal(const char *name, int age, double weight, double height);
    char* getName();
    uint8_t getAge();
    double getWeight();
    double getHeight();
    double BMI();
    void compareAge(int num, ...);
    void compareWeight(int num, ...);
};

/*
*Class: Animal
*Describe: This is Constructor of class Animal
*Input: name - a character type
   age - an integer value
   weight - a double value
   height - a double value
*Output: None
*/
Animal::Animal(const char *name, int age, double weight, double height)
{
    Animal::age = age;
    Animal::height = height;
    Animal::weight = weight;
    strcpy(Animal::name, name);    
}

/*
* Class: Animal
* Function: getName
* Description: This function use for get name of animal
* Input:
*   Don't have input parameters
* Output:
*   return: name of animal
*/
char* Animal::getName(){
    return name;
}

/*
* Class: Animal
* Function: getAge
* Description: This function use for get age of animal
* Input:
*   Don't have input parameters
* Output:
*   return: age of animal
*/
uint8_t Animal::getAge(){
    return age;
}
/*
* Class: Animal
* Function: getWeight
* Description: This function use for get weight of animal
* Input:
*   Don't have input parameters
* Output:
*   return: weight of animal
*/
double Animal::getWeight()
{
    return weight;
}

/*
* Class: Animal
* Function: getHeight
* Description: This function use for get height of animal
* Input:
*   Don't have input parameters
* Output:
*   return: height of animal
*/
double Animal::getHeight(){
    return height;
}
/*
* Class: Animal
* Function: BMI
* Description: This function use for get BMI of animal
* Input:
*   Don't have input parameters
* Output:
*   return: BMI of animal
*/
double Animal::BMI()
{
    return weight/(height * height);

}


/*
* Class: Animal
* Function: cpmpareAge
* Description: This function use for compare age of animals
* Input:
*   num - number of animals
*   ... - Animal for compare
* Output:
*   return: None
*/

void Animal::compareAge(int num, ...)
{
    uint8_t max_age = 0;
    uint8_t count = 0;
    Animal animal;
    va_list args;

    va_start(args, num);
    max_age = va_arg(args, Animal).getAge();  // gán tuổi max = tuổi của đối tượng đầu tiên trong mảng args 
    for(int i=0; i < num - 1; i++)
    {
        animal = va_arg(args, Animal);
        if(max_age < animal.getAge()){  
            max_age = animal.getAge();   // Nếu tuổi max nhỏ hơn tuổi của đối tượng tiếp theo thì age max = age của đối tượng lớn hơn đó
        }
    }

    va_end(args);

    va_start(args, num);
    for(int i=0; i<num; i++){
        animal = va_arg(args, Animal);
        if(max_age == animal.getAge())
        {
            if(count > 0) printf("va ");  // nếu xuất hiện thêm 1 đối tượng nữa có tuổi = max_gae thì thêm "và"
            printf("\n%s ",animal.getName());
            count ++;     // đếm số phần tử có tuổi lớn nhất
        }
    }
    va_end(args);
    printf("co tuoi lon nhat\n");
}


/*
* Class: Animal
* Function: compareWeight
* Description: This function use for compare weight of animals
* Input:
*   num - number of animals
*   ... - Animal for compare
* Output:
*   return: None
*/
void Animal::compareWeight(int num, ...){
    uint8_t max_weight = 0;
    uint8_t count = 0;
    Animal animal;
    va_list args;

    va_start(args, num);
    max_weight = va_arg(args, Animal).getWeight();  // gán cân nặng max = cân của đối tượng đầu tiên trong mảng args 
    for(int i=0; i < num - 1; i++)
    {
        animal = va_arg(args, Animal);
        if(max_weight < animal.getWeight()){
            max_weight = animal.getWeight();
        }
    }

    va_end(args);

    va_start(args, num);
    for(int i=0; i<num; i++){
        animal = va_arg(args, Animal);
        if(max_weight == animal.getWeight())
        {
            if(count > 0) printf("va ");  // nếu xuất hiện thêm 1 đối tượng nữa có tuổi = max_gae thì thêm "và"
            printf("%s ",animal.getName());
            count ++ ;   // đếm số phần tử có cân năng lớn nhất
        }
    }
    va_end(args);
    printf("nang nhat\n");
}


 int main(int argc, char const *argv[])
 {
    // animal(ten, tuoi, can nang, chieu cao)
    Animal Ho("Ho", 3, 30.5, 2);
    Animal Khi("Khi", 5, 20.3, 1.5);
    Animal Huou("Huou cao co", 3, 120, 10);

    printf("Name\t   | Age| Weight | Height | BMI\n");
    printf("%s\t   | %d\t| %.2lf\t | %.2lf   | %.2lf\n", Ho.getName(),Ho.getAge(), Ho.getWeight(), Ho.getHeight() ,Ho.BMI());
    printf("%s\t   | %d\t| %.2lf\t | %.2lf   | %.2lf\n", Khi.getName(),Khi.getAge(), Khi.getWeight(), Khi.getHeight() ,Khi.BMI());
    printf("%s| %d\t| %.2lf | %.2lf  | %.2lf\n", Huou.getName(),Huou.getAge(), Huou.getWeight(), Huou.getHeight() ,Huou.BMI());

    Animal animal;
    animal.compareAge(3, Ho, Khi, Huou);
    animal.compareWeight(3,  Ho, Khi, Huou);

    return 0;

 }
 