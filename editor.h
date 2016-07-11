#ifndef EDITOR_H
#define EDITOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>

#include "file.h"
#include "gui.h"

void initEditor(FILE *fp, const char *filename);
void refreshEditor();
void keyCommandInput();

#endif
