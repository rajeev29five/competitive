		//not my tamplate
// #include <vector> 
// #include <queue>
// #include <map> 
// #include <set>
// #include <utility> //Pair
// #include <algorithm>
// #include <sstream> // istringstream>> ostring stream<<
#include <iostream> 
// #include <iomanip> 
// //setbase - cout << setbase (16); cout << 100 << endl; Prints 64
// //setfill -   cout << setfill ('x') << setw (5); cout << 77 << endl; prints xxx77
// //setprecision - cout << setprecision (4) << f << endl; Prints x.xxxx
// #include <cstdio>
// #include <cmath>
// #include <cstdlib>
// #include <ctime>
// #include <cstring>
// #include <cassert>
// #include <fstream>
// #include <limits>
using namespace std;
 
// typedef long long ll;
// typedef vector <int> vi;
// typedef pair< int ,int > pii;
// typedef istringstream iss;
// typedef ostringstream oss;
// #define pb push_back
// #define mp make_pair
// #define ff first
// #define ss second
// #define sz size()
// #define ln length()
// #define rep(i,n) for(int i=0;i<n;i++)
// #define fu(i,a,n) for(int i=a;i<=n;i++)
// #define fd(i,n,a) for(int i=n;i>=a;i--)
// #define all(a)  a.begin(),a.end() 
 
// #define gi(n) scanf("%d",&n)
// #define gll(n) scanf("%lld",&n);
// #define gl(n) cin >> n
// #define pi(n) printf("%d",n)
// #define pll(n) printf("%lld",n)
// #define pl(n) cout << n
// #define ps printf(" ")
// #define pn printf("\n")
// #define dg(n,s); printf("%s %d",s,n)
// #define imax numeric_limits<int>::max()
// #define imin numeric_limits<int>::min()
// #define lmax numeric_limits<ll>::max()
// #define lmin numeric_limits<ll>::min()

int M, a, b;
int answer;
int x[10], go[10][10];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < 8; i ++)
        cin >> x[i];
    cin >> M;
    for(int i = 0; i < M; i ++){
        cin >> a >> b;
        --a, --b;
        go[a][b] = go[b][a] = 1;
    }
    
    for(int i = 1; i < (1 << 8); i ++){
        int good = 1;
        for(int j = 0; j < 8; j ++)
            if(i & (1 << j))
                for(int k = 0; k < 8; k ++)
                    if(i & (1 << k))
                        if(go[j][k])
                            good = 0;
        if(good){
            int s = 0;
            for(int j = 0; j < 8; j ++)
                if(i & (1 << j))
                    s += x[j];
            answer = max(answer, s);
        }
    }
    
    cout << answer << endl;
    
    return 0;
}