#include <stdio.h>
#include <stdlib.h>


int main()
{

   char tab[30];
   scanf("%s",tab);
    int len=0;
   for(int i=0;i<30;i++){
        printf("%c",tab[i]);
        if(tab[i]!='\0'){
            len=len+1;
        }
        else{
            break;
        }
   }
   printf("%d",len);

}


