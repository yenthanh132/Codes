#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <ctime>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
#define FOR(a,b,c) for (int a=b,_c=c;a<=_c;a++)
#define FORD(a,b,c) for (int a=b;a>=c;a--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; ++i)
#define REPD(i,a) for(int i=(a)-1; i>=0; --i)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

char s[111111];
pii a[111111];


int main(){
    //freopen("input.txt","r",stdin);
    scanf("%s",s);
    int n=strlen(s);
    int i=0;
    int cnt=0;
    while(i<n){
        int j=i;
        while(j+1<n && s[j+1]=='0') ++j;
        a[cnt++]=pii(s[i]-'0',j-i+1);
        i=j+1;
    }

    int u=0,v=a[u].fi, len=a[0].se;
    for(i=1; i<cnt; ++i){
        if(a[i].se>len || (a[i].se==len && a[i].fi>v))
            u=i;
        len+=a[i].se;
    }
    cout<<cnt-u<<endl;
}

