#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void show()
{
	FILE *fp,*ft;
	char d[80],s[80],s1[80],s2[80],s3[80],name[80],fname[10],jname[10];
	int check,check1,check2,check3,x,i,num;
	char ch,ch2,ch4;
	int ch1,ch3,ch5;
	// clrscr();
	ft=fopen("program.txt","r");
	if(ft==NULL)
	{
		printf("Cannot open file");
		exit(0);
	}
	while(fgets(d,79,ft)!=NULL)
	{
		// check=strstr(d,"MACRO");
		// check1=strstr(d,"ADD");
		if(check!=0)
		{// check=strstr(d,"MACRO");
		// check1=strstr(d,"ADD");
			fgets(name,79,ft);
			num=9;
			while(num<=14)
			{
				jname[x]=name[num];
				num++;
			}
			printf("%s",jname);
			fgets(s1,79,ft);
			fgets(s2,79,ft);
			fgets(s3,79,ft);
		}
		if(check1!=0)
		{
			x=1;
			ch=d[x];
			ch1=d[x+1];
			while(ch!='0'||ch!='0')
			{
				x++;
				ch=d[x];
				ch1=d[x+1];
			}
			x=x+3;
			ch2=d[x];
			ch3=d[x+1];
			x=x+3;
			ch4=d[x];
			ch5=d[x+1];
		}
	}
	fclose(ft);
	ft=fopen("sp10_scr.txt","r");
	if(ft==NULL)
	{
		printf("Cannot open file");
		exit(0);
	}
	printf("Expanded program:\n");
	while(fgets(d,79,ft)!=NULL)
	{
		check=0;
		check1=1;
		check2=2;
		check3=3;
		if(check== 0 && check1 == 0 && check2 == 0)
		{
			printf("%s",d);
		}
		if(check!=0)
		{
			i=0;
			while(d[i]!='&')
			{
				printf("%c",d[i]);
				i++;
			}
		}
	}
}
int main() {
  int c;
  FILE *doc;
  doc = fopen("sp10_out.txt", "r");
  while ((c=getc(doc)) != EOF) {
    printf("%c", c);
  }
  return 0;
}
