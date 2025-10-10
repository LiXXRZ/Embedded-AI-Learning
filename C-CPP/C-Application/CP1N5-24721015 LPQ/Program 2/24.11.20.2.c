#include<stdio.h>
#include<string.h>

void printf1(char str[]);
void printf2(char str[]);
void printf3(char str[]);

int main(){
    char str[] = "CProgramming";
    printf1(str);
    printf2(str);
    printf3(str);
    return 0;
}

void printf1(char str[]){
    for(int i = 1; i <= strlen(str); i++){
        printf("%*.*s\n", strlen(str), i, str);
    }
}

void printf2(char str[]){
    for(int i = 0; i < strlen(str); i++){
        for(int s = 0; s <= i; s++){
            printf("%c", str[s]);
    }
    printf("|\n");
    }
}

void printf3(char str[]){
    for(int i = 1; i <= strlen(str) - 2; i++){
        printf("%*.*s|\n", i, 1, str);
    }
    for(int a = 0; a < 2; a++){
        printf("%*.*s|\n", strlen(str), 1, str);
    }
}