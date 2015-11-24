#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

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

const int maxn=400007;

int n,a[maxn],s[maxn],f[maxn];
int node[maxn*30],go[2][maxn*30],cnt,root;

int newNode(){
    ++cnt;
    go[0][cnt]=go[1][cnt]=0;
    return cnt;
}

void add(int p, int v){
    for(int i=29; i>=0; --i){
        int b=v>>i&1;
        if(go[b][p]==0) go[b][p]=newNode();
        p=go[b][p];
    }
}

int get(int p, int v){
    int res=0;
    for(int i=29; i>=0; --i){
        int b=v>>i&1;
        if(go[b^1][p]){
            p=go[b^1][p];
            res|=1<<i;
        }else p=go[b][p];
    }
    return res;
}



int main(){
//    freopen("input.txt","r",stdin);

    read(n);
    for(int i=1; i<=n; ++i) read(a[i]);
    s[0]=0;
    cnt=0;
    root=newNode();
    add(root,0);
    for(int i=1; i<=n; ++i){
        s[i]=s[i-1]^a[i];
        f[i]=max(f[i-1],get(root,s[i]));
        add(root,s[i]);
    }

    int res=0;
    cnt=0;
    root=newNode();
    s[n+1]=0;
    add(root,0);
    for(int i=n; i>=2; --i){
        s[i]=s[i+1]^a[i];
        res=max(res,f[i-1] + get(root,s[i]));
        add(root,s[i]);
    }


    printf("%d\n",res);
}

