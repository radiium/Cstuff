#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{
    char * message = calloc(200, sizeof(char));
    int  i = 1;

    if (argc==1 || argv[1]==NULL)
        printf("Nothing to encrypt!\n");
    else {
        do {
            strcat(message, argv[i]);
            message[strlen(message)] = ' ';
            i++;
        }while (argv[i]!=NULL);
    }
    i = 0;
    while(message[i]!=0) {
        message[i] = toupper(message[i]);
        i++;
    }
    i = 0;
    while(message[i]!=0) {
        if (message[i]==88)
            message[i] = 65;
        else if (message[i]==89)
            message[i] = 66;
        else if (message[i]==90)
            message[i] = 67;
        else if(message[i]==32)
            message[i] = 32;
        else
            message[i] = message[i] + 3;
        i++;
    }

    printf("%s\n", message);
    free(message);

    return 0;
}

