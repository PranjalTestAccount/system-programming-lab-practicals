#include <stdio.h>
#include <string.h>
int main() {
  FILE *fp;
  char ch, l[10];
  int i=0,j=0;
  fp=fopen("sp7_src.txt","r");
  printf("Literal Table\n\nLiteral\tValue\tRelocation\n");
  do
  {
  	ch=fgetc(fp);
  	if(ch == '=')
  	{
  		ch=fgetc(fp);
  		while(ch!=' ' && ch!='\n' && ch!=EOF && ch!='\t')
  		{
  			l[j]=ch;
  			printf("%c",ch);
  			ch=fgetc(fp);
  			j++;
  		}
  		l[j]='\0';
  		printf("\t %d",i+2);
  		printf("\t    R");
  		printf("\n");
  		if((strlen(l))>=7)
  		{
  			i=i+3;
  		}
  	else
  	{
  		i=i+4;
  	}
  	j=0;
  	}
  } while(ch!=EOF);
  fclose(fp);
  return 0;
}
