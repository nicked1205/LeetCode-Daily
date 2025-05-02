#include <stdio.h>
#include <string.h>

char* pushDominoes(char* dominoes) {
    int prevInd = 0;
    char prevChar = dominoes[0];
    int len = strlen(dominoes);
    for (int i = 0; i < len; i++) {
        if (dominoes[i] == 'R' || dominoes[i] == 'L') {
            if (dominoes[i] == 'L') for (int j = i; j >= 0; j--) dominoes[j] = 'L';
            prevInd = i;
            prevChar = dominoes[i];
            break;
        }
    }
    // printf("String: %s, prevInd: %d, prevChar: %c\n", dominoes, prevInd, prevChar);
    for (int i = prevInd + 1; i < len; i++) {
        if (prevChar == 'L') {
            if (dominoes[i] == 'L') {
                for (int j = i - 1; j > prevInd; j--)
                    dominoes[j] = 'L';
                prevInd = i;
                prevChar = 'L';
            } else if (dominoes[i] == 'R') {
                prevInd = i;
                prevChar = 'R';
            }
        }
        if (prevChar == 'R') {
            if (dominoes[i] == '.') {
                dominoes[i] = 'R';
            } else if (dominoes[i] == 'L') {
                prevChar = 'L';
                int dis = i - prevInd + 1;
                if (dis % 2 == 0) {
                    for (int k = prevInd + (dis / 2); k < i; k++)
                        dominoes[k] = 'L';
                } else {
                    for (int k = prevInd + (dis / 2 + 1); k < i; k++)
                        dominoes[k] = 'L';
                    dominoes[prevInd + (dis / 2)] = '.';
                }
                prevInd = i;
            } else if (dominoes[i] == 'R') {
                prevInd = i;
                prevChar = 'R';
            }
        }
        // printf("String: %s, prevInd: %d, prevChar: %c, cur: %d, curChar: %c\n", dominoes, prevInd, prevChar, i, dominoes[i]);
    }
    return dominoes;
}