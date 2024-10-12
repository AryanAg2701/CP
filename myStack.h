#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_STACK_SIZE 500

typedef struct Stack
{
	double value[MAX_STACK_SIZE];
	unsigned top_index;
} Stack;

Stack *createEmptyStack()
{
	Stack *S = (Stack *)malloc(sizeof(Stack));
	if (S)
	{
		S->top_index = 0;
	}
	return S;
}

bool push(Stack *S, double number)
{
	if (S->top_index == MAX_STACK_SIZE)
		return false;
	S->value[S->top_index++] = number;
	return true;
}

double pop(Stack *S)
{
	if (S->top_index == 0)
	{
		printf("Error: Stack underflow\n");
		return 0;
	}
	return S->value[--S->top_index];
}

double top(Stack *S)
{
	if (S->top_index == 0)
	{
		printf("Error: Stack is empty\n");
		return 0;
	}
	return S->value[S->top_index - 1];
}

