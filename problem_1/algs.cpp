#include "algs.hpp"

using namespace std;

static const int N = 1000;

alg1IOType* fast_search(alg1IOType * input) {
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

alg1IOType* fast_merge(alg1IOType * input) {
    int i, p, q, proot, qroot, id[N];
    for (i = 0; i < N; i++) id[i] = i;
    alg1IOType* output = new alg1IOType();
    for (std::pair<int, int> pq : *input) {
        p = pq.first;
        q = pq.second;
        for (proot = p; id[proot] != proot; proot = id[proot]);
        for (qroot = q; id[qroot] != qroot; qroot = id[qroot]);
        if (proot != qroot) {
            output->push_back(std::pair<int, int>(p, q));
            id[proot] = qroot;
        }
    }
    return output;
}

alg1IOType* weighed_fast_merge(alg1IOType * input) {
    int i, p, q, proot, qroot, id[N], sz[N];
    for (i = 0; i < N; i++) {
        id[i] = i;
        sz[1] = 1;
    }
    alg1IOType* output = new alg1IOType();
    for (std::pair<int, int> pq : *input) {
        p = pq.first;
        q = pq.second;
        for (proot = p; id[proot] != proot; proot = id[proot]);
        for (qroot = q; id[qroot] != qroot; qroot = id[qroot]);
        if (proot != qroot) {
            output->push_back(std::pair<int, int>(p, q));
            if (sz[proot] < sz[qroot]) {
                id[proot] = qroot;
                sz[proot] += sz[qroot];
            } else {
                id[qroot] = proot;
                sz[qroot] += sz[proot];
            }
            
        }
    }
    return output;
}

alg1IOType* weighed_fast_merge_with_path_compresion(alg1IOType * input) {
    int i, p, q, proot, qroot, id[N], sz[N];
    for (i = 0; i < N; i++) {
        id[i] = i;
        sz[1] = 1;
    }
    alg1IOType* output = new alg1IOType();
    for (std::pair<int, int> pq : *input) {
        p = pq.first;
        q = pq.second;
        for (proot = p; id[proot] != proot; proot = id[proot])
            id[proot] = id[id[proot]];
        for (qroot = q; id[qroot] != qroot; qroot = id[qroot])
            id[qroot] = id[id[qroot]];
        if (proot != qroot) {
            output->push_back(std::pair<int, int>(p, q));
            if (sz[proot] < sz[qroot]) {
                id[proot] = qroot;
                sz[proot] += sz[qroot];
            } else {
                id[qroot] = proot;
                sz[qroot] += sz[proot];
            }
            
        }
    }
    return output;
}