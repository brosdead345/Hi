#include<stdio.h>
#include<stdlib.h>
typedef struct crsnglst
{
  int data;
  struct crsnglst *lnk;
}crsnglst;
crsnglst *nxt,*tmp,*lst;
int n,i,elm,pos;
main()
{
  int ch;
  void creation();
  void display();
  void insertion();
  void deletion();
  void search();
  lst=NULL;
  while(1)
  {
  clrscr();
  printf("1.Creation \n");
  printf("2.Display \n");
  printf("3.Insertion \n");
  printf("4.Deletion \n");
  printf("5.Search \n");
  printf("6.Exit \n");
  printf("Select ur choice \n");
  scanf("%d",&ch);

  switch(ch)
  {
	case 1:
		creation();
		break;
	case 2:
		display();
		break;
	case 3:
		insertion();
		break;
	case 4:
		deletion();
		break;
	case 5:
		search();
		break;
	
case 6:
		free(lst);
		free(nxt);
		exit(0);
	default:
		printf("Invalid choice \n");
  }
  getch();
  }
}
void creation()
{
	lst=NULL;
	printf("Enter the range");
	scanf("%d",&n);

	printf("Enter %d elements \n",n);
	for(i=1;i<=n;i++)
	{
	   tmp=(crsnglst*)malloc(sizeof(crsnglst));
	   printf("Enter the element %d: ",i);
	   scanf("%d",&tmp->data);
	   if(lst==NULL)
	   {
	     tmp->lnk=tmp;
	     lst=tmp;
	   }
	   else
	   {
	     tmp->lnk=lst->lnk;
	     lst->lnk=tmp;
	     lst=tmp;
	   }
	}
	printf("List was created Successfully \n ");
}
void insertion()
{
   if(lst==NULL)
   {
     printf("List is empty");
     return;
   }
   printf("Enter the pos to insert \n");
   scanf("%d",&pos);
   if(pos<1 || pos>n+1)
    printf("%d is out of range",pos);
   else
   {
    printf("Enter the elem to insert\n");
    scanf("%d",&elm);
    tmp=(crsnglst*)malloc(sizeof(crsnglst));
    tmp->data=elm;


    if(pos==1 || pos==n+1)
    {
      tmp->lnk=lst->lnk;
      lst->lnk=tmp;
      if(pos==n+1)
       lst=tmp;
    }
    else
    {
      nxt=lst->lnk;
      for(i=1;i<pos-1;i++)
       nxt=nxt->lnk;

     tmp->lnk=nxt->lnk;
     nxt->lnk=tmp;
     }
    n++;
    printf("%d is inserted successfully \n",elm);
   }
}
void deletion()
{
   if(lst==NULL)
   {
     printf("List is empty");
     return;
   }
  printf("Enter the position to delete \n");
  scanf("%d",&pos);
  if(pos<1 || pos>n)
   {
      printf("%d is out of range",pos);
      return;
   }
   nxt=lst->lnk;
  if(pos==1)
    {
      tmp=nxt;
      lst->lnk=nxt->lnk;
      elm=tmp->data;
      free(tmp);
    }
   else
    {
       for(i=1;i<pos-1;i++)
	 nxt=nxt->lnk;

       tmp=nxt->lnk;
       nxt->lnk=tmp->lnk;
       if(pos==n)
	lst=nxt;
      elm=tmp->data;
      free(tmp);
    }
     n--;
     if(n==0)
      lst=NULL;
     printf("%d deleted successfully from position %d",elm,pos);
}
void display()
{
   crsnglst *dsp;
   if(lst==NULL)
   {
     printf("List is empty");
     return;
   }
   dsp=lst->lnk;
   printf("List is \n");
   printf("%d\t",dsp->data);
   dsp=dsp->lnk;
   while(dsp!=lst->lnk)
    {
      printf("%d\t",dsp->data);
      dsp=dsp->lnk;
    }
}
void search()
{
   if(lst==NULL)
   {
     printf("List is empty");
     return;
   }
   nxt=lst->lnk;
   printf("Enter the elm to search \n");
   scanf("%d",&elm);
   if(elm==nxt->data)
    {
      printf("%d found at position 1",elm);
      return;
    }
    i=2;
    nxt=nxt->lnk;
   while(nxt!=lst->lnk)
    {
      if(nxt->data==elm)
       {
	  printf("%d found at position %d",elm,i);
	  break;
       }
    i++;
    nxt=nxt->lnk;
    }
    if(nxt==lst->lnk)
      printf("%d not found in the list ",elm);
}


