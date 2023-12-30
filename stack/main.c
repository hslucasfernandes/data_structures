#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node* next_node;
} Node;

Node* new_node(int, Node*);

typedef struct Stack
{
    Node* top;
} Stack;

Stack* new_stack();

void push(Stack*, int);
void show(Stack*);

int main(void)
{
    Stack* stack = new_stack();

    for (int i = 0; i < 10; i++)
    {
        push(stack, i);
    }

    show(stack);

    return 0;
}

Node* new_node(int value, Node* next_node)
{
    Node* node = (Node*) malloc(sizeof(Node));

    if (node == NULL)
    {
        fprintf(stderr, "Memory Allocation Error\n");
    }

    node->value = value;
    node->next_node = next_node;

    return node;
}

Stack* new_stack()
{
    Stack* stack = (Stack*) malloc(sizeof(Stack));

    if (stack == NULL)
    {
        fprintf(stderr, "Memory Allocation Error\n");
    }

    stack->top = NULL;

    return stack;
}

void push(Stack* stack, int value)
{
    if (stack->top == NULL)
    {
        stack->top = new_node(value, NULL);
    }
    else
    {
        stack->top = new_node(value, stack->top);
    }
}

void show_helper(Node* node)
{
    if (node != NULL)
    {
        if (node->next_node == NULL)
        {
            printf("%d", node->value);
        }
        else
        {
            printf("%d, ", node->value);

            show_helper(node->next_node);
        }
    }
}

void show(Stack* stack)
{
    if (stack->top == NULL)
    {
        printf("[]\n");
    }
    else
    {
        printf("[");

        show_helper(stack->top);

        printf("]\n");
    }
}
