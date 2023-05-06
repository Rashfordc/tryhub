#include <bits/stdc++.h>
using namespace std; 
typedef long long ll;
const int N = 100100;
int dp[N][13];
ll a[N];

int check1(ll number)
{
	while(number>=10)number/=10;
	return number;
}
int main()
{
	int n;ll ans = 1e9+100;
	cin >> n;
    for(int i = 1;i<=n;i++)
    {
    	cin >> a[i];
	}
	for(int i = 1;i<=n;i++)
	{
	   int first = check1(a[i]);
	   int last = a[i]%10;
	   for(int j = 1;j<10;j++)
	   {
	   	 dp[i][j] = dp[i-1][j]+1;
	     if(dp[i][last]>dp[i-1][first])dp[i][last]=dp[i-1][first];
	     if(dp[i][last]>i-1)dp[i][last] = i-1;
	   }
    }
    for(int i = 2;i<10;i++)
    {
    	if(ans>dp[n][i])ans = dp[n][i];
	}
	cout << ans << endl;
	return 0;
}
