---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/modint.cpp
    title: mod int
  - icon: ':x:'
    path: structure/SegmentTree.cpp
    title: Lazy Segment Tree
  - icon: ':question:'
    path: template/template.cpp
    title: template/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_affine_range_sum
  bundledCode: "#line 1 \"test/SegmentTree.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n\n#line 2 \"template/template.cpp\"\n#include<bits/stdc++.h>\nusing namespace\
    \ std;\n#define ll long long\n#define rep(i,n) for(ll i=0;i<n;i++)\n#define REP(i,n)\
    \ for(ll i=1;i<n;i++)\n#define rev(i,n) for(ll i=n-1;i>=0;i--)\n#define all(v)\
    \ v.begin(),v.end()\n#define P pair<ll,ll>\n#define len(s) (ll)s.size()\n \ntemplate<class\
    \ T,class U> inline bool chmin(T &a, U b){\n\tif(a>b){a=b;return true;}\n\treturn\
    \ false;\n}\ntemplate<class T,class U> inline bool chmax(T &a, U b){\n\tif(a<b){a=b;return\
    \ true;}\n\treturn false;\n}\nconstexpr ll inf = 3e18;\n#line 3 \"structure/SegmentTree.cpp\"\
    \n\ntemplate<typename Monoid,\n\t\ttypename OperatorMonoid,\n\t\tMonoid(*f)(Monoid,Monoid,int),\n\
    \t\tMonoid(*g)(Monoid,OperatorMonoid,int),\n\t\tOperatorMonoid(*h)(OperatorMonoid,OperatorMonoid,int)>\n\
    struct Segtree{\n\tint size=1;\nprivate:\n\tvector<Monoid>dat;\n\tvector<OperatorMonoid>lazy;\n\
    \tMonoid M;\n\tOperatorMonoid OM;\npublic:\n\tvoid eval(int k,int l,int r){\n\t\
    \tif(lazy[k]!=OM){\n\t\t\tdat[k]=g(dat[k],lazy[k],r-l);\n\t\t\tif(r-l>1){\n\t\t\
    \t\tlazy[(k<<1)+1]=h(lazy[(k<<1)+1],lazy[k],r-l);\n\t\t\t\tlazy[(k<<1)+2]=h(lazy[(k<<1)+2],lazy[k],r-l);\n\
    \t\t\t}\n\t\t\tlazy[k]=OM;\n\t\t}\n\t}\n\tvoid update(int a,int b,OperatorMonoid\
    \ M,int k=0,int l=0,int r=-1){\n\t\tif(r==-1)r=size;\n\t\teval(k,l,r);\n\t\tif(r<=a||b<=l)return;\n\
    \t\tif(a<=l&&r<=b){\n\t\t\tlazy[k]=h(lazy[k],M,r-l);\n\t\t\teval(k,l,r);\n\t\t\
    \treturn;\n\t\t}\n\t\tupdate(a,b,M,(k<<1)+1,l,(l+r)>>1);\n\t\tupdate(a,b,M,(k<<1)+2,(l+r)>>1,r);\n\
    \t\tdat[k]=f(dat[(k<<1)+1],dat[(k<<1)+2],r-l);\n\t}\n\tMonoid query(int a,int\
    \ b,int k=0,int l=0,int r=-1){\n\t\tif(r==-1)r=size;\n\t\teval(k,l,r);\n\t\tif(r<=a||b<=l)return\
    \ M;\n\t\tif(a<=l&&r<=b)return dat[k];\n\t\tMonoid lv=query(a,b,(k<<1)+1,l,(l+r)>>1);\n\
    \t\tMonoid rv=query(a,b,(k<<1)+2,(l+r)>>1,r);\n\t\treturn f(lv,rv,r-l);\n\t}\n\
    \ttemplate<class C>\n\tint minLeft(int a,int b,C &check,Monoid x,int k=0,int l=0,int\
    \ r=-1){\n\t\tif(r==-1)r=size;\n\t\teval(k,l,r);\n\t\tif(r<=a||b<=l||!check(dat[k],x))return\
    \ -1;\n\t\tif(r-l==1)return l;\n\t\tint lv=minLeft(a,b,check,x,(k<<1)+1,l,(l+r)>>1);\n\
    \t\tif(lv!=-1)return lv;\n\t\treturn minLeft(a,b,check,x,(k<<1)+2,(l+r)>>1,r);\n\
    \t}\n\ttemplate<class C>\n\tint maxRight(int a,int b,C &check,Monoid x,int k=0,int\
    \ l=0,int r=-1){\n\t\tif(r==-1)r=size;\n\t\teval(k,l,r);\n\t\tif(r<=a||b<=l||!check(dat[k],x))return\
    \ -1;\n\t\tif(r-l==1)return l;\n\t\tint rv=maxRight(a,b,check,x,(k<<1)+2,(l+r)>>1,r);\n\
    \t\tif(rv!=-1)return rv;\n\t\treturn maxRight(a,b,check,x,(k<<1)+1,l,(l+r)>>1);\n\
    \t}\n\tSegtree(int x,Monoid M,OperatorMonoid OM)\n\t:M(M),OM(OM){\n\t\twhile(size<x)size<<=1;\n\
    \t\tdat.resize((size<<1)-1,M);\n\t\tlazy.resize((size<<1)-1,OM);\n\t}\n};\n\n\
    /*\n@brief Lazy Segment Tree\n@docs docs/SegmentTree.md\n*/\n#line 3 \"math/modint.cpp\"\
    \n\ntemplate<int MOD>\nstruct mint{\n\tint32_t n;\n\tmint():n(0){}\n\tmint(ll\
    \ x):n(x>=0?x%MOD:(MOD-(-x)%MOD)%MOD){}\n\n\tmint &operator+=(const mint &p){\n\
    \t\tif((n+=p.n)>=MOD)n-=MOD;\n\t\treturn *this;\n\t}\n\tmint &operator-=(const\
    \ mint &p){\n\t\tif((n+=MOD-p.n)>=MOD)n-=MOD;\n\t\treturn *this;\n\t}\n\tmint\
    \ &operator*=(const mint &p){\n\t\tn=1ll*n*p.n%MOD;\n\t\treturn *this;\n\t}\n\t\
    mint &operator/=(const mint &p){\n\t\t*this*=p.inverse();\n\t\treturn *this;\n\
    \t}\n\tmint operator-()const{return mint(-n);}\n\tmint operator+(const mint &p)const{return\
    \ mint(*this)+=p;}\n\tmint operator-(const mint &p)const{return mint(*this)-=p;}\n\
    \tmint operator*(const mint &p)const{return mint(*this)*=p;}\n\tmint operator/(const\
    \ mint &p)const{return mint(*this)/=p;}\n\tbool operator==(const mint &p)const{return\
    \ n==p.n;}\n\tbool operator!=(const mint &p)const{return n!=p.n;}\n\n\tfriend\
    \ ostream &operator<<(ostream &os,const mint &p){\n\t\treturn os<<p.n;\n\t}\n\t\
    friend istream &operator>>(istream &is,mint &p){\n\t\tint x;is>>x;\n\t\tp=mint(x);\n\
    \t\treturn is;\n\t}\n\tmint pow(int64_t x)const{\n\t\tmint res(1),mul(n);\n\t\t\
    while(x>0){\n\t\t\tif(x&1)res*=mul;\n\t\t\tmul*=mul;\n\t\t\tx>>=1;\n\t\t}\n\t\t\
    return res;\n\t}\n\tmint inverse()const{\n\t\treturn pow(MOD-2);\n\t}\n};\n/*\n\
    @brief mod int\n@docs docs/modint.md\n*/\n#line 5 \"test/SegmentTree.test.cpp\"\
    \n\nconstexpr int mod=998244353;\n\nusing modint=mint<mod>;\n \nusing PM=pair<modint,modint>;\n\
    auto f=[](modint a,modint b,int sz)->modint{return a+b;};\nauto g=[](modint a,PM\
    \ b,int sz)->modint{return a*b.first+b.second*modint(sz);};\nauto h=[](PM a,PM\
    \ b,int sz)->PM{return PM(a.first*b.first,a.second*b.first+b.second);};\n \nint\
    \ main(){\n\tcin.tie(0);ios::sync_with_stdio(false);\n\tint N,Q;\n\tcin>>N>>Q;\n\
    \tSegtree<modint,PM,f,g,h>segtree(N,0,PM(1,0));\n\trep(i,N){\n\t\tint a;cin>>a;\n\
    \t\tsegtree.update(i,i+1,PM(1,a));\n\t}\n\twhile(Q--){\n\t\tint t;cin>>t;\n\t\t\
    if(!t){\n\t\t\tint l,r,b,c;cin>>l>>r>>b>>c;\n\t\t\tsegtree.update(l,r,PM(b,c));\n\
    \t\t}else {\n\t\t\tint l,r;cin>>l>>r;\n\t\t\tcout<<segtree.query(l,r)<<\"\\n\"\
    ;\n\t\t}\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n\n#include \"../structure/SegmentTree.cpp\"\n#include \"../math/modint.cpp\"\
    \n\nconstexpr int mod=998244353;\n\nusing modint=mint<mod>;\n \nusing PM=pair<modint,modint>;\n\
    auto f=[](modint a,modint b,int sz)->modint{return a+b;};\nauto g=[](modint a,PM\
    \ b,int sz)->modint{return a*b.first+b.second*modint(sz);};\nauto h=[](PM a,PM\
    \ b,int sz)->PM{return PM(a.first*b.first,a.second*b.first+b.second);};\n \nint\
    \ main(){\n\tcin.tie(0);ios::sync_with_stdio(false);\n\tint N,Q;\n\tcin>>N>>Q;\n\
    \tSegtree<modint,PM,f,g,h>segtree(N,0,PM(1,0));\n\trep(i,N){\n\t\tint a;cin>>a;\n\
    \t\tsegtree.update(i,i+1,PM(1,a));\n\t}\n\twhile(Q--){\n\t\tint t;cin>>t;\n\t\t\
    if(!t){\n\t\t\tint l,r,b,c;cin>>l>>r>>b>>c;\n\t\t\tsegtree.update(l,r,PM(b,c));\n\
    \t\t}else {\n\t\t\tint l,r;cin>>l>>r;\n\t\t\tcout<<segtree.query(l,r)<<\"\\n\"\
    ;\n\t\t}\n\t}\n}"
  dependsOn:
  - structure/SegmentTree.cpp
  - template/template.cpp
  - math/modint.cpp
  isVerificationFile: true
  path: test/SegmentTree.test.cpp
  requiredBy: []
  timestamp: '2020-11-23 14:22:56+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/SegmentTree.test.cpp
layout: document
redirect_from:
- /verify/test/SegmentTree.test.cpp
- /verify/test/SegmentTree.test.cpp.html
title: test/SegmentTree.test.cpp
---