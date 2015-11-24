#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define FOR(a,b,c) for (int a=b,_c=c;a<=_c;a++)
#define FORD(a,b,c) for (int a=b;a>=c;a--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; ++i)
#define REPD(i,a) for(int i=(a)-1; i>=0; --i)
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;


const int maxn=5007;

int c[maxn],SA[maxn],RA[maxn],tSA[maxn],tRA[maxn],m[107],len;
int k;
char S[maxn];

int fRA(int v){return(v<=len?RA[v]:0);}

void sort(int k){
    int t,sum,i,maxi=max(300,len);
    FOR(i,0,maxi) c[i]=0;
    FOR(i,1,len) {c[fRA(SA[i]+k)]++;}
    for(i=sum=0; i<=maxi; i++){
        t=c[i];
        c[i]=sum;
        sum+=t;
    }
    FOR(i,1,len) tSA[++c[fRA(SA[i]+k)]]=SA[i];
    FOR(i,1,len) SA[i]=tSA[i];
}

void constructSA(){
    int r;
    FOR(i,1,len) RA[i]=S[i], SA[i]=i;
    for(int k=1; k<len; k<<=1){
        sort(k); sort(0);
        r=tRA[SA[1]]=1;
        FOR(i,2,len)
            tRA[SA[i]]=(RA[SA[i]]==RA[SA[i-1]] && fRA(SA[i]+k)==fRA(SA[i-1]+k))?r:++r;
        FOR(i,1,len) RA[i]=tRA[i];
    }
}

bool ok[maxn][maxn];

void constructOK(){
    for(int i=1,x,y; i<=len; ++i){
        x=y=i;
        while(1<=x && y<=len && S[x]==S[y]){
            ok[x][y]=1;
            x-=2;
            y+=2;
        }
        x=i; y=i+1;
        while(1<=x && y<=len && S[x]==S[y]){
            ok[x][y]=1;
            x-=2;
            y+=2;
        }
        x=i; y=i+2;
        while(1<=x && y<=len && S[x]==S[y]){
            ok[x][y]=1;
            x-=2;
            y+=2;
        }
        x=i; y=i+3;
        while(1<=x && y<=len && S[x]==S[y]){
            ok[x][y]=1;
            x-=2;
            y+=2;
        }
    }
}

char getS(int i){
    if(i<=len) return S[i];
    return '@';
}

void dfs(int l, int r, int base){
    if(k<=0) return;
    if(l>r) return;
    int i=l;
    while(i<=r){
        int j=i;
        while(j+1<=r && getS(SA[i]+base) == getS(SA[j+1]+base)) ++j;
        if(getS(SA[i]+base)!='@'){
            for(int x=i; x<=j; ++x) if(ok[SA[x]][SA[x]+base]){
                --k;
                if(k==0){
                    for(int it=SA[x]; it<=SA[x]+base; ++it) putchar(S[it]);
                    puts("");
                    return;
                }
            }
            dfs(i,j,base+1);
        }
        i=j+1;
    }
}

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%s",S+1); len=strlen(S+1);
    scanf("%d",&k);
    constructSA();
    constructOK();
//    for(int i=1; i<=len; ++i) printf("%d %s\n",SA[i],S+SA[i]);
    dfs(1,len,0);
}

