#include<stdio.h>
#include<string.h>
#define Max 100

void inputstring(char str[]);
void findchar(char str[], char ch1, char ch2);

int main(){
    char ch1, ch2;
    char str[Max];
    inputstring(str);
    printf("Enter what you want to find:\n");
    scanf("%c %c", &ch1, &ch2);
    findchar(str, ch1, ch2);
    return 0;
}

void inputstring(char str[]){
    char ch;
    int i = 0;
    while((ch = getchar()) != '\n'){
        str[i] = ch;
        i++;
    }
    str[i] = '\n';
}

void findchar(char str[], char ch1, char ch2){
    int i;
    int num1 = 0;
    int num2 = 0;
    int num3 = 1;
    int num4 = 1;
    for(i = 0; i < strlen(str); i++){
        if(str[i] == ch1){
            num1++;
        }
        if(str[i] == ch2){
            num2++;
        }
    }
    for(i = 0; i < strlen(str); i++){
        if(str[i] != ch1){
            num3++;
        }
        else{break;}
    }
    for(i = 0; i < strlen(str); i++){
        if(str[i] != ch2){
            num4++;
        }
        else{break;}
    }
    if(num1 == 0){
        printf("%c not found.\n", ch1);
    }
    else{
        printf("%c first appears at %d char, the frequency is %d\n", ch1, num3, num1);
    }
    if(num2 == 0){
        printf("%c not found.\n", ch2);
    }
    else{
        printf("%c first appears at %d char, the frequency is %d\n", ch2, num4, num2);
    }
}