#ifndef EDITOR_H
#define EDITOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>

#include "file.h"
#include "gui.h"

typedef enum mode_t { INSERT, APPEND, COMMAND } Mode;

struct Position {
    int row;
    int col;
};

void initEditor();
void refreshEditor();
void keyCommandInput();

#endif
