#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc,string argv[]){
    if(argc !=2){
        printf("Use ./caesar key\n");
        return 1;
    }
     int key = atoi(argv[1]);
     if (key<0){
         printf("must be positive!\n");
         return 1;
     }  
    
    string a = get_string("plaintext: ");
    int n= strlen(a);
    printf("ciphertext: ");
      for(int j=0 ; j < n; j++){
                if (a[j]>= 'a' && a[j] <= 'z'){
                    printf("%c", (((a[j] - 'a') + key) % 26) + 'a');
                }else if(a[j]>= 'A' && a[j] <= 'Z'){
                    printf("%c", (((a[j] - 'A') + key) % 26) + 'A');
                }else{
                    printf("%c", a[j]);
   
                }
    }
    printf("\n");
    return 0;
  }    

