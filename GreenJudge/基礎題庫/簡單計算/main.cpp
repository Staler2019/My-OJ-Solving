#include <stdio.h>  
  
int main()   
{  
    int a,b;  
    char input;  
    scanf("%d%c%d",&a,&input,&b);  
    switch(input)  
    {  
        case '+':  
            printf("%d",a+b);  
            break;  
        case '-':  
            printf("%d",a-b);  
            break;  
        case '*':  
            printf("%d",a*b);  
    }  
}
