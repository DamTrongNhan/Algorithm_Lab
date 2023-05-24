#include <stdio.h>
#include <conio.h>
#define max 100
typedef int elementtype;
typedef int position;
typedef struct
{
	elementtype elements[max];
	position last;
}list;
void makenull_list (list *l)
{
	l->last=0;
}
int empty_list (list l)
{
	return (l.last==0);
}
int full_list(list l)
{
	return (l.last==max);
	}
position first_list(list l)
{
	return 1;
}
position end_list(list l)
{
	return l.last+1;
}
position next(position p, list l)
{
	return p+1;
}
position previous (position p, list l)
{
	return p-1;
}
elementtype retrieve(position p, list l)
{
	return l.elements[p-1];
}
void insert_list (elementtype x, position p, list *l)
{
	position i;
	if (l->last==max)
	printf("Danh sach day ! \n ");
	else if ((p<1)||(p>l->last+1))
	printf("Vi tri khong hop le !\n");
	else
	{
		for (i=l->last;i>=p;i--)
		l->elements[i]=l->elements[i-1];
		l->last++;
		l->elements[p-1]=x;
	}
}
void delete_list(position p, list *l)
{
	if ((p<1)||(p>l->last))
	printf("Vi tri khong hop le ! \n");
	else 
	if (empty_list(*l))
	printf("Danh sach rong ! \n");
	else
	{
		position i;
		for (i=p;i<l->last;i++)
		l->elements[i-1]=l->elements[i];
		l->last--;
	}
}
position locate(elementtype x, list l)
{
	position i;
	int found=0;
	i=first_list(l);
	while ((i!=end_list(l))&&(found==0))
	{
		if (retrieve (i,l)==x)
		found=1;
		else i=next(i,l);
	}
	return i;
}
void read_list (list *l)
{
	int i,n,x;
	makenull_list(l);
	printf("Nhap vao so phan tu trong danh sach: ");
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
	printf("Phan tu thu %d la: ",i);
	scanf("%d",&x);
	insert_list(x,i,l);
	}
}
void print_list(list l)
{
	position i=first_list(l);
	while (i!=end_list(l))
	{
		printf("%d ",retrieve(i,l));
		i=next(i,l);
	}
printf("\n ");
}
int main ()
{
	list l;
	elementtype x;
	position p;
	makenull_list(&l);
	read_list(&l);
	printf("Danh sach vua nhap: ");
	print_list(l);
	printf("Nhap phan tu can them: ");scanf("%d",&x);
	printf("Nhap vi tri can them: ");scanf("%d",&p);
	insert_list(x,p,&l);
	printf("Danh sach sau khi them phan tu: ");
	print_list(l);
	printf("Nhap vao phan tu muon xoa: ");scanf("%d",&x);
	p=locate(x,l);
	delete_list(p,&l);
	printf("Danh sach sau khi xoa phan tu %d la: ",x);
	print_list(l);
	return 0;
}
