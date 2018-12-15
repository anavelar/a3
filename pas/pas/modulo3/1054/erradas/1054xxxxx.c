#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

// https://pt.cppreference.com/w/cpp/algorithm

int main() {
    int testcase, n, D, cases = 0;
    char s[50];
    int i, j, k;

    scanf("%d", &testcase);

    while(testcase--) {
        scanf("%d %d", &n, &D);
        int A[305], m = 0, x;
        for(i = 0; i < n; i++) {
            scanf("%s", s);
            sscanf(s+2, "%d", &x);
            A[m++] = x;
            if(s[0] == 'B')
                A[m++] = x;
        }
        A[m++] = 0;
        A[m++] = D, A[m++] = D;
        sort(A, A+m);
        int dp[305][305];
#define oo 2147483647
        for(i = 0; i < m; i++)
            for(j = 0; j < m; j++)
                dp[i][j] = oo;
        dp[0][0] = 0;
        for(i = 0; i < m; i++) {
            for(j = 0; j < m; j++) {
                k = max(i, j)+1;
                dp[i][k] = min(dp[i][k], max(dp[i][j], A[k]-A[j]));
                dp[k][j] = min(dp[k][j], max(dp[i][j], A[k]-A[i]));
            }
        }
        printf("Case %d: %d\n", ++cases, dp[m-1][m-2]);
    }
    return 0;
}
