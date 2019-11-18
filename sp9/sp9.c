#include<stdio.h>
// #include<conio.h>
#include<string.h>
#include<stdlib.h>
void show()
{
	int mntc=1,mdtc=0;
	int i;
	char s[20];
  char p[20];
	FILE *fp;
	fp=fopen("sp9_src.txt","r");
	if(fp == NULL)
	{
		printf("Cannot open file");
	}
	printf("\nMacro Index \t Macro Name \t MDT Index\n");
	while(feof(fp)==0)
	{
		fgets(s,18,fp);
		if(strstr(s,"MACRO")!=NULL)
		{
		mdtc=mdtc+1;
		fgets(s,18,fp);
		printf("%d",mntc);
    // if (strstr(s, "INCR") != NULL || strstr(s, "DCR") != NULL ) {
    //   printf("%s", s);
    // }
		printf("\t\t");
		for(i=0;i<4;i++)
		putchar(s[i]);
		printf("\t\t%d",mdtc);
		printf("\n");
		mntc=mntc+1;
		while(strstr(s,"MEND")==NULL)
			{
			fgets(s,18,fp);
			mdtc=mdtc+1;
			}
		}
	}
}
int main() {
  FILE *doc;
  int c;
  doc = fopen("sp9_out.txt", "r");
  while ((c=getc(doc)) != EOF) {
    printf("%c", c);
  }
  fclose(doc);
}
