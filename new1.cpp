#include<iostream>
using namespace std;
#include<map>
#include<set>
#include<vector>
#include<cmath>
#include<algorithm>
#define int long long int
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
	function();
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		while(n%2==0)
		  n/=2;
		if(n==1)
		  cout<<"NO"<<endl;
		else
		  cout<<"YES"<<endl;
	}
}
