#include "stack.h"
#include <math.h>
#include <stdio.h>

void StrToStack(Stack *st, char *s)
{
    char *it = s;
    while(*it != '\0')
    {
        Push(st, *it - '0');
        it++;
    }
}

int getStreLen(char* s)
{
    int cnt = 0;
    char *it = s;
    while(*it != '\0')
    {
        cnt++;
        it++;
    }
    return cnt;
}

void subtract(Stack st1, Stack st2, Stack *ans)
{
    while(!IsEmpty(st1) || !IsEmpty(st2))
    {
        infotype top1 , top2;
        if(!IsEmpty(st2))
        {
            Pop(&st1, &top1);
            Pop(&st2, &top2);

            if(top1 < top2)
            {
                top1 += 10;
                infotype currTop;
                Pop(&st1, &currTop);
                currTop--;
                Push(&st1, currTop);
            }
            Push(ans, top1-top2);
        }
        else
        {
            Push(ans, InfoTop(st1));
            Pop(&st1, &top1);
        }
    }
}

void printStack(Stack st)
{
    infotype tmpPop;
    while(!IsEmpty(st))
    {
        printf("%d", InfoTop(st));
        Pop(&st, &tmpPop);
    }
    printf("\n");
}

int whichGreater(char *s1, char *s2)
{
    int lens1 = getStreLen(s1);
    int lens2 = getStreLen(s2);

    if(lens1 > lens2) return 1;
    else if(lens1 < lens2) return -1;
    else
    {
        for(int i = 0; i < lens1 ; i++)
        {
            if(s1[i] > s2[i]) return 1;
            else if(s1[i] < s2[i]) return -1;
        }
        return 1;
    }
}

void removeTrailingZero(Stack *st)
{
    infotype tmpPop;
    while(!IsEmpty(*st))
    {
        if(InfoTop(*st) == 0) Pop(st,&tmpPop);
        else break;
    }
    if(IsEmpty(*st))
    {
        Push(st,0);
    }
}

int main()
{
    char s1[100], s2[100];
    scanf("%s", s1);
    scanf("%s", s2);

    Stack st1; CreateEmpty(&st1);
    Stack st2; CreateEmpty(&st2);
    Stack ans; CreateEmpty(&ans);

    StrToStack(&st1, s1);
    StrToStack(&st2, s2);

    int checkGreater = whichGreater(s1, s2);
    if(checkGreater == 1)
    {
        subtract(st1, st2, &ans);
    }
    else if (checkGreater == -1)
    {
        printf("-");
        subtract(st2, st1, &ans);
    }
    removeTrailingZero(&ans);
    printStack(ans);
    return 0;
}