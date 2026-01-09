#include <stdio.h>

char b[10] = {'0','1','2','3','4','5','6','7','8','9'};

// board print
void showBoard() {
    printf("\n");
    printf(" %c | %c | %c \n", b[1], b[2], b[3]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", b[4], b[5], b[6]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n\n", b[7], b[8], b[9]);
}

// win check
int checkWin() {
    if (b[1]==b[2] && b[2]==b[3]) return 1;
    if (b[4]==b[5] && b[5]==b[6]) return 1;
    if (b[7]==b[8] && b[8]==b[9]) return 1;

    if (b[1]==b[4] && b[4]==b[7]) return 1;
    if (b[2]==b[5] && b[5]==b[8]) return 1;
    if (b[3]==b[6] && b[6]==b[9]) return 1;

    if (b[1]==b[5] && b[5]==b[9]) return 1;
    if (b[3]==b[5] && b[5]==b[7]) return 1;

    return 0;
}

int main() {
    int player = 1, choice;
    char mark;

    do {
        showBoard();

        player = (player % 2) ? 1 : 2;
        mark = (player == 1) ? 'X' : 'O';

        printf("Player %d enter number (1-9): ", player);
        scanf("%d", &choice);

        if (b[choice] != 'X' && b[choice] != 'O')
            b[choice] = mark;
        else {
            printf("❌ Galat move\n");
            player--;
        }

        player++;

    } while (!checkWin());

    showBoard();
    printf("🎉 Player %d wins!\n", --player);

    return 0;
}
