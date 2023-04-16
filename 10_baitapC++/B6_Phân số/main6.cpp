/*
* File: main6.cpp
* Author: MAI THANH DAT
* Date: 10/04/2023
* Description: This is file for 2 fraction
*/

#include<stdio.h>
#include<stdint.h>
#include<math.h>


class Fraction
{
private:
    float numerator ; //tử số
    float denominator; // mẫu số
public:
    Fraction(){};
    Fraction(float numerator, float denominator);
    double addition(Fraction x1, Fraction x2);  // phép cộng
    double subtraction(Fraction x1, Fraction x2);  // phép trừ
    double multiplication(Fraction x1, Fraction x2); // Phép nhân 
    double division(Fraction x1, Fraction x2);  // Phép chia
};

/*
*Class: Fraction
*Describe: This is Constructor of class Fraction
*Input: 
   numerator - a float value
   denominator - a float value
*Output: None
*/
Fraction::Fraction(float numerator, float denominator)
{
    int i;
    if (denominator == 0)
    {
        printf("Error!!!!! Mau so phai khac 0");
    }
    
    Fraction::numerator = numerator;
    Fraction::denominator = denominator;
    printf("Phan so %d: %.2f/%.2f \n",i+1, numerator, denominator);
    i++;

}

/*
* Class: Fraction
* Function: addition
* Description: This function use for calculate addition.
* Input:
*   fraction 1, fraction 2.
* Output:
*   return: value of the sum of 2 fractions
*/
double Fraction::addition(Fraction x1, Fraction x2)
{
    float _numerator, _denominator;
	_numerator = (x1.numerator * x2.denominator) + (x1.denominator * x2.numerator);
	_denominator = x1.denominator * x2.denominator;
	return (double)_numerator/_denominator;    
}

/*
* Class: Fraction
* Function: subtraction
* Description: This function use for calculate subtraction.
* Input:
*   fraction 1, fraction 2.
* Output:
*   return: value of the subtraction of 2 fractions
*/
double Fraction::subtraction(Fraction x1, Fraction x2)
{
    float _numerator, _denominator;
	_numerator= (x1.numerator * x2.denominator) - (x1.denominator * x2.numerator);
	_denominator = x1.denominator * x2.denominator;
	return (double)_numerator/_denominator; 

}

/*
* Class: Fraction
* Function: multiplication
* Description: This function use for calculate multiplication.
* Input:
*   fraction 1, fraction 2.
* Output:
*   return: value of the multiplication of 2 fractions
*/
double Fraction::multiplication(Fraction x1, Fraction x2)
{
    float _numerator, _denominator;
	_numerator= x1.numerator * x2.numerator;
	_denominator = x1.denominator * x2.denominator;
	return (double)_numerator/_denominator; 

}

/*
* Class: Fraction
* Function: division
* Description: This function use for calculate division.
* Input:
*   fraction 1, fraction 2.
* Output:
*   return: value of the division of 2 fractions
*/
double Fraction::division(Fraction x1, Fraction x2)
{
    float _numerator, _denominator;
	_numerator= x1.numerator * x2.denominator;
	_denominator = x1.denominator * x2.numerator;
	return (double)_numerator/_denominator; 

}

int main(int argc, char const *argv[])
{
    Fraction x1(2,3);
    Fraction x2(3,4);
    Fraction ft;
    
    printf("Tinh toan:  \n");
    printf("- Tong 2 phan so: %.2lf\n", ft.addition(x1, x2));
    printf("- Hieu 2 phan so: %.2lf\n", ft.subtraction(x1, x2));
    printf("- Tich 2 phan so: %.2lf\n", ft.multiplication(x1, x2));
    printf("- Thuong 2 phan so: %.2lf\n", ft.division(x1, x2));

    return 0;
}

