#include <stdio.h>

char arr[] = "The Grammy award-winning singer. who has been less active on digital platforms in recent weeks. Explained her decision to distance herself from social media platforms during an appearance on the Conan OBrien Needs a Friend podcast, alongside her brother Finneas";

//Cau 1: Viet mot chuyen dao nguoc VD: "Finneas brother her alongside .... Grammy The"
void dao()
{
    int length = sizeof(arr);
    int dem=0;
    for(int i =length; i>=0; i--) // xét từ vị trí cuối cùng của mảng 
    {
        dem++; // biến đếm để đếm số lượng chữ cái trong 1 từ 
        if(*(arr + i) == ' ') // nếu xét đến vị trí dấu cách
        {
            for(int j = i+1; j < i + dem ; j++)  // i+1 là ký tự sau dấu cách, i+dem là độ dài của từ 
            {
                printf("%c", *(arr + j));    // in lần theo thứ tự đúng của chữ
            }
            printf("%c", ' ');            // thêm dấu cách
            dem=0;                       // trả biến đếm về 0 để tính độ dài của từ tiếp theo
        }
        if (i == 0) // in ra chữ đầu tiên. VD "The"
        {
            for (int j = 0; j < length; j++) // xét từ đầu chuỗi. khi gặp dấu cách thì in ra chữ đầu tiên và break luôn
            {
                if (*(arr + j) == ' ')
                {
                    for (int k = 0; k < j; k++)
                    {
                        printf("%c", *(arr + k));
                    }
                    break;  // sau khi in ra chữ đầu tiên xong break luôn khỏi vòng for
                }
            }
        } 
    }
    
}
//cau 2: In Hoa chu cai dau tien sau dau cham
void in_hoa_sau_cham()
{
    for(int i=0; i<sizeof(arr); i++)
    {
          
        if(*(arr+i) =='.' && 97<=*(arr+i+2) && *(arr+i+2)<= 122)  // dựa vào bảng ASCII từ a(=97)-> z(122)
        {
            *(arr+i+2) = *(arr+i+2)-32;    // nếu sau dấu chấm, chữ sau dấu chấm là chữ thường thì đổi thành chữ in hoa(chữ thường-32= chữ in hoa)
        }
        printf("%c", *(arr+i));
    }
}
//Cau 3: Chuyen doi tat ca doan van thanh chu thuong
void in_thuong()
{
    for(int i=0; i<sizeof(arr); i++)
    {
          
        if( 65<=*(arr+i) && *(arr+i)<= 90)   // dựa vào bảng ASCII từ A(65)-> Z(90)
        {
            *(arr+i) = *(arr+i)+32;    // chữ in hoa + 32 = chữ in thường
        }
        printf("%c", *(arr+i));
    }
}
//Cau 4: Chuyen doi tat ca doan van thanh chu hoa
void in_hoa()
{
    for(int i=0; i<sizeof(arr); i++)
    {
          
        if(97<=*(arr+i) && *(arr+i)<= 122)  // dựa vào bảng ASCII từ a(=97)-> z(122)
        {
            *(arr+i) = *(arr+i)-32;  // chữ thường -32 = chữ in hoa
        }
        printf("%c", *(arr+i));
    }
}


int main(int argc, char const *argv[])
{
    printf("1,Chuoi dao nguoc: \n");
    dao();
    printf("\n----------------------\n");
    printf("2,In Hoa chu cai dau tien sau dau cham: \n");
    in_hoa_sau_cham();
    printf("\n----------------------\n");
    printf("3,Chuyen doi doan van thanh chu thuong: \n");
    in_thuong();
    printf("\n-----------------------\n");
    printf("4,Chuyen doi doan van thanh chu hoa: \n");
    in_hoa();
    return 0;
}
