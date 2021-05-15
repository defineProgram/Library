---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: string/SuffixArray.cpp
    title: Suffix Array (SA-IS)
  - icon: ':question:'
    path: template/template.cpp
    title: template/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/suffixarray
    links:
    - https://judge.yosupo.jp/problem/suffixarray
  bundledCode: "#line 1 \"test/SuffixArray.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/suffixarray\"\
    \n\n#line 2 \"template/template.cpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n#define ll long long\n#define rep(i, n) for (int i = 0; i < n; i++)\n\
    #define REP(i, n) for (int i = 1; i < n; i++)\n#define rev(i, n) for (int i =\
    \ n - 1; i >= 0; i--)\n#define REV(i, n) for (int i = n - 1; i > 0; i--)\n#define\
    \ all(v) v.begin(), v.end()\n#define PL pair<ll, ll>\n#define PI pair<int,int>\n\
    #define len(s) (int)s.size()\n\ntemplate <class T, class U>\ninline bool chmin(T\
    \ &a, U b) {\n    if (a > b) {\n        a = b;\n        return true;\n    }\n\
    \    return false;\n}\ntemplate <class T, class U>\ninline bool chmax(T &a, U\
    \ b) {\n    if (a < b) {\n        a = b;\n        return true;\n    }\n    return\
    \ false;\n}\nconstexpr ll inf = 3e18;\n#line 3 \"string/SuffixArray.cpp\"\n\n\
    template <class T>\nclass SuffixArray {\n#define typeS make_pair(false, false)\n\
    #define LMS make_pair(false, true)\n#define typeL make_pair(true, true)\n    using\
    \ TYPE = pair<bool, bool>;\n    vector<TYPE> assignType(vector<ll> &S) {\n   \
    \     vector<TYPE> type(len(S));\n        type[len(S) - 1] = LMS;\n        for\
    \ (ll i = len(S) - 2; i >= 0; i--) {\n            if (S[i] < S[i + 1])\n     \
    \           type[i] = typeS;\n            else if (S[i] > S[i + 1]) {\n      \
    \          type[i] = typeL;\n                if (type[i + 1] == typeS) type[i\
    \ + 1] = LMS;\n            } else\n                type[i] = type[i + 1];\n  \
    \      }\n        return type;\n    }\n    vector<ll> getBucket(vector<ll> &S,\
    \ ll alph) {\n        vector<ll> bucket(alph);\n        for (ll i : S) bucket[i]++;\n\
    \        rep(i, len(bucket) - 1) bucket[i + 1] += bucket[i];\n        return bucket;\n\
    \    }\n    void sortTypeL(vector<ll> &S, vector<ll> &SA, vector<TYPE> &type,\
    \ ll alph) {\n        vector<ll> bucket = getBucket(S, alph);\n        for (ll\
    \ i : SA) {\n            if (i > 0 && type[i - 1] == typeL) SA[bucket[S[i - 1]\
    \ - 1]++] = i - 1;\n        }\n    }\n    void sortTypeS(vector<ll> &S, vector<ll>\
    \ &SA, vector<TYPE> &type, ll alph) {\n        vector<ll> bucket = getBucket(S,\
    \ alph);\n        rev(j, len(S)) {\n            ll i = SA[j];\n            if\
    \ (i > 0 && (type[i - 1] == typeS || type[i - 1] == LMS)) SA[--bucket[S[i - 1]]]\
    \ = i - 1;\n        }\n    }\n    vector<ll> InducedSorting(vector<ll> &S, ll\
    \ alph) {\n        vector<ll> SA(len(S), -1);\n        vector<TYPE> type = assignType(S);\n\
    \        vector<ll> bucket = getBucket(S, alph);\n        vector<ll> nextlms(len(S),\
    \ -1), ordered_lms;\n        ll lastlms = -1;\n        rep(i, len(S)) if (type[i]\
    \ == LMS) {\n            SA[--bucket[S[i]]] = i;\n            if (lastlms != -1)\
    \ nextlms[lastlms] = i;\n            lastlms = i;\n            ordered_lms.emplace_back(i);\n\
    \        }\n        nextlms[lastlms] = lastlms;\n        sortTypeL(S, SA, type,\
    \ alph);\n        sortTypeS(S, SA, type, alph);\n        vector<ll> lmses;\n \
    \       for (ll i : SA)\n            if (type[i] == LMS) lmses.emplace_back(i);\n\
    \        ll nowrank = 0;\n        vector<ll> newS = {0};\n        REP(i, len(lmses))\
    \ {\n            ll pre = lmses[i - 1], now = lmses[i];\n            if (nextlms[pre]\
    \ - pre != nextlms[now] - now)\n                newS.emplace_back(++nowrank);\n\
    \            else {\n                bool flag = false;\n                rep(j,\
    \ nextlms[pre] - pre + 1) {\n                    if (S[pre + j] != S[now + j])\
    \ {\n                        flag = true;\n                        break;\n  \
    \                  }\n                }\n                if (flag)\n         \
    \           newS.emplace_back(++nowrank);\n                else\n            \
    \        newS.emplace_back(nowrank);\n            }\n        }\n        if (nowrank\
    \ + 1 != len(lmses)) {\n            vector<ll> V(len(S), -1);\n            rep(i,\
    \ len(lmses)) {\n                V[lmses[i]] = newS[i];\n            }\n     \
    \       vector<ll> newnewS;\n            rep(i, len(S)) if (V[i] != -1) newnewS.emplace_back(V[i]);\n\
    \            vector<ll> SA_ = InducedSorting(newnewS, nowrank + 1);\n        \
    \    rep(i, len(SA_)) {\n                lmses[i] = ordered_lms[SA_[i]];\n   \
    \         }\n        }\n        SA.assign(len(S), -1);\n        bucket = getBucket(S,\
    \ alph);\n        rev(i, len(lmses)) {\n            SA[--bucket[S[lmses[i]]]]\
    \ = lmses[i];\n        }\n        sortTypeL(S, SA, type, alph);\n        sortTypeS(S,\
    \ SA, type, alph);\n        return SA;\n    }\n    vector<ll> SA;\n    T ST;\n\
    \n   private:\n    ll ismatch(T &S, ll index) {\n        rep(i, len(S)) {\n  \
    \          if (i + index >= len(ST)) return 1;\n            if (ST[i + index]\
    \ < S[i]) return 1;\n            if (ST[i + index] > S[i]) return -1;\n      \
    \  }\n        return 0;\n    }\n\n   public:\n    PL occ(T &S) {\n        ll okl\
    \ = len(ST) + 1, ngl = 0;\n        while (okl - ngl > 1) {\n            ll mid\
    \ = (okl + ngl) / 2;\n            if (ismatch(S, SA[mid]) <= 0)\n            \
    \    okl = mid;\n            else\n                ngl = mid;\n        }\n   \
    \     ll okr = len(ST) + 1, ngr = 0;\n        while (okr - ngr > 1) {\n      \
    \      ll mid = (okr + ngr) / 2;\n            if (ismatch(S, SA[mid]) < 0)\n \
    \               okr = mid;\n            else\n                ngr = mid;\n   \
    \     }\n        return PL(okl, okr);\n    }\n    vector<ll> locate(T &S) {\n\
    \        vector<bool> v(len(ST) + 1);\n        PL range = occ(S);\n        for\
    \ (ll i = range.first; i < range.second; i++) v[SA[i]] = true;\n        vector<ll>\
    \ res;\n        rep(i, len(ST) + 1) if (v[i]) res.emplace_back(i);\n        return\
    \ res;\n    }\n    ll operator[](ll k) { return SA[k]; }\n\n   public:\n    vector<ll>\
    \ LCP;\n\n   private:\n    void constructLCP() {\n        vector<ll> rank(len(ST)\
    \ + 1);\n        LCP.resize(len(ST) + 1);\n        rep(i, len(ST) + 1) rank[SA[i]]\
    \ = i;\n        ll h = 0;\n        rep(i, len(ST)) {\n            ll j = SA[rank[i]\
    \ - 1];\n            if (h > 0) h--;\n            for (j; j + h < len(ST) && i\
    \ + h < len(ST); h++) {\n                if (ST[j + h] != ST[i + h]) break;\n\
    \            }\n            LCP[rank[i] - 1] = h;\n        }\n    }\n\n   public:\n\
    \    SuffixArray(T S) : ST(S) {\n        ll mn = inf, mx = -inf;\n        for\
    \ (auto i : S) {\n            chmin(mn, (ll)i);\n            chmax(mx, (ll)i);\n\
    \        }\n        vector<ll> newS;\n        for (auto i : S) newS.emplace_back(i\
    \ - mn + 1);\n        newS.emplace_back(0);\n        SA = InducedSorting(newS,\
    \ mx - mn + 2);\n        constructLCP();\n    }\n};\n\n/*\n@brief Suffix Array\
    \ (SA-IS)\n@docs docs/SuffixArray.md\n*/\n#line 4 \"test/SuffixArray.test.cpp\"\
    \n\nint main(){\n    string s;cin>>s;\n    SuffixArray<string>SA(s);\n    REP(i,len(s)+1)cout<<SA[i]<<\"\
    \ \";cout<<\"\\n\";\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/suffixarray\"\n\n#include\
    \ \"../string/SuffixArray.cpp\"\n\nint main(){\n    string s;cin>>s;\n    SuffixArray<string>SA(s);\n\
    \    REP(i,len(s)+1)cout<<SA[i]<<\" \";cout<<\"\\n\";\n}"
  dependsOn:
  - string/SuffixArray.cpp
  - template/template.cpp
  isVerificationFile: true
  path: test/SuffixArray.test.cpp
  requiredBy: []
  timestamp: '2021-05-15 13:43:26+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/SuffixArray.test.cpp
layout: document
redirect_from:
- /verify/test/SuffixArray.test.cpp
- /verify/test/SuffixArray.test.cpp.html
title: test/SuffixArray.test.cpp
---