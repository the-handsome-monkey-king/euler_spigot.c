/*
 * euler_spigot.c
 *
 * Print digits of euler's constant e.
 *
 * author: Ryan Morehouse
 * license: MIT
 */

#include <stdio.h>
#include <stdlib.h>
#define LIMIT 1000

void error_msg() {
  printf("Usage: ./euler_spigot.o [n]\n");
  printf("[n] is a positive integer less than 1000\n");
}

int main(int argc, char* argv[]) {
  // verify arg exist
  if(argc < 2)
  {
    error_msg();
    return 1;
  }
  
  // verify arg is within limits
  int n = atoi(argv[1]);
  if(n > LIMIT || n < 1) {
    error_msg();
    return 1;
  }

  int a_len = n+2;
  int a[a_len];
  for(int i=0; i< a_len; i++)
    a[i] = 1;

  // first digit is 2
  printf("2");

  if(n > 1)
  {
    for(int i=0; i < n-1; i++)
    {
      int q = 0;
      // traverse a[] backwards
      for(int j = a_len-1; j > -1; j--)
      {
        int denom = j+2;
        int nom = (10 * a[j]) + q;
        q = nom / denom;
        int r = nom % denom;
        /*
        printf("a[%d], nom = %d, denom = %d, "
          "q = %d, r = %d\n", 
          j, nom, denom, q, r);
        */
        a[j] = r;
        if(j == 0)
        {
          printf("%d", q);
        }
      }
    }
  }

  printf("\n");
  return 0;
}

