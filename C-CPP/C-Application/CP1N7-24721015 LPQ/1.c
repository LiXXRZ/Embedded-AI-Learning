#include <stdio.h>
#include <string.h>

int binarysearch(int nums[], int low, int high, int target) {
	while (low <= high) {
		int middle = (low + high) / 2;
		if (target == nums[middle])
			return middle;
		else if (target > nums[middle])
			low = middle + 1;
		else if (target < nums[middle])
			high = middle - 1;} return -1;}

void sort(int nums[], int n) {
	int i, j;
	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n - i - 1; j++) {
			if (nums[j] > nums[j + 1]) {
				int temp = nums[j];
				nums[j] = nums[j + 1];
				nums[j + 1] = temp;} } } }

void findchar(char str[], char ch1, char ch2){
    int i; int num1 = 0; int num2 = 0; int num3 = 1; int num4 = 1;
    for(i = 0; i < strlen(str); i++){
        if(str[i] == ch1){ num1++;}
        if(str[i] == ch2){ num2++;} }
    for(i = 0; i < strlen(str); i++){
        if(str[i] != ch1){ num3++;}
        else{break;}}
    for(i = 0; i < strlen(str); i++){
        if(str[i] != ch2){ num4++;}
        else{break;}}
    if(num1 == 0){ printf("%c not found.\n", ch1);}
    else{ printf("%c first appears at %d char, the frequency is %d\n", ch1, num3, num1);}
    if(num2 == 0){ printf("%c not found.\n", ch2);}
    else{ printf("%c first appears at %d char, the frequency is %d\n", ch2, num4, num2);} }

void inputstring(char str[]){
    char ch; int i = 0;
    while((ch = getchar()) != '\n'){ str[i] = ch; i++;}
    str[i] = '\0';}

void printf1(char str[]){
    for(int i = 1; i <= strlen(str); i++){ printf("%*.*s\n", strlen(str), i, str);} }

void printf2(char str[]){
    for(int i = 0; i < strlen(str); i++){
        for(int s = 0; s <= i; s++){ printf("%c", str[s]);}
    printf("|\n");} }

void printf3(char str[]){
    for(int i = 1; i <= strlen(str) - 2; i++){ printf("%*.*s|\n", i, 1, str);}
    for(int a = 0; a < 2; a++){ printf("%*.*s|\n", strlen(str), 1, str);} }

struct stu{
    int score[100];
    float average[10];
    int low[10];
    int high[10];
    int above[10];
    int failed[10];
};

void input(struct stu* students, int m, int n){
    for(int i = 0; i < n; i++){ printf("Enter the scores of student%d:", i + 1);
        for(int j = 0; j < m; j++){ scanf("%d", &students->score[i*m + j]);} } }

void calculate(struct stu* students, int m, int n){
    for (int j = 0; j < n; j++) {
        int sum = 0;
        int high = students->score[j*m];
        int low = students->score[j*m];
        for (int i = 0; i < m; i++) {
            sum += students->score[j*m + i];
            if (students->score[j*m + i] > high)
            high = students->score[j*m + i];
            if (students->score[j*m + i] < low)
            low = students->score[j*m + i];}
        students->high[j] = high;
        students->low[j] = low;
        students->average[j] = (float)sum / m;}
    for(int i = 0; i < m; i++){
        int above = 0; int failed = 0;
        for(int j = 0; j < n; j++){
            if (students->score[j*m + i] > 85) above++;
            if (students->score[j*m + i] < 60) failed++;}
        students->above[i] = above;
        students->failed[i] = failed;} }

void print(struct stu* students, int m, int n){
    for (int j = 0; j < m; j++) { printf("------------------");}
    printf("\n");
    printf("| Course ");
    for (int j = 0; j < m; j++) {printf("| %d ", j + 1);}
    printf("|\n");
    for (int j = 0; j < m; j++) { printf("------------------");}
    printf("\n");
    for (int j = 0; j < m; j++) { printf("| Above | Failed |");}
    printf("\n");
    for (int j = 0; j < m; j++) { printf("------------------");}
    printf("\n");
    for (int j = 0; j < m; j++) { printf("| %d | %d |", students->above[j], students->failed[j]);}
    printf("\n");
    for (int j = 0; j < m; j++) { printf("------------------");}
    printf("\n");
    for (int j = 0; j < m; j++) { printf("--------------------");}
    printf("\n");
    printf("| Student ");
    for (int j = 0; j < m; j++) { printf("| %d ", j + 1);}
    printf("|\n");
    for (int j = 0; j < m; j++) { printf("--------------------");}
    printf("\n");
    for (int j = 0; j < m; j++) { printf("| Avg | High | Low |");}
    printf("\n");
    for (int j = 0; j < m; j++) { printf("--------------------");}
    printf("\n");
    for (int j = 0; j < m; j++) {
        printf("| %.2f | %d | %d |", students->average[j], students->high[j], students->low[j]);}
    printf("\n");
    for (int j = 0; j < m; j++) { printf("--------------------");}
    printf("\n");}

int main(void){
    int choice;
    while(1) {
        printf("[1] Calculate the total scores \n");
        printf("[2] Find the value of int \n");
        printf("[3] Guess the number \n");
        printf("[4] Transform Fahrenheit to Celsius \n");
        printf("[5] Find the upper and the number \n");
        printf("[6] Confirm the type of character \n");
        printf("[7] Calculates the sum of factorials for all even numbers between 1 and 9 \n");
        printf("[8] Find the special element in an arry \n");
        printf("[9] Calculate grades of students and courses \n");
        printf("[10] Find char and the location in a string \n");
        printf("[11] Print in three diffent types \n");
        printf("[12] program 12 \n");
        printf("[0] exit \n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        if(choice == 0) break;
        switch(choice) {
            case 1:{
            printf("the first programming experience by class 1\n");
            float  num1, num2, num3, num4;
            printf("Enter Experiment scorce(<=50):"); scanf("%f", &num1);
            printf("Enter Experiment socument scorce(<=10):"); scanf("%f", &num2);
            printf("Enter Test scorce(<=40):"); scanf("%f", &num3);
            printf("Enter Bonus scorce(<=5):"); scanf("%f", &num4);
            int sum = num1 + num2 + num3 + num4;
            if (sum <= 100) { printf("Score=%d\nExperiment scorce=%f\nExperiment socument scorce=%f\nTest scorce=%f\nBonus scorce=%f", sum, num1, num2, num3, num4);}
            else { printf("Score=100\nExperiment scorce=%f\nExperiment socument scorce=%f\nTest scorce=%f\nBonus scorce=%f", num1, num2, num3, num4);}; break;}
            case 2:{
            int max = 0;
            while (1) { max += 1;
            if (max < 0) { printf("The maximum value of int is:%d\n", max - 1); break;} }
            printf("Exceed the maximum value: %d\n", max);
            int min = 0;
            while (1) { min -= 1;
            if (min > 0) { printf("The minimum value of int is:%d\n", min + 1); break;} }
            printf("Below the minimum value: %d\n", min); break;}
            case 3:{
            int a, b; int Correct = 0;
            printf("Enter the secret:"); scanf("%d", &a);
            printf("I'm thinking of a number between 1 and 499.\n");
            while (Correct == 0) {
                printf("Enter your guess: "); scanf("%d", &b);
                if (b > a) { printf("It is high.\n");}
                else if (b < a) { printf("It is low.\n");}
                else {printf("You are right.\n"); Correct = 1;} }; break;}
            case 4:{
            double Fahrenheit, Celsius;
            printf("Enter the Fahrenheit temperature: "); scanf("%lf", &Fahrenheit);
            Celsius = 5.0 / 9.0 * (Fahrenheit - 32);
            printf("The corresponding Celsius temperature is: %.2f\n", Celsius); break;}
            case 5:{
            char ch; int correct = 0;
            while (correct == 0) {
                printf("Enter a lowercase English letter:"); scanf("%c", &ch); while (getchar() != '\n');
                if (ch >= 'a' && ch <= 'z') { correct = 1;}
                else { printf("Please enter the correct letter.\n");} }
                printf("The number is %d", ch - 'a' + 1); break;}
            case 6:{
            char ch;
            printf("Enter 'q' to quit.\n");
            while (1) { printf("Please enter a character: "); ch = getchar();
            if (ch == 'q') { break;}
            if (ch >= 'a' && ch <= 'z') {
            printf("You entered a lowercase letter.\n");}
            else if (ch >= 'A' && ch <= 'Z') { printf("You entered an uppercase letter.\n");}
            else if (ch >= '0' && ch <= '9') { printf("You entered a digit.\n");}
            else { printf("You entered a special character.\n");} }
            printf("Program exited.\n"); break;}
            case 7:{
            int a = 1, c = 0;
	        for (int b = 1; b <= 9; b++) { a *= b;
		    if (b % 2 == 0) { c += a;} }
	        printf("The sum is %d", c); break;}
            case 8:{
            int nums[] = { -5,0,6,-2,2,-1,9 }; int n = sizeof(nums) / sizeof(nums[0]);
            sort(nums, n);
            for (int i = 0; i < n; i++) { printf("%d ", nums[i]);} printf("\n");
            int target;
            printf("Enter the number you want to find:"); scanf("%d", &target);
            int low = 0; int high = sizeof(nums) / sizeof(nums[0]); int right = binarysearch(nums, low, high, target);
            if (right == -1) { printf("Element not found.");}
            else { printf("Find the element.");}; break;}
            case 9:{
            int m, n;
            printf("Enter the number of course and student:"); scanf("%d %d", &m, &n);
            int score[m][n]; int i, j;
            printf("The grade of each student.");
            for (i = 0; i < m; i++) {
                for (j = 0; j < n; j++) { scanf("%d", &score[i][j]);} }
            for (i = 0; i < m; i++) {
                int max = score[i][0]; int min = score[i][0]; int sum = 0;
                for (j = 0; j < n; j++) {
                sum += score[i][j];
                if (score[i][j] > max) { max = score[i][j];}
                if (score[i][j] < min) { min = score[i][j];}}
                int average = sum / n;
                printf("Course%d: Average:%d Max:%d Min:%d\n", i+1, average, max, min);}
            for (i = 0; i < m; i++) {
                int num1 = 0, num2 = 0;
                for (j = 0; j < n; j++) {
			    if (score[i][j] > 80) { num1 ++;}
	     		if (score[i][j] < 60) { num2 ++;}}
                printf("Course%d: Over:%d Below:%d\n", i+1, num1, num2);}; break;}
            case 10:{
            char ch1, ch2; char str[100];
            inputstring(str);
            printf("Enter what you want to find:\n"); scanf("%c %c", &ch1, &ch2);
            findchar(str, ch1, ch2); break;}
            case 11:{
            char str[] = "CProgramming";
            printf1(str); printf2(str); printf3(str); break;}
            case 12:{
            int m, n;
            printf("Enter the number of students:"); scanf("%d", &n);
            printf("Enter the number of scores:"); scanf("%d", &m);
            struct stu students;
            input(&students, m, n); calculate(&students, m, n); print(&students, m, n); break;}
            default: printf("Wrong number!\n"); break;
        }
        while (getchar() != '\n');
    }
    printf("Thanks \n");
}