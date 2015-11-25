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
#define FOR(a,b,c) for (int a=b;a<=c;a++)
#define FORD(a,b,c) for (int a=b;a>=c;a--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; ++i)
#define REPD(i,a) for(int i=(a)-1; i>=0; --i)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) int(a.size())
#define all(a) a.begin(),a.end()
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int maxn=50;

int n,T,c0,c1,c2,a[maxn],b[maxn],res[maxn];
vector<int> l0,l1,l2;
string s;

bool canswap(int x, int y){
    FOR(i,1,n) if(a[i]==x) b[i]=y; else if (a[i]==y) b[i]=x; else b[i]=a[i];
    int v;
    char ch;
    FOR(i,1,n){
        v=1;
        FOR(j,1,n) if(i!=j)
            if(b[i]<b[j]) v=-v; 
            else if(b[i]==b[j]){v=0;break;}
        if(v==1) ch='+'; else if(v==0) ch='0'; else ch='-';
        if(s[i-1]!=ch) return 0;
    }
    FOR(i,1,n) if(b[i]<a[i]) return 1; else if(b[i]>a[i]) return 0;
    return 0;
}

bool mycmp(const int &a, const int &b){return (a>b);}

void xuli(int a[]){
    int ans[maxn],b[maxn];
    FOR(i,1,n) ans[i]=a[i];
    int v=-1;
    FOR(i,1,n){
        int c=0;
        FOR(j,1,n) if(a[i]==a[j]) c++;
        if(c%2==0){
            v=a[i];
            break;
        }
    }
    if(v==-1) return;
    int maxv=a[1]; FOR(i,2,n) maxv=max(maxv,a[i]);
    FOR(x,1,maxv) if(x!=v){
        FOR(i,1,n) 
            if(a[i]==v) b[i]=x; 
            else if(min(x,v)<=a[i] && a[i]<=max(x,v)){
                if(v<x) b[i]=a[i]-1; else b[i]=a[i]+1;
            }
            else b[i]=a[i];
        bool ok=0;
        FOR(i,1,n) if(b[i]!=ans[i]){
            if(b[i]<ans[i]) ok=1;
            break;
        }
        if(ok) FOR(i,1,n) ans[i]=b[i];
    }
    FOR(i,1,n) a[i]=ans[i];
}
        

void solve(int v, vector<int> &l0, vector<int> l1, vector<int> l2){
    sort(l0.begin(), l0.end(),mycmp);
    FOR(i,1,n) 
        if(s[i-1]=='+') a[i]=l1.back()-v, l1.pop_back();
        else if(s[i-1]=='-') a[i]=l2.back()-v, l2.pop_back();
        else a[i]=l0.back()-v, l0.pop_back();
        
    bool ok;
    while(1){
        ok=0;
        FOR(i,1,n-1) FOR(j,i+1,n) if(canswap(i,j)){
            ok=ok | 1;
            FOR(k,1,n) a[k]=b[k];
        }
        if(!ok) break;
    }     
    xuli(a);
    
    ok=0;
    FOR(i,1,n) 
        if(res[i]<a[i]) return; else if(res[i]>a[i]){ok=1; break;}
    if(!ok) return;
    
    string ss="";
    char ch;
    FOR(i,1,n){
        v=1;
        FOR(j,1,n) if(i!=j)
            if(a[i]<a[j]) v=-v; 
            else if(a[i]==a[j]){v=0;break;}
        if(v==1) ch='+'; else if(v==0) ch='0'; else ch='-';
        ss=ss+ch;
    }    
    if(s==ss) FOR(i,1,n) res[i]=a[i];
}   

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    cin>>T;
    REP(index,T){
        cin>>s; n=s.length(); FOR(i,1,n) res[i]=oo;
        //Phase 1---------------------------------------
        c0=c1=c2=0;
        REP(i,n) if(s[i]=='0') c0++; else if(s[i]=='+') c1++; else c2++;
        l0.clear(); l1.clear(); l2.clear();
        bool plus=1,ok=1;
        int v=n;
        while(c1>0 || c2>0)
            if(plus){
                if(c1>=c2) l1.pb(v), v--, c1--;
                else if(c0>=3){
                    REP(l,3) l0.pb(v);
                    c0-=3;
                    v--;
                }else{
                    ok=0;
                    break;
                }
                plus=0;
            }else{
                if(c2>=c1-1) l2.pb(v), v--, c2--;
                else if(c0>=3){
                    REP(l,3) l0.pb(v);
                    c0-=3;
                    v--;
                }else{
                    ok=0;
                    break;
                }
                plus=1;
            }
        if(c0==1) ok=0;
        if(!ok){
            cout<<"TIDAK MUNGKIN\n";
            continue;
        }
        
        vector<int> ds0=l0;
        
        REP(i,c0) ds0.pb(v); 
        solve(v-1,ds0,l1,l2);
        
        ds0=l0; REP(i,c0) ds0.pb(n+1);
        solve(v,ds0,l1,l2);
        
        if(c0>=3){
            ds0=l0;
            REP(i,3) ds0.pb(v);
            REP(i,c0-3) ds0.pb(v-1);
            solve(v-2,ds0,l1,l2);
            
            ds0=l0;
            REP(i,3) ds0.pb(v);
            REP(i,c0-3) ds0.pb(n+1);
            solve(v-1,ds0,l1,l2);
        }
        
        if(c0>=6){
            ds0=l0;
            REP(i,3) ds0.pb(v);
            REP(i,3) ds0.pb(v-1);
            REP(i,c0-6) ds0.pb(v-2);
            solve(v-3,ds0,l1,l2);
            
            ds0=l0;
            REP(i,3) ds0.pb(v);
            REP(i,3) ds0.pb(v-1);
            REP(i,c0-6) ds0.pb(n+1);
            solve(v-2,ds0,l1,l2);
        }
        
        if(c0%2==0 && !l0.empty()){
            ds0=l0;
            REP(i,c0) ds0.pb(ds0.back());
            solve(v,ds0,l1,l2);
        }
        
        //Phase 2---------------------------------------
        c0=c1=c2=0;
        REP(i,n) if(s[i]=='0') c0++; else if(s[i]=='+') c1++; else c2++;
        l0.clear(); l1.clear(); l2.clear();
        plus=1;ok=1;
        v=n;
        while(c1>0 || c2>0)
            if(plus){
                if(c1>0) l1.pb(v), v--, c1--;
                else if(c0>=3){
                    REP(l,3) l0.pb(v);
                    c0-=3;
                    v--;
                }else{
                    ok=0;
                    break;
                }
                plus=0;
            }else{
                if(c2>0) l2.pb(v), v--, c2--;
                else if(c0>=3){
                    REP(l,3) l0.pb(v);
                    c0-=3;
                    v--;
                }else{
                    ok=0;
                    break;
                }
                plus=1;
            }
        if(c0==1) ok=0;
        if(!ok){
            cout<<"TIDAK MUNGKIN\n";
            continue;
        }
        
        ds0=l0;
        
        REP(i,c0) ds0.pb(v); 
        solve(v-1,ds0,l1,l2);
        
        ds0=l0; REP(i,c0) ds0.pb(n+1);
        solve(v,ds0,l1,l2);
        
        if(c0>=3){
            ds0=l0;
            REP(i,3) ds0.pb(v);
            REP(i,c0-3) ds0.pb(v-1);
            solve(v-2,ds0,l1,l2);
            
            ds0=l0;
            REP(i,3) ds0.pb(v);
            REP(i,c0-3) ds0.pb(n+1);
            solve(v-1,ds0,l1,l2);
        }
        
        if(c0>=6){
            ds0=l0;
            REP(i,3) ds0.pb(v);
            REP(i,3) ds0.pb(v-1);
            REP(i,c0-6) ds0.pb(v-2);
            solve(v-3,ds0,l1,l2);
            
            ds0=l0;
            REP(i,3) ds0.pb(v);
            REP(i,3) ds0.pb(v-1);
            REP(i,c0-6) ds0.pb(n+1);
            solve(v-2,ds0,l1,l2);
        }
        
        if(c0%2==0 && !l0.empty()){
            ds0=l0;
            REP(i,c0) ds0.pb(ds0.back());
            solve(v,ds0,l1,l2);
        }
        
        //------------------------------------------------------
        
        FOR(i,1,n) cout<<res[i]<<' '; cout<<endl;
        /*cout<<s<<endl;
        char ch;
        FOR(i,1,n){
            v=1;
            FOR(j,1,n) if(i!=j)
                if(res[i]<res[j]) v=-v; 
                else if(res[i]==res[j]){v=0;break;}
            if(v==1) ch='+'; else if(v==0) ch='0'; else ch='-';
            cout<<ch;
        }cout<<endl;*/
    }
    
    //getch();
    return 0;
}
