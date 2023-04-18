/*
* File: main8.cpp
* Author: MAI THANH DAT
* Date: 10/04/2023
* Description: This is file for Bank account
*/

#include<stdio.h>
#include<stdint.h>
#include<math.h>
#include<string.h>
#include<vector>
using namespace std;

class Bank_Account
{
private:
    char account_name[50];
    uint64_t account_number;
    uint64_t surplus; // so du
public:
    Bank_Account(const char* name, const uint64_t number, const uint64_t surplus);
    void withdraw_Money();  // rut tien
    void deposit_Money();   // nap tien
    void check_Surplus();
};

/*
*Class: Bank_Account
*Constructor: Bank_Account
*Describe: This is constructor of class Bank_Account
*Input: 
*   name - a character type ;
*   number - an integer value;
*   surplus - an integer value.
*Output: None
*/
Bank_Account::Bank_Account(const char* name, const uint64_t number, const uint64_t surplus)
{
    strcpy(Bank_Account::account_name, name);
    Bank_Account::account_number = number;
    Bank_Account::surplus = surplus;
}

/*
 * class: Bank_Account
 * Function: withdraw_Money
 * Describe: This is the function to withdraw money from the bank account
 * Input: money - an integer value
 * Output: none.
*/
void Bank_Account::withdraw_Money()
{
    uint64_t money;
    printf("Nhap so tien can rut: ");
    scanf("%d", &money);
    if(surplus ==0 )
    {
        printf("So du khong du de rut.\n");
    }
    else
    {
        Bank_Account::surplus = surplus - money;
        printf(" Ban da rut thanh cong %d$ ra khoi tai khoan.\n", money);
        
    }
}

/*
 * class: Bank_Account
 * Function: deposit_Money
 * Describe: This is the function to deposit money from the bank account
 * Input: money - an integer value
 * Output: none.
*/
void Bank_Account::deposit_Money()
{
    uint64_t money;
    printf("Nhap so tien can nap: ");
    scanf("%d", &money);
    Bank_Account::surplus = surplus + money;
    printf(" Ban da nap thanh cong %d$ vao tai khoan.\n", money);
}

/*
 * class: Bank_Account
 * Function: check_Surplus
 * Describe: This is the function to check money of the bank account
 * Input: none
 * Output: none.
*/
void Bank_Account::check_Surplus()
{
    printf("So du hien tai la: %d\n", surplus);
}


int main(int argc, char const *argv[])
{
    Bank_Account bnk_ac("Agrri bank", 9999, 1000);

    int i=0;
    do
    {
        
        printf("----Welcome to your bank account----: \n");
        printf("1, Rut tien.\n");
        printf("2, Nap tien.\n");
        printf("3, Kiem tra so du.\n");
        printf("4, Thoat.\n");
        printf("=>Chon giao dich ban muon thuc hien: ");
        scanf("%d",&i);
        switch (i)
        {
        case 1:
            bnk_ac.withdraw_Money();
            break;
        case 2:
            bnk_ac.deposit_Money();
             break;
        case 3:
            bnk_ac.check_Surplus();
            break;
        case 4:
            printf("Ket thuc giao dich.\n");
            return 0;
        default:
            printf("Hay lua chon dung yeu cau.\n");
            break;
        }

        
    } while (1);
    

    return 0;
}

