#include<stdio.h>
#include<stdlib.h>
#include "image.h"

int bin[8];

int printChar(){
 int i, multiplier=1, sum=0, flag=0;
 for (i=0; i<8; i++)
 {
  sum+=multiplier*bin[i];
  multiplier*=2;
  if (bin[i]>0)
  {
   flag=1;
  }
 }
 printf("%c",(char)sum);
 return flag;
}

int main(int argc, char** argv){

int i, j, flag=1;

 if(argc!=2){
  printf("exactly 1 input arguments required\n");
  exit(0);
 }

 int *cImage, size;

 cImage=ReadImage(argv[1]);
 size=cImage[3999997]*cImage[3999998];
 printf("This image contains message:\n");
    for (i=0; flag>0 ; i+=8)
    {
	 for (j=0; j<8; j++)
	 {
	  bin[j]=cImage[i+j]%2;
	 }
	 flag=printChar();
    }
 printf("\n");
return 0;
}
