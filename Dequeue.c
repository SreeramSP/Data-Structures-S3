#include<stdio.h>
void menu();
void insright();
void insleft();
void delleft();
void delright();
void display();
int a[100];
int size;
int l=-1;
int r=-1;
void menu()
{
    int n,subn;
    printf("\n\n\n0.EXIT\n1.Input restricted\n2.Output restricted\n3.Display\n");
    printf("Enter choice ");
    scanf("%d",&n);
    switch(n)
    {
        case 0:break;
        case 1:{
                    printf("\n\nINPUT RESTRICTED\n");
                    printf("1.Insert right\n2.Delete left\n3.Delete right\nEnter choice ");
                    scanf("%d",&subn);
                    switch(subn)
                    {
                        case 1:insright();
                                break;
                        case 2:delleft();
                                break;
                        case 3:delright();
                                break;
                        default:menu();
                    }

                }
                break;

        case 2:{
                    printf("\n\nOUTPUT RESTRICTED\n");
                    printf("1.Delete left\n2.Insert left\n3.Insert right\nEnter choice ");
                    scanf("%d",&subn);
                    switch(subn)
                    {
                        case 1:delleft();
                                break;
                        case 2:insleft();
                                break;
                        case 3:insright();
                                break;
                        default:menu();
                    }

                }
                break;

        default:display();
                break;
    }
}
void main()
{
    printf("Enter the size of the DEQUEUE ");
    scanf("%d",&size);
    menu();
}


void insleft()
{
    if(l==-1 && r==-1)
        {
            l=0;
            r=0;
        }

    else
    {
        if(r==l-1)
        {
            printf("------------------------------------------------------------\n");
            printf("\t\t\tOVERFLOW\n");
            printf("------------------------------------------------------------\n");
            menu();

        }
        else if(l==0)
        {
            if(r==-1)
            {
                printf("------------------------------------------------------------\n");
                printf("\t\t\tOVERFLOW\n");
                printf("------------------------------------------------------------\n");
            }
            else
            {
                l=size-1;
            }
        }
        else
        {
            l--;
        }
    }
    printf("Enter the element ");
    scanf("%d",&a[l]);
    menu();
}


void insright()
{
    if(l==-1 && r==-1)
        {
            l=0;
            r=0;
        }
    else
    {
        if(r==l-1)
        {
            printf("------------------------------------------------------------\n");
            printf("\t\t\tOVERFLOW\n");
            printf("------------------------------------------------------------\n");
            menu();
        }
        else
        {
            if(r==size-1&&l==0)
            {
                printf("------------------------------------------------------------\n");
                printf("\t\t\tOVERFLOW\n");
                printf("------------------------------------------------------------\n");
                menu();
            }
            else
            {
                if(r==size-1)
                {
                    r=0;
                }
                else
                    r++;
            }
        }

    }

    printf("Enter the element ");
    scanf("%d",&a[r]);
    menu();
}






void delleft()
{
    if(l==-1 && r==-1)
    {
        printf("EMPTY");
        menu();
    }
    else
    {
        if(l==r)
        {
            printf("%d HAS BEEN DELETED",a[l]);
            l=-1,r=-1;
        }
        else
        {
            if(l==size-1)
            {
                printf("%d HAS BEEN DELETED",a[l]);
                l=0;
            }
            else
            {
                printf("%d HAS BEEN DELETED",a[l]);
                l++;
            }
        }
    }
    menu();
}

void delright()
{
    if(l==-1 && r==-1)
    {
        printf("EMPTY\n");
        menu();
    }
    else
    {
        if(l==r)
        {
            printf("%d HAS BEEN DELETED",a[r]);
            l=-1,r=-1;
        }
        else
        {
            if(r==0)
            {
                printf("%d HAS BEEN DELETED",a[r]);
                r=size-1;
            }
            else
            {
                printf("%d HAS BEEN DELETED",a[r]);
                r--;
            }
        }
    }

    menu();

}



void display()
{
    int temp=l;
    if(l==-1 &&r==-1)
    {
        printf("EMPTY\n");
        menu();
    }
    printf("ELEMENTS ARE\n---------------------------------------------------------------------\n");
    while(temp!=r)
    {
                printf("%d\t",a[temp]);
                if(temp==size-1)
                    temp=0;
                else
                    temp++;
    }
        printf("%d\n",a[temp]);
        printf("---------------------------------------------------------------------\n");
        menu();
}
