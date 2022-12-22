#include<stdio.h>
#include<stdlib.h>
typedef struct stack
{
  int data;
  struct stack *lnk;
}stack;
stack *top=NULL;
stack *tmp;
int elm;
void push();
void pop();
void peek();
void display();
void isempty();
void isfull();
void main()
{
   int ch;

   while(1)
   {
       printf("1. Push \n");
       printf("2. Pop \n");
       printf("3. Peek \n");
       printf("4. Display \n");
       printf("5. IsEmpty \n");
       printf("6. IsFull \n");
       printf("7. Exit \n");
       printf("Select ur choice \n");
       scanf("%d",&ch);
       switch(ch)
       {
	 	case 1:
				push();
				break;
	 	case 2:
				pop();
				break;
	 	case 3:
				peek();
				break;
	 	case 4:
				display();
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
				printf("Invalid choice \n");
       }
   }
}


void push()
{
   tmp=(stack*)malloc(sizeof(stack));
   if(tmp==NULL)
     {
		printf("Stack Overflows");
		return;
     }
     printf("Enter the element to push");
     scanf("%d",&elm);
     tmp->data=elm;
     tmp->lnk=NULL;
     if(top==NULL)
     {
       top=tmp;
     }
     else
     {
       tmp->lnk=top;
       top=tmp;
     }
     printf("%d pushed into stack successfully...\n",elm);
}
void pop()
{
   if(top==NULL)
   {
     printf("Stack Underflows");
     return;
   }
   tmp=top;
   top=tmp->lnk;
   elm=tmp->data;
   free(tmp);
   printf("%d popped out from stack successfully...\n",elm);
}
void peek()
{
  if(top==NULL)
    {
      printf("Stack is Empty...\n");
    }
  else
    printf("Peek element is %d",top->data);
}
void display()
{
  stack *dsp=top;
  if(top==NULL)
   {
     printf("Stack is empty...\n");
     return;
   }
   printf("Stack List is...\n");
   while(dsp!=NULL)
   {
      printf("%d  ",dsp->data);
      dsp=dsp->lnk;
   }
}
void isempty()
{
   if(top==NULL)
     printf("Yes it is empty...\n");
   else
     printf("No it is not Empty..\n");
}
void isfull()
{
   tmp=(stack*)malloc(sizeof(stack));
   if(tmp==NULL)
     printf("Yes stack is full...\n");
   else
     printf("No stack is not full...\n");

}
