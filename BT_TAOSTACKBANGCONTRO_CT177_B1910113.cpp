#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <malloc.h>
typedef int elementtype ;
typedef struct node
{
	elementtype a;
	node *next;
}node;
typedef node *stack;
stack makenull()
{
	stack header = (node*)malloc(sizeof(node));
	(header)->next=NULL;
	return header;
}
int empty(stack s)
{
	return s->next==NULL;
}
node *makenode(elementtype x)
{
	node *temp =(node*)malloc(sizeof(node));
	temp->a=x;
	return temp;
}
void push(elementtype x, stack p)
{
	node *temp =makenode(x);
	temp->next=p->next;
	p->next=temp;
}
void pop (stack p)
{
	 stack temp;
	 if (!empty(p))
	 {
	 	temp=p->next;
	 	p->next=temp->next;
	 	free(temp);
	 }
}
stack input (int n)
{
	stack l=makenull();
	elementtype x;
	for (int i=1;i<=n;i++)
	{
		printf("Phan tu thu %d ",i);
		scanf("%d",&x);
		push(x,l);
	}
	return l;
}
stack output (stack l)
{
	stack temp=l;
	printf("\n");
	while (!empty(temp))
	{
		printf("%d\t",temp->next->a);
		temp=temp->next;
	}
}
void menu ()
{
	char chon;
	int n;
	stack l;
	makenull();
	do
	{
		printf("\n\t\t MENU ");
		printf("\n\t 1. Nhap stack ");
		printf("\n\t 2. Xuat stack ");
		printf("\n\t NHAN 0 DE THOAT CHUONG TRINH");
		chon=getch();
		switch(chon)
		{
			case '1':
				{   printf("\nNhap n phan tu ");
				    scanf("%d",&n);
				    input(n);
					break;
				}
			case '2':
				{   output(l);
				    pop(l);
				    output(l);
				    pop(l);
				    output(l);
				    pop(l);
				    output(l);
					break;
				}
			case '0': exit (1);
		}
	}while (chon !=0 );
	}
int main ()
{
	while (1)
	{
		menu ();
		getch ();
	}
	return 0;
}

