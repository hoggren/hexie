#include <termios.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int c = 0;
    static struct termios oldTermios, newTermios;

    tcgetattr(STDIN_FILENO, &oldTermios);
    tcgetattr(STDIN_FILENO, &newTermios);
    cfmakeraw(&newTermios);

    while(1) {
        tcsetattr(STDIN_FILENO, TCSANOW, &newTermios);
        c = getchar();
        tcsetattr(STDIN_FILENO, TCSANOW, &oldTermios);

        switch (c) {
            case 113: // q
                printf("\n\n");
                exit(0);
                break;
            case 27: // 27  91 (65 up, 66 down, 67 right, 68 left)
                getchar(); // 91
                c = getchar(); //arrow
                
                switch (c) {
                    case 65:
                        printf("up\n");
                        break;
                    case 66:
                        printf("down\n");
                        break;
                    case 67:
                        printf("right\n");
                        break;
                    case 68:
                        printf("left\n");
                }
            default:
                break;
        }
    }
}
