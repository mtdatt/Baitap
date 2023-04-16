/*
* File: main7.cpp
* Author: MAI THANH DAT
* Date: 10/04/2023
* Description: This is file for Date(Day_Month_Year)
*/

#include<stdio.h>
#include<stdint.h>
#include<math.h>

class Date
{
private:
    uint8_t day;
    uint8_t month;
    uint8_t year;
public:
    Date(){};
    Date(uint8_t day,uint8_t month ,uint16_t year);
    void calculate_Age(Date today, Date birthday);
    void check_holiday();
};

/*
*Class: Date
*Describe: This is constructor of class Date
*Input: 
*   day - an integer value;
*   month - an integer value;
*   year- an integer value.
*Output: None
*/
Date::Date(uint8_t day,uint8_t month ,uint16_t year)
{   
// month
    if(month > 12 || month <=0)
    {
        printf("Thang khong hop le.\n");
    }
    else Date::month = month;
// year
    if(year <= 0) 
    {
        printf("Nam khong hop le.\n");
    }
    else Date::year = year;

// day
    if(day >31 || day <= 0)
    {
        printf("Ngay khong hop le.\n");
    }
    Date::day = day;
}


/*
 * class: Date
 * Function: calculate_Age
 * Describe: This is the function to calculate age
 * Input:
 *   today , birthday.
 * Output: age 
*/
void Date::calculate_Age(Date today, Date birthday)
{
    Date age;
    int _DAY;

    if(today.year < birthday.year)
    {
        perror("Error. Today phai lon hon Birthday"); 
    }
    
    // if(birthday.month == 1 || birthday.month == 3 || birthday.month == 5\
    //   || birthday.month ==7 || birthday.month ==8 || birthday.month ==10 || birthday.month ==12) //những tháng có 31 ngày: 1,3,5,7,8,10,12
    // {
    //     _DAY= 31;       
    // }
    // else if(birthday.month == 4 || birthday.month ==6 \
    //        || birthday.month ==9 || birthday.month ==11)  //những tháng có 30 ngày: 4,6,9,11
    // {
    //     _DAY =30;
    // }
    // else if( birthday.year%4==0 && birthday.year % 100 !=0)  // năm không nhuận
    // {
    //     _DAY = 28;  // tháng 2 có 28 ngày năm không nhuận
    // }
    // else 
    // {
    //     _DAY =29;   // năm nhuận tháng 2 có 29 ngày 
    // }

    
// calculate Age
    if(today.month <= birthday.month  && today.day < birthday.day)
    {
        age.year = today.year - birthday.year - 1;  // nếu chưa tới sinh nhật thì năm -1 
    }
    else age.year = today.year - birthday.year;     


    printf("Tuoi hien tai la: %d tuoi.\n", age.year);

}

/*
 * class: Date
 * Function: check_holiday
 * Describe: This is the function to check if today is holiday or not
 * Input: none
 * Output: today is holiday or not.
*/
void Date::check_holiday()
{
    if(day == 1 && month == 1){
        printf("Hom nay la ngay TET DUONG LICH\n");
    }
    else if(day == 8 && month == 3){
        printf("Hom nay la QUOC TE PHU NU\n");
    }
    else if(day == 30 && month == 4){
        printf("Hom nay la ngay GIAI PHONG MIEM NAM, THONH NHAT DAT NUOC\n");
    }
    else if(day == 1 && month == 5){
        printf("Hom nay la ngay QUOC TE LAO DONG\n");
    }
    else if(day == 1 && month == 6){
        printf("Hom nay la ngay QUOC TE THIEU NHI\n");
    }
    else if(day == 2 && month == 9){
        printf("Hom nay la ngay QUOC KHANH\n");
    }
    else{
        printf("Hom nay KHONG PHAI NGAY NGHI LE\n");
    }
}

int main(int argc, char const *argv[])
{
    Date date;
    Date birthday(21, 3, 2000);
    Date today(8, 3, 2023);

    printf("--------------------\n");
    date.calculate_Age(today, birthday);
    today.check_holiday();
    return 0;
}
