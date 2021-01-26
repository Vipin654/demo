#include<iostream>
using namespace std;
#include<map>
#include<set>
#include<vector>
#include<cmath>
#include<algorithm>
#define mod 1000000007
int fact[2001];
void function()
{
	fact[0]=1;
	int j;
	for(j=1;j<=2000;j++)
	{
		fact[j]=(j*fact[j-1])%mod;
	}
}
int power(int a,int b)
{
	if(b==0)
	  return 1;
	else
	{
		int r=power(a,b/2);
		if(b%2==0)
		  return (r*r)%mod;
		else
		{
			int x=(r*r)%mod;
			return (a*x)%mod;
		}
	}
}
int ncr(int n,int r)
{
	int answer=fact[n];
	answer*=power(fact[r],mod-2);
	answer%=mod;
	answer*=power(fact[n-r],mod-2);
	answer%=mod;
	return answer;
}
int32_t main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		cin>>n;
		vector<int> arr;
		int j;
		for(j=0;j<n;j++)
		{
			int x;
			scanf("%d",&x);
			arr.push_back(x);
		}
		sort(arr.begin(),arr.end());
		reverse(arr.begin(),arr.end());
		int dp[200001]={0};
		int answer=0;
		for(j=n-1;j>=0;j--)
		{
			int x=arr[j];
			int here=1;
			for(int i=1;i*i<=x;i++)
			{
				if(x%i==0)
				{
					int p=i,q=x/i;
					here=max(here,1+dp[p]);
					here=max(here,1+dp[q]);
				}
			}
			dp[x]=here;
			answer=max(answer,here);
		}
		int val=n-answer;
		printf("%d\n",val);
	}
}
