#include <stdio.h>
#define size 30

typedef struct 
{
	float dodai;
	int dau, cuoi;
	int dadung;
}canh;

void readfile(char file_name[], canh a[][size], int *n)
{
	int i,j;
	FILE *f;
	f=fopen(file_name,"r");
	if (f==NULL)
	{
	printf("Loi mo file");
	return;
	}
	fscanf(f,"%d",n);
	for (i=0;i<*n;i++)
	for (j=0;j<*n;j++)
	{
		fscanf(f,"%f",&a[i][j].dodai);
		a[i][j].dau=i;
		a[i][j].cuoi=j;
		a[i][j].dadung=0;
	}
	fclose(f);
}
void inmatran(canh a[][size], int n)
{
	int i,j;
	printf("\n Ma tran trong so cua do thi \n");
	for (i=0;i<n;i++)
	{
		for (j=0;j<n;j++)
		printf("%c%c=%5.2f ",a[i][j].dau+97,a[i][j].cuoi+97,a[i][j].dodai);
		printf("\n");
	}
}
void inpa(canh pa[], int n)
{
	int i;
	float sum=0;
	printf("\n Phuong an tim duoc \n");
	for (i=0;i<n;i++)
	{
			sum+=pa[i].dodai;
			printf("Canh %c%c=%5.2f \n",pa[i].dau+97,pa[i].cuoi+97,pa[i].dodai);
	}
	printf("\n Chu trinh tim duoc la\n");
	for (i=0;i<n;i++)
	{
		printf("%c",pa[i].dau+97);
		printf("->");
	}
	printf("%c",pa[0].dau+97);
	printf("\nTong do dai cua chu trinh la %5.2f\n",sum);
}
float canhnn(canh a[][size], int n)
{
	float cmin=3.40282e+38;
	int i,j;
	for (i=0;i<n;i++)
	for (j=0;j<n;j++)
	if (i!=j && !a[i][j].dadung && a[i][j].dodai<cmin)
		cmin=a[i][j].dodai;
		return cmin;	
}
float canduoi(canh a[][size], float tgt, int n, int i)
{
	return tgt+(n-i)*canhnn(a,n);
}
void capnhatpa(canh a[][size], int n, float tgt, float *gnntt, canh x[], canh pa[])
{
	int i;
	x[n-1]=a[x[n-2].cuoi][x[0].dau];
	tgt= tgt + x[n-1].dodai;
	if (*gnntt > tgt)
	{
		*gnntt=tgt;
		for (i=0;i<n;i++)
		pa[i]=x[i];
	}
}
int cochutrinh(canh x[], int k, int ketiep)
{
	int i=0, coct=0;
	while (i<k && !coct)
		if (ketiep == x[i].dau)
		coct=1;
		else i++;
	return coct;
}
void nhanhcan(canh a[][size], int n, int i, int dau, float *tgt, float *cd, float *gnntt, canh x[],canh pa[])
{
	int j;
	for (j=0;j<n;j++)
	if (dau !=j && !a[dau][j].dadung && !cochutrinh(x,i,j))
	{
		*tgt = *tgt + a[dau][j].dodai;
		*cd = canduoi(a, *tgt, n ,i+1);
		if (*cd < *gnntt)
		{
			x[i]=a[dau][j];
			a[dau][j].dadung=1;
			a[j][dau].dadung=1;
			
			if (i==n-2)
			capnhatpa(a,n,*tgt,gnntt,x,pa);
		else
		    nhanhcan(a, n, i+1, j, tgt, cd, gnntt, x, pa);    
		}
		*tgt= *tgt - a[dau][j].dodai;
		a[dau][j].dadung=0;
		a[j][dau].dadung=0;
	}
}
void reset(canh a[][size], int n)
{
	int i,j;
	for (i=0;i<n;i++)
	for (j=0;j<n;j++)
	a[i][j].dadung=0;
}
int main ()
{
	canh a[size][size];
	int n;
	printf("\n Phuong an TSP dung thuat toan NHANH CAN: \n");
	readfile("input2.txt",a,&n);
	canh pa[n];
	canh x[n];
	char tpxp, yn;
	while (1)
	{
		fflush(stdin);
		inmatran(a,n);
		float tgt=0, cd=0, gnntt=3.40282e+38;
		printf("\n Xuat phat thanh pho nao? ");
		printf("\n Nhap mot trong cac thanh pho tu a den %c: ",n-1+97);
		scanf("%c",&tpxp);
		nhanhcan(a,n,0,tpxp-97,&tgt,&cd,&gnntt,x,pa);
		inpa(pa,n);
		fflush(stdin);
		printf("\n Tiep tuc Y/N ");
		scanf("%c",&yn);
		if (yn=='N'|| yn=='n')
		break;
		reset(a,n);
	}
	return 0;
}
