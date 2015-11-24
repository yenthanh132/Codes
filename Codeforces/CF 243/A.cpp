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

const int maxn=207;

int a[maxn],n,k,l1[maxn],l2[maxn],c1,c2;

bool mycmp(const int &a, const int &b){
    return a>b;   
}

int cal(int l, int r){
    c1=0;
    FOR(i,1,l-1) l1[++c1]=a[i];
    FOR(i,r+1,n) l1[++c1]=a[i];
    c2=0;
    int res=0;
    FOR(i,l,r) l2[++c2]=a[i], res+=a[i];
    if(c1>0) sort(l1+1,l1+c1+1,mycmp);
    if(c2>0) sort(l2+1,l2+c2+1);
    int idx=1;
    FOR(i,1,min(k,min(c1,c2))){
        if(l1[i]-l2[i]>0) res+=l1[i]-l2[i];   
        else break;
    }
    return res;
}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);  
    cin>>n>>k;
    FOR(i,1,n) cin>>a[i];
    int res=-oo;
    FOR(i,1,n) FOR(j,i,n){
        res=max(res,cal(i,j)); 
    }
    cout<<res<<endl;
}
