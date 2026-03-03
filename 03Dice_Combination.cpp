#include<bits/stdc++.h>
using namespace std;
vector<long long>dp(1000006,-1);
const int M = 1e9+7;
long long Method_Count(long long sum)
{
    dp[0] = 1;
    for(int n = 1;n<=sum;n++)
    {
        long long result = 0;
        for(int i=1;i<=6;i++)
        {
            if(n-i<0)break;
            result = (result + dp[n-i])%M;
        }
        dp[n] = result;
    }
    return dp[sum];
}
int main()
{
    long long sum;
    cin>>sum;
    cout<<Method_Count(sum);
    return 0;
}