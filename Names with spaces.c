#include <stdio.h>
#include <string.h>

/* Reads one line into name[] (32 bytes).
   Returns 1 if OK, 0 if the line is empty or longer than 31 characters. */
int read_name(char name[]) {
    char temp[100];
    int len;

    if (fgets(temp, 100, stdin) == NULL)    /* nothing could be read */
        return 0;

    len = strlen(temp);
    if (len > 0 && temp[len - 1] == '\n') { /* remove ONE final newline only */
        temp[len - 1] = '\0';
        len--;
    }

    if (len == 0)                           /* empty line: rejected */
        return 0;
    if (len > 31)                           /* too long for a 32-byte buffer */
        return 0;

    strcpy(name, temp);                     /* leading spaces are kept as they are */
    return 1;
}

int main() {
    char a[32], b[32], label[32];

    printf("Enter name 1: ");
    if (read_name(a) == 0) {
        printf("Empty or too long name rejected.\n");
        return 0;
    }

    printf("Enter name 2: ");
    if (read_name(b) == 0) {
        printf("Empty or too long name rejected.\n");
        return 0;
    }

    if (strcmp(a, b) == 0)                  /* exact match only */
        printf("MATCH\n");
    else
        printf("NO MATCH\n");

    if (strlen(a) + 3 > 31) {               /* "-W3" needs 3 more bytes */
        printf("Label would be too long.\n");
        return 0;
    }
    strcpy(label, a);
    strcat(label, "-W3");
    printf("Label: [%s]\n", label);         /* brackets show leading spaces */
    return 0;
}
