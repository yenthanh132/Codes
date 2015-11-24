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

const int maxn=500007;
int n,t,cH,cS;
char a[maxn];


bool check(int v){
    stack<int> mystack;
    int prev;
    int c=v,cost=0,pos=-1;
    REP(i,n) if(a[i]=='S'){
        if(mystack.empty()){
            c++;
        }else{
            prev=mystack.top();
            mystack.pop();
            if(mystack.empty()){
                cost+=abs(prev-i)+abs(i-pos);
                pos=prev;
            }
        }
        
    }else if(a[i]=='H'){
        if(c>0){
            c--;
            cost+=abs(i-pos);
            pos=i;
        }else{
            mystack.push(i);
            cost+=abs(i-pos);
            pos=i;
        }
    }
    return cost<=t;
}
    
//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d%d\n",&n,&t);
    gets(a);
    cH=cS=0;
    REP(i,n) if(a[i]=='H') cH++; else if(a[i]=='S') cS++;
    if(t>=n*2-1){
        printf("%d\n",max(cH-cS,0));
        return 0;
    }
        int l=max(cH-cS,0), r=cH ,mid,res=oo;
        while(l<=r){
            mid=(l+r)/2;
            if(check(mid)){
                res=mid;
                r=mid-1;
            }else l=mid+1;
        }
        if(res==oo) puts("-1"); else printf("%d\n",res);
    //getch();
    return 0;
}
