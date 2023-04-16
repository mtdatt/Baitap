/*
* File: main1.cpp
* Author: MAI THANH DAT
* Date: 10/04/2023
* Description: This is file for point coordinates
*/

#include<stdio.h>
#include<stdint.h>
#include<math.h>

using namespace std;
/*----------------------------Class Point-----------------------------------*/
class Point
{
private: 
    float ordinate;  // tung do
    float abscissa; // hoanh do

public:
    Point(float ordinate = 0, float abscissa=0) ;
    float getOrdinate() {return Point::ordinate; };
    float getAbscissa() {return Point::abscissa; };
};

/*
*Class: Point
*Constructor: Point
*Describe: This is Constructor of class Point
*Input:
   ordinate - a float value
   abscissa - a float value
*Output: None
*/
Point:: Point(float ordinate, float abscissa){
    Point::ordinate = ordinate;
    Point::abscissa = abscissa;
}
/*----------------------------Class SpaceMath--------------------------------*/
class SpaceMath
{
private:
    Point firstCoordinate; // diem 1
    Point secondCoordinate; // diem 2
    Point thirdCoordinate;  // diem 3

public: 
    SpaceMath(Point firstCoordinate , Point secondCoordinate ); // tinh khoang cach
    SpaceMath(Point firstCoordinate , Point secondCoordinate, Point thirdCoordinate); // tinh dien tich tam giac
    double calculateDistance();
    double calculateAreaOfTriangle();
};
/*------------------Calculate Distance--------------------------------------*/
SpaceMath::SpaceMath(Point fistCoordinate ,Point secondCoordinate )
{
    SpaceMath::firstCoordinate = fistCoordinate;
    SpaceMath::secondCoordinate = secondCoordinate;
    printf("Khoang cach giua 2 diem la: %lf\n", calculateDistance());
}

/*
* Class: SpaceMath
* Function: calculateDistance
* Description: This is the function to calculate the distance between 2 points
* Input:
*   Don't have input parameters
* Output:
*   return: Distance between 2 points
*/
double SpaceMath::calculateDistance()
{

   return  sqrt( pow((secondCoordinate.getOrdinate() - firstCoordinate.getOrdinate()),2) \
                       + pow((secondCoordinate.getAbscissa() - firstCoordinate.getAbscissa()),2) ) ;
    
}
/*-------------------Calculate Area Of Striangle----------------------------*/
SpaceMath::SpaceMath(Point firstCoordinate,Point secondCoordinate,Point thirdCoordinate)
{
  SpaceMath::firstCoordinate = firstCoordinate;
  SpaceMath::secondCoordinate = secondCoordinate;
  SpaceMath::thirdCoordinate = thirdCoordinate;
  printf("Dien tich tam giac tu 3 diem la: %lf\n", calculateAreaOfTriangle());
}


/*
* Class: SpaceMath
* Function: calculateAreaOfTriangle
* Description: This is the function to calculate the area of ​​a triangle formed by 3 points
* Input:
*   Don't have input parameters
* Output:
*   return: Area of ​​a triangle formed by 3 points
*/
double SpaceMath::calculateAreaOfTriangle()
{
    double distance_a = sqrt(pow(firstCoordinate.getOrdinate() - secondCoordinate.getOrdinate(),2)\
                           + pow(firstCoordinate.getAbscissa() - secondCoordinate.getAbscissa(),2));
    double distance_b = sqrt(pow(firstCoordinate.getOrdinate() - thirdCoordinate.getOrdinate(),2)\
                           + pow(firstCoordinate.getAbscissa() - thirdCoordinate.getAbscissa(),2));
    double distance_c = sqrt(pow(thirdCoordinate.getOrdinate() - secondCoordinate.getOrdinate(),2) \
                           + pow(thirdCoordinate.getAbscissa() - secondCoordinate.getAbscissa(),2));
    double p = (distance_a + distance_b + distance_c) / 2;
    return (double)(sqrt(p*(p - distance_a)*(p - distance_b)*(p - distance_c)));
}


int main(int argc, char const *argv[])
{
    // Point point(8,9);
    // printf("x=%d, y=%d\n", point.getOrdinate(), point.getAbscissa());
    typedef enum{
        DISTANCE = 1 ,
        AREA_OF_TRIANGLE
    }Math;

    Math math;

    Point point1(5.1, 9);
    Point point2(3, 3);
    Point point3(5, 6);
    
    do{
        printf("----------------------------------------------\n");
        printf("1, Tinh khoang cach 2 diem.\n");
        printf("2, Tinh dien tich tam giac tu 3 diem.\n");
        printf("3, Ket thuc truong trinh.\n");
        printf("Chon yeu cau: ");
        scanf("%d", &math);
    switch (math)
    {
    case DISTANCE:

        SpaceMath(point1 , point2);
        break;
    case AREA_OF_TRIANGLE: 
        SpaceMath(point1, point2, point3);
        break;
    case 3:
        printf("Ket thuc ctrinh.\n");
        return 0;
    default:
        printf("Hay lua chon yeu cau phu hop\n");
        break;
    }
    }while (1);
    

    return 0;
}

