
/******************************************************************************

Singly Linked List
By Sreeram SP

*******************************************************************************/


#include<stdio.h>
#include<stdlib.h>

struct node
{
 int info;
 struct node *link;
};
struct node *ptr,*ptr1,*ptr2,*first=NULL;
void main()
{
    
    int ch,x;
    int c;
    printf("1.Insert\n2.Delete\n3.Display\n");
    printf("\nEnter Choice=");
    scanf("%d",&c);
    switch(c)
    {
        case 1:
        {
            printf("INSERTION\n");        
            printf("Enter the node\n1.In the Beginning\n2.In the End\n3.After \n4.Before\n");
            printf("Enter Choice=");
            scanf("%d",&ch);
            switch(ch)
            {
                case 1:/*Entering the data In the Beginning*/
                       {
                       ptr=(struct node*)malloc(sizeof(struct node));
                       printf("Enter the data=");
                       scanf("%d",&ptr->info);/*Entering the data*/
                       ptr->link=first;
                       first=ptr;                                           
                       }
                       main();
                       break;
                case 2:/*Entering the data In the End*/
                       ptr=(struct node*)malloc(sizeof(struct node));
                       printf("Enter the data=");
                       scanf("%d",&ptr->info);/*if no nodes are there then entering the data*/
                       if(first==NULL)
                       {
                         ptr->link=first;
                         first=ptr;
                       }
                       else
                       {
                         ptr1 =first;
                         while(ptr1->link!=NULL)
                         {
                             ptr1=ptr1->link;
                         }
                         ptr1->link=ptr;
                         ptr->link=NULL;
                        }
                        main();
                        break;
                case 3:/*Entering the data In After*/
                       ptr=(struct node*)malloc(sizeof(struct node));
                       printf("Enter the data=");
                       scanf("%d",&ptr->info);
                       printf("Enter the element next to which next node is to be created=");
                       scanf("%d",&x);
                       ptr1=first;
                       while(ptr1!=NULL && ptr1->info!=x)
                       {
                          ptr1=ptr1->link;
                       }
                       if(ptr1==NULL)
                          printf("Element not found");
                       else
                       {
                         ptr->link=ptr1->link;
                         ptr1->link=ptr;
                       }
                       main();
                       break;
                case 4:/*Entering the data In Before*/
                       ptr=(struct node*)malloc(sizeof(struct node));
                       printf("Enter the data=");
                       scanf("%d",&ptr->info);
                       printf("Enter the element before to which next node is to be created=");
                       scanf("%d",&x);
                       ptr1=first;
                       while(ptr1!=NULL && ptr1->info!=x)
                       {                                                                               
                          ptr2=ptr1;
                          ptr1=ptr1->link;
                       }
                       if(ptr1==NULL)
                          printf("Element not found");
                       else if(ptr1==first)
                       {                         
                          ptr->link=ptr1;
                          first=ptr;
                          
                       }            
                       
                       else
                       {
                         ptr2->link=ptr;                        
                         ptr->link=ptr1;
                       }
                       main();
                       break;
               default:main();
                }
        }
        break;
        
      
        case 2:
        {
            printf("DELETION\n");            
            printf("Deleting from \n1.Beginning\n2.End\n3.In Between\n");
            printf("Enter Choice=");
            scanf("%d",&ch);
            switch(ch)
            {
                case 1:/*Deleting the data from the Beginning*/
                       if(first==NULL)
                       printf("Linked List Underflow");
                       else
                       {
                         ptr=first;
                         first=first->link;
                         ptr->link=NULL;
                         printf("%d is deleted",ptr->info);
                         free(ptr);
                       }
                       main();
                       break;
                case 2:/*Deleting the data from the End*/
                       if(first==NULL)
                       printf("Link List Underflow");
                       else
                       {
                         ptr=first;
                         while(ptr->link!=NULL)
                         {
                            ptr1=ptr;
                            ptr=ptr->link;
                         }
                         if(ptr1==first && ptr==NULL)
                          printf("%d is deleted",ptr1->info);
                         else
                         {
                          ptr1->link=NULL;
                          printf("%d is deleted",ptr->info);
                         free(ptr);
                       }
                       }
                       main();
                       break;
                case 3:/*Deleting the data In Between*/
                      if(first==NULL)
                      printf("Link List Underflow");
                      else
                      {
                         printf("Enter the element of the node to be deleted=");
                         scanf("%d",&x);
                         ptr=first;
                         while(ptr!=NULL && ptr->info!=x)
                         {
                            ptr1=ptr;
                            ptr=ptr->link;
                         }
                        if(ptr==NULL)
                        printf("Element not found");
                        else
                        {
                             if(ptr==first)
                                first=ptr->link;
                             else
                                ptr1->link=ptr->link;
                           ptr->link=NULL;
                           printf("%d is deleted",ptr->info);
                           free(ptr);
                        }
                      }
                      main();
                      break;
               default:main();
                }
            }
       case 3:/*Display*/
             {
              printf("DISPLAY\n");
              if(first==NULL)
                 printf("No Nodes");
              else
              {
                 ptr=first;
                 while(ptr!=NULL)
                 {
                    printf("%d\t",ptr->info);
                    ptr=ptr->link;
                 }
              }
              main();
              break;
             }
       case 4 :exit(0);
  }
}
 

 
 
 

