#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"

#include "../structure/SegmentTree.cpp"
#include "../math/modint.cpp"

constexpr int mod=998244353;

using modint=mint<mod>;
 
using PM=pair<modint,modint>;
auto f=[](modint a,modint b,int sz)->modint{return a+b;};
auto g=[](modint a,PM b,int sz)->modint{return a*b.first+b.second*modint(sz);};
auto h=[](PM a,PM b,int sz)->PM{return PM(a.first*b.first,a.second*b.first+b.second);};
 
int main(){
	cin.tie(0);ios::sync_with_stdio(false);
	int N,Q;
	cin>>N>>Q;
	Segtree<modint,PM,f,g,h>segtree(N,0,PM(1,0));
	rep(i,N){
		int a;cin>>a;
		segtree.update(i,i+1,PM(1,a));
	}
	while(Q--){
		int t;cin>>t;
		if(!t){
			int l,r,b,c;cin>>l>>r>>b>>c;
			segtree.update(l,r,PM(b,c));
		}else {
			int l,r;cin>>l>>r;
			cout<<segtree.query(l,r)<<"\n";
		}
	}
}