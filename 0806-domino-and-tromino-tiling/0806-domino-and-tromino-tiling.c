int numTilings(int n) {
    if (n == 0 || n == 1) return 1;
    else if (n == 2) return 2;
    else {
        int prevAns[n + 1];
        prevAns[0] = 1;
        prevAns[1] = 1; 
        prevAns[2] = 2;
        for (int i = 3; i <= n; i++) {
            prevAns[i] = ((prevAns[i - 1] * 2) % 1000000007 + (prevAns[i - 3]) % 1000000007) % 1000000007;
        }
        return prevAns[n];
    }
}