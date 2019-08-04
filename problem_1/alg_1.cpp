#include "algs.hpp"

using namespace std;

static const int N = 1000;

alg1IOType* alg_1(alg1IOType * input) {
    int i, p, q, id[N];
    for (i = 0; i < N; i++) id[i] = i;
    alg1IOType* output = new alg1IOType();
    for (std::pair<int, int> pq : *input) {
        p = pq.first;
        q = pq.second;
        int t = id[p];
        if (t != id[q]) {
            output->push_back(std::pair<int, int>(p, q));
            for (int i = 0; i < N; i++) if (id[i] == t) id[i] = id[q];
        }
    }
    return output;
}