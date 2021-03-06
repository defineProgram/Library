#pragma once
#include "../template/template.cpp"
#include "math/extgcd.cpp"

template <int MOD>
struct mint {
    int32_t n;
    mint() : n(0) {}
    mint(ll x) : n(x >= 0 ? x % MOD : (MOD - (-x) % MOD) % MOD) {}

    mint &operator+=(const mint &p) {
        if ((n += p.n) >= MOD) n -= MOD;
        return *this;
    }
    mint &operator-=(const mint &p) {
        if ((n += MOD - p.n) >= MOD) n -= MOD;
        return *this;
    }
    mint &operator*=(const mint &p) {
        n = 1ll * n * p.n % MOD;
        return *this;
    }
    mint &operator/=(const mint &p) {
        *this *= p.inverse();
        return *this;
    }
    mint operator-() const { return mint(-n); }
    mint operator+(const mint &p) const { return mint(*this) += p; }
    mint operator-(const mint &p) const { return mint(*this) -= p; }
    mint operator*(const mint &p) const { return mint(*this) *= p; }
    mint operator/(const mint &p) const { return mint(*this) /= p; }
    bool operator==(const mint &p) const { return n == p.n; }
    bool operator!=(const mint &p) const { return n != p.n; }

    friend ostream &operator<<(ostream &os, const mint &p) {
        return os << p.n;
    }
    friend istream &operator>>(istream &is, mint &p) {
        int x;
        is >> x;
        p = mint(x);
        return is;
    }
    mint pow(int64_t x) const {
        mint res(1), mul(n);
        while (x > 0) {
            if (x & 1) res *= mul;
            mul *= mul;
            x >>= 1;
        }
        return res;
    }
    mint inverse() const {
        return mint(modinv(n,MOD));
    }
};
/*
@brief mod int
@docs docs/modint.md
*/