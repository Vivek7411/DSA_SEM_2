#include <stdio.h>

#define MAX 100
#define NIL -1

typedef struct stack
{
    int a[MAX];
    int top;
} stack;

void peek(stack);
void push(stack *, int);
void pop(stack *);
int isempty(stack); // tey to do call by value.
int isfull(stack);

void main()
{
    int c, val, a;
    stack s;
    s.top = NIL;

    while (1)
    {
        printf("\n********Select a option from menu********");
        printf("\n1.peek");
        printf("\n2.pop");
        printf("\n3.push\n\n\n");
        scanf("%d", &c);

        switch (c)
        {

        case 1:
            peek(s);
            break;

        case 2:
            pop(&s);
            break;

        case 3:
            printf("\nEnter value : ");
            scanf("%d", &val);
            push(&s, val);
            break;

        default:
            break;
        }
    }
}

int isempty(stack s)
{
    return (s.top == NIL);
}

int isfull(stack s)
{
    return (s.top == (MAX - 1));
}

void push(stack *s, int val)
{
    if (isfull(*s))
    {
        printf("\nStack is full");
    }

    else
    {
        s->a[++s->top] = val;
        // printf("\n%d", s->top);
    }
}

void pop(stack *s)
{
    if (isempty(*s))
    {
        printf("\nStack is empty");
    }

    else
    {
        printf("\npoped element is %d", s->a[s->top--]);
    }
}

void peek(stack s)
{
    if (isempty(s))
    {
        printf("\nStack is empty");
    }

    else
    {
        printf("\n%d is at the top of stack", s.a[s.top]);
    }
}

/*

#include<stdio.h>

#define MAX 100

typedef struct stack {
    int a[MAX];
    int top;
} stack;

void initialize(stack *s) {
    s->top = -1;
}

int isFull(stack *s) {
    return s->top == MAX - 1;
}

int isEmpty(stack *s) {
    return s->top == -1;
}

void push(stack *s, int data) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
        return;
    }
    s->a[++s->top] = data;
}

int pop(stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return s->a[s->top--];
}

int peek(stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return -1;
    }
    return s->a[s->top];
}

int main() {
    stack s;
    initialize(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    printf("Top element: %d\n", peek(&s));

    printf("Popped element: %d\n", pop(&s));
    printf("Popped element: %d\n", pop(&s));
    push(&s, 60);
    printf("Top element: %d\n", peek(&s));

    return 0;
}
















*/