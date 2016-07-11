#include "editor.h"

FILE *_fp = 0;
const char *_filename = 0;
int pos = 0;

void initEditor(FILE *fp, const char *filename) {
    _fp = fp;
    _filename = filename;
}

void refreshEditor() {
    int len = 0;
    
    getFileLength(_fp, &len);
    renderStatusbar(_filename, len, pos);
}

void keyCommandInput() {
    int c = 0;
    static struct termios oldTermios, newTermios;

    tcgetattr(STDIN_FILENO, &oldTermios);
    newTermios = oldTermios;

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
