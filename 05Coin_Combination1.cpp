#include<bits/stdc++.h>
using namespace std;
vector<long long>dp(1000006,-1);
vector<int>Coin;
const int M = 1e9+7;
long long Method_Count(int sum)
{
    if(sum==0)return 1;
    if(dp[sum]!=-1)return dp[sum];
    long long result = 0;
    for(int i=0;i<Coin.size();i++)
    {
        if(sum-Coin[i]<0)continue;
        result = (result + Method_Count(sum-Coin[i]))%M;
    }
    return dp[sum] = result;
}
int main()
{
    int n;
    cin>>n;
    Coin.resize(n);
    int sum;
    cin>>sum;
    for(int i=0;i<n;i++)cin>>Coin[i];
    cout<<Method_Count(sum);
    return 0;
}