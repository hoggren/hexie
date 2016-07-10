#include "gui.h"

/* Renders a statusbar with open filename, filesize in B and current position.*/
void render_statusbar(char *filename, int filesize) {
    char *buffer = (char*) malloc(sizeof(char) * (W + 1));

    memset(buffer, '-', W);
    printf("\n%s\n", buffer);
    printf("%s (%d B) 2, 33\n", filename, filesize);

    free(buffer);
}

/* renders the hex and string representation defined by COLS and BYTES. */
void render_content(char *content, int len) {
    char *buffer = (char*) malloc(sizeof(char) * (BYTES * COLS));

    /*
    i: total byte count
    k: row byte count
    n: columns count
    */
    int i, k = 0, n = 0;
    for (i = 0; i < len; i++) {
        printf("%02x", (unsigned char)content[i]);
        buffer[k] = content[i];
        k++;

        if((i+1) % BYTES == 0 && i > 1) {
            printf(" ");
            n++;

            if(n % COLS == 0) {
                ascii_readable_str(buffer, BYTES * COLS);
                printf("    %s\n", buffer);
                k = 0;
            }
        }
    }

    /* prints last rows string representation if it isnt a complete row */
    if(n % COLS != 0) {
        for (i = 0; i < (COLS - (n % COLS)); i++)   printf(" ");
        for (i = k; i < BYTES*COLS; i++)            printf("  ");

        ascii_readable_str(buffer, k);
        printf("    %s\n", buffer);
    }

    free(buffer);
}

/* convert to readable ascii only (32-126) */
void ascii_readable_str(char *content, int len) {
    int i;
    for (i = 0; i <= len; i++) {
        char c = content[i];

        if(c < 32 || c > 126) {
            content[i] = ' ';
        }
    }
    content[len] = '\0';
}
