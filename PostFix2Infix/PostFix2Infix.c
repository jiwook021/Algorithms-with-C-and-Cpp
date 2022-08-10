#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void push(char* element, char* stack[], int* top)
{
    stack[(*top)] = element;
    (*top)++;
}



char* pop(char* stack[], int* top)
{
    int item;
    if (*top < -1)
    {
        return NULL;
    }
    else {
        (*top)--;
        item = (*top);
        return stack[item];
    }
}

int isOperand(char x)
{
    return (x >= 'a' && x <= 'z') ||
        (x >= 'A' && x <= 'Z');
}

void Posfix2Infix(char* szPostfixInput, char* szInfixOutput)
{
    char* stack[10] = { 0 };
    int top = 0;
    int i = 0;
    char* tempOp1;
    char* tempOp2;
 
    for (i = 0; szPostfixInput[i] != '\0'; i++)
    {

        if (isOperand(szPostfixInput[i]))
        {
            char* tempExp = (char*)malloc(sizeof(char) * 16);
            tempExp[0] = szPostfixInput[i];
            tempExp[1] = '\0';
            push(tempExp, stack, &top);
        }
        else
        {
            tempOp1 = pop(stack, &top);
            tempOp2 = pop(stack, &top);

            char* tempExp = (char*)calloc(16, sizeof(char));
            char* tempInput = (char*)malloc(sizeof(char) * 16);
            tempInput[0] = szPostfixInput[i];
            tempInput[1] = '\0';

            strcat(tempExp, "(") ;
            strcat(tempExp, tempOp2);
            strcat(tempExp, tempInput);
            strcat(tempExp, tempOp1);
            strcat(tempExp, ")");
            //strcat(tempExp[5], '\0');
            push(tempExp, stack, &top);
        }
    }
    strcpy(szInfixOutput, pop(stack, &top));
}


int main()
{

    char szPostfixInput1[20] = "ab*c+";
    char szPostfixInput2[20] = "abc/-ad/e-*";
    char szInfixOutput1[20] = { 0 };
    char szInfixOutput2[20] = { 0 };

    Posfix2Infix(szPostfixInput1, szInfixOutput1);
    Posfix2Infix(szPostfixInput2, szInfixOutput2);

    printf("Postfix input 1: %s \n", szPostfixInput1);
    printf("Postfix output 2: %s \n\n", szInfixOutput1);

    printf("Infix input 1: %s \n", szPostfixInput2);
    printf("Infix output 2: %s \n\n", szInfixOutput2);

    return 0;
}