#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

typedef vector< vector<int> > Matrix;

Matrix create(int m, int n){
    return vector< vector<int> > (m, vector<int> (n, 0) );
}

Matrix base[64],mult[64];

Matrix mul(Matrix a, Matrix b){
    int m=sz(a), n=sz(b), p=sz(b[0]);
    Matrix c = create(m,p);
    for(int i=0; i<m; ++i) for(int j=0; j<p; ++j)
        for(int k=0; k<n; ++k)
            c[i][j] = (c[i][j] + 1ll*a[i][k]*b[k][j])%oo;
    return c;
}

Matrix mpow(Matrix &base, int n){
    if(n==1) return base;
    Matrix t=mpow(base,n/2);
    t=mul(t,t);
    if(n&1) return mul(t,base);
    return t;
}

const int maxt=2007;
int T;
int idlist[64],cnt,posid[64];
map<pii,int> result;
int n[maxt],k[maxt];
vector<int> nlist[27];

int main(){
//    freopen("input.txt","r",stdin);
    cnt=0;
    reset(posid,-1);
    for(int id=0; id<64; ++id){
        if((id>>3&1) && (!(id>>0&1) || !(id>>1&1))) continue;
        if((id>>4&1) && (!(id>>0&1) || !(id>>2&1))) continue;
        if((id>>5&1) && (!(id>>1&1) || !(id>>2&1))) continue;
        idlist[cnt]=id;
        posid[id]=cnt++;
    }
    for(int k=1; k<=26; ++k){
        base[k] = create(cnt,cnt);
        for(int i=0; i<cnt; ++i){
            int id=idlist[i];
            for(char x='a'-1; x<'a'+k; ++x){
                if(x>='a' && (id>>3&1)) break;
                for(char y='a'-1; y<'a'+k; ++y){
                    if(y>='a' && (id>>4&1)) break;
                    for(char z='a'-1; z<'a'+k; ++z){
                        if(z>='a' && (id>>5&1)) break;

                        int id2=id;
                        if(x!='a'-1 && y!='a'-1 && x!=y) id2|=1<<0;
                        if(x!='a'-1 && z!='a'-1 && x!=z) id2|=1<<1;
                        if(z!='a'-1 && y!='a'-1 && y!=z) id2|=1<<2;

                        if(x=='a'-1) id2|=1<<3;
                        if(y=='a'-1) id2|=1<<4;
                        if(z=='a'-1) id2|=1<<5;
                        if(posid[id2]!=-1)
                            base[k][posid[id2]][posid[id]]++;
                    }
                }
            }
        }

        mult[k] = create(cnt,1);
        for(int x='a'; x<'a'+k; ++x)
            for(int y='a'; y<'a'+k; ++y)
                for(int z='a'; z<'a'+k; ++z){
                    int id=0;
                    if(x!=y) id|=1;
                    if(x!=z) id|=2;
                    if(y!=z) id|=4;
                    ++mult[k][posid[id]][0];
                }
    }

    scanf("%d",&T);
    for(int i=1; i<=T; ++i){
        scanf("%d%d",&n[i],&k[i]);
        nlist[k[i]].pb(n[i]);
    }

    for(int k=1; k<=26; ++k) if(!nlist[k].empty()){
        sort(nlist[k].begin(), nlist[k].end());
        nlist[k].resize(unique(nlist[k].begin(), nlist[k].end())-nlist[k].begin());
        Matrix tbase;
        Matrix tmult=mult[k];
        int nprev=1;
        for(int i=0; i<sz(nlist[k]); ++i){
            int n=nlist[k][i];
            int res = 0;
            if(n>nprev){
                tbase=mpow(base[k],n-nprev);
                tmult=mul(tbase,tmult);
                nprev=n;
            }
            for(int i=0; i<8; ++i) res=(res+tmult[posid[(i<<3) + 7]][0])%oo;
            result[pii(n,k)]=res;
        }
    }

    for(int i=1; i<=T; ++i){
        printf("%d\n",result[pii(n[i],k[i])]);
    }
}

