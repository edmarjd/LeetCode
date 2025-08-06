#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool comp(char** board, int numLi, int numCol, char* word, int i, int j, int index);

bool exist(char** board, int boardSize, int* boardColSize, char* word) {
    int numLi = boardSize;
    int numCol;
    
    if (numLi > 0) {
        numCol = boardColSize[0];
    } else {
        numCol = 0;
    }

    for (int i = 0; i < numLi; i++) {
        for (int j = 0; j < numCol; j++) {
            if ( board [i][j] == word[0] && comp(board, numLi, numCol, word, i, j, 0)) {
                return true;
            }
        }
    }

    return false;
}

bool comp(char** board, int numLi, int numCol, char* word, int i, int j, int index) {
    
    if (index == strlen(word) - 1) {
        return true;
    }
    char temp = board[i][j];
    board[i][j] = '#';

    int dir[] = {0, 1, 0, -1, 0};
    int ni, nj;
    for (int d = 0; d < 4; d++) {
        ni = i + dir[d];
        nj = j + dir[d + 1];
        

        if(ni >= 0 && ni < numLi && nj >= 0 && nj < numCol && board[ni][nj] == word[index + 1]) {
            if (comp(board, numLi, numCol,word, ni, nj, index + 1)) {
                return true;
            }
        }
    }

    board[i][j] = temp;
    return false;
}

int main() {
    
    int rows = 3, cols = 4;
    char* word = "ABCCED";

    char** board = malloc(rows * sizeof(char*));
    int* boardColSize = malloc(rows * sizeof(int));
    char data[3][4] = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };

    for (int i = 0; i < rows; i++) {
        board[i] = malloc(cols * sizeof(char));
        boardColSize[i] = cols;
        for (int j = 0; j < cols; j++) {
            board[i][j] = data[i][j];
        }
    }

    if (exist(board, rows, boardColSize, word)) {
        printf("A palavra \"%s\" foi encontrada no tabuleiro.\n", word);
    } else {
        printf("A palavra \"%s\" NÃO foi encontrada no tabuleiro.\n", word);
    }

    for (int i = 0; i < rows; i++) {
        free(board[i]);
    }
    free(board);
    free(boardColSize);

    return 0;
}