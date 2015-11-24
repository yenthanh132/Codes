#include <conio.h>
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

const int maxn=1000007;
int a[maxn],sum,c[5],n;

int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d",&n);
    sum=0; reset(c,0);
    FOR(i,1,n) scanf("%d",&a[i]), sum+=a[i], c[a[i]]++;
    
    if(sum<=2 || sum==5){
        puts("-1");
        return 0;
    }
    
    int res=0;
    if(c[1]>=c[2]){
        res+=c[2];
        c[1]-=c[2];
        c[3]+=c[2];
        c[2]=0;
        if(c[1]>0){
            c[3]+=c[1]/3;
            res+=(c[1]/3)*2;
            int t=c[1]%3;
            if(t>0){
                if(t==1 && c[3]>0) res++;
                else res+=2;
            }
            c[1]=0;              
        }
    }else{
        res+=c[1];
        c[2]-=c[1];
        c[3]+=c[1];
        c[1]=0;
        if(c[2]>0){
            res+=(c[2]/3)*2;
            c[3]+=(c[2]/3)*2;
            int t=c[2]%3;
            if(t==1 && c[4]>0) res+=1;
            else if(t>=1) res+=2;
            c[2]=0;
        }
    }
    cout<<res<<endl;
    //getch();
    return 0;
}
    

