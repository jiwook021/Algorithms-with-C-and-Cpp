#include <stdio.h> 
#include <string.h>


void push(char element, char stack[], int* top)
{
    stack[++(*top)] = element;
}

char pop(char stack[], int* top)
{
    char item; 
    if (*top < 0)
    {
        return -1;
    }
    else {
        item = (*top); 
        (*top)--; 
        return stack[item];
    }
}

void Infix2Posfix(char* szInfixInput, char* szPostfixOutput)
{
    char stack[10] = {0};
    int top = -1;
    int OutputIndex = 0;
    int i = 0;
        
        for (i = 0; szInfixInput[i] != '\0'; i++)
        {
        switch (szInfixInput[i])
        {
            case '(':
                push('(', stack, &top);
            break;

            case ')':
                while (stack[top]  != '(')
                {
                    szPostfixOutput[OutputIndex] = pop(stack, &top);
                    OutputIndex++;
                }
                pop(stack, &top);
            break;
            

        case '*':           
            if (!((stack[top] == '*' || stack[top] == '/')))
            {
            push('*', stack, &top);
            break;
            }
            else 
            {
            while (stack[top] == '*' || stack[top] == '/' )
            {
                szPostfixOutput[OutputIndex] = pop(stack, &top);
                OutputIndex++;
            }
            push('*', stack, &top);
            }
            break;

        case '/':
            if (!(stack[top] == '*' || stack[top] == '/'))
            {
                push('/', stack, &top); 
                break;
            }
            while (stack[top] == '*' || stack[top] == '/')
            {
                szPostfixOutput[OutputIndex] = pop(stack, &top);
                OutputIndex++;
            }
            push('/', stack, &top);
       
        break;

        case '+':
            if (!(stack[top] == '+' || stack[top] == '-' || stack[top] == '/' || stack[top] == '*'))
            {
                push('+', stack, &top);
                break;
            }

            while (stack[top] == '+' || stack[top] == '-' || stack[top] == '/' || stack[top] == '*')
            {
                szPostfixOutput[OutputIndex] = pop(stack, &top);
                OutputIndex++;
            }
            push('+', stack, &top);

            break;

        case '-':

            if(!(stack[top] == '+' || stack[top] == '-' || stack[top] == '*' || stack[top] == '/'))
            {
                push('-', stack, &top);
                break;
            }
            
            while (stack[top] == '+' || stack[top] == '-' || stack[top] == '*' || stack[top] == '/')
            {
                szPostfixOutput[OutputIndex] = pop(stack, &top);
                OutputIndex++;
            }
            push('-', stack, &top);
            break;

        default:
            szPostfixOutput[OutputIndex]= szInfixInput[i];
            OutputIndex++;
            break;
        }
    }
    while (top > -1)
    {
        szPostfixOutput[OutputIndex] = pop(stack, &top);
        OutputIndex++;
    }
}


int main()
{

    char szInfixInput1[] = "a/b-c+d*e-a*c";
    printf("Infix input 1: %s \n", szInfixInput1);

    char szPostfixOutput1[30] = {0};
    
    Infix2Posfix(szInfixInput1, szPostfixOutput1);
   
    printf("Postfix output 1: %s \n\n", szPostfixOutput1);
  


    char szInfixInput2[] = "(a/(b-c+d))*(e-a)*c";
    printf("Infix input 2: %s \n", szInfixInput2);

    char szPostfixOutput2[30] = { 0 };

    Infix2Posfix(szInfixInput2, szPostfixOutput2);

    printf("Postfix output 2: %s \n\n", szPostfixOutput2);

    return 0;
}