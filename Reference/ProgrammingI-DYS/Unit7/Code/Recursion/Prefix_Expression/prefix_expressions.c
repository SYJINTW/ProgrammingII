#include <stdio.h>
#include <ctype.h>

int prefix(void);

int main(void)
{
    printf("%d\n", prefix());

    return 0;
}

int prefix(void)
{
    char c;

    int ans;
    int op1, op2;

    //skip whitespace
    while(isspace(c=getchar())) continue;

    if (c=='+')
    {
        op1 = prefix();
        op2 = prefix();
        ans = op1 + op2;
    }
    else if (c=='-')
    {
        op1 = prefix();
        op2 = prefix();
        ans = op1 - op2;
    }
    else if (c=='*')
    {
        op1 = prefix();
        op2 = prefix();
        ans = op1 * op2;
    }
    else if (isdigit(c))
    {
        ungetc(c, stdin);
        scanf("%d", &ans);
    }

    return ans;
}
