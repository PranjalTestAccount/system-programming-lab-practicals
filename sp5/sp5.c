#include<stdio.h>
// #include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int main()
{
  int c;
  FILE *f;
  char INST[20],lit[20][20];
  static char OPCODE[20],OPND1[20],OPND2[20];
  int i=0,j=0,coun=0,m,a=0,h,g;
  f=fopen("sp5_out.txt","r");
  printf("literal     value     length    reloc\n");
  if(f != NULL)
  {
    while ((c=getc(f)) != EOF) {
    printf("%c", c);
    }
    fclose(f);
    return 0;
  } else {
      fgets(INST,25,f);
      if(strstr(INST,"LOOP")||strstr(INST,"START")||strstr(INST,"USING")||strstr(INST,"DROP")||strstr(INST,"DC")||strstr(INST,"DS")||strstr(INST,"LTORG")||strstr(INST,"END"))
      i=0;
      j=0;
      do{
      OPCODE[j]=INST[i];
      i++;
      j++;
      } while(INST[i]!=' ');
      i++;
      j=0;
      do{
      OPND1[j]=INST[i];
      i++;
      j++;
      } while(INST[i]!=',');
      i++;
      j=0;
      do
      {
      OPND2[j]=INST[i];
      i++;
      j++;
      } while(INST[i]!='\n');
      i=0;
      j=0;
      if(OPND1[0]>47&&OPND1[0]<58&&OPND2[0]>47&&OPND2[0]<58)
        coun=coun+2;    //rr
      else if(OPND1[0]>47&&OPND1[0]<58)
      {
      if(strstr(OPND2,"=")!=NULL)
      {
      for(h=0;h<5;h++)
      {
      lit[a][h]=OPND2[h];
      }
      a++;
      coun=coun+4;
      }      //rx
      else if(atoi(OPND2))
      {
      coun=coun+4;          //rs
      }
      }
      else if(atoi(OPND1) && atoi(OPND2))
      {
      if(strstr(OPND1,"[")!=NULL)
      {
      coun=coun+6;
      }
      else
      coun=coun+4;
      }

      /*for(i=0;i<20;i++)
      {
      OPCODE[i]=0;
      OPND1[i]=0;
      OPND2[i]=0;
      } */
      fflush(f);
      }
      for(i=0;i<3;i++)
      {
      for(g=0;g<5;g++)
      {
      printf("%c",lit[i][g]);
      }
      printf("\t%d      4        R\n",coun);
      coun=coun+4;
      }
}
