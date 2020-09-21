#include <stdio.h>
#include <cs50.h>

int main(void){
     int h,n;
 do{
     h = get_int("Height: ");
 }while (h <= 1 && h >= 23);

for (int i=0 ; i < h ; i++){
     for (int j=0 ; j < h-1 ; j++ ){
          printf(" ");
     }
     for (int s=0 ; s<i+1 ; s++){
          printf("#");
     }
     printf("\n");
}


}
