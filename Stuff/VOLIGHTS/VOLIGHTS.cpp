//Solution:

//  Lưu ý, dưới đây khi nói tới 1 mặt phẳng x tức là nói tới mặt phẳng chứa tất cả các điểm (x,y0,z0)
//với (1<=y0<=n; 1<=z0<=k); tương tự cho mặt phẳng y,z nhé. Trước tiên ta thấy nếu chọn 2 ô (x, y1, z1),
//(x, y2, z2) thì khi đó nếu ta không cần thiết phải chọn 2 ô (x, y1, z2), (x,y2,z1) nữa, tương tự
//nếu 2 ô nằm cùng 1 mặt phẳng y, z cũng vậy. Ta có thể đưa về đồ thị có m+n+k đỉnh, đỉnh [1..m] cho
//chiều x, [m+1..m+n] cho chiều y, [m+n+1 .. m+n+k] cho chiều z. Mỗi khi có 1 điểm (x,y,z) thì ta nối
//các đỉnh x, y+m, z+m+n lại (dùng disjoin-set). Bằng cách này sau khi xét hết q đỉnh ta có thể biết
//được có bao nhiêu thành phần liên thông > 1 đỉnh, gọi số lượng này là K, ta sẽ có K cube mà mỗi cube
//tất cả các điểm đều đã được chọn; ta cũng biết được bao nhiêu thành phần liên thông có 1 đỉnh, mỗi
//thành phần liên thông có 1 đỉnh đại diện cho 1 mặt phẳng mà không chứa điểm nào cả, gọi X,Y,Z là số
//lượng thành phần liên thông có 1 đỉnh và lần lượt đại diện cho các mặt phẳng x, y, z.
//  Xét cube kích thước X.Y.Z, cube này sẽ không có điểm nào bên trong, ta cần xét bài toán con:
//Chọn ít điểm nhất trong 1 cube kích thước X.Y.Z để tất cả các điểm khác được chọn. Bài toán này
//có thể được phát biểu lại như sau: Cho 3 số dương, đầu tiên ta sẽ giảm mỗi số đi 1 đơn vị, sau
//đó mỗi lượt đi ta được chọn 2 số và giảm mỗi số đi 1 đơn vị, tìm số lượt đi ít nhất để cả 3 số
//đều <=0. Kq bài toán này là MAX( (<tổng 3 số>+1) div 2 , <số lớn nhất trong 3 số> ) Như vậy với 1
//cube kích thước X.Y.Z, số lượng điểm ít nhất cần chọn là: Max( ((X-1)+(Y-1)+(Z-1)+1) div 2, X-1, Y-1, Z-1) + 1
//= Max( (X+Y+Z-2, X-1, Y-1, Z-1) + 1.
//  Sau khi group xong X.Y.Z, ta sẽ được thêm 1 cube mà tất cả các điểm đều được chọn. Tổng cộng
//ta có (K+1) cube, để nối các cube này lại với nhau cần chọn thêm đúng K điểm nữa. Vậy kq cuối
//cùng là: K + Max( (X+Y+Z-2, X-1, Y-1, Z-1) + 1

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
const int maxn=1007;

int lab[maxn*3],c[5],m,n,k;

int getroot(int u){
    if(lab[u]<0) return u;
    lab[u]=getroot(lab[u]);
    return lab[u];
}

void dsu(int u, int v){
    int r1=getroot(u), r2=getroot(v);
    if(r1==r2) return;
    if(lab[r1]<lab[r2]){
        lab[r1]+=lab[r2];
        lab[r2]=r1;
    }else{
        lab[r2]+=lab[r1];
        lab[r1]=r2;
    }
}

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d%d%d",&m,&n,&k);
    int q,x,y,z;
    FOR(u,1,m+n+k) lab[u]=-1;
    scanf("%d",&q);
    REP(i,q){
        scanf("%d%d%d",&x,&y,&z);
        dsu(x,y+m);
        dsu(x,z+m+n);
    }
    reset(c,0);
    FOR(u,1,m+n+k) if(lab[u]<0){
        if(lab[u]<-1) c[0]++;
        else if(u<=m) c[1]++;
        else if(u<=m+n) c[2]++;
        else c[3]++;
    }
    int res=0,cnt=c[0];
    if(c[1]+c[2]+c[3]>0){
        int maxv=c[1];
        ++res;
        FOR(i,1,3) maxv=max(maxv,c[i]-1);
        res+=max((c[1]+c[2]+c[3]-2)/2, maxv);
    }
    if(cnt>1) res+=cnt-1;
    cout<<res<<endl;
    return 0;
}

