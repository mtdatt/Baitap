#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

//mang bat ky vd arr[] = {1, 7, 8, 2, 3, 8, 3, 7, 6, 7, 8, 8, 2}
// sap xep mang theo thu tu tang dan
// liet ke cac phan tu co so lan xuat hien vd: 1 xuat hien 1 lan
//                                             7 xuat hien 2 lan
//                                             8 xuat hien 3 lan
typedef struct{
    uint8_t size;
    uint8_t *firstAdd;
}typeArray;

int randomA(int minN, int maxN){
 return minN + rand() % (maxN + 1 - minN);
}

void randomArray(typeArray *value, uint8_t length){
    srand((int)time(0));

    value->size = length;

    value->firstAdd = (uint8_t *)malloc(sizeof(uint8_t)*value->size);
    for(int i = 0; i < value->size; ++i){
        value->firstAdd[i] = randomA(0,10);
    }    
}

#if(0) // thuật toán sắp xếp đổi chỗ trực tiếp (Interchangr sort)
// thay đổi giá trị của mảng dùng "*arr", chỉ lấy gtri ra sử dụng thì dùng "arr" 
void Interchange_sort(typeArray *arr )  /// thuật toán sắp xếp đổi chỗ trực tiếp (Interchangr sort)
 //-Xuất phát từ đầu dãy, so sánh nó với toàn bộ các ptu còn lại trong mảng.
//- nếu ptu nào nhỏ hơn thì đổi chỗ phần 2 phần tử đang xét.
// -Lặp lại xử lý trên với các phần tử tiếp theo trong dãy.
{
    for(int i=0; i< arr->size; i++)
    {
        for(int j=i+1; j< arr->size ; j++)
        {
            if(arr->firstAdd[i] > arr->firstAdd[j])
            {
                int tg = arr->firstAdd[i];
                arr->firstAdd[i] = arr->firstAdd[j];
                arr->firstAdd[j] = tg;               
            }

        }
    }

}
int main(int argc, char const *argv[])
{
    typeArray arr;

    randomArray(&arr, 10);

    for (int i = 0; i < arr.size; i++)
    {
        printf("arr[%d] = %d\n",i, arr.firstAdd[i]);
    }
    
    Interchange_sort(&arr);
    printf("-Thuat toan sap xep Interchange:\n");
    for (int i = 0; i < arr.size; i++)
    {
        printf("arr[%d] = %d, ",i, arr.firstAdd[i]);
    }


    return 0;
}

#endif

#if(0) // thuật toán sắp xếp nổi bọt (bubble sort)
// thay đổi giá trị của mảng dùng "*arr", chỉ lấy gtri ra sử dụng thì dùng "arr" 
void Bubble_sort(typeArray *arr )  // thuật toán sắp xếp nổi bọt (bubble sort)
///- Xuất phát từ cuối dãy, đổi chỗ các cặp phần tử kế cận để đưa phần tử nhỏ hơn trong cặp phần tử đó về vị trí đầu dãy hiện hành,
//     sau đó sẽ không xét đến nó ở bước tiếp theo

// -Ở lần xử lý thứ i có vị trí đầu dãy là i

// -Lặp lại xử lý trên cho đến khi không còn cặp phần tử nào để xét
{
    for(int i=0; i< (arr->size)-1; i++)
    
        for(int j=(arr->size)-1; j> i; j--)
        
            if(arr->firstAdd[j] < arr->firstAdd[j-1])
            {
                int tg = arr->firstAdd[j];
                arr->firstAdd[j] = arr->firstAdd[j-1];
                arr->firstAdd[j-1] = tg;               
            }

        
    

}
int main(int argc, char const *argv[])
{
    typeArray arr;

    randomArray(&arr, 10);

    for (int i = 0; i < arr.size; i++)
    {
        printf("arr[%d] = %d\n",i, arr.firstAdd[i]);
    }

    Bubble_sort(&arr);
    printf("\n-Thuat toan sap xep Bubble sort:\n");
    for (int i = 0; i < arr.size; i++)
    {
        printf("arr[%d] = %d, ",i, arr.firstAdd[i]);
    }

    return 0;
}

#endif

#if(0) // thuật toán sắp xếp Chọn trực tiếp (Selection sort)
void Selection_sort(typeArray *arr ) /// thuật toán sắp xếp Chọn trực tiếp (Selection sort)
//- B1:Chọn phần tử nhỏ nhất trong n phần tử ban đầu, đưa phần tử này về vị trí đúng là đầu dãy hiện hành.
//- B2:Xem dãy hiện hành chỉ còn n-1 phần tử của dãy ban đầu, bắt đầu làm lại bước 1 từ vị trí thứ 2; 
//- B3:lặp lại quá trình trên cho dãy hiện hành... đến khi dãy hiện hành chỉ còn 1 phần tử
{
    int min;
    for(int i=0; i< (arr->size)-1; i++)
    {
        min = i;
        for(int j=i+1; j< (arr->size); j++)
        {
            if(arr->firstAdd[j] < arr->firstAdd[min])
            {
                min =j;   // ghi nhận vị trí phần tử nhỏ nhất         
            }
            if(min != i)
            {
                int tg = arr->firstAdd[min];
                arr->firstAdd[min] = arr->firstAdd[i];
                arr->firstAdd[i] = tg;
            }

        }
    }

}
int main(int argc, char const *argv[])
{
    typeArray arr;

    randomArray(&arr, 10);

    for (int i = 0; i < arr.size; i++)
    {
        printf("arr[%d] = %d\n",i, arr.firstAdd[i]);
    }
    
    Selection_sort(&arr);
    printf("\n-Thuat toan sap xep Seclection sort:\n");
    for (int i = 0; i < arr.size; i++)
    {
        printf("arr[%d] = %d, ",i, arr.firstAdd[i]);
    }

    return 0;
}
#endif

#if(0) // cách 1: Đếm số lần xuất hiện của từng phần tử trong mảng 
void Interchange_sort(typeArray *arr )  /// thuật toán sắp xếp đổi chỗ trực tiếp (Interchangr sort)
{
    for(int i=0; i< arr->size; i++)
    {
        for(int j=i+1; j< arr->size ; j++)
        {
            if(arr->firstAdd[i] > arr->firstAdd[j])
            {
                int tg = arr->firstAdd[i];
                arr->firstAdd[i] = arr->firstAdd[j];
                arr->firstAdd[j] = tg;               
            }

        }
    }

}
// sau khi đã săp xếp các phần tử từ bé đến lớn
void countArr(typeArray *arr)
{
    int dem = 1;
    for(int i=0; i < arr->size ; i++)
    {  
        if (arr->firstAdd[i] == arr->firstAdd[i+1] ) // xét xem có bao nhiêu phần tử giống nhau
        {
            dem ++;         // mỗi lần giống thì  đếm tăng lên 1
        }
        if(arr->firstAdd[i] != arr->firstAdd[i+1])  // nếu phần tử tiếp theo khác thì đếm =1, in ra số lần xuất hiện của số trước
          {
            printf("\nSo %d xuat hien %d lan",arr->firstAdd[i], dem);
            dem = 1;
          } 
    }      
}

int main(int argc, char const *argv[])
{
    typeArray arr;

    randomArray(&arr, 10);

    for (int i = 0; i < arr.size; i++)
    {
        printf("arr[%d] = %d\n",i, arr.firstAdd[i]);
    }
    
    Interchange_sort(&arr);
    printf("-Thuat toan sap xep Interchange:\n");
    for (int i = 0; i < arr.size; i++)
    {
        printf("arr[%d] = %d, ",i, arr.firstAdd[i]);
    }

    countArr(&arr);

    return 0;
}
#endif

#if(0) // cách 2: Đếm số lần xuất hiện của từng phần tử trong mảng
void countArr(typeArray *arr)
{
    int dem1=0;
    for(int i=0; i< arr->size; i++)
    {
        if(arr->firstAdd[i]==0) // đếm số phần tử có giá trị = 0
        {
            dem1++;    
        }
    }
    printf("so 0 xuat hien %d lan\n", dem1);

    int dem2=1;
    for(int i= 0; i< arr->size; i++)
    {
        if(arr->firstAdd[i] !=0)  // chỉ xét những phần tử khác 0
        {
        for(int j=i+1; j< arr->size; j++)
        {
           if(arr->firstAdd[i] == arr->firstAdd[j])  // lấy phần tử đầu tiên(khác 0) làm mốc, xét từ thằng thứ j= i+1 đến phần tử cuối n
            {
              dem2++;                                // nếu phần tử thứ j bằng ptu gốc i thì tăng đếm lên 1
              arr->firstAdd[j]= 0;                   // sau đó gán luôn thằng a[j] = 0
            }
            if(j==(arr->size)-1) // khi nào j chạy đến phần tử cuối mảng thì in kqua và bắt đầu vòng lặp mới lấy mốc là phần tử kế tiếp(khác 0)
            {
                printf("so %d xuat hien %d lan\n", arr->firstAdd[i], dem2);
                dem2 =1;
            }
        }
        }
    }
}

int main(int argc, char const *argv[])
{
    typeArray arr;

    randomArray(&arr, 10);

    for (int i = 0; i < arr.size; i++)
    {
        printf("arr[%d] = %d\n",i, arr.firstAdd[i]);
    }
    
    countArr(&arr);

    return 0;
}
#endif

#if(0) // cách 3: Đếm số lần xuất hiện của từng phần tử trong mảng
void countArr(typeArray *arr)
{
    int b[20]= {0};  // dùng 1 mảng  thứ 2 có giá trị của các phần tử = 0
    for(int i=0; i < (arr->size); i++)
    {
        for(int j=0; j<=10; j++)  // mảng hiện tại đang có 10 phần tử  
        {
            if(arr->firstAdd[i]==j) // nếu giá trị phần tử của mảng a = index của mảng b thì value của b tại index đó +1
            {
              b[j] ++;         // VD: a[2]=6 thì b[6]=1
            }
        }   
    }

    for(int j =0; j<=10; j++)
    {
        if(b[j]!=0) // nếu  giá trị các phàn tử mảng  b  khác 0
        {
            printf("so %d xuat hien %d lan\n", j, b[j]);
        }
    }
}
int main(int argc, char const *argv[])
{
    typeArray arr;

    randomArray(&arr, 10);

    for (int i = 0; i < arr.size; i++)
    {
        printf("arr[%d] = %d\n",i, arr.firstAdd[i]);
    }
    
    countArr(&arr);

    return 0;
}
 
#endif

#if(1)  // đếm số lần xuất hiện và giá trị của phần tử xuất hiện NHIỀU NHẤT

void countArr(typeArray *arr)
{
    int b[10]= {0};  // tạo 1 mảng b có số lượng ptu bằng mảng a và giá trị các pt trong b = 0
    int max=0;
    for(int i=0; i < arr->size; i++)
    {
        for(int j=0; j<10; j++)
        {
            if(arr->firstAdd[i]==j) // nếu phần tử a[i] = index của mảng b thì value tại index đó của mảng b + 1 
            {
              b[j] ++;             // ví dụ a[3] =7, a[6]=7  thì b[7] = 2
            }
            if(b[j]>max)   
            { max=b[j]; }   // tìm giá trị lớn nhất của mảng b, tương ứng với việc tìm số lần xuất hiện nhiều nhất của ptu thuộc mảng a
        }   
    }

    for(int j =0; j<10; j++)
    { 
        if(b[j]==max)
        {
            printf("so %d xuat hien nhieu nhat(%d lan)\n", j, max);
            
        }
    }
}

int main(int argc, char const *argv[])
{
    typeArray arr;

    randomArray(&arr, 10);

    for (int i = 0; i < arr.size; i++)
    {
        printf("arr[%d] = %d\n",i, arr.firstAdd[i]);
    }
    
    countArr(&arr);

    return 0;
}
#endif