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
#define pb push_back
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


const int maxn=800007;

struct ITNode{
    int T, p, val[12];
}IT[maxn*4];

int num[maxn][4], len[maxn];
int arr[maxn],n,m;

void init(int i, int l, int r, int x){
    if(l==r){
        IT[i].T = 0;
        IT[i].val[x] = arr[l];
        return;
    }
    int mid = (l+r)/2;
    init(i*2,l,mid,x); init(i*2+1,mid+1,r,x);
    IT[i].val[x] = max(IT[i*2].val[x], IT[i*2+1].val[x]);
}

int tmp[12];

void lazyupdate(int i, int l, int r){
    if(IT[i].T==0) return;
    if(l<r){
        IT[i*2].T += IT[i].T;
        IT[i*2+1].T += IT[i].T;
    }
    int x = IT[i].T%12;
    for(int j=0; j<12; ++j) tmp[j]=IT[i].val[(j+x)%12];
    for(int j=0; j<12; ++j) IT[i].val[j] = tmp[j];
    IT[i].T = 0;
}

void rotate(int i, int l, int r, int s, int f, int x){
    lazyupdate(i,l,r);
    if(r<s || l>f) return;
    if(s<=l && r<=f){
        IT[i].T = x;
        lazyupdate(i,l,r);
        return;
    }
    int mid=(l+r)/2;
    rotate(i*2,l,mid,s,f,x); rotate(i*2+1,mid+1,r,s,f,x);
    for(int j=0; j<12; ++j) IT[i].val[j] = max(IT[i*2].val[j], IT[i*2+1].val[j]);

}

int resIT;
void get(int i, int l, int r, int s, int f){
    lazyupdate(i,l,r);
    if(r<s || l>f) return;
    if(s<=l && r<=f){
        resIT = max(resIT, IT[i].val[0]);
        return;
    }
    int mid=(l+r)/2;
    get(i*2,l,mid,s,f); get(i*2+1,mid+1,r,s,f);
    for(int j=0; j<12; ++j) IT[i].val[j] = max(IT[i*2].val[j], IT[i*2+1].val[j]);

}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    read(n);
    for(int i=1; i<=n; ++i){
        read(arr[i]);
        len[i]=0;
        reset(num[i],0);
        if(arr[i]==0){
            len[i]=1;
            continue;
        }
        while(arr[i]){
            num[i][len[i]++]=arr[i]%10;
            arr[i]/=10;
        }
    }

    for(int x=0; x<12; ++x){
        for(int i=1; i<=n; ++i){
            arr[i]=0;
            for(int j=len[i]-1; j>=0; --j) arr[i] = arr[i]*10 + num[i][(j-x%len[i]+len[i])%len[i]];
        }
        init(1,1,n,x);
    }

    read(m);
    int k,l,r,f;
    for(int i=0; i<m; ++i){
        read(k); read(l); read(r);
        ++l; ++r;
        if(k==0){
            read(f);
            rotate(1,1,n,l,r,f);
        }else{
            resIT = 0;
            get(1,1,n,l,r);
            printf("%d\n",resIT);
        }
    }

    return 0;
}
