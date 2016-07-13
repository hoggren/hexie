#ifndef GUI_H
#define GUI_H

#define YELLOW "\x1B[33m"
#define BLUE   "\x1B[34m"
#define RESET  "\x1B[0m"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "editor.h"

#define W       80
#define H       24
#define COLS    4
#define BYTES   4

void renderStatusbar();
void renderContent();
void asciiReadableStr();

#endif
