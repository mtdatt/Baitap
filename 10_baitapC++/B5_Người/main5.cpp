/*
* File: main5.cpp
* Author: MAI THANH DAT
* Date: 10/04/2023
* Description: This is file for Person
*/
#include<stdio.h>
#include<stdint.h>
#include<string.h>

class Person
{
private:
    char name[20];
    uint8_t age;
    char address[20];
public:
    Person();
    void getInformation();
};

/*
* Class: Person
* Description: This is Constructor of class Person
* Input:
*   None
* Output:
*   return: none
*/
Person::Person()
{
    const char* name = Person::name;
    const char* address = Person::address;
    uint8_t age;
    

    printf("Nhap thong tin: \n");
    printf("Nhap ten: ");
    scanf("%s", name);
    printf("Nhap dia chi: ");
    scanf("%s", address);
    printf("Nhap tuoi: ");
    scanf("%d", &age);
    Person::age = age;


}

/*
* Class: Person
* Function: getInformation
* Description: This function use for get information of person.
* Input:
*   None
* Output:
*   return: information of person
*/
void Person::getInformation()
{
    printf("Thong tin: \n");
    printf("Name| Age | Address\n");

    printf("%s  | %d  | %s", name, age, address );

}


int main(int argc, char const *argv[])
{
        
    Person pr;
    pr.getInformation();
    
    return 0;
}
