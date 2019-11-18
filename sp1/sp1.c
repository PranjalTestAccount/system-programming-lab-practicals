#include<stdio.h>
int main() {
  int c;
  int size=0;
  FILE *doc;
  // Open the file in reading mode
  doc = fopen("sp1_src.txt","r");
  if(doc) {
    while((c=getc(doc))!= EOF) {
      printf("%c",c);
      size += 1;
    }
  }
  printf("\nSize of given file is: %d\n",size);
  return 0;
}
