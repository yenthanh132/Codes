#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=55;

string name[maxn];
int score[maxn],total_time[maxn],penalty[maxn][10],last_solve[maxn][10],last_time[maxn][10],id[maxn];
bool acc[maxn][10];

int n,t,m;
map<string,int> m_name;

bool cmp(const int &i, const int &j){
    if(score[i]!=score[j]) return score[i]>score[j];
    if(total_time[i]!=total_time[j]) return total_time[i]<total_time[j];
    for(int x=score[i]; x>=1; --x){
        if(last_solve[i][x]!=last_solve[j][x]) return last_solve[i][x]<last_solve[j][x];
        if(last_time[i][x]!=last_time[j][x]) return last_time[i][x]<last_time[j][x];
    }
    return name[i]<name[j];
}

bool cmp2(const int &i, const int &j){
    if(score[i]!=score[j]) return score[i]>score[j];
    if(total_time[i]!=total_time[j]) return total_time[i]<total_time[j];
    for(int x=score[i]; x>=1; --x){
        if(last_solve[i][x]!=last_solve[j][x]) return last_solve[i][x]<last_solve[j][x];
        if(last_time[i][x]!=last_time[j][x]) return last_time[i][x]<last_time[j][x];
    }
    return 0;
}

int main(){
    //freopen("input.txt","r",stdin);
    ios::sync_with_stdio(0);
    cin>>t;
    while(t--){
        cin>>n>>m;
        m_name.clear();
        for(int i=1; i<=n; ++i) cin>>name[i], m_name[name[i]]=i;
        reset(score,0); reset(total_time,0); reset(penalty,0); reset(last_solve,0); reset(last_time,0); reset(acc,0);
        int second,prob_id,team_id;
        string team,prob,result;
        for(int i=1; i<=m; ++i){
            cin>>second>>team>>prob>>result;
            team_id=m_name[team];
            prob_id=prob[0]-'A';
            if(result=="accepted" && !acc[team_id][prob_id]){
                score[team_id]++;
                last_solve[team_id][score[team_id]]=second;
                last_time[team_id][score[team_id]]=total_time[team_id];
                total_time[team_id]+=second+penalty[team_id][prob_id]*20;
                acc[team_id][prob_id]=1;
            }else{
                penalty[team_id][prob_id]++;
            }
        }
        for(int i=1; i<=n; ++i) id[i]=i;
        sort(id+1,id+n+1,cmp);
        for(int i=1,last; i<=n; ++i){
            int r=i;
            if(i>1 && !cmp2(id[i-1],id[i])){
                r=last;
            }else{
                last=i;
            }
            cout<<r<<' '<<name[id[i]]<<' '<<score[id[i]]<<' '<<total_time[id[i]]<<endl;
        }
    }
}

