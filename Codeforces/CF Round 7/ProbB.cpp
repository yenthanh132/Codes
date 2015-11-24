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
typedef pair<pii, int> piii;

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    int t, m, v, c=0;
    vector<piii> list; list.pb(piii(pii(0,1),0));
    string s;
    cin>>t>>m;
    REP(index,t){
        cin>>s;
        if(s=="alloc"){
            cin>>v;
            int p=1;
            FOR(i,1,sz(list)-1)
                if(p+v-1<list[i].fi.fi) break;
                else p=list[i].fi.fi+list[i].fi.se;
            if(p+v-1<=m){
                list.pb(piii(pii(p,v),++c));
                sort(all(list));
                cout<<c<<endl;
            }else cout<<"NULL\n";
        }else if(s=="erase"){
            cin>>v;
            bool found=0;
            FOR(i,1,sz(list)-1) if(list[i].se==v){
                found=1;
                list.erase(list.begin()+i);
                break;
            }
            if(!found) cout<<"ILLEGAL_ERASE_ARGUMENT\n";
        }else{
            REP(i,sz(list)-1)
                list[i+1].fi.fi=list[i].fi.fi+list[i].fi.se;
        }
    }
    //getch();
    return 0;
}
            
            
            
