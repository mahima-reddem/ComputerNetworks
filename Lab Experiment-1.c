#include <stdio.h>
#include <string.h>

int main(){
    char str[20],final[50];
    printf("Enter the string:");
    scanf("%s",str);
    printf("01111110");
    
    int i, c = 0;
    for(i=0;i<strlen(str);i++){
        printf("%c", str[i]);
        if(str[i] == '1'){
            c++;
            
            if(c == 5){
              printf("0");
            }
        }
        else{
            c = 0;
        }
        
    }
    
    
   printf("01111110");

}            