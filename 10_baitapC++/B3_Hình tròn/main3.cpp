/*
* File: main3.cpp
* Author: MAI THANH DAT
* Date: 10/04/2023
* Description: This is file for circle
*/
#include<stdio.h>
#include<math.h>

class Circle
{
private:
    double radius;
public:
    Circle(double radius);
    void perimeter();
    void area();
    
};

/*
*Class: Circle
*Constructor: Circle
*Describe: This is Constructor of class Circle
*Input:
   radius - a double value
*Output: None
*/
Circle::Circle(double radius)
 {
    Circle::radius=radius;
    if (radius <=0)
    {
        printf("Ban kinh khong hop le.\n");
    }
       
 }


/*
* Class: Circle
* Function: Area
* Description: This function use for get area of circle
* Input:
*   Don't have input parameters
* Output:
*   return: area of circle
*/
void Circle::area()
{
    if (radius <=0)
    {
        printf("Ban kinh khong hop le.\n");
    }
    else{
    double area = (M_PI)*radius;
    printf("Dien tich hinh tron R = %.2lf la: %.2lf\n",radius,area);
    }
}


/*
* Class: Circle
* Function: Perimeter
* Description: This function use for get perimeter of circle
* Input:
*   Don't have input parameters
* Output:
*   return: perimeter of circle
*/
void Circle::perimeter()
{
    if (radius <=0)
    {
        printf("Ban kinh khong hop le.\n");
    }
    else{
    double perimeter = 2*M_PI*radius;
    printf("Chu vi hinh tron R = %.2lf la: %.2lf\n",radius, perimeter);
    }
}




int main(int argc, char const *argv[])
{
    Circle cr(4);
    cr.area();
    cr.perimeter();
    return 0;
}
