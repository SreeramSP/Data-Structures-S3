#include<stdio.h>
void menu();
void push(int);
void pop(int);
void display();
int size,n1,n2,top1,top2;
int a[100];
void main()
{
    int s1;
    printf("Enter the size of the array\n");
    scanf("%d",&size);
    printf("Enter the size of the first stack\n");
    scanf("%d",&s1);
    if(s1>=size)
        main();
    n1=s1;
    n2=size-s1;
    printf("SIZE of First stack:%d\n",s1);
    printf("SIZE of Second stack:%d\n",size-s1);
    top1=-1;
    top2=n1-1;
    menu();
}

void menu()
{
    int c;
    printf("\n\n\nENTER CHOICE\n");
    printf("1.Stack ONE\n2.Stack TWO\n3.DISPLAY\n");
    scanf("%d",&c);
    switch(c)
    {
        case 1:
        {
                printf("------------------------STACK ONE------------------------\n");
                printf("ENTER CHOICE\n");
                printf("1.PUSH\n2.POP\n3.DISPLAY\n");
                scanf("%d",&c);
                switch(c)
                {
                        case 1:push(1);
                        break;
                        case 2:pop(1);
                        break;
                        case 3:display();
                        break;
                        default:menu();
                }
        }
        break;
        case 2:
        {
                printf("------------------------STACK TWO------------------------\n");
                printf("ENTER CHOICE\n");
                printf("1.PUSH\n2.POP\n3.DISPLAY\n");
                scanf("%d",&c);
                switch(c)
                {
                        case 1:push(2);
                        break;
                        case 2:pop(2);
                        break;
                        case 3:display();
                        break;
                        default:menu();
                }
        }
        break;
        case 3:display();
        break;
        case 4:menu();
    }
}


void push(int st)
{
    if(st==1)
    {

        if(top1==n1-1)
        {
            printf("OVERFLOW");
            menu();
        }
        else
        {
            top1++;
            printf("Enter value to be inserted\n");
            scanf("%d",&a[top1]);
        }
    }

    else
    {
        if(top2==n1+n2-1)
        {
            printf("OVERFLOW");
            menu();
        }
        else
        {
            top2++;
            printf("Enter value to be inserted\n");
            scanf("%d",&a[top2]);
        }
    }
    menu();
}

void display()
{
    int temp;
    printf("STACK 1\n");
    if(top1==-1)
        printf("!!!EMPTY!!!\n");
    else
    {
        temp=top1;
        printf("----------------------------------------------------------------\n");
        while(temp!=0)
        {
            printf("%d\t",a[temp]);
            temp--;
        }
        printf("%d\t",a[temp]);
        printf("\n----------------------------------------------------------------\n");
    }

    printf("STACK 2\n");
    if(top2==n1-1)
        printf("!!!EMPTY!!!\n");
    else
    {
        temp=top2;
        printf("----------------------------------------------------------------\n");
        while(temp!=0)
        {
            printf("%d\t",a[temp]);
            temp--;
        }
        printf("%d\t",a[temp]);
        printf("\n----------------------------------------------------------------\n");
    }
menu();
}

void pop(int st)
{
    if(st==1)
    {
        if(top1==-1)
        {
            printf("EMPTY!!!\n");
            menu();
        }
        else
        {
            if(top1==0)
            {
                printf("POPPED:%d",a[top1]);
                top1=-1;
            }
            else
            {
                printf("POPPED:%d",a[top1]);
                top1--;
            }
        }
    }
    else
    {
        if(top2==n1-1)
        {
            printf("EMPTY!!!\n");
            menu();
        }
        else
        {
            if(top2==n1)
            {
                printf("POPPED:%d",a[top2]);
                top2=n1-1;
            }
            else
            {
                printf("POPPED:%d",a[top2]);
                top2--;
            }
        }
    }
    menu();
}
