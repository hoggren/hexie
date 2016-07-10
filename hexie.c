#include "hexie.h"

int main(int argc, char **argv) {
    if(argc < 2) {
        printf("No file specified, quitting!\n");
    }

    const char *filename = argv[1];
    int fp_len;
    char *fbuffer = NULL;

    FILE *fp = fopen(filename, "r");

    if(fp == NULL) {
        return -1;
    }

    fseek(fp, 0, SEEK_END);
    fp_len = ftell(fp);
    rewind(fp);

    fbuffer = (char*) malloc(fp_len);

    fread(fbuffer, 1, fp_len, fp);

    render_content(fbuffer, fp_len);
    render_statusbar(filename, fp_len);

    fclose(fp);

    return 0;
}
