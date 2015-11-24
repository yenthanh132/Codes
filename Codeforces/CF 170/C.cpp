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

const int maxn=100007;

struct hor{int x,y1,y2;} a[maxn];
struct ver{int y,x1,x2;} b[maxn];
int m,n,k,c1,c2,d1,d2;

vector<pii> list_hor[maxn];
int x_hor[maxn], y_ver[maxn], sum_hor[maxn], sum_ver[maxn];
vector<pii> list_ver[maxn];

bool cmp1(const hor &a, const hor &b){
    return a.x<b.x || (a.x==b.x && a.y1<b.y1);
}

bool cmp2(const ver &a, const ver &b){
    return a.y<b.y || (a.y==b.y && a.x1<b.x1);
}

int find_x(){
    int x=1;
    FOR(i,1,d1) if(x_hor[i]==x) x++; else if(x_hor[i]>x) return x;
    return x;
}

int find_y(){
    int y=1;
    FOR(i,1,d2) if(y_ver[i]==y) y++; else if(y_ver[i]>y) return y;
    return y;
}

int find_x2(int bit){
    FOR(i,1,d1) if(sum_hor[i]>=bit) return x_hor[i];
    return -1;
}

int find_y2(int bit){
    FOR(i,1,d2) if(sum_ver[i]>=bit) return y_ver[i];
    return -1;
}
    

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d%d%d",&m,&n,&k);
    c1=c2=0;
    int x1,y1,x2,y2;
    FOR(i,1,k){
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        if(x1==x2){
            a[++c1].x=x1;
            a[c1].y1=min(y1,y2);
            a[c1].y2=max(y1,y2);
        }else{
            b[++c2].y=y1;
            b[c2].x1=min(x1,x2);
            b[c2].x2=max(x1,x2);
        }
    }
    sort(a+1,a+c1+1,cmp1);
    sort(b+1,b+c2+1,cmp2);
    d1=d2=0;
    int i,j,maxval;
    
    //horizontal
    i=1;
    while(i<=c1){
        j=i;
        while(j<c1 && a[j+1].x==a[i].x) j++;
        d1++;
        x_hor[d1]=a[i].x;
        sum_hor[d1]=0;
        
        maxval=0;
        FOR(it,i,j){
            if(maxval < a[it].y1){
                list_hor[d1].pb(pii(maxval,a[it].y1));
                sum_hor[d1]+=a[it].y1-maxval;
            }
            maxval=max(maxval,a[it].y2);
        }
        if(maxval<n){
            list_hor[d1].pb(pii(maxval,n));
            sum_hor[d1]+=n-maxval;
        }
        
        i=j+1;
    }
    //vertical
    i=1;
    while(i<=c2){
        j=i;
        while(j<c2 && b[j+1].y==b[i].y) j++;
        d2++;
        sum_ver[d2]=0;
        y_ver[d2]=b[i].y;
        
        maxval=0;
        FOR(it,i,j){
            if(maxval < b[it].x1){
                list_ver[d2].pb(pii(maxval,b[it].x1));
                sum_ver[d2]+=b[it].x1-maxval;
            }
            maxval=max(maxval,b[it].x2);
        }
        if(maxval<m){
            list_ver[d2].pb(pii(maxval,m));
            sum_ver[d2]+=m-maxval;
        }
        i=j+1;
    }

    int bit=0;
    if(m-1>d1 && (m-1-d1)%2==1) bit^=n;
    if(n-1>d2 && (n-1-d2)%2==1) bit^=m;
    FOR(i,1,d1) bit^=sum_hor[i];
    FOR(i,1,d2) bit^=sum_ver[i];
    
                
    
    if(bit){
        puts("FIRST");
            int bit2,tmp,xi,yi;
            if(m-1>d1 && (n^bit)<=n){
                bit2=n-(bit^n);
                int x=find_x();
                printf("%d %d %d %d\n",x,0,x,bit2);
            }else if(n-1>d2 && (m^bit)<=m){
                bit2=m-(bit^m);
                int y=find_y();
                printf("%d %d %d %d\n",0,y,bit2,y);
            }else{
                FOR(it,1,d1) if((bit^sum_hor[it])<=sum_hor[it]){
                    bit2=sum_hor[it]-(bit^sum_hor[it]);
                    xi=it;
                    i=0; 
                    tmp=list_hor[xi][i].se-list_hor[xi][i].fi;
                    while(tmp<bit2){
                        i++;
                        tmp+=list_hor[xi][i].se-list_hor[xi][i].fi;
                    }
                    printf("%d %d %d %d\n",x_hor[xi],0,x_hor[xi],list_hor[xi][i].se-(tmp-bit2));
                    return 0;
                }
                FOR(it,1,d2) if((bit^sum_ver[it])<=sum_ver[it]){
                    bit2=sum_ver[it]-(bit^sum_ver[it]);
                    yi=it;
                    i=0;
                    tmp=list_ver[yi][i].se-list_ver[yi][i].fi;
                    while(tmp<bit2){
                        i++;
                        tmp+=list_ver[yi][i].se-list_ver[yi][i].fi;
                    }
                    printf("%d %d %d %d\n",0,y_ver[yi],list_ver[yi][i].se-(tmp-bit2),y_ver[yi]);
                }
            }
        
    }else puts("SECOND");
    return 0;
}                
