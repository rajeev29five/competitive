		//not my tamplate
#include <vector> 
#include <queue>
#include <map> 
#include <set>
#include <utility> //Pair
#include <algorithm>
#include <sstream> // istringstream>> ostring stream<<
#include <iostream> 
#include <iomanip> 
//setbase - cout << setbase (16); cout << 100 << endl; Prints 64
//setfill -   cout << setfill ('x') << setw (5); cout << 77 << endl; prints xxx77
//setprecision - cout << setprecision (4) << f << endl; Prints x.xxxx
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>
#include <fstream>
#include <limits>
using namespace std;
 
typedef long long ll;
typedef vector <int> vi;
typedef pair< int ,int > pii;
typedef istringstream iss;
typedef ostringstream oss;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define sz size()
#define ln length()
#define rep(i,n) for(int i=0;i<n;i++)
#define fu(i,a,n) for(int i=a;i<=n;i++)
#define fd(i,n,a) for(int i=n;i>=a;i--)
#define all(a)  a.begin(),a.end() 
 
#define gi(n) scanf("%d",&n)
#define gll(n) scanf("%lld",&n);
#define gl(n) cin >> n
#define pi(n) printf("%d",n)
#define pll(n) printf("%lld",n)
#define pl(n) cout << n
#define ps printf(" ")
#define pn printf("\n")
#define dg(n,s); printf("%s %d",s,n)
#define imax numeric_limits<int>::max()
#define imin numeric_limits<int>::min()
#define lmax numeric_limits<ll>::max()
#define lmin numeric_limits<ll>::min()
int main(){
	ll t,q,a,b,n,m,u,v;
	gll(t);
	
	while(t--)
	{
		scanf("%lld%lld%lld",&n,&m,&q);
		multiset<ll> xc,yc,xd,yd;
		xc.insert(0);
		yc.insert(0);
		xc.insert(n);
		yc.insert(m);
		xd.insert(n);
		yd.insert(m);
		while(q--)
		{
			gll(a);
			if(a==0)
			{
				gll(b);
				if(xc.find(b)!=xc.end())
				{
					printf("%lld\n",(*xd.rbegin())*(*yd.rbegin()));
					continue;
				}
				else
				{
					auto it1 = xc.upper_bound(b);
					it1;
					auto it2 = xc.lower_bound(b);it2--;
					u = *it1;v=*it2;
					// cout<<"u "<<u<<" v "<<v<<endl;
					it1 = xd.find(u-v);
					xd.erase(it1);
					xd.insert(u-b);
					xd.insert(b-v);
					xc.insert(b);
				}
			}
			else if(a==1)
			{
				gll(b);
				// cout<<"b "<<b<<endl;
				if(yc.find(b)!=yc.end())
				{
					printf("%lld\n",(*xd.rbegin())*(*yd.rbegin()));
					continue;
				}
				else
				{
					auto it1 = yc.upper_bound(b);
					it1;
					auto it2 = yc.lower_bound(b);it2--;
					u = *it1;v = *it2;
					u = *it1;v=*it2;
					// cout<<"u "<<u<<" v "<<v<<endl;
					it1 = yd.find(u-v);
					yd.erase(it1);
					yd.insert(u-b); 
					yd.insert(b-v);
					yc.insert(b);
				}
			}
			printf("%lld\n",(*xd.rbegin())*(*yd.rbegin()));
			// cout<<*yd.rbegin()<<" "<<*xd.rbegin()<<endl;
		}
	}	
	return 0;
}