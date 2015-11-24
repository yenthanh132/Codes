#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

int a[666],b[666];
int f[2][333][666];

bool check(int sum, int len, bool bigger){
    if(len==0) return (bigger && sum==0);
    if(f[bigger][sum][len]!=-1) return f[bigger][sum][len];
    int &res=f[bigger][sum][len];
    res=0;
    int s=0;
    if(!bigger) s=a[len];
    for(int v=s; v<=min(sum,9); ++v)
        res|=check(sum-v,len-1,bigger | (v>a[len]));
    return res;
}

int main(){
//    freopen("input.txt","r",stdin);
    reset(f,0);
    int n,sum,lastlen,curlen;
    lastlen=1; reset(a,0);
    cin>>n;
    for(int i=1; i<=n; ++i){
        cin>>sum;
        reset(f,-1);
        for(curlen=lastlen; !check(sum,curlen,0);curlen++);
        bool bigger=0;
        for(int i=curlen; i>=1; --i){
            int s=0;
            if(!bigger) s=a[i];
            for(int v=s; v<=min(sum,9); ++v)
                if(check(sum-v,i-1,bigger | (v>a[i]))){
                    sum-=v;
                    b[i]=v;
                    bigger|=(v>a[i]);
                    break;
                }
        }
        for(int i=curlen; i>=1; --i){
            cout<<b[i];
            a[i]=b[i];
        }
        lastlen=curlen;
        cout<<endl;

    }
}

