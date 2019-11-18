#include<stdio.h>
int main()
{
  FILE *fps,*fptr;
  char c;
  fps= fopen("sp2_src.txt","r");
  fptr = fopen("sp2_out.txt","r");
  while((c=getc(fps))!=EOF) {
    printf("%c",c);
  }
  printf("\n");
  while((c=getc(fptr))!=EOF) {
    printf("%c",c);
  }
  return 0;
}
