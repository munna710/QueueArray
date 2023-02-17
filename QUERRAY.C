#include<stdio.h>
#include<conio.h>
#define LENGTH 5
int queue[LENGTH];
int front=0,rear=0;
void add(int);
void del();
void list();
void main()
{
	int choice,n;

	do
	{
		clrscr();
		printf("\n\tqueue operation\n");
		printf("\n\t\t1.add");
		printf("\n\t\t2.delete");
		printf("\n\t\t3.list");
		printf("\n\t\t4.exit");
		printf("\nenter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("\n enter the data: ");
			       scanf("%d",&n);
			       add(n);
				break;
			case 2:del();
				break;
			case 3:list();
				break;
			default:printf("please enter the choice between(1-6)");
				continue;
		 }
		 getch();
	}
	while(choice!=4);
}
void add (int x)
{
	int i;
	if(rear==LENGTH&&front==0)
	{
		printf("\nsorry,queue is full...");
		return;
	}
	if(rear==LENGTH)
	{
		for(i=front;i<rear;i++)
		queue[i-front]=queue[i];
		rear=rear-front;
		front=0;
	}
	queue[rear++]=x;
	printf("\n%d is added",x);
}
void del()
{
	if(front==rear)
	{
		printf("\nsorry...queue is empty...");
		return;
	}

	printf("\n%d is removed",queue[front++]);
}
void list()
{
	int i;
	if(front==rear)
	{
		printf("\nsorry...queue is empty...");
		return;
	}
	printf("\nthe elments in queue are:\n ");
	for(i=front;i<rear;i++)
	printf("%d\n",queue[i]);
}
