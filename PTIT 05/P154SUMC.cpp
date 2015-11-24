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

int main(){
//    freopen("input.txt","r",stdin);
    cin>>s;
    sort(s.begin(),s.end());
    int c = unique(s.begin(),s.end())-s.begin();
    if(c&1) cout<<"IGNORE HIM!"<<endl; else cout<<"CHAT WITH HER!"<<endl;
}

