#include <stdio.h>
#include <stdlib.h>

int main()
{
    char s[50];
    scanf("%s",s);
    int i=0;
    for (i = 0; s[i] != '\0'; ++i);


    char tmp_max=s[0];
    int idx_of_max=0;

    while(idx_of_max<i){
        tmp_max=s[idx_of_max];
        for(int j=idx_of_max+1;j<i;j++){
            if(tmp_max<s[j]){
                tmp_max=s[j];
                idx_of_max=j;
            }
        }
        printf("%c",s[idx_of_max]);
        idx_of_max=idx_of_max+1;
    }




}
