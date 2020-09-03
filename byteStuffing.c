#include <stdio.h>
#include <string.h>

int main(){
    char str[20], start[5], end[5], temp[10];
    printf("Enter a string:");
    scanf("%s",str);
    printf("Enter starting delimiter:");
    scanf("%s", start);
    printf("Enter ending delimiter:");
    scanf("%s", end);
    printf("Enter the string to be inserted:");
    scanf("%s",temp);
    printf("%s ",start);
    
    int i=0;
    while(i<strlen(str)){
        int j = 0, c = 0, k = i;
        while(j<strlen(start)){
            if(str[k] == start[j] || str[k] == end[j]){
                c++;
            }
            k++;
            j++;
        
            if(c == strlen(start)){
               printf("%s ",temp);
            } 
        }
        
        printf("%c ",str[i]);
        i++;
        
    }
    printf("%s",end);
}
