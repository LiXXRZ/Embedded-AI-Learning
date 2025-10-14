#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print(int lot[], int count) 
{
    printf("parking lot:");
    for (int i = 0; i < count; ++i) {
        printf(" %d", lot[i]);
    }
    printf("\n");
}

int main() {
    int n, q;
    if (scanf("%d %d", &n, &q) != 2) 
    {
        return 1;
    }

    int* parking_lot = (int*)malloc(n * sizeof(int));
    int* temp_stack = (int*)malloc(n * sizeof(int));

    if (!parking_lot || !temp_stack) 
    {
        perror("Failed to allocate memory for parking lot");
        return 1;
    }

    int lot_count = 0;

    for (int i = 0; i < q; ++i) {
        int op, x;
        if (scanf("%d %d", &op, &x) != 2) 
        {
            break;
        }

        switch (op) {
            case 1: {
                if (lot_count < n) 
                {
                    parking_lot[lot_count] = x;
                    lot_count++;
                }
                print_parking_lot(parking_lot, lot_count);
                break;
            }
            case 2: {
                int found_idx = -1;
                for (int j = 0; j < lot_count; ++j) 
                {
                    if (parking_lot[j] == x) 
                    {
                        found_idx = j;
                        break;
                    }
                }
                if (found_idx == -1) 
                {
                    printf("-1\n");
                } 
                else 
                {
                    printf("%d\n", found_idx + 1);

                    int temp_stack_count = 0;
                    while (lot_count > found_idx + 1) 
                    {
                        lot_count--;
                        temp_stack[temp_stack_count] = parking_lot[lot_count];
                        temp_stack_count++;
                    }
                    lot_count--;
                    while (temp_stack_count > 0) 
                    {
                        temp_stack_count--;
                        parking_lot[lot_count] = temp_stack[temp_stack_count];
                        lot_count++;
                    }
                }
                print_parking_lot(parking_lot, lot_count);
                break;
            }
            case 3: {
                if (x >= 1 && x <= lot_count) 
                {
                    printf("%d\n", parking_lot[x - 1]);
                } 
                else
                {
                    printf("-1\n");
                }
                break;
            }
        }
    }

    free(parking_lot);
    free(temp_stack);

    return 0;
}