#include "myStack.h"

/* Main Program */
int main()
{
    int num;
    char op;
    double result;
    Stack *S;

    S = createEmptyStack();

    while (1)
    {
       if (scanf("%d", &num) == 1)
        {
            push(S, num);
        }
        else if (scanf("%c", &op) == 1)
        {
            if (S->top_index < 1 || op == '#')
                break;
            else
            {
                double x = pop(S);
                double y = pop(S);
                if (op == '+')
                    push(S, y + x);
                else if (op == '-')
                    push(S, y - x);
                else if (op == '*')
                    push(S, y * x);
                else if (op == '/')
                    push(S, y / x);
            }
        }
    }

    result = top(S);
    printf("%.3f\n", result);

    free(S);
    return 0;
}
