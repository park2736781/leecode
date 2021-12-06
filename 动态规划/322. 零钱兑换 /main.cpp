//
// Created by park on 2021/12/5.
//
#include <stdio.h>
#include <cstdlib>
#include <math.h>
#include <climits>

/*
            0, n = 0
 dp(n) =    -1, n < 0
            min{dp(n - coin) + 1 | coin E coins}, n > 0
 */

int rCoinChange(int *coins, int len, int amount) {
    if (amount == 0) {
        return 0;
    }
    if (amount < 0) {
        return -1;
    }
    int res = INT_MAX;
    for (int i = 0; i < len; i++) {
        int subRes = rCoinChange(coins, len, amount - coins[i]);
        if (subRes == -1) {
            continue;
        }
        res = fmin(res, subRes + 1);
    }
    return (res == INT_MAX ? -1 : res);
}

int coinChange(int *coins, int len, int amount) {
    if (amount == 0) {
        return 0;
    }
    if (amount < 0) {
        return -1;
    }
    // 设置为amount + 1。最大硬币数不过amount + 1
    int *dp = (int *) malloc(sizeof(int) * (amount + 1));
    for (int i = 0; i < amount + 1; i++) {
        dp[i] = amount + 1;
    }
    dp[0] = 0;
    for (int i = 0; i < amount + 1; i++) {
        for (int j = 0; j < len; j++) {
            if (i - coins[j] < 0) {
                continue;
            }
            dp[i] = fmin(dp[i], dp[i - coins[j]] + 1);
        }
    }
    return (dp[amount] == amount + 1 ? -1 : dp[amount]);
}

int main() {
    int coins[] = {5, 7, 30};
    int a = coinChange(coins, sizeof(coins) / sizeof(int), 125);
    int b = rCoinChange(coins, sizeof(coins) / sizeof(int), 125);

    printf("%d\n", a);
    printf("%d\n", b);
    return 0;
}
