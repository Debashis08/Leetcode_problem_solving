class Solution {
private:
    string x,y;
public:
    int longestCommonSubsequence(string text1, string text2) {
        x=text1;
        y=text2;
        int m=x.length();
        int n=y.length();
        int dp[m+1][n+1];
        
        for(int i=0;i<m+1;i++)
        {
            dp[i][0]=0;
        }
        for(int i=0;i<n+1;i++)
        {
            dp[0][i]=0;
        }
        for(int i=1;i<m+1;i++)
        {
            for(int j=1;j<n+1;j++)
            {
                if(x[i-1]==y[j-1])
                {
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else if(dp[i-1][j]>=dp[i][j-1])
                {
                    dp[i][j]=dp[i-1][j];
                }
                else
                {
                    dp[i][j]=dp[i][j-1];
                }
            }
        }
        return dp[m][n];
    }
};