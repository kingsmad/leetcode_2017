/*************************************************************************
    > File Name: uva11402.cpp
    > Author: grinch.Lopedz
    > Mail: grinchcoder@gmail.com 
 ************************************************************************/

#include <cstdio>
#include <cstring>
#include <algorithm>

#define lc (o<<1)
#define rc (o<<1|1)
using namespace std;
const int maxn = 1024010;
const int INF = 1000000000;

int s[maxn];

int qL, qR, uV, _sum, op;
struct IntervalTree {
    int setv[maxn*3], addv[maxn*3], sumv[maxn*3];

    void init() {
        memset(setv, -1, sizeof(setv));
        memset(addv, 0, sizeof(addv));
        memset(sumv, 0, sizeof(sumv));
    }

    void build(int o, int L, int R) {
        if (L == R) {
            setv[o] = sumv[o] = s[L];
            addv[o] = 0;
            return;
        }
        int M = (L+R) /2;
        build(lc, L, M);
        build(rc, M+1, R);
        maintain(o, L, R);
    }

    void query(int o, int L, int R, int add) {
        if (setv[o] >= 0) {
            // if setv[o], the information of node o is sufficient.
            //int v = setv[o]; if (add^addv[o]) v = 0; last bug here!
            int v = setv[o]; if (add^addv[o]) v = 1^v;
            _sum += v * (min(R, qR) - max(L, qL)+1);
        } else if (qL <= L && qR >= R) {
            // The interval is a sub-interval of [qL, qR]
            // Hence, we use the node information
            // In addtion, we assume node o is maintained.
            int v = sumv[o]; if (add) v = R-L+1-v;
            _sum += v;
        } else {
            /*Only a fragment of the interval of node o can be used
             * So we should divide it*/
            int M = (L+R) / 2;
            if (qL <= M) query(lc, L, M, add ^ addv[o]);
            if (qR > M ) query(rc, M+1, R, add ^ addv[o]);
        }
    }

    void update(int o, int L, int R) {
        if (qL <= L && qR >= R) {
            if (op == 1) addv[o] ^= uV;
            else {setv[o] = uV; addv[o] = 0;}
        } else {
            pushdown(o);
            int M = (R+L) / 2;
            if (qL <= M) update(lc, L, M); else maintain(lc, L, M);
            if (qR > M) update(rc, M+1, R); else maintain(rc, M+1, R);
        }
        maintain(o, L, R);
    }

    /*Flags like setv && addv can not be cleared once sumv is updated.
     * The reason is that children will lose information if flags were cleared*/
    void pushdown(int o) {
        if (setv[o] >= 0) {
            setv[lc] = setv[rc] = setv[o];
            addv[lc] = addv[rc] = 0;
            setv[o] = -1;
        }
        if (addv[o]) {
            addv[lc] ^= addv[o];
            addv[rc] ^= addv[o];
            addv[o] = 0;
        }
    }

    /*Excluding build(), This is the only method in which sumv can be changed*/
    // Semantics => when setv and addv is decided, maintain information
    void maintain(int o, int L, int R) {
        if (R > L)
            sumv[o] = sumv[lc] + sumv[rc];
        if (setv[o] >= 0) { sumv[o] = setv[o] * (R-L+1);}
        if (addv[o]) { sumv[o] = R-L+1 - sumv[o];}
    }
};

IntervalTree tree;

char str[100];
int main(int argc, char** argv) {
    //freopen("dats/uva11402.txt", "r", stdin);
    int T, n, cnt, m;
    scanf("%d\n", &T);
    for(int kase=1; kase<=T; ++kase) {
        printf("Case %d:\n", kase);
        scanf("%d\n", &n);
        cnt = 0;
        while(n--) {
            scanf("%d\n", &m);
            scanf("%s\n", str);
            int len = strlen(str);
            while(m--){
                for(int i=0; i<len; ++i) 
                    s[cnt++] = str[i] - '0';
            }
        }
        tree.init();
        tree.build(1, 0, cnt-1);
        int q, qn=1; scanf("%d\n", &q);
        while(q--) {
            char c; scanf("%c %d %d\n", &c, &qL, &qR);
            if (c == 'F') { op = 2; uV = 1; tree.update(1, 0, cnt-1); }
            if (c == 'E') { op = 2; uV = 0; tree.update(1, 0, cnt-1); }
            if (c == 'I') { op = 1; uV = 1; tree.update(1, 0, cnt-1); }
            if (c == 'S') {
                _sum = 0; tree.query(1, 0, cnt-1, 0); 
                printf("Q%d: %d\n", qn++, _sum);
            }
        }
    }
    return 0;
}
