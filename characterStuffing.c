#include <stdio.h>
#include <string.h>

int main(){
    //char start='d', end='g';
    char str[20],start,end;
    printf("Enter starting and ending delimiter:");
    scanf("%c%c",&start,&end);
   
    printf("Enter a string:");
    scanf("%s",str);
     printf("%c ",start);
    for(int i=0;i<strlen(str);i++){
        if(str[i] == start || str[i] == end){
            printf("esc ");
        }
        printf("%c ",str[i]);
        
    }
    printf("%c",end);
}
