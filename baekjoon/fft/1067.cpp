#include <bits/stdc++.h>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <random>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>

typedef std::complex<double> cpx;
typedef long long int llint;

void fft(std::vector<cpx> &f, bool inv) {
    int N = f.size();
    // separate odd and even indexes
    for(int i = 1, j = 0; i < N; i++) {
        int bit = (N >> 1);
        while(j >= bit) {
            j -= bit;
            bit >>= 1;
        } j += bit;
        if(i < j) std::swap(f[i], f[j]);
    }

    // euler identity parts
    std::vector<cpx> euler(N/2);
    double x = 2 * acos(-1) / N * (inv ? 1 : -1);
    for(int k = 0; k < N/2; k++)
        euler[k] = cpx(cos(x * k), sin(x * k)); // e^iw = cos(w) + isin(w)

    // FFT
    for(int n = 2; n <= N; n <<= 1) {
        int step = N / n;
        for(int i = 0; i < N; i += n) {
            for(int k = 0; k < n/2; k++) {
                cpx p = f[i+k], q = f[i+k+n/2] * euler[step * k];
                f[i+k] = p + q;
                f[i+k+n/2] = p - q;
            }
        }
    }

    if(inv) for(int i = 0; i < N; i++) f[i] /= N;
}

std::vector<llint> convolution(std::vector<llint> &f, std::vector<llint> &g) {
    std::vector<cpx> cf(f.begin(), f.end());
    std::vector<cpx> cg(g.begin(), g.end());

    int n = 2; while(n < f.size() + g.size()) n <<= 1;
    cf.resize(n); fft(cf, false);
    cg.resize(n); fft(cg, false);

    for(int i = 0; i < n; i++) cf[i] *= cg[i];
    fft(cf, true);

    std::vector<llint> conv(n);
    for(int i = 0; i < n; i++)
        conv[i] = (llint)std::round(cf[i].real());
    return conv;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N;
    std::cin >> N;

    std::vector<llint> a(N*2), b(N);
    for(int i = 0; i < N; i++) { std::cin >> a[i]; a[i+N] = a[i]; }
    for(int i = 1; i <= N; i++) std::cin >> b[N-i];

    std::vector<llint> conv = convolution(a, b);

    llint ans = 0;
    for(llint &x: conv)
        ans = std::max(x, ans);
    std::cout << ans << "\n";

    return 0;
}