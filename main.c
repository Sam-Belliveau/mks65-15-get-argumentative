#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

char** parse_args(char* args);

int main(void)
{
    char buf[1024] = {};
    char** args;

    printf("Enter Command> ");
    fgets(buf, sizeof(buf), stdin);

    args = parse_args(buf);

    execvp(args[0], args);
}

char** parse_args(char* args)
{
    char **out = calloc(strlen(args), sizeof(char*)), *t;
    int i = 0;

    out[i++] = t = strtok(args, " ");
    while((t = strtok(NULL, " "))) out[i++] = t;

    return out;
}