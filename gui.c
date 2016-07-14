#include "gui.h"

/* Renders a statusbar with open filename, filesize in B and current row.*/
void renderStatusbar(char *filename, int filesize, struct Position *pos) {
    char *buffer = (char*) malloc(sizeof(char) * (W + 1));

    sprintf(buffer, "%s (%d B) %d,%d", filename, filesize, pos->row, pos->col);
    printf(YELLOW "%-80s\r" RESET, buffer);

    free(buffer);
}

/* renders the hex and string representation defined by COLS and BYTES. */
void renderContent(char *content, int len) {
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
                asciiReadableStr(buffer, BYTES * COLS);
                printf("    %s\n", buffer);
                k = 0;
            }
        }
    }

    /* prints last rows string representation if it isnt a complete row */
    if(n % COLS != 0) {
        for (i = 0; i < (COLS - (n % COLS)); i++)   printf(" ");
        for (i = k; i < BYTES*COLS; i++)            printf("  ");

        asciiReadableStr(buffer, k);
        printf("    %s\n", buffer);
    }

    /* full height with newlines \n */
    int rows = len / (BYTES * COLS);

    if(rows < (H - 0)) {
        int diff = (H - 0) - rows - 1; // - 1 bcause of math floor.. eh

        for (size_t i = 0; i < diff; i++) {
            printf("\n");
        }
    }

    free(buffer);
}

/* convert to readable ascii only (32-126) */
void asciiReadableStr(char *content, int len) {
    int i;
    for (i = 0; i <= len; i++) {
        char c = content[i];

        if(c < 32 || c > 126) {
            content[i] = ' ';
        }
    }
    content[len] = '\0';
}
