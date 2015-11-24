#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

string s;

vector<pii> lst,ans;

int main(){
//    freopen("input.txt","r",stdin);
    cin>>s;
    int len=sz(s);
    int i=0;
    while(i<len && s[i]=='0') ++i;
    while(i<len){
        int j=i;
        while((j+1<len && s[j+1]=='1') || (j+2<len && s[j+2]=='1')) ++j;
        if(j==i) ans.pb(pii(len-i-1,1));
        else{
            int c0=0, c1=0;
            for(int x=i; x<=j; ++x) if(s[x]=='1') ++c1; else ++c0;
            if(c1 < 2+c0){
                for(int x=i; x<=j; ++x) if(s[x]=='1') ans.pb(pii(len-x-1,1));
            }else{
                ans.pb(pii(len-i,1));
                ans.pb(pii(len-j-1,-1));
                for(int x=i; x<=j; ++x) if(s[x]=='0') ans.pb(pii(len-x-1,-1));
            }
        }
        i=j+1;
        while(i<len && s[i]=='0') ++i;
    }

    printf("%d\n",sz(ans));
    for(int i=0; i<sz(ans); ++i)
        if(ans[i].second==1) printf("+2^%d\n",ans[i].first);
        else printf("-2^%d\n",ans[i].first);

    return 0;
}
