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

const int maxn=15;
const int maxm=600000;

int n,c1,c2,m,a1[maxn],a2[maxn],res;
struct node{int val,c;} list[maxm];


int p_val,p_c;
void duyet1(int i){
    if(i>c1){
        m++;
        list[m].val=p_val;
        list[m].c=p_c;
        return;
    }
    duyet1(i+1);
    p_val-=a1[i];
    p_c+=a1[i];
    duyet1(i+1);
    p_val+=a1[i]*2;
    duyet1(i+1);
    p_val-=a1[i];
    p_c-=a1[i];
}
 
bool cmp(const node &a, const node &b){
    return (a.val<b.val || (a.val==b.val && a.c>b.c));
}       

int find(int v){
    int l=1, r=m, mid;
    while(l<=r){
        mid=(l+r)>>1;
        if(list[mid].val==v) return list[mid].c;
        else if(list[mid].val>v) r=mid-1; else l=mid+1;
    }
    return -oo;
}

void duyet2(int i){
    if(i>c2){
        res=max(res,p_c+find(p_val));
        return;
    }
    duyet2(i+1);
    p_val+=a2[i];
    p_c+=a2[i];
    duyet2(i+1);
    p_val-=a2[i]*2;
    duyet2(i+1);
    p_val+=a2[i];
    p_c-=a2[i];
}
        
//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d",&n);
    c1=n/2;
    c2=n-c1;
    FOR(i,1,c1) scanf("%d",&a1[i]);
    FOR(i,1,c2) scanf("%d",&a2[i]);
    m=p_val=p_c=0;
    duyet1(1);
    sort(list+1,list+m+1,cmp);
    int tm=1;
    FOR(i,2,m) if(list[tm].val!=list[i].val) list[++tm]=list[i];
    m=tm;
    res=-oo;
    duyet2(1);
    printf("%d\n",res/2);
    //getch();
    return 0;
}
