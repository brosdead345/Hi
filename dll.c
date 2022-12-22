#include<stdio.h>
#include<stdlib.h>
typedef struct dblnklst
{
  struct dblnklst *plnk;
  int data;
  struct dblnklst *nlnk;
}dblnklst ;
dblnklst  *strt,*nxt,*tmp,*lst;
int n,i,elm,pos;
int main()
{
  int ch;
  void creation();
  void display();
  void revdisplay();
  void insertion();
  void deletion();
  void search();
  while(1)
  {
      
      printf("1.Creation \n");
      printf("2.Display \n");
      printf("3.Revdisplay \n");
      printf("4.Insertion \n");
      printf("5.Deletion \n");
      printf("6.Search \n");
      printf("7.Exit \n");
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
		revdisplay();
		break;
	case 4:
		insertion();
		break;

	case 5:
		deletion();
		break;
	case 6:
		search();
		break;
	case 7:
		free(strt);
		exit(0);
	default:
		printf("Invalid choice \n");
  }
  }
}
void creation()
{
	strt=NULL;
	printf("Enter the range");
	scanf("%d",&n);

	printf("Enter %d elements \n",n);
	for(i=1;i<=n;i++)
	{
	   tmp=(dblnklst *)malloc(sizeof(dblnklst ));
	   printf("Enter the element %d: ",i);
	   scanf("%d",&tmp->data);
	   tmp->plnk=NULL;
	   tmp->nlnk=NULL;
	   if(strt==NULL)
	   {
	     strt=tmp;
	     lst=tmp;
	   }
	   else
	   {
	     lst->nlnk=tmp;
	     tmp->plnk=lst;
	     lst=tmp;
	   }
	}
	printf("Double Linked List created Successfully \n ");
}
void insertion()
{
   if(strt==NULL)
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
    tmp=(dblnklst *)malloc(sizeof(dblnklst ));
    tmp->data=elm;
    nxt=strt;

    if(pos==1)
    {
      tmp->nlnk=strt;
      tmp->plnk=NULL;
      strt->plnk=tmp;
      strt=tmp;
    }
    else if(pos==n+1)
    {
      lst->nlnk=tmp;
      tmp->plnk=lst;
      tmp->nlnk=NULL;
      lst=tmp;
    }
    else
    {
      for(i=1;i<pos-1;i++)
       nxt=nxt->nlnk;

      tmp->plnk=nxt;
      tmp->nlnk=nxt->nlnk;
      nxt->nlnk->plnk=tmp;
      nxt->nlnk=tmp;
     }
    n++;
    printf("%d is inserted successfully \n",elm);
   }
}
void deletion()
{
   dblnklst  *del;
   if(strt==NULL)
   {
     printf("List is empty");
     return;
   }
  printf("Enter the elm's position to delete \n");
  scanf("%d",&pos);
  if(pos<1 || pos>n)
  {
   printf("%d is out of range",pos);
   return;
  }
  if(pos==1)
    {
      elm=strt->data;
      tmp=strt;
      strt=tmp->nlnk;
      strt->plnk=NULL;
    }
  else if(pos==n)
  {
    elm=lst->data;
    tmp=lst;
    lst=tmp->plnk;
    lst->nlnk=NULL;
  }
   else
    {
      nxt=strt;
      for(i=1;i<pos;i++)
	nxt=nxt->nlnk;

      elm=nxt->data;
      tmp=nxt;
      nxt->plnk->nlnk=tmp->nlnk;
      tmp->nlnk->plnk=nxt->plnk;
    }
     free(tmp);
     printf("%d deleted successfully from pos %d",elm,pos);
     n--;
}

void display()
{
   dblnklst  *dsp;
   if(strt==NULL)
   {
     printf("List is empty");
     return;
   }
   dsp=strt;
   printf("List is \n");
   while(dsp!=NULL)
    {
      printf("%d\t",dsp->data);
      dsp=dsp->nlnk;
    }
}
void revdisplay()
{
   dblnklst  *dsp;
   if(strt==NULL)
   {
     printf("List is empty");
     return;
   }
   dsp=lst;
   printf("List is \n");
   while(dsp!=NULL)
    {
      printf("%d\t",dsp->data);
      dsp=dsp->plnk;
    }
}
void search()
{
   dblnklst  *srch;
   if(strt==NULL)
   {
     printf("List is empty");
     return;
   }
   srch=strt;
   printf("Enter the elm to search \n");
   scanf("%d",&elm);
   i=1;
   while(srch!=NULL)
    {
      if(srch->data==elm)
       {
	  printf("%d found at position %d",elm,i);
	  break;
       }
    i++;
    srch=srch->nlnk;
    }
    if(srch==NULL)
      printf("%d not found in the list ",elm);
}

