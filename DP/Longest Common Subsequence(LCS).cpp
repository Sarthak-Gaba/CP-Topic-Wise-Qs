//https://practice.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1

vector<vector<int>> dp;

int util(int i, int j, int x, int y, string s1, string s2)
{
    if(i>=x || j>=y)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    if(s1[i]==s2[j])
        return dp[i][j] = 1 + util(i+1,j+1,x,y,s1,s2);
    int op1 = util(i+1,j,x,y,s1,s2);
    int op2 = util(i,j+1,x,y,s1,s2);
    return dp[i][j] = max(op1,op2);
}

int lcs(int x, int y, string s1, string s2){
    dp = vector<vector<int>>(x+1,vector<int>(y+1,-1));
    return util(0,0,x,y,s1,s2);
}