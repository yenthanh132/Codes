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

//fast input
template<typename T>
void read(T& x){
    register int c;
    static bool isNega;
    isNega=false;
    while(!((x=getchar())>='-' && x<='9'));
    if(x=='-') isNega=true, x=0; else x-='0';
    while(((c=getchar())>='-' && c<='9')) x=10*x+(c-'0');
    if(isNega) x=-x;
}


const ll maxv=150094635296999121ll+1;
const int maxn=56000;

ll list[maxn];
unsigned int dp[20][maxn],t[20][maxn],ans0[20][maxn],ans1[20][maxn],res0[40];
int movediv[maxn][10],movemul[maxn][10];
int n;

int find(ll v){
    int l=1,r=n,mid;
    while(l<=r){
        mid=(l+r)>>1;
        if(list[mid]==v) return mid;
        else if(list[mid]>v) r=mid-1;
        else l=mid+1;
    }
    return 0;
}

unsigned int tohop[20][20];

unsigned int mpow(unsigned int v0, unsigned int n){
    if(n==0) return 1;
    unsigned int t=mpow(v0,n/2);
    t=(t*t);
    if(n&1) return (t*v0); else return t;
}

unsigned int get0(int l){
    unsigned int v=9,t=0;
    int cdiv,cmul;
    cdiv=l/2;
    cmul=l-cdiv-1;
    v=v*mpow(9,cdiv);
    FOR(x,1,cmul)
        t=t + (tohop[cmul][x] * mpow(9,cmul-x));
    return v*t;
}

void init(){
    //tohop
    tohop[0][0]=1;
    FOR(i,1,18){
        tohop[i][0]=1;
        FOR(j,1,i) tohop[i][j]=tohop[i-1][j]+tohop[i-1][j-1];
    }
    //------------------------
    ll v2,v3,v5,v7;
    n=0;
    v2=1;
    while(v2<maxv){
        v3=1;
        while(v3*v2<maxv){
            v5=1;
            while(v5*v3*v2<maxv){
                v7=1;
                while(v7*v5*v3*v2<maxv){
                    list[++n]=v2*v3*v5*v7;
                    v7*=7;
                }
                v5*=5;
            }
            v3*=3;
        }
        v2*=2;
    }
    sort(list+1,list+n+1);
    dp[0][1]=1;
    FOR(j,1,n) FOR(k,1,9) if(list[j]%k==0) movediv[j][k]=find(list[j]/k);
    FOR(j,1,n) FOR(k,1,9) if(list[j]*k<maxv) movemul[j][k]=find(list[j]*k);
    FOR(i,1,18)
        FOR(j,1,n){
            FOR(k,1,9) if(movediv[j][k])
                dp[i][j]=(dp[i][j]+dp[i-1][movediv[j][k]]);
        }
    FOR(z,1,18){
        FOR(j,1,n){
            t[1][j]=0;
            FOR(k,1,9) if(movemul[j][k])
                t[1][j]=(t[1][j]+dp[z][movemul[j][k]]);
        }
        FOR(i,2,z)
            FOR(j,1,n){
                t[i][j]=0;
                FOR(k,1,9) if(movemul[j][k])
                    t[i][j]=(t[i][j]+t[i-1][movemul[j][k]]);
            }
        FOR(j,1,n) ans0[z][j]=t[z][j];
    }
    FOR(z,1,17){
        FOR(j,1,n){
            t[1][j]=0;
            FOR(k,1,9) if(movemul[j][k])
                t[1][j]=(t[1][j]+dp[z+1][movemul[j][k]]);
        }
        FOR(i,2,z)
            FOR(j,1,n){
                t[i][j]=0;
                FOR(k,1,9) if(movemul[j][k])
                    t[i][j]=(t[i][j]+t[i-1][movemul[j][k]]);
            }
        FOR(j,1,n) ans1[z][j]=t[z][j];
    }
    
    FOR(i,1,36) res0[i]=get0(i);
}


int main(){
    
    init();
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int test,l,pos;
    ll v;
    read(test);
    REP(index,test){
        read(l); read(v);
        
        if(v==0) printf("%u\n",res0[l]);
        else{
            pos=find(v);
            if(!pos){
                puts("0");
                continue;
            }
            if(l&1)
                if(l>1) printf("%u\n",ans1[l/2][pos]);
                else printf("%u\n",dp[1][pos]);
            else printf("%u\n",ans0[l/2][pos]);
        }
    }                
    
    return 0;
}
