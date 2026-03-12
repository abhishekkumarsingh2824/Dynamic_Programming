#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>dp;
vector<int>color;
int mixture(vector<int>&color,int i,int j)
{
    int res = 0;
    for(int k = i;k<=j;k++)
    {
        res = (res%100 + color[k]%100)%100;
    }
    return res;
}
int Counting(vector<int>&color,int i,int j)
{
    if(i==j)return dp[i][j]=0;
    if(dp[i][j]!=-1)return dp[i][j];
    int result = INT_MAX;
    for(int k=i;k<j;k++)
    {
        result = min(result,Counting(color,i,k)+Counting(color,k+1,j)+mixture(color,i,k)*mixture(color,k+1,j));
    }
    return dp[i][j] = result;
}
int B_U_Counting(vector<int>color)
{
    dp.assign(105, vector<int>(105, 0));
    int n = color.size();
    for(int len=2;len<=n;len++)
    {
       for(int i = 0;i<=n-len;i++)
       {
        int j = i+len-1;
        int res = INT_MAX;
        for(int k = i;k<j;k++)
        {
            res = min(res,dp[i][k]+dp[k+1][j]+mixture(color,i,k)*mixture(color,k+1,j));
        }
           dp[i][j] = res;
       }
    }
    return dp[0][n-1];
}
int main()
{
    int n;
    while(cin>>n)
    {
        // dp.assign(105, vector<int>(105, -1));
        color.resize(n);
        for(int i=0;i<n;i++)cin>>color[i];
        cout<<B_U_Counting(color)<<'\n';
        color.clear();
        dp.clear();
    }
    return 0;
}