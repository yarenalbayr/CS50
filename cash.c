#include<stdio.h>
#include<cs50.h>
#include<math.h>

 

int main(void){
int counter=0;    
float dollar;
float cent;
do{
    dollar=get_float("Change owed: ");
}while(dollar<=0 );

cent = round(dollar*100.00);

while(cent>=25){   
    cent-=25;
    counter++;
}
while(cent>=10 && cent<25){   
    cent-=10;
    counter++;
}
while(cent>=5 && cent<10){   
    cent-=5;
    counter++;
}
while(cent>=1 && cent<5){   
    cent-=1;
    counter++;
}

 printf("%i \n",counter);

}
