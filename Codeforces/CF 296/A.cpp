#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

multiset<int> sw,sh;
set<int> vw,vh;
int w,h,n;

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d%d%d",&w,&h,&n);
    sw.insert(w); sh.insert(h);
    vw.insert(0); vw.insert(w);
    vh.insert(0); vh.insert(h);
    for(int i=0; i<n; ++i){
        char s[5];
        int x;
        scanf("%s%d",s,&x);
        if(s[0]=='V'){
            vw.insert(x);
            set<int>::iterator l=--vw.find(x);
            set<int>::iterator r=++vw.find(x);
            sw.erase(sw.find(*r-*l));
            sw.insert(x-*l);
            sw.insert(*r-x);
        }else{
            vh.insert(x);
            set<int>::iterator l=--vh.find(x);
            set<int>::iterator r=++vh.find(x);
            sh.erase(sh.find(*r-*l));
            sh.insert(*r-x);
            sh.insert(x-*l);
        }

        ll W = *(--sw.end());
        ll H = *(--sh.end());
        printf("%I64d\n",W*H);
    }
}
