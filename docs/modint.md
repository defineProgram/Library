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