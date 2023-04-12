#include<stdio.h>
int main()
{
  //khai báo biến n và yêu cầu người dùng nhập vào từ bàn phím
  // 5  3  7  4  9  2  1 
  //a0 a1 a2 a3 a4 a5 a6
  int n;
  printf("\nNhap so: ");
  scanf("%d", &n);
  
  int a6 = n % 10;              // đơn vị
  int a5 = (n / 10) % 10;      //  chục
  int a4 = (n/100)%10;        // hàng trăm
  int a3 = (n/1000)%10;      // hàng nghìn
  int a2 = (n/10000)%10;    // hàng chục nghìn
  int a1 = (n/100000)%10;  // hàng trăm nghìn
  int a0 = (n/1000000);   // hàng triệu
  //
  if( n > 9999999 )
  {
    printf("ERRO!! khong hop le.");
  }
  else{
    printf("==> ");
// in hang trieu
    switch(a0){
      case 1: printf("Mot trieu ");break;
      case 2: printf("Hai trieu ");break;
      case 3: printf("Ba trieu ");break;
      case 4: printf("Bon trieu ");break;
      case 5: printf("Nam trieu ");break;
      case 6: printf("Sau trieu ");break;
      case 7: printf("Bay trieu ");break;
      case 8: printf("Tam trieu ");break;
      case 9: printf("Chin trieu ");break;
    }

// in hang tram nghin
    if(a1==0 & ( a2!=0 || a3!=0 || a4!=0 || a5!=0 || a6!=0) & n>=99999)
    {
      printf("khong tram "); 
    }
    switch(a1){
      case 1: printf("mot tram ");break;
      case 2: printf("hai tram ");break;
      case 3: printf("ba tram ");break;
      case 4: printf("bon tram ");break;
      case 5: printf("nam tram ");break;
      case 6: printf("sau tram ");break;
      case 7: printf("bay tram ");break;
      case 8: printf("tam tram ");break;
      case 9: printf("chin tram ");break;
    }
//in hang chuc nghin
    if(a2==0 &a3!=0 &n>9999 & (a1!=0 || a4!=0 || a5!=0||a6!=0||a0!=0) )
    {
      printf("linh "); 
    }
    switch(a2){
      case 1: printf("muoi ");break;
      case 2: printf("hai muoi ");break;
      case 3: printf("ba muoi ");break;
      case 4: printf("bon muoi ");break;
      case 5: printf("nam muoi ");break;
      case 6: printf("sau muoi ");break;
      case 7: printf("bay muoi ");break;
      case 8: printf("tam muoi ");break;
      case 9: printf("chin muoi ");break;
    }
// in hang nghin
    if(a3==0 & (a1!=0||a2!=0) )
    {
      printf("nghin ");  
    }
    switch (a3) 
    {
      case 1: printf("mot nghin ");break;
      case 2: printf("hai nghin ");break;
      case 3: printf("ba nghin ");break;
      case 4: printf("bon nghin ");break;
      case 5: 
        if(a2!=0 || (a0==0||a3==0) &n>5000 & (n/100)%10!=5 )
        {
          printf("lam nghin ");
        }
        else 
        {
          printf("nam nghin ");
        }
      break;
      case 6: printf("sau nghin ");break;
      case 7: printf("bay nghin ");break;
      case 8: printf("tam nghin ");break;
      case 9: printf("chin nghin ");break;
      default:
      break;
    }
//in ra hàng trăm
    if(a4==0 & n>99 &(a6!=0||a5!=0) &(a2!=0||a3!=0||a1!=0))
    {
      printf("khong tram "); 
    }
    switch(a4){
      case 1: printf("mot tram ");break;
      case 2: printf("hai tram ");break;
      case 3: printf("ba tram ");break;
      case 4: printf("bon tram ");break;
      case 5: printf("nam tram ");break;
      case 6: printf("sau tram ");break;
      case 7: printf("bay tram ");break;
      case 8: printf("tam tram ");break;
      case 9: printf("chin tram ");break;
    }
//in ra hàng chục
    if(a5 % 10 == 0 && a6 != 0 & n>9){
      printf("linh ");  
    }
    switch(a5){
      case 1: printf("muoi ");break;
      case 2: printf("hai muoi ");break;
      case 3: printf("ba muoi ");break;
      case 4: printf("bon muoi ");break;
      case 5: printf("nam muoi ");break;
      case 6: printf("sau muoi ");break;
      case 7: printf("bay muoi ");break;
      case 8: printf("tam muoi ");break;
      case 9: printf("chin muoi ");break;
    }

//in ra hàn đơn vị
    switch(a6){
      case 1: printf("mot ");break;
      case 2: printf("hai ");break;
      case 3: printf("ba ");break;
      case 4: printf("bon ");break;
      case 5: 
        if(a5==0)
        {
          printf("nam "); 
        }
        else
        {
          printf("lam ");
        }
      break;
      case 6: printf("sau ");break;
      case 7: printf("bay ");break;
      case 8: printf("tam ");break;
      case 9: printf("chin ");break;
    }
  }
  printf("\n------------------------------------\n");
}