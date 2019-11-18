// #include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
   FILE *fp;
   char p[8],strline[25],file_name[25],re;

int LC=0,l=1,value,length,i;

fp = fopen("sp6_out.txt","r"); // read mode
printf("-------------------------------------------------------------------\n");
printf(" symbol      value     length      reallocation \n");
printf("-------------------------------------------------------------------\n");
if( fp != NULL ) {
      int c;
      while ((c=getc(fp)) != EOF) {
          printf("%c", c);
      }
} else {

while( (fgets(strline,25,fp)) )
    {
    	if(strline[0]!=' ') {
        printf(" ");

   		for(i=0;i<5;i++)

{
    	p[i]=strline[i];

      printf("%c",p[i]);

}

 printf("\t");
  strncpy(p,strline,5);
  value=LC;
       re='R';
          if(LC==0)         // 1st label is of length 1
          length=1;
else
         length=4;
printf("\t%d	%d		%c\n",value,length,re);

if(length!=1)

LC=LC+4;
}
else

if((strstr(strline,"START")||strstr(strline,"USING")||strstr(strline,"DC")||strstr(strline,"DS")||strstr(strline,"END"))==0)
  {
  if(strline[11]=='R'||strline[12]=='R'||strline[13]=='R'||strline[14]=='R')
 LC=LC+2;
  else
          LC=LC+4;
    }
  }
}
fclose(fp);
printf("\n-------------------------------------------------------------------\n");
}
