int checkCommonInPairs(int a1, int b1, int a2, int b2, int a3, int b3) {
    if ((a1 == a2 || a1 == b2) && (a1 == a3 || a1 == b3)) {
        return 1;
    }
    if ((b1 == a2 || b1 == b2) && (b1 == a3 || b1 == b3)) {
        return 1;
    }
    
    return 0;
}
int minDominoRotations(int* tops, int topsSize, int* bottoms, int bottomsSize) {
    int rotation = 0;
    int rotation2 = 1;
    int firstTop = tops[0];
    int firstBot = bottoms[0];
    if (firstTop == firstBot) rotation2 = 0;
    char curMatching = '2';
    for (int i = 1; i < topsSize; i++) {
        bool check = checkCommonInPairs(firstTop, firstBot, tops[i - 1], bottoms[i - 1], tops[i], bottoms[i]);
        if (!check) return -1;
        if (firstTop != firstBot) {
            if ((tops[i] != firstTop && bottoms[i] == firstTop) || (bottoms[i] != firstBot && tops[i] == firstBot)) {
                printf("Rotate %d\n", i);
                rotation++;
            }
            if ((tops[i] != firstBot && bottoms[i] == firstBot) || (bottoms[i] != firstTop && tops[i] == firstTop)) {
                printf("Rotate2 %d\n", i);
                rotation2++;
            }
        } else {
            if (tops[i] != firstTop && bottoms[i] == firstTop) rotation++;
            if (bottoms[i] != firstBot && tops[i] == firstBot) rotation2++;
        }
    }

    printf("%d %d\n", rotation, rotation2);

    if (rotation2 <= rotation && rotation2 != -1) return rotation2;
    return rotation;
}