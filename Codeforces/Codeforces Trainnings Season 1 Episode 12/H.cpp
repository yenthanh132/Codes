//#include <bits/stdc++.h>
//
//using namespace std;
//
//#define pb push_back
//#define sz(a) int(a.size())
//#define sqr(x) (x)*(x)
//#define reset(a, b) memset(a, b, sizeof(a))
//#define oo 1000000007
//
//typedef pair<int, int> pii;
//typedef pair<pii, int> iii;
//typedef pair<pii, pii> i4;
//typedef long long ll;
//
//const int maxn=20;
//const int maxv=1007;
//const int Value[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
//const string sValue[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
//const int dx[4]={-1,0,1,0};
//const int dy[4]={0,1,0,-1};
//
//char s[maxn][maxn];
//int mark[maxn][maxn][maxn],idx,m,n;
//
//bool inside(int x, int y){
//    return 1<=x && x<=m && 1<=y && y<=n;
//}
//
//string gen(int v){
//    string res="";
//    int i=12;
//    while(v>0){
//        while(Value[i] > v) --i;
//        res += sValue[i];
//        v -= Value[i];
//    }
//    return res;
//}
//
//queue<iii> myq;
//
//bool check(string str){
//    ++idx;
//    myq = queue<iii>();
//    for(int i=1; i<=m; ++i) if(s[i][1]==str[0]){
//        myq.push(iii(pii(i,1),0));
//        mark[i][1][0]=idx;
//    }
//    while(!myq.empty()){
//        iii p=myq.front(); myq.pop();
//        int x=p.first.first, y=p.first.second, v=p.second;
//        if(v==sz(str)-1){
//            if(y==n) return 1;
//            continue;
//        }
//        for(int k=0; k<4; ++k){
//            int xt=x+dx[k], yt=y+dy[k];
//            if(!inside(xt,yt)) continue;
//            if(s[xt][yt]==str[v+1]){
//                if(mark[xt][yt][v+1]==idx) continue;
//                mark[xt][yt][v+1]=idx;
//                myq.push(iii(pii(xt,yt),v+1));
//            }
//        }
//    }
//    return 0;
//}
//
//string solve(){
//    idx=0;
//    for(int v=1; v<=3999; ++v){
//        string str=gen(v);
//        if(check(str)) return str;
//    }
//    return "NO";
//}
//
//int main() {
////    freopen("input.txt", "r", stdin);
//
//    scanf("%d%d",&m,&n);
//    for(int i=1; i<=m; ++i) scanf("%s",s[i]+1);
//
//    cout<<solve()<<endl;
//
//    return 0;
//}
//
