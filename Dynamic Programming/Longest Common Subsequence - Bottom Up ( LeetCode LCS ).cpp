#define f(i,n)          for(int i=0;i<n;i++)
#define F(i,a,n)        for(int i=a;i<n;i++)
#define fo(i,a,b)       for(int i=a;i<=b;i++)

int dp[1001][1001];

class Solution {
public:
    int longestCommonSubsequence(string x, string y) {

        int m = x.length();
        int n = y.length();

        // Initialisation ( Base condition )
        fo(i, 0, m) {
            fo(j, 0, n) {
                if (i == 0 or j == 0)
                    dp[i][j] = 0;
            }
        }

        fo(i, 1, m) {
            fo(j, 1, n) {
                // if character of both strings matches
                if (x[i - 1] == y[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }

        return dp[m][n];
    }
};
