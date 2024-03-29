/* Vunlerable program: stack.c */
/* You can get this program from the lab's website */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* You should choose last 2-digits of your 800-number as BUF_SIZE
 * Suggested value: between 0 and 400  */
#ifndef BUF_SIZE
#define BUF_SIZE 24
#endif

int bof(char *str)
{
    char buffer[BUF_SIZE];

    /* The following were used to determine whether results in
       gdb were correct. */

    /* register int x asm("ebp"); */
    /* register int y asm("esp"); */
    /* printf("Address of buffer is: %p\n", (void*)&buffer); */
    /* printf("Address of ebp is: %x\n", x); */
    /* printf("Address of esp is: %x\n", y); */

    /* The following statement has a b overflow problem */
    strcpy(buffer, str);

    return 1;
}

int main(int argc, char **argv)
{
    char str[517];
    FILE *badfile;

     /* Change the size of the dummy array to randomize the parameters
       for this lab. Need to use the array at least once */
     char dummy[BUF_SIZE]; memset(dummy, 0, BUF_SIZE);

    badfile = fopen("badfile", "r");
    fread(str, sizeof(char), 517, badfile);
    bof(str);
    printf("Returned Properly\n");
    return 1;
}
