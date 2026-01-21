#include<stdio.h>

int main()
{
    char operator;
    float num1, num2;

    printf("Enter calculation: ");
    scanf("%f %c %f", &num1, &operator, &num2);

    switch(operator)
    {
        case '+': printf("%.2f ",num1+num2);
                break;

        case '-': printf("%.2f ",num1-num2);
                break; 

        case '*': printf("%.2f ",num1*num2);
                break; 

        case '/': printf("%.2f ",num1/num2);
                break; 

        default: printf("Invalid operator!"); 
    }
    
}