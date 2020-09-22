---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template/template.cpp
    title: template/template.cpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/Combination.cpp
    title: Combination (nCk)
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/Combination.test.cpp
    title: test/Combination.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    _deprecated_at_docs: docs/modint.md
    document_title: mod int
    links: []
  bundledCode: "#line 2 \"template/template.cpp\"\n#include<bits/stdc++.h>\n#pragma\
    \ GCC optimization (\"Ofast\")\n#pragma GCC optimization (\"unroll-loops\")\n\
    using namespace std;\n#define int long long\n#define rep(i,n) for(int i=0;i<n;i++)\n\
    #define REP(i,n) for(int i=1;i<n;i++)\n#define rev(i,n) for(int i=n-1;i>=0;i--)\n\
    #define all(v) v.begin(),v.end()\n#define P pair<int,int>\n#define len(s) (int)s.size()\n\
    \ \ntemplate<class T> inline bool chmin(T &a, T b){\n\tif(a>b){a=b;return true;}\n\
    \treturn false;\n}\ntemplate<class T> inline bool chmax(T &a, T b){\n\tif(a<b){a=b;return\
    \ true;}\n\treturn false;\n}\nconstexpr int mod = 1e9+7;\nconstexpr long long\
    \ inf = 3e18;\n#line 3 \"math/modint.cpp\"\n\ntemplate<int MOD>\nstruct mint{\n\
    \tint32_t n;\n\tmint():n(0){}\n\tmint(int x):n(x>=0?x%MOD:(MOD-(-x)%MOD)%MOD){}\n\
    \n\tmint &operator+=(const mint &p){\n\t\tif((n+=p.n)>=MOD)n-=MOD;\n\t\treturn\
    \ *this;\n\t}\n\tmint &operator-=(const mint &p){\n\t\tif((n+=MOD-p.n)>=MOD)n-=MOD;\n\
    \t\treturn *this;\n\t}\n\tmint &operator*=(const mint &p){\n\t\tn=1ll*n*p.n%MOD;\n\
    \t\treturn *this;\n\t}\n\tmint &operator/=(const mint &p){\n\t\t*this*=p.inverse();\n\
    \t\treturn *this;\n\t}\n\tmint operator-()const{return mint(-n);}\n\tmint operator+(const\
    \ mint &p)const{return mint(*this)+=p;}\n\tmint operator-(const mint &p)const{return\
    \ mint(*this)-=p;}\n\tmint operator*(const mint &p)const{return mint(*this)*=p;}\n\
    \tmint operator/(const mint &p)const{return mint(*this)/=p;}\n\tbool operator==(const\
    \ mint &p)const{return n==p.n;}\n\tbool operator!=(const mint &p)const{return\
    \ n!=p.n;}\n\n\tfriend ostream &operator<<(ostream &os,const mint &p){\n\t\treturn\
    \ os<<p.n;\n\t}\n\tfriend istream &operator>>(istream &is,mint &p){\n\t\tint x;is>>x;\n\
    \t\tp=mint(x);\n\t\treturn is;\n\t}\n\tmint pow(int64_t x)const{\n\t\tmint res(1),mul(n);\n\
    \t\twhile(x>0){\n\t\t\tif(x&1)res*=mul;\n\t\t\tmul*=mul;\n\t\t\tx>>=1;\n\t\t}\n\
    \t\treturn res;\n\t}\n\tmint inverse()const{\n\t\treturn pow(MOD-2);\n\t}\n};\n\
    /*\n@brief mod int\n@docs docs/modint.md\n*/\n"
  code: "#pragma once\n#include \"../template/template.cpp\"\n\ntemplate<int MOD>\n\
    struct mint{\n\tint32_t n;\n\tmint():n(0){}\n\tmint(int x):n(x>=0?x%MOD:(MOD-(-x)%MOD)%MOD){}\n\
    \n\tmint &operator+=(const mint &p){\n\t\tif((n+=p.n)>=MOD)n-=MOD;\n\t\treturn\
    \ *this;\n\t}\n\tmint &operator-=(const mint &p){\n\t\tif((n+=MOD-p.n)>=MOD)n-=MOD;\n\
    \t\treturn *this;\n\t}\n\tmint &operator*=(const mint &p){\n\t\tn=1ll*n*p.n%MOD;\n\
    \t\treturn *this;\n\t}\n\tmint &operator/=(const mint &p){\n\t\t*this*=p.inverse();\n\
    \t\treturn *this;\n\t}\n\tmint operator-()const{return mint(-n);}\n\tmint operator+(const\
    \ mint &p)const{return mint(*this)+=p;}\n\tmint operator-(const mint &p)const{return\
    \ mint(*this)-=p;}\n\tmint operator*(const mint &p)const{return mint(*this)*=p;}\n\
    \tmint operator/(const mint &p)const{return mint(*this)/=p;}\n\tbool operator==(const\
    \ mint &p)const{return n==p.n;}\n\tbool operator!=(const mint &p)const{return\
    \ n!=p.n;}\n\n\tfriend ostream &operator<<(ostream &os,const mint &p){\n\t\treturn\
    \ os<<p.n;\n\t}\n\tfriend istream &operator>>(istream &is,mint &p){\n\t\tint x;is>>x;\n\
    \t\tp=mint(x);\n\t\treturn is;\n\t}\n\tmint pow(int64_t x)const{\n\t\tmint res(1),mul(n);\n\
    \t\twhile(x>0){\n\t\t\tif(x&1)res*=mul;\n\t\t\tmul*=mul;\n\t\t\tx>>=1;\n\t\t}\n\
    \t\treturn res;\n\t}\n\tmint inverse()const{\n\t\treturn pow(MOD-2);\n\t}\n};\n\
    /*\n@brief mod int\n@docs docs/modint.md\n*/"
  dependsOn:
  - template/template.cpp
  isVerificationFile: false
  path: math/modint.cpp
  requiredBy:
  - math/Combination.cpp
  timestamp: '2020-09-23 07:35:54+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/Combination.test.cpp
documentation_of: math/modint.cpp
layout: document
redirect_from:
- /library/math/modint.cpp
- /library/math/modint.cpp.html
title: mod int
---
## 概要

演算で全て mod を取る整数型。mod の除算などで何も考えないで済む。

- 四則演算 , 代入 ( +, -, \*, /, +=, -=, \*=, /=)
- ```pow(x)``` : ```x``` 乗
- ```inverse()``` : mod上の逆元

## 計算量

- 除算 : $O(log\ mod)$
- ```pow(x)``` : $O(log\ n)$
- ```inverse()``` : $O(log\ mod)$
- その他 : $O(1)$