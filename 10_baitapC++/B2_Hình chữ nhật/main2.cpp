/*
* File: main2.cpp
* Author: MAI THANH DAT
* Date: 10/04/2023
* Description: This is file for Rectangle
*/

#include<stdio.h>
#include<math.h>

class rectangle
{
private:
    double length;
    double width;
public:
    rectangle(double length,double width);
    double area_calculation();
    double perimeter_calculation(); 
    double diagonal_line();
    void checkSquare();
    
};

/*
*Class: rectangle
*Constructor: rectangle
*Describe: This is Constructor of class rectangle
*Input:
   length - a double value
   width - a double value
*Output: None
*/
rectangle::rectangle(double length,double width)
{
    rectangle::length = length;
    rectangle::width = width;
    if (length <=0 || width <=0)
    {
        printf("Error. Kich thuoc khong hop le.\n");
    }  
}

//---------area_calculation---------------/
/*
* Class: Rectangle
* Function: area_calculation
* Description: This function use for get Area of Rectangle
* Input:
*   Don't have input parameters
* Output:
*   return: Area of Rectangle
*/
double rectangle::area_calculation()
{
    return length * width;
}

//---------perimeter_calculation-----------------/
/*
* Class: Rectangle
* Function: perimeter_calculation
* Description: This function use for get perimeter of rectangle
* Input:
*   Don't have input parameters
* Output:
*   return: perimeter of rectangle
*/
double rectangle::perimeter_calculation()
{
    return (length + width)*2;
}

//---------diagonal_line calculatation------------/
/*
* Class: Rectangle
* Function: diagonal_line
* Description: This function use for get diagonal line of rectangle
* Input:
*   Don't have input parameters
* Output:
*   return: diagonal line of rectangle
*/
double rectangle::diagonal_line()
{
    return (double)(sqrt(pow(length, 2) + pow(width, 2)));
}

//---------------Check its square-------------------/
/*
* Class: Rectangle
* Function: checkSquare
* Description: This function use for check if it is a square or not
* Input:
*   Don't have input parameters
* Output:
*   return: diagonal line of rectangle
*/
void rectangle::checkSquare()
{
    if(length == width)
    {
        printf("Day la hinh vuong.\n");
    }
    else{
        printf("Day la hinh chu nhat, khong phai hinh vuong.\n");
    }
}

int main(int argc, char const *argv[])
{
    rectangle rtg(4,4);
    printf("Dien tich: %.2lf\n", rtg.area_calculation());
    printf("Chu vi: %.2lf\n", rtg.perimeter_calculation());
    printf("Do dai duong cheo: %.2lf\n", rtg.diagonal_line());
    rtg.checkSquare();
    return 0;
}
