/*
* File: main9.cpp
* Author: MAI THANH DAT
* Date: 10/04/2023
* Description: This is a file for Book
*/

#include<stdio.h>
#include<stdint.h>
#include<math.h>
#include<string.h>
#include<vector>

using namespace std;

/*-------------------class Book--------------------*/
class Book
{
private:
    char name[50];
    char author[20];
    uint16_t publishing_year;
    uint16_t quantity;
public:
    Book(const char name[50], const char author[20], uint16_t publishing_year, uint16_t quantity);
    void setQuantity(uint16_t quantity);

    char* getNameOfBook();
    char* getAuthor();
    uint16_t getYear();
    uint16_t getQuantity();
};

/*
*Class: Book
*Constructor: Book
*Describe: This is constructor of class book
*Input: 
*   name - a character type ;
*   author - a character type ;
*   publishing_year - an integer value;
*   quantity - an integer value.
*Output: None
*/
Book::Book(const char name[50], const char author[20], uint16_t publishing_year, uint16_t quantity)
{
    strcpy(Book::name, name);
    strcpy(Book::author, author);
    Book::publishing_year = publishing_year;
    Book::quantity = quantity;
}

/*
* Class: Book
* Function: setQuantity
* Description: This function use for set quantity of book
* Input:
*   quantiy - quantity of book
* Output:
*   return: none
*/
void Book::setQuantity(uint16_t quantity){
   this->quantity = quantity;
}


/*
* Class: Book
* Function: getNameOfBook
* Description: This function use for get name of book
* Input:
*   Dont have input parameters
* Output:
*   return: name of book
*/
char* Book::getNameOfBook(){
    return name;
}

/*
* Class: Book
* Function: getAuthor
* Description: This function use for get author of book
* Input:
*   Dont have input parameters
* Output:
*   return: author of book
*/
char* Book::getAuthor(){
    return author;
}

/*
* Class: Book
* Function: getYear
* Description: This function use for get year of book
* Input:
*   Dont have input parameters
* Output:
*   return: year of book
*/
uint16_t Book::getYear(){
    return publishing_year ;
}

/*
* Class: Book
* Function: getQuantity
* Description: This function use for get quantity of book
* Input:
*   Dont have input parameters
* Output:
*   return: quantity of book
*/
uint16_t Book::getQuantity(){
    return quantity;
}

/*
* Class: Book
* Function: showInformation
* Description: This function use for show information of book
* Input:
*   Dont have input parameters
* Output:
*   return: none
*/


/*-------------------class Menu--------------------*/
class Menu
{
private:
    static vector<Book> dataBook;
public:
    void addBook(Book book);
    void borrow(const char* name, uint16_t quantity);
    void giveBack(const char* name, uint16_t quantity);
    void showListBook();
};

vector<Book> Menu::dataBook;

/*
* Class: Menu
* Function: addBook
* Description: This function use for add book to list book
* Input:
*   book - book for add 
* Output:
*   return: none
*/
void Menu::addBook(Book book)
{
    dataBook.push_back(book);
}


/*
* Class: Library
* Function: borrowBook
* Description: This function use for borrow book
* Input: none
* Output:
*   return: none
*/

void Menu::borrow(const char* nameofbook, uint16_t quantity){
    if(dataBook.empty()){
        printf("CHUA CO DU LIEU SACH\n");
        return;
    }

    for(Book &book : dataBook){
        if(strcmp(book.getNameOfBook(), nameofbook) == 0)
        {
            if(book.getQuantity() < quantity)
            {
                printf("SO LUONG SACH CON LAI KHONG DU\n");
                return;
            }
            printf("DA MUON THANH CONG\n");
            book.setQuantity(book.getQuantity() - quantity);
        }
    }
}


/*
* Class: Library
* Function: giveBookBack
* Description: This function use for give book back
* Input: none
* Output:
*   return: none
*/
void Menu::giveBack(const char* name, uint16_t quantity)
{
    int i;
    for(Book &book : dataBook)
    {
        if(strcmp(book.getNameOfBook(), name) == 0)
        {
            printf("DA TRA THANH CONG\n");
            book.setQuantity(book.getQuantity() + quantity);
        }
        else if(i == dataBook.size() )
        {
            printf("Day khong phai sach da muon.\n");
        }
        i++;
    }
}

/*
* Class: Library
* Function: showListBook
* Description: This function use for show list book
* Input:
*   Dont have input parameters
* Output:
*   return: none
*/
void Menu::showListBook(){
    if(dataBook.empty()){
        printf("CHUA CO DU LIEU SACH\n");
    }
    else 
    printf("STT\tTEN SACH\tTAC GIA\t\tNAM XUAT BAN\tSO LUONG\n");
    for(int i=0; i< dataBook.size(); i++)
    {
        printf("%d\t%s\t\t%s\t%d\t\t%d\n", i, dataBook[i].getNameOfBook(), dataBook[i].getAuthor(), dataBook[i].getYear(), dataBook[i].getQuantity());
    }
}

int main(int argc, char const *argv[])
{
    Book book1("A", "Dale Carnegie", 1936, 15);
    Book book2("B", "Mario Puzo", 1969, 6);
    Book book3("C", "Fujiko Fujio", 1996, 20);

    Menu mn;
    mn.addBook(book1);
    mn.addBook(book2);
    mn.addBook(book3);

    mn.showListBook();
    printf("----Muon 5 sach A, 6 sach B-------- \n");
    mn.borrow("A", 5);
    mn.borrow("B", 6);
    mn.showListBook();
    printf("----Tra 3 sach C-------- \n");
    mn.giveBack("C", 3);
    mn.showListBook();
    return 0;
}



