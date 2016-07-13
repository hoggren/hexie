#include "editor.h"

struct Position *_pos;
Mode mode = COMMAND; // COMMAND APPEND INSERT

FILE *_fp = 0;
char *_fileBuffer = 0; // hela filen
const char *_filename = 0;

int _len = 0;

void initEditor(FILE *fp, const char *filename) {
    getFileLength(fp, &_len);

    _fp = fp;
    _filename = filename;

    _pos = malloc(sizeof(struct Position));
    _pos->row = 0;
    _pos->col = 0;

    _fileBuffer = malloc(sizeof(char) * _len);
    getContent(_fp, _fileBuffer, _len);
}

void refreshEditor() {
    int contentLength = BYTES * COLS * (H - 1);
    char *content = (char*) malloc(sizeof(char) * contentLength);
    memcpy(content, _fileBuffer, contentLength);

    renderContent(_fileBuffer, contentLength);
    renderStatusbar(_filename, _len, _pos);
}

void keyCommandInput() {
    int c = 0;
    static struct termios oldTermios, newTermios;

    tcgetattr(STDIN_FILENO, &oldTermios);
    tcgetattr(STDIN_FILENO, &newTermios);
    cfmakeraw(&newTermios);

    tcsetattr(STDIN_FILENO, TCSANOW, &newTermios);
    c = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldTermios);

    switch (c) {
        case 113: // q
            printf("\n\n");
            exit(0);
            break;
        case 105: // i
            printf("insert\n");
            break;
        case 97: // a
            printf("append\n");
            break;
        default:
            break;
    }
}
