//https://practice.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1

#define ll int

int lcs(int x, int y, string s1, string s2){
    vector<vector<int>> dp;
    dp = vector<vector<int>>(x+1,vector<int>(y+1,-1));
    for(ll i=0; i<=x; i++)
        dp[i][y]=0;
    for(ll i=0; i<=y; i++)
        dp[x][i]=0;
    for(ll i=x-1; i>=0; i--)
    {
        for(ll j=y-1; j>=0; j--)
        {
            if(s1[i]==s2[j])
            {
                dp[i][j] = 1 + dp[i+1][j+1];
                continue;
            }
            ll right,down;
            down = dp[i+1][j];
            right = dp[i][j+1];
            dp[i][j] = max(down,right);
        }
    }
    return dp[0][0];
}