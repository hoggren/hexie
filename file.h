#ifndef FILE_H
#define FILE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int openFile(FILE *fp, const char *filename, const char *permissions);
void getFileLength(FILE *fp, int *len);
void getContent(FILE *fp, char *buffer, int len);

#endif
