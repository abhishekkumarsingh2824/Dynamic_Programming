#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>dp(1000,vector<int>(1000,0));
//Top_Down_Method
// int Counting(vector<int>arr,int i,int j)
// {
//     if(i==j || j==i+1)return 0;
//     if(dp[i][j]!=-1)return dp[i][j];
//     int ans = INT_MAX;
//     for(int k = i+1;k<j;k++)
//     {
//         ans = min(ans,Counting(arr,i,k)+Counting(arr,k,j)+arr[i]*arr[j]*arr[k]);
//     }
//     return dp[i][j] = ans;
// }
//Bottom_Up_Method
int B_U_Counting(vector<int>arr)
{
     int n = arr.size();
     for(int len = 3;len<=n;len++)
     {
        for(int i = 0;i+len-1<n;i++)
        {
            int j = i+len-1;
            dp[i][j] = INT_MAX;
            for(int k=i+1;k<j;k++)
            {
                dp[i][j] = min(dp[i][j],dp[i][k]+dp[k][j]+arr[i]*arr[j]*arr[k]);
            }
        }
     }
     return dp[0][n-1];
}
int main()
{
     int n ; 
     cin>>n;
     vector<int>arr(n);
     for(int i=0;i<n;i++)cin>>arr[i];
     cout<<B_U_Counting(arr);
}