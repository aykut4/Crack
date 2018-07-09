#define _XOPEN_SOURCE
#include <stdio.h>
#include <crypt.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char str1[15];
    char str2[15];
    int n = 97;
    
    for (int i = 97; i <= 122; i++)
    {
        char wordArray[3] = {n, i};
        char *hash = crypt(wordArray, "50");
        
        int check = strcmp(argv[1], hash);
        
        if(check == 0)
        {
            printf("Password: %s\n", wordArray);
            return 0;
        }
        
        if (i == 122)
        {
            n++;
            i = 97;
        }
        
        if (n == 123)
        {
            return 0;
        }
    }
}