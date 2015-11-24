#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=100007;

int x[maxn],y[maxn],n,T,id[maxn];

bool cmp(const int &a, const int &b){
    return y[a]<y[b];
}

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d",&T);
    while(T--){
        int minx=oo, maxx=-oo;
        int miny=oo, maxy=-oo;

        scanf("%d",&n);
        for(int i=1; i<=n; ++i){
            scanf("%d%d",&x[i],&y[i]);
            minx=min(minx,x[i]);
            maxx=max(maxx,x[i]);

            miny=min(miny,y[i]);
            maxy=max(maxy,y[i]);

            id[i]=i;
        }

        sort(id+1,id+n+1,cmp);

        bool found=0;
        for(int i=1; i<=n; ++i){
            if(x[i]==minx && y[i]==miny){
                puts("1");
                printf("%d NE\n",i);
                found=1;
                break;
            }else if(x[i]==minx && y[i]==maxy){
                puts("1");
                printf("%d SE\n",i);
                found=1;
                break;
            }else if(x[i]==maxx && y[i]==miny){
                puts("1");
                printf("%d NW\n",i);
                found=1;
                break;
            }else if(x[i]==maxx && y[i]==maxy){
                puts("1");
                printf("%d SW\n",i);
                found=1;
                break;
            }
        }

        if(!found){
            puts("2");
            int x1=x[id[1]], x2=x[id[2]];
            if(x1<x2){
                printf("%d NE\n",id[1]);
                printf("%d NW\n",id[2]);
            }else{
                printf("%d NW\n",id[1]);
                printf("%d NE\n",id[2]);
            }
        }
    }
}

