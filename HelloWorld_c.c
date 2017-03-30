#include <stdio.h>

int converted_main (void)  {
  int a = 10;

  printf("Start with a= %d,\n", a );
  printf("HELLO WORLD~!!\n");
  // printf("%s\n",a );
  printf("a++= %d/%d, a--= %d/%d, --a= %d/%d, ++a= %d/%d\n\n\n",
  a++,a, a--,a, --a,a, ++a,a);
  return 0;
}

int main (void) {
  converted_main();
  printf("HELLO WORLD~!!\n\n");
  return 0;
}



/*
code C  int argc, char const *argv[]
int a=5;
printf("%d,%d,%d,%d, a++, a--, --a, ++a");
*/
