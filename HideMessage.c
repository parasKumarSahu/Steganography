#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "image.h"

int bin[8];

void binaryConverter(char ch){

 int i, n;
 for (i=0; i<8; i++)
 {
  bin[i]=0;
 }
 //printf("%c",ch);
 n=(int)ch;

 for(i=0; i<8 && n>0 ; i++)
 {
  bin[i]=n%2;
  n=n/2;
 }
}

int main(int argc, char** argv){

int i, j, k=0;
char *str;
 if(argc<3){
  printf("min 2 input arguments required\n");
  exit(0);
 }

 int *cImage, size, message_size=9, len;

 cImage=ReadImage(argv[1]);
 size=cImage[3999997]*cImage[3999998];

    for (i=0; i<size; i++)
    {
      if (cImage[i]%2==1)
      {
          cImage[i]-=1;
      }
    }



 for (i=2; i<argc; i++)
 {
  message_size+=strlen(argv[i]);
  message_size++;
 }

 str=malloc(size*sizeof(char));
 str[0]='\0';

 if (message_size*8>size-8)
 {
  printf("length of message can be max %d characters\n",(size/8)-1);
  exit(0);
 }

 for (i=2; i<argc; i++)
 {
  len=strlen(argv[i]);
  for(j=0; j<len; j++, k++)
  {
   str[k]=argv[i][j];
  }
  str[k]=' ';
  k++;
 }
 str[k]='\0';

//printf("you intered %s",str);

    for (i=0; i<message_size*8; i++)
    {
         binaryConverter(str[i]);
	 for (j=0; j<8; j++)
	 {
	  cImage[(i*8)+j]+=bin[j];
	 }
    }

 WriteImage(argv[1],1);
 printf("\n");
return 0;
}
