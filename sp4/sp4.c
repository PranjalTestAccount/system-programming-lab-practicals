#include<stdio.h>
#include<string.h>
#include<ctype.h>
int show()
{
	FILE *fp1,*fp2;
	char c,line[33];
	fp1=fopen("sp4_src","r");
	if(fp1==NULL)
	{
		printf("cannot open file");
    return 0;
	}
	c=fgetc(fp1);
	while(c!=EOF)
	{
		printf("%c",c);
		c=fgetc(fp1);
	}
	rewind(fp1);
	fp2=fopen("sp4_out.txt","a");
	while(feof(fp1))
	{
		fgets(line,33,fp1);

	if(strstr(line,"START")||strstr(line,"USING")||strstr(line,"END")||strstr(line,"DS")||strstr(line,"DC")||strstr(line,"EQU")||strstr(line,"ENTRY")||strstr(line,"EXTRN")||strstr(line,"DROP")||strstr(line,"MACRO"))
	{
		fprintf(fp2,"pseudo-op %s",line);
	}
	else
	{
		if(strstr(line,"'"))
		{
			fprintf(fp2,"machine-op s1 %s",line);
		}
		else
		{
			if(isalpha(line[17])||isalpha(line[18]))
			{
				fprintf(fp2,"machine-op RX %s",line);
			}
			else
			{
				if(isalpha(line[19])||isalpha(line[20])||isalpha(line[21]))
				{
					fprintf(fp2,"machine-op RS %s",line);
				}
				else
				{
					fprintf(fp2,"machine-op RR %s",line);
				}
			}
		}
	}
}
	fclose(fp1);
	fclose(fp2);
	return 0;
}
int main() {
  int c;
  FILE *doc;
  doc = fopen("sp4_out.txt","r");
  if(doc) {
    while((c=getc(doc))!= EOF) {
      printf("%c",c);
    }
  }
  return 0;
}
