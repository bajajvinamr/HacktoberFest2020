#include <stdio.h>
#include <stdlib.h>

#define MAX 5

struct Stack {
    int items[MAX];
    int top;
};

// Function declarations
void initStack(struct Stack *s);
void push(struct Stack *s, int value);
int pop(struct Stack *s);
int peek(struct Stack *s);
int isFull(struct Stack *s);
int isEmpty(struct Stack *s);
void display(struct Stack *s);

int main() {
    struct Stack s;
    int choice, value;

    initStack(&s);

    while (1) {
        printf("\n--- Stack Operations ---\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&s, value);
                break;
            case 2:
                pop(&s);
                break;
            case 3:
                peek(&s);
                break;
            case 4:
                display(&s);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}

// Initialize stack
void initStack(struct Stack *s) {
    s->top = -1;
}

int isFull(struct Stack *s) {
    return s->top == MAX - 1;
}

int isEmpty(struct Stack *s) {
    return s->top == -1;
}

void push(struct Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow! Cannot push %d\n", value);
    } else {
        s->items[++(s->top)] = value;
        printf("%d pushed to stack\n", value);
    }
}

int pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow! Cannot pop.\n");
        return -1;
    } else {
        printf("%d popped from stack\n", s->items[s->top]);
        return s->items[(s->top)--];
    }
}

int peek(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty.\n");
        return -1;
    } else {
        printf("Top element: %d\n", s->items[s->top]);
        return s->items[s->top];
    }
}

void display(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements: ");
        for (int i = s->top; i >= 0; i--) {
            printf("%d ", s->items[i]);
        }
        printf("\n");
    }
}
