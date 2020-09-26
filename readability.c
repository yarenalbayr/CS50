#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
  string text = get_string("Text: ");

  int numOfLetters = 0;
  int numOfWords = 0;
  int numOfSentences =0;
  int i;
  for( i = 0 ; i<strlen(text) ; i++)
  {
     if ( (text[i]>= 'a' && text[i]<= 'z') || (text[i]>= 'A' && text[i] <= 'Z'))
     {
         numOfLetters++;
     }
     else if (text[i]== ' ')
     {
         numOfWords++;
     }
     else if(text[i]=='.' || text[i]=='!' || text[i]=='?')
     {
         numOfSentences++;
     }
  }

   float grade = 0.0588 * (100 * (float)numOfLetters/(float)numOfWords )- 0.296 * ( 100 * (float)numOfSentences/(float)numOfWords ) - 15.8;

   if(grade<16 && grade>=0 )
   {
       printf("Grade: %i \n", (int)grade);

   }
   else if (grade>=16)
   {
       printf("Grade: 16+ \n");
   }
   else
   {
       printf("Before grade 1\n");
   }
}
