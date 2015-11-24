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

const int maxn=250007;
const int hashbase=73471;

char s1[maxn],s2[maxn];
int m,n;
ll val1[maxn],val2[maxn],hashpw[maxn];

ll gethash(ll *arr, int l, int r){
    return arr[r]-arr[l-1]*hashpw[r-l+1];   
}

ll arr[maxn];
int cnt;
bool found(ll v){
    int l=1, r=cnt, mid;
    while(l<=r){
        mid=(l+r)/2;
        if(arr[mid]==v) return 1;
        if(v<arr[mid]) r=mid-1; else l=mid+1;        
    }    
    return 0;
}

int check(int len){
    cnt=0;
    FOR(i,1,m-len+1) arr[++cnt]=gethash(val1,i,i+len-1);
    sort(arr+1,arr+cnt+1);
    
    FOR(i,1,n-len+1) 
        if(found(gethash(val2,i,i+len-1))) {
            return i;
        }
    return 0;
}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);   
    
    scanf("%s%s",s1+1,s2+1);
    m=strlen(s1+1);
    n=strlen(s2+1);
    hashpw[0]=1;
    val1[0]=val2[0]=0;
    FOR(i,1,max(m,n)) hashpw[i]=hashpw[i-1]*hashbase;
    FOR(i,1,m) val1[i]=val1[i-1]*hashbase + s1[i];  
    FOR(i,1,n) val2[i]=val2[i-1]*hashbase + s2[i];
    
    int l=1, r=min(m,n), mid, res=0;
    while(l<=r){
        mid=(l+r)/2;
        if(check(mid)){
            res=mid;
            l=mid+1;   
        }else r=mid-1;
    } 
    if(res==0) puts("0");
    else{
        int p=check(res);
        s2[p+res]='\0';
        printf("%s\n%d",s2+p,res);
    }
    return 0;
}
