#include<bits/stdc++.h>
using namespace std;
vector<int>dp(1000006,-1);
vector<int>Coin;
string Method_Count(int k,int l,int mx)
{
    dp[0] = 0;
    dp[1] = 1;
    dp[k] = 1;
    dp[l] = 1;
    for(int n=2;n<=mx;n++)
    {
        if(n==k ||n==l)continue;
        bool flag = true;
        if(n-l>=0 && dp[n-l]==0)flag = false;
        if(n-k>=0 && dp[n-k]==0)flag = false;
        if(n-1>=0 && dp[n-1]==0)flag = false;
        if(flag)dp[n] = 0;
        else dp[n] = 1;
    }
    string ans = "";
    for(int i=0;i<Coin.size();i++)
    {
        if(dp[Coin[i]]==0)ans+='B';
        else ans+='A';
    }
    return ans;
}
int main()
{
    int k,l,m;
    cin>>k>>l>>m;
    Coin.resize(m);
    int mx = 0;
    for(int i=0;i<Coin.size();i++)
    {
        cin>>Coin[i];
        mx = max(mx,Coin[i]);
    }
    cout<<Method_Count(k,l,mx);
    return 0;
}