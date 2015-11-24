#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

string modify(string S, int v)
{
    char sarr[20];
    for(int i=0; i<sz(S); ++i) sarr[i]=S[i];
    sarr[sz(S)]=0;
    int h,m,s,t;
    sscanf(sarr,"%d:%d:%d,%d",&h,&m,&s,&t);
    int val=t+s*1000+m*1000*60+h*1000*60*60 + v;
    t=val%1000;
    val/=1000;
    s=val%60;
    val/=60;
    m=val%60;
    val/=60;
    h=val;
    sprintf(sarr,"%02d:%02d:%02d,%03d",h,m,s,t);
    return string(sarr,sarr+strlen(sarr));
}

int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int h,m,s,t;
    cin>>h>>m>>s>>t;
    int val=t+s*1000+m*1000*60+h*1000*60*60;
    string S;
    cin>>S;
    if(S=="slower") val*=-1;
    getline(cin,S);

    bool first=1;
    while(getline(cin,S))
    {
        if(first) first=0;
        else cout<<endl;
        cout<<S<<endl;
        cin>>S;
        cout<<modify(S,val)<<' ';
        cin>>S;
        cout<<S;
        cin>>S;
        cout<<' '<<modify(S,val);
        getline(cin,S);
        while(getline(cin,S), S!="") cout<<endl<<S;
        cout<<endl;
    }
}

