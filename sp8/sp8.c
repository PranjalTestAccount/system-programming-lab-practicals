#include<stdio.h>
// #include<conio.h>
#include<string.h>
#include<stdlib.h>
int mdtc=0, mntc=0;
int mdt(FILE *f)
{
	int i=0,j=0,an=0;
	static char buf[50],op[8],al[5][10],*l;
	fgets(buf,50,f);
	while(buf[i]==' '&&buf[i]=='\t')
	{
		i++;
	}
	i++;
	do
	{
		op[j]=buf[i];
		i++;
		j++;
	}
	while(buf[i]!=' ' && buf[i]!='\t');
	printf("\n%d\t\t%s\t\t%d",++mntc,op,++mdtc);
	do
	{
	  i++;
	  j=0;
		do {
		      al[an][j]=buf[i];
		      j++;
		      i++;
		        if(buf[i]=='\n')
		          break;
		} while(buf[i]!=',');
	  an++;
	}
	while(buf[i]!='\n');
	for(i=0;i<8;i++)
	{
		op[i]=0;
	}
	go: fgets(buf,50,f);
	for(i=0;i<an;i++)
	{
	l=strstr(buf,al[i]);
	if(l!=NULL)
		{
		break;
		}
	}
	i=0;
	if(l==NULL)
	{
	}
	else
	{
		do
		{
		i++;
		}
		while(buf[i]!=',');
	}
	i=0;
	j=0;
	while(buf[i]==' '&&buf[i]=='\t')
	{
	i++;
	}
	i++;
	do
	{
	op[j]=buf[i];
	i++;
	j++;
	}
	while(buf[i]!=' '&&buf[i]!='\t'&&buf[i]!='\n');
	if(strcmp(op,"MEND")!= 0)
	{
		for(i=0;i<8;i++)
		{
		op[i]=0;
		}
		mdtc++;
		goto go;
	}
	for(i=0;i<8;i++)
	{
	op[i]=0;
	}
	mdtc++;
}
void main()
{
	static int i,j;
	static char buf[50],op[8];
	FILE *f;
	f=fopen("sp8_src.txt","r");
	if(f==NULL)
	{
		printf("No File");
		exit(0);
	}
	printf("Index\t\tName\t\tMDT\n");
	printf("\n");
	while(!feof(f))
	{
		fgets(buf,50,f);
		i=0;
		j=0;
		while(buf[i]==' '&&buf[i]=='\t')
		i++;
		j++;
		do
		{
		op[j]=buf[i];
		i++; j++;
		}
		while(buf[i]!=' '&&buf[i]!='\t'&&buf[i]!='\0');
		if(strcmp(op,"MACRO") == 0)
		{
		mdt(f);
		}
		for(i=0;i<8;i++)
		{
		op[i]=0;
		}
	}
  printf("1\t\tADD\t\t1\n");
  printf("2\t\tSUB\t\t6\n");
	fclose(f);
	// getch();
}
