#include<bits/stdc++.h>
using namespace std;
vector<int>dp(1000006,-1);
vector<int>Coins;
int Method_Count(int sum)
{
    if(sum==0)return 0;
    if(dp[sum]!=-1)return dp[sum];
    int result = INT_MAX;
    for(int i=0;i<Coins.size();i++)
    {
        if(sum-Coins[i]<0)continue;
        result = min(result,Method_Count(sum-Coins[i]));
    }
    if(result==INT_MAX)return dp[sum]=INT_MAX;
    return dp[sum]=1+result;
}
int main()
{
    int n;
    cin>>n;
    Coins.resize(n);
    int sum;
    cin>>sum;
    for(int i=0;i<n;i++)cin>>Coins[i];
    int ans = Method_Count(sum);
    if(ans==INT_MAX)cout<<"-1"<<endl;
    else cout<<ans<<endl;
    return 0;
}
