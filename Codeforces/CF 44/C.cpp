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

string s[10],a[10];
int p[10];
vector<string> res,tmp;

int cmp(const vector<string> a, const vector<string> b){
    REP(i,min(sz(a),sz(b))) if(a[i]<b[i]) return -1; else if(a[i]>b[i]) return 1;
    if(sz(a)<sz(b)) return -1; else if(sz(a)>sz(b)) return 1;
    return 0;
}

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    FOR(i,1,6) cin>>s[i];
    FOR(i,1,6) p[i]=i;
    do{
        FOR(i,1,6) a[i]=s[p[i]];
        int l[7];
        FOR(i,1,6) l[i]=sz(a[i]);
    if(l[1]>2 && l[1]<l[2] && l[3]>2 && l[3]<l[2] && l[4]>2 && l[4]<l[5] && l[6]>2 && l[6]<l[5])
        if(l[2]==l[1]+l[3]-1 && l[5]==l[4]+l[6]-1){
            if(a[1][0]==a[4][0] && a[4][l[4]-1]==a[2][0] && a[1][l[1]-1]==a[5][0]
            && a[2][l[1]-1]==a[5][l[4]-1]
            && a[2][l[2]-1]==a[6][0] && a[5][l[5]-1]==a[3][0] && a[3][l[3]-1]==a[6][l[6]-1])
            {
                tmp.clear();
                string st;
                REP(i,l[2]){
                    st="";
                    if(i==0){
                        REP(k,l[5]-l[4]) st+='.';
                        st=a[4]+st;
                    }else if(i==l[2]-1){
                        REP(k,l[5]-l[6]) st+='.';
                        st=st+a[6];
                    }else if(i==l[1]-1) st=a[5];
                    else if(i<l[1]-1){
                        REP(k,l[5]) st+='.';
                        st[0]=a[1][i];
                        st[l[4]-1]=a[2][i];
                    }else{
                        REP(k,l[5]) st+='.';
                        st[l[4]-1]=a[2][i];
                        st[l[5]-1]=a[3][i-(l[1]-1)];
                    }
                    tmp.pb(st);
                }
                if(sz(res)==0 || cmp(res,tmp)>0) res=tmp;
            }
        }
    }while(next_permutation(p+1,p+7));  
    if(sz(res)>0){
        REP(i,sz(res)) cout<<res[i]<<endl;
    }
    else cout<<"Impossible"<<endl;
    
    //getch();
    return 0;
}
