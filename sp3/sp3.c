#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int main()
{
  FILE *f;
  char INST[20];
  static char OPCODE[20],OPND1[20],OPND2[20];
  int i=0,j=0;
  f=fopen("sp3_src.txt","r");
  if(f==NULL)
  {
  	printf("no file");
  	return 0;
  }
  while(!feof(f))
  {
  	fgets(INST,25,f);
  	if(strstr(INST,"START")!=NULL||strstr(INST,"USING")!=NULL||strstr(INST,"DROP")!=NULL||strstr(INST,"DC")!=NULL||strstr(INST,"DS")!=NULL||strstr(INST,"LTORG")!=NULL||strstr(INST,"END")!=NULL)
  	{
  		printf("%s      : pseudo op\n",INST);
  	}
  	else
  	{
  		i=0;  j=0;
  		do{
  			OPCODE[j]=INST[i];
  			i++;
  			j++;
  		}while(INST[i]!=' ');
  		j=0;
  		i++;
  		do{
  			OPND1[j]=INST[i];
  			i++;
  			j++;
  		}while(INST[i]!=',');
  		j=0;
  		i++;
  		do{
  			OPND2[j]=INST[i];
  			i++;
  			j++;
  		}while(INST[i]!='\n');
  		printf("%s %s %s      : machine op\n",OPCODE,OPND1,OPND2);
  	}
  	i=0;
  	for(i=0;i<25;i++)
  	{
  		OPCODE[i]=0;
  		OPND1[i]=0;
  		OPND2[i]=0;
  	}
  }
  fclose(f);
  return 0;
}
