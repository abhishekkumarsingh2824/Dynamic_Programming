//https://www.hackerearth.com/problem/algorithm/mancunian-and-k-ordered-lcs-e6a4b8c6/
#include<bits/stdc++.h>
using namespace std;
vector<vector<vector<int>>>dp;
int Method_Counting(vector<int>&nums1,vector<int>&nums2,int i,int j,int k)
{
    if(i==nums1.size()||j==nums2.size())return 0;
    if(dp[i][j][k]!=-1)return dp[i][j][k];
    int ans = 0;
    if(nums1[i]==nums2[j])
    {
         ans=1+Method_Counting(nums1,nums2,i+1,j+1,k);
    }
    else
    {
        if(k>0)ans = 1 + Method_Counting(nums1,nums2,i+1,j+1,k-1);
        ans = max(ans, Method_Counting(nums1,nums2,i+1,j,k));
        ans = max(ans, Method_Counting(nums1,nums2,i,j+1,k));
    }
    dp[i][j][k] = ans;
    return ans;
}
int main()
{
    int n1;
    cin>>n1;
    vector<int>nums1(n1);
    int n2;
    cin>>n2;
    vector<int>nums2(n2);
    int k;
    cin>>k;
    for(int i=0;i<n1;i++)cin>>nums1[i];
    for(int i=0;i<n2;i++)cin>>nums2[i];
	dp.clear();
	dp.assign(n1+1,vector<vector<int>>(n2+1,vector<int>(k+1,-1)));
    cout<<Method_Counting(nums1,nums2,0,0,k)<<"\n";
}