#include <stdio.h>
#include <stdlib.h>

typedef struct Node 
{
    int data;
    struct Node* next;
} Node;

typedef struct 
{
    Node* top;
} Stack;

void initStack(Stack *s) 
{
    if (s != NULL) 
    {
        s->top = NULL;
    }
}

int isEmpty(Stack *s) 
{
    if (s == NULL) return 1;
    return s->top == NULL;
}

void push(Stack *s, int val) 
{
    if (s == NULL) return;
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) 
    {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = val;
    newNode->next = s->top;
    s->top = newNode;
    printf("Push successful: %d\n", val);
}

int pop(Stack *s) 
{
    if (s == NULL || isEmpty(s)) 
    {
        printf("Pop failed: stack is empty\n");
        return -1;
    }
    Node* temp = s->top;
    int val = temp->data;
    s->top = s->top->next;
    free(temp);
    return val;
}

int getTop(Stack *s) {
    if (s == NULL || isEmpty(s)) {
        printf("GetTop failed: stack is empty\n");
        return -1;
    }
    return s->top->data;
}

void destroyStack(Stack *s) {
    if (s == NULL) return;
    while (!isEmpty(s)) 
    {
        Node* temp = s->top;
        s->top = s->top->next;
        free(temp);
    }
    printf("Stack destroyed.\n");
}

int main() {
    Stack myStack;

    printf("1. Initialization and empty stack verification\n");
    initStack(&myStack);
    printf("Is stack empty? %s\n", isEmpty(&myStack) ? "Yes (1)" : "No (0)");

    pop(&myStack);
    getTop(&myStack);
    printf("\n");

    printf("2. Push operation verification\n");
    push(&myStack, 10);
    push(&myStack, 20);
    push(&myStack, 30);
    
    printf("Is stack empty after pushes? %s\n", isEmpty(&myStack) ? "Yes (1)" : "No (0)");
    printf("Current top element is: %d\n", getTop(&myStack));
    printf("\n");

    printf("3. Pop operation verification\n");
    printf("Popped element: %d\n", pop(&myStack));
    printf("Top element after one pop is: %d\n", getTop(&myStack));

    printf("Popped element: %d\n", pop(&myStack));
    printf("Popped element: %d\n", pop(&myStack));
    
    printf("Is stack empty after all pops? %s\n", isEmpty(&myStack) ? "Yes (1)" : "No (0)");
    printf("\n");

    printf("Repeated operations and boundary verification\n");
    push(&myStack, 5);
    push(&myStack, 6);
    printf("Top element after pushing 5 and 6 is: %d\n", getTop(&myStack));
    printf("Popped element: %d\n", pop(&myStack));
    printf("Top element is now: %d\n", getTop(&myStack));
    printf("\n");

    printf("4. Stack destruction verification\n");
    destroyStack(&myStack);

    printf("Attempting to get top after destruction:\n");
    getTop(&myStack);
    printf("Attempting to pop after destruction:\n");
    pop(&myStack);
    printf("Is stack empty after destruction? %s\n", isEmpty(&myStack) ? "Yes (1)" : "No (0)");

    return 0;
}