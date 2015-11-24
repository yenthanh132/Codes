#include <iostream>
#include <stdio.h>
#include <utility>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <math.h>
#include <cstdio>
#include <assert.h>
 
#define FOR(i,x,y) for(int i=(x);i<(y);i++)
#define RFOR(i,x,y) for(int i=(x);i>=(y);i--)
#define ABS(x) ((x)>0?(x):-(x))
#define SQ(x) ((x)*(x))
#define mset(x,y) memset(x,y,sizeof(x))
#define INF 1000000000
#define MOD 1000000007
#define pb(X) push_back(X) 
 
using namespace std;
 
typedef long long int lli;
typedef long double ld;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<double> vd;


lli arr[20];
lli val[20];
lli pow9[20];
lli pow1[20];

lli getcnt(int s, int sec)
{
	if(s==0)
	{
		if(arr[s]>=sec) return 1;
		return 0;
	}
	if(arr[s]==0)
	{
		if(sec==0) return val[s-1]+1;
		return getcnt(s-1,sec);
	}

	lli ans;
	if(arr[s]==sec)ans=val[s-1]+1;
	else ans=getcnt(s-1,sec);

	lli temp;
	temp=pow1[s]-pow9[s];
	temp*=(arr[s]-1<sec?arr[s]:arr[s]-1);
	ans+=temp;
	if(arr[s]-1>=sec) ans+=pow1[s];
	return ans;
}

bool chk(int k, int dig)
{
	while(k)
	{
		if(k%10==dig) return 1;
		k/=10;
	}
	return 0;
}

void init()
{
	pow9[0]=pow1[0]=1;
	for(int i=1;i<20;i++) pow9[i]=pow9[i-1]*9LL,pow1[i]=pow1[i-1]*10LL;
}

int main()
{
	#ifndef ONLINE_JUDGE
    //freopen("inp.txt","r",stdin);
    #endif

    init();
    int t;
    scanf("%d",&t);
    lli n,k;
    while(t--)
    {
    	scanf("%lld",&n);
    	k=n;
    	int s=0;
    	while(n)
    	{
    		arr[s++]=n%10;
    		n/=10;
    	}

    	val[0]=arr[0];
    	for(int i=1;i<s;i++) val[i]=pow1[i]*arr[i]+val[i-1];

    	lli ans=0;

    	// for(int j=0;j<10;j++)
    	// {
    	// 	ans=0;
    	// 	for(int i=1;i<=k;i++) if(chk(i,j)) ans++;
    	// 	cout<<ans<<endl;
    	// }

    	//cout<<getcnt(s-1,8)<<endl;

    	if(s>1)
    	{
    		ans+=getcnt(s-2,0);
    		ans+=(arr[s-1]-1)*(pow1[s-1]-pow9[s-1]);
    		for(int i=2;i<s;i++) ans+=9*(pow1[i-1]-pow9[i-1]);
    	}
    	//cout<<ans<<endl;
    	for(int i=1;i<10;i++)
    	{
    		//ans=0;
    		ans+=getcnt(s-1,i);
    		//cout<<ans<<endl;
    	}
    	lli g=__gcd(ans,k*10);
    	printf("%lld/%lld\n",ans/g,(k*10)/g);
    }

    return 0;
}
