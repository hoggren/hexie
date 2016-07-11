#include "file.h"

void getFileLength(FILE *fp, int *len) {
    fseek(fp, 0, SEEK_END);
    *len = ftell(fp);
    rewind(fp);
}

void getContent(FILE *fp, char *buffer, int len) {
    buffer = (char*) malloc(len);
    fread(buffer, 1, len, fp);
}
