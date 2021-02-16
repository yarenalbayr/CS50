#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc!=2)
    {
        printf("Usage: ./recover image");
        return 1;
    }


    char *card=argv[1];
    FILE *inptr=fopen(card,"r");

    if (!inptr)
    {
        fclose(inptr);
        return 1;
    }

    unsigned char buffer[512];  //WHYYYY?
    char fileName[8];  //8 chars for every file namee
    int fileCount=0;
    int jpgFound=0;

    FILE *f = NULL; //to put jpg files

    // fread returns the number of readed data, in this case our number is 1, if it becomes less than 1 that means that EOF.
    while(fread(buffer, 512, 1, inptr)==1)
    {
        if(buffer[0]==0xff && buffer[1]==0xd8 && buffer[2]==0xff && (buffer[3]& 0xf0)==0xe0)
        {
            if (jpgFound==0)  //if it is the first one write 000.jpg
            {
                jpgFound=1;
                sprintf(fileName,"%03i.jpg",fileCount);
            }
            else
            {
                fclose(f);
            }

            fileCount++;
            f=fopen(fileName,"w");   //write to file
        }
        else   //if already find a jpeg an searching in it
        {
            fwrite(&buffer, 512, 1, f);
        }
    }

    fclose(f);
    fclose(inptr);
}
