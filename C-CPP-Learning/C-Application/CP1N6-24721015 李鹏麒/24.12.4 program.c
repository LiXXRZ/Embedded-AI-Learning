#include<stdio.h>

struct stu{
    int score[100];
    float average[10];
    int low[10];
    int high[10];
    int above[10];
    int failed[10];
};

void input(struct stu* students, int m, int n){
    for(int i = 0; i < n; i++){
        printf("Enter the scores of student%d:", i + 1);
        for(int j = 0; j < m; j++){
            scanf("%d", &students->score[i*m + j]);
        }
    }
}

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
            low = students->score[j*m + i];
        }

        students->high[j] = high;
        students->low[j] = low;
        students->average[j] = (float)sum / m;
    }

    for(int i = 0; i < m; i++){
        int above = 0;
        int failed = 0;

        for(int j = 0; j < n; j++){
            if (students->score[j*m + i] > 85) above++;
            if (students->score[j*m + i] < 60) failed++;
        }
        
        students->above[i] = above;
        students->failed[i] = failed;
    }
}

void print(struct stu* students, int m, int n){
     for (int j = 0; j < m; j++) {
        printf("------------------");
    }
    printf("\n");

    printf("| Course ");
    for (int j = 0; j < m; j++) {
        printf("| %d ", j + 1);
    }
    printf("|\n");

    for (int j = 0; j < m; j++) {
        printf("------------------");
    }
    printf("\n");

    for (int j = 0; j < m; j++) {
        printf("| Above | Failed |");
    }
    printf("\n");

    for (int j = 0; j < m; j++) {
        printf("------------------");
    }
    printf("\n");

    for (int j = 0; j < m; j++) {
        printf("| %d | %d |", students->above[j], students->failed[j]);
    }
    printf("\n");

    for (int j = 0; j < m; j++) {
        printf("------------------");
    }
    printf("\n");

    for (int j = 0; j < m; j++) {
        printf("--------------------");
    }
    printf("\n");

    printf("| Student ");
    for (int j = 0; j < m; j++) {
        printf("| %d ", j + 1);
    }
    printf("|\n");

    for (int j = 0; j < m; j++) {
        printf("--------------------");
    }
    printf("\n");

    for (int j = 0; j < m; j++) {
        printf("| Avg | High | Low |");
    }
    printf("\n");

    for (int j = 0; j < m; j++) {
        printf("--------------------");
    }
    printf("\n");

    for (int j = 0; j < m; j++) {
        printf("| %.2f | %d | %d |", students->average[j], students->high[j], students->low[j]);
    }
    printf("\n");

    for (int j = 0; j < m; j++) {
        printf("--------------------");
    }
    printf("\n");
}

int main(){
    int m, n;

    printf("Enter the number of students:");
    scanf("%d", &n);
    printf("Enter the number of scores:");
    scanf("%d", &m);

    struct stu students;
    input(&students, m, n);
    calculate(&students, m, n);
    print(&students, m, n);

    return 0;
}