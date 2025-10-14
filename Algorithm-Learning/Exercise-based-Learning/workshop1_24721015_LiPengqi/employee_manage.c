#include "employee_manage.h"

int main(){
    Employee arr[MAX_SIZE]; 
    int n, m, count = 0;

    scanf("%d %d", &n, &m);
    read(arr, n);
    count = n;

    for (int i = 0; i < m; i++) {
        int op, x;
        scanf("%d %d", &op, &x);
        int c = 0;

        switch (op) {
            case 1:
                if (x >= 1 && x <= count) {
                    c = 1;
                }
                break;
            case 2:
                if (x >= 1 && x <= count + 1) {
                    c = 1;
                }
                break;
            case 3:
                if (x >= 1 && x <= count) {
                    c = 1;
                }
                break;
            default:
                c = 0;
        }

        if (c == 0) {
            printf("-1\n");
            if (op == 2) {
                char temp1[51], temp2[51];
                int temp;
                scanf("%s %s %d", temp1, temp2, &temp);
            }
            continue;
        }

        int y = x - 1;
        switch (op) {
            case 1: del(arr, &count, y); break; 
            case 2: add(arr, &count, y); break;   
            case 3: find(arr, y); break; 
            default : printf("-1\n"); break;   
        }
    }

    return 0;
}

void read(Employee arr[], int n) {
    for (int i = 0; i < n; i++) {
        scanf("%s %s %d", arr[i].name, arr[i].position, &arr[i].id);
    }
}

void del(Employee arr[], int* a, int b) {
    for (int j = b; j < *a - 1; j++) {
        arr[j] = arr[j + 1]; 
    }
    (*a)--;

    for (int j = 0; j < *a; j++) {
        printf("%s %s %d\n", arr[j].name, arr[j].position, arr[j].id);
    }
}

void add(Employee arr[], int* a, int b) {
    Employee new_arr;
    scanf("%s %s %d", new_arr.name, new_arr.position, &new_arr.id);

    for (int j = *a; j > b; j--) {
        arr[j] = arr[j - 1]; 
    }
    arr[b] = new_arr; 
    (*a)++; 

    for (int j = 0; j < *a; j++) {
        printf("%s %s %d\n", arr[j].name, arr[j].position, arr[j].id);
    }
}

void find(Employee arr[], int a) {
    printf("%s %s %d\n", arr[a].name, arr[a].position, arr[a].id);
}
