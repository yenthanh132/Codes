#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

int a[4111111];
int b[4111111];
int n,d;

int main(){
//    freopen("input.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&d);
        int last = 0;
        for(int i=0; i<n-1; ++i) a[last++]=0;
        int t=0;
        for(int i=0; i<n; ++i){
            t += d*d;
            a[last++] = t%10;
            t/=10;
        }
        while(t){
            a[last++] = t;
            t/=10;
        }

        int sum=0;
        for(int i=last-1; i>=0; --i){
            sum += a[i];
            if(i+n<last) sum-=a[i+n];
            b[i] = sum;
        }
        for(int i=0; i<last; ++i){
            int t=b[i]/10;
            b[i]%=10;
            if(t>0){
                if(i+1>=last) b[last++]=t;
                else b[i+1]+=t;
            }
        }

        ll p=1;
        ll res=0;
        for(int i=last-1; i>=0; --i){
            res = (res + b[i]*p)%oo;
            p = p * 23 %oo;
        }

        printf("%lld\n",res);
    }
}

