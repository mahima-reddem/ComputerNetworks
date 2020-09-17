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
    //printf("%s",temp);
    
    int i=0;
    while(i<strlen(str)){
        int j = 0,l =0, c = 0, k = i, c1 = 0;
        while(j<strlen(start)){
            if(str[k] == start[j] || str[k] == end[j]){
                c++;
            }
            int m=i,n=0;
            while(m<strlen(temp)+i){
                if(str[m] == temp[n]){
                    c1++;
                }
                m++;
                n++;
            }   
            if(c1 == strlen(temp)){
                printf("%s",temp);
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
