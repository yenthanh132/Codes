#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

bool swapped;
int Q;
char s[10];

int getheight(int x){
    int h=0;
    while(x){
        x/=2;
        ++h;
    }
    return h;
}

pii calc(int x, int y){
    int hx=getheight(x), hy=getheight(y);
    int r1=0, r2=0;
    if(hx>hy) swap(hx,hy), swap(x,y);
    while(hy>hx){
        r1 += hy&1;
        r2++;
        --hy;
        y/=2;
    }
    while(x!=y){
        r1+=(hx&1)*2;
        r2+=2;
        x/=2; y/=2;
        --hx; --hy;
    }
    r1+=(hx&1);
    r2++;
    return pii(r1,r2);
}

int main(){
//    freopen("input.txt","r",stdin);
    int x,y;
    scanf("%d",&Q);
    swapped = 0;
    for(int i=0; i<Q; ++i){
        scanf("%s",s);
        if(s[1]=='i') swapped ^= 1;
        else{
            scanf("%d%d",&x,&y);
            pii v=calc(x,y);
            int res = v.first;
            if(s[1]=='r' ^ swapped) res = v.second - res;
            printf("%d\n",res);
        }
    }
}

