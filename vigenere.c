#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int shift(char c);

int main(int argc,string argv[]){
    if(argc !=2){
        printf("Usage ./vigenere keyword\n");
        return 1;
     } 
    else 
    {
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            if (!isalpha(argv[1][i]))
            {
                printf("Key must be alphabetic.");
                return 1;
            }    
        }
    }

    int l=strlen(argv[1]);
    string a = get_string("plaintext: ");
    int n= strlen(a);
    printf("ciphertext: ");
    int k=0;
    for (int j=0; j<n ; j++)
    {        
        int key = shift(argv[1][k % l]);
        if(isupper(a[j])) 
        {
            printf("%c", (((a[j] - 'A') + key) % 26) + 'A'); //if upper add key mod by numnof characters
            k++;
        }
        
        else if(islower(a[j]))
        {
            printf("%c", (((a[j] - 'a') + key) % 26) + 'a'); //if lower add key mod by numof characters
            k++;
        }
        else
        {
            printf("%c", a[j]); 
        }
        
        
    }
    printf("\n"); 
    return 0;
  }

int shift(char c)
{
    c= toupper(c);
    int key= ((int)c)-65;
    return key;
}


