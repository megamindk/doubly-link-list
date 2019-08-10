#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next,*prev;
};
struct node *root=NULL,*temp,*newnode,*temp2;

void create()
{
	int n,i;
	printf("enter how many node you want:\n");
	scanf("%d",&n);
	printf("\nenter data");
for(i=0;i<n;i++)
{
	newnode=(struct node*)malloc (sizeof(struct node));
	scanf("%d",&newnode->data);
	newnode->next=NULL;
	newnode->prev=NULL;

	if(root==NULL)
	{
		root=newnode;
	}
	else
	{
		temp=root;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=newnode;
		newnode->prev=temp;
	}
}
printf("\n nodes inserted successfully");
}
void display1()
{
	clrscr();
	temp=root;
	while(temp!=NULL)
	{
		printf("%d->",temp->data);
		temp=temp->next;
	}
}
void reverse1()
{
	temp=root;
	while(temp!=NULL)
	{
	     temp=temp->next;
	}
	temp2=temp;
	while(temp2->next!=NULL)
	{
		printf("%d->",temp2->data);
		temp2=temp2->prev;
	}
 getch();
}
void delete1()
{
	int loc,i=1;
	struct node *dnode;
		temp=root;
		printf("\nenter node number to be deleted");
		scanf("%d",&loc);
	while(i<loc-1)
	{
		temp=temp->next;
		i++;
	}
	dnode=temp->next;
	temp->next=temp->next->next;
	dnode->next->prev=temp;
	free(dnode);
}


void main()
{
int ch;
clrscr();
	while(1)
	{
		printf("\nenter choice \n1.create/add\n2.delete\n3.display\n4.reverse\n5.exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:create();
				break;
			case 2: delete1();
				break;
			case 3:display1();
				break;
			case 4:reverse1();
				break;
			case 5:exit(0);
		}
	}
}
