#include<stdio.h>
#include<stdlib.h>
typedef struct queue
{
   int data;
   struct queue *lnk;
}queue;
void enqueue();
void dequeue();
void display();
void peek();
void isempty();
void isfull();
queue *front,*rear,*tmp;
int elm;
void main()
{
   int ch;
   front=NULL;
   rear=NULL;
   while(1)
   {
      printf("\n");
      printf("1. Enqueue \n");
      printf("2. Dequeue \n");
      printf("3. Display \n");
      printf("4. Peek  \n");
      printf("5. IsEmpty \n");
      printf("6. IsFull \n");
      printf("7. Exit \n");
      printf("Select ur choice....\n");
      scanf("%d",&ch);
      switch(ch)
      {
	  case 1:
		  enqueue();
		  break;
	  case 2:
		  dequeue();
		  break;
	  case 3:
		  display();
		  break;
	  case 4:
		  peek();
		  break;
	  case 5:
		  isempty();
		  break;
	  case 6:
		  isfull();
		  break;
	  case 7:
		  exit(0);
	  default:
		   printf("Invalid choice...\n");
      }
   }
}
void enqueue()
{
   tmp=(queue*)malloc(sizeof(queue));
   if(tmp==NULL)
     {
       printf("Queue Overflows...\n");
       return;     }
      printf("Enter the element to insert");
      scanf("%d",&elm);
      tmp->data=elm;
      tmp->lnk=NULL;
     if(front==NULL && rear==NULL)
      {
	 front=tmp;
	 rear=tmp;
      }
      else
      {
	 rear->lnk=tmp;
	 rear=tmp;
      }
      printf("%d inserted successfully...",elm);
}
void dequeue()
{
   if(front==NULL)
   {
      printf("Queueu Underflows....\n");
      return;
   }
   elm=front->data;
   tmp=front;
   front=tmp->lnk;
   free(tmp);
   printf("%d deleted successfully...",elm);
}
void peek()
{
  if(front==NULL)
  {
     printf("Queue is empty....\n");
  }
  else
  {
     printf("Peek element is %d",front->data);
   }
}
void display()
{
  if(front==NULL)
  {
     printf("Queue is empty....\n");
  }
  else
  {
     printf("Queue elements r ");
     tmp=front;
     
while(tmp!=NULL)
     {
       printf("%d ",tmp->data);
       tmp=tmp->lnk;
     }
   }
}
void isempty()
{
  if(front==NULL)
  {
     printf("Yes... Queue is empty....\n");
  }
  else
  {
     printf("No... Queue is not empty....\n");
   }
}
void isfull()
{
  tmp=(queue*)malloc(sizeof(queue));
  if(tmp==NULL)
  {
     printf("Yes... Queue is FULL....\n");
  }
  else
  {
     printf("No... Queue is not FULL....\n");
   }
}
