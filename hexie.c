#include "hexie.h"
#include "editor.h"

int main(int argc, char **argv) {
    if(argc < 2) {
        printf("No file specified, quitting!\n");
        exit(1);
    }

    FILE *fp = fopen(argv[1], "r");
    if(fp == 0) return -1;

    initEditor(fp, argv[1]);

    while(1) {
        refreshEditor();
        keyCommandInput();
        exit(0);
    }

    fclose(fp);
    return 0;
}
