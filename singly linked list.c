#include<stdio.h>
#include<stdlib.h>
int num;
struct node{
    int data;
    struct node*next;
};
struct node *create()
{
    printf("Enter The Number:");
    scanf("%d",&num);
    struct node*nn;
    nn=(struct node*)malloc(sizeof(struct node));
    nn->data=num;
    nn->next=NULL;
    return nn;
}
void insert_begging(struct node **q)
{
    struct node*nn;
    nn=create();
    if((*q)==NULL)
    {
        (*q)=nn;
    }
    else
    {
       nn->next=(*q);
       (*q)=nn;
    }

}
void insert_end(struct node **q)
{
 struct node*nn;
    nn=create();
    if((*q)==NULL)
    {
        (*q)=nn;
    }
    else
    {
        struct node*temp;
        temp=(*q);
        while(temp->next!=NULL)
        {
           temp=temp->next;

        }
        temp->next=nn;

    }

}
void insert_position(struct node **q)
{   int quantity;
    struct node*nn;
    nn=create();
    int pos;
    quantity = count(q);
    printf("Enter the Position:");
    scanf("%d",&pos);
    if(pos==1)
    {
        insert_begging(q);
    }
    else  if(pos==quantity)
{

    insert_end(q);
}
else
{
    struct node*temp;
    temp=*q;
    int i=1;
    while(i<=pos-1)
    {
        temp=temp->next;
        i++;
    }
    nn->next=temp->next;
    temp->next=nn;

}

}
int count(struct node **q)
{
    int c=0;
    struct node*temp;
    temp=*q;
    while(temp!=NULL)
    {
        c++;
        temp=temp->next;
    }
    return c;
}
void display(struct node**q)
{
   struct node*temp ;
   temp=*q;
   while(temp!=NULL)
   {
       printf("%d",temp->data);
       temp=temp->next;
   }

}
int main()
{
    int choice;
   struct node *head=NULL;
   do{
   printf("_______MENU_______\n1.Insert  at begging\n2.insert at end\n3.insert at position\n4.create\n5.count\n6.Display\n7.exit");

   printf("Enter the choice:");
   scanf("%d",&choice);
   switch(choice)
   {
   case 1:
        insert_begging(&head);
        break;

    case 2:
        insert_end(&head);
        break;

   case 3:
        insert_position(&head);
        break;

   case 4:
        create();
        break;

   case 5:
        printf("count is %d ",count(&head));
        break;

   case 6:
        display(&head);
        break;

   case 7:
        printf("thank you");
        break;

   default:
    printf("invalid choice");
    break;
        }
    }while(choice!=7);

}
