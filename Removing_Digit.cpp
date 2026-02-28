            // TABULATION METHOD  AND RECURSIVE

#include<bits/stdc++.h>
using namespace std;
vector<int> r(int n)
{
    vector<int>result;
    while(n>0)
    {
        if(n%10!=0)result.push_back(n%10);
        n/=10;
    }
    return result;
}
vector<int>dp;
int f1(int n)
{
    if(n==0)return 0;
    if(n<=9)return 1;
    // if(dp[n]!=-1)return dp[n];
    vector<int>v = r(n);
    int result = INT_MAX;
    for(int i=0;i<v.size();i++)
    {
        result = min(result,f1(n-v[i]));
    }
    return 1 + result;
}
int fbu(int num)
{
    dp[0] = 1;
    for(int i=1;i<=9;i++)dp[i] = 1;
    for(int n=10;n<=num;n++)
    {
        vector<int>v = r(n);
        int result = INT_MAX;
        for(int i=0;i<v.size();i++)
        {
            result = min(result,dp[n-v[i]]);
        }
        dp[n] = 1+result;
    }
    return dp[num];
}
int main()
{
    int n;
    cin>>n;
    dp.resize(1000009,-1);
    cout<<fbu(n);
    return 0;
}