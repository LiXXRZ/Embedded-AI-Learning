#ifndef EMPLOYEE_MANAGE_H 
#define EMPLOYEE_MANAGE_H

#include <stdio.h>  
#include <string.h>

#define MAX_SIZE 2000

typedef struct { 
    char name[51];    
    char position[51];
    int id;           
} Employee;

void read(Employee arr[], int n);
void del(Employee arr[], int* count, int idx);
void add(Employee arr[], int* count, int idx);
void find(Employee arr[], int idx);

#endif
