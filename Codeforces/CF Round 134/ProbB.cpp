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

int f[35],n,r;
vector<int> ds;

int check(int n, int l, int r){
    if(l>r) swap(l,r);
    if(l<=0 || n<0) return -1;
    if(r==l && r==1) return 0;
    int res=0;
    if(l==1){
        if(r-l+1!=n) return -1;
        else return(r-l-1);
    }else{
        int v=(r/l);
        int cost=v-1;
        res=check(n-v,l,r-v*l);
        if(res==-1) return -1; else return(res+cost);
    }
}

void build(int n, int l, int r){
    if(l>r) swap(l,r);
    if(l==1) ds.pb(r-l);
    else{
        int v=(r/l);
        ds.pb(v);
        build(n-v,l,r-v*l);
    }
}

void printstr(){
    putchar('T');
    char ch='T';
    REPD(i,sz(ds)){
        if(ch=='T'){
            REP(j,ds[i]) putchar('B');
            ch='B';
        }else{
            REP(j,ds[i]) putchar('T');
            ch='T';
        }
    }
    if(ch=='T') putchar('B'); else putchar('T');
}

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    f[0]=0; f[1]=1;
    FOR(i,2,31) f[i]=f[i-1]+f[i-2];
    cin>>n>>r;
    if(r<n) printf("IMPOSSIBLE");
    else{
        if(r==n){
            printf("%d\n",max(n-3,0));
            printf("T");
            REP(i,n-2) printf("B");
            if(n>=2) if(n==2) printf("B"); else printf("T");
        }else{
            int v,u,minv=oo;
            FOR(i,1,(r-1)/2){
                v=check(n-1,i,r-i);
                if(v!=-1 && v<minv){
                    minv=v;
                    u=i;
                }
            }
            if(minv==oo) printf("IMPOSSIBLE");
            else{
                printf("%d\n",minv);
                ds.clear();
                build(n-1,u,r-u);
                printstr();
            }
        }
    }
    //getch();
    return 0;
}
                
        
