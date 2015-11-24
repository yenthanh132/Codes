#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
typedef pair<int, char> pic;

const int maxn=100007;
int T,n,c[26],k;
char s[maxn];
vector<pic> lst;

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&k);
        scanf("%s",s+1);
        reset(c,0);
        for(int i=1; i<=n; ++i) c[s[i]-'a']++;
        lst.clear();
        for(int i=0; i<26; ++i) if(c[i]>k) lst.pb(pic(-c[i],i+'a'));
        if(lst.empty()){
            cout<<"NONE"<<endl;
        }else{
            sort(lst.begin(),lst.end());
            for(int i=0; i<sz(lst); ++i) cout<<lst[i].second; cout<<endl;
        }
    }
}

