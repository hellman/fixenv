#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[], char *env[]) {
    int i;
    printf("Local var: %p\n", &i);
    printf("Env vars:\n");
    while (*env != NULL) {
        printf("%p %s\n", *env, *env);
        env++;
    }
    return 0;
}
