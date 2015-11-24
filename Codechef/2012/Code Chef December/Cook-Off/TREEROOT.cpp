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

const int maxn=31;

int id[maxn],sid[maxn];
int n,test;

bool check(int p){
    int s1,s2;
    s1=s2=0;
    FOR(i,1,n){
        if(i!=p) s1+=id[i];
        s2+=sid[i];
    }
    return (s1==s2);
}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d",&test);
    REP(i,test){
        scanf("%d",&n);
        FOR(i,1,n) scanf("%d%d",&id[i],&sid[i]);
        vector<int> list;
        FOR(i,1,n) if(check(i)) list.pb(id[i]);
        sort(list.begin(),list.end());
        REP(i,sz(list)-1) printf("%d ",list[i]);
        if(!list.empty()) printf("%d\n",list.back());
    }   
    return 0;
}
