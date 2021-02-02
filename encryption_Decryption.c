#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(){
        char s[100];
        printf("Enter a message: ");
        scanf("%s", s);
        int l = strlen(s);
        char t[100];
        int j = 0, x;
        for(int i = 0;i < l; i++){
                x = s[i] + 3;
                if(islower(s[i])){
                        if(x <= 122)
                                t[j++] = x;
                        else
                                t[j++] = x % 122 + 96;
                }
                else{
                        if(x <= 90)
                                t[j++] = x;
                        else
                                t[j++] = x % 90 + 64;
                }

        }
        t[j] = '\0';
        printf("The encrypted message is %s\n", t);
        printf("The decrypted message is %s\n", s);
        return 0;
}
                        

