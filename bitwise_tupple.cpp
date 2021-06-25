#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
// typedef unsigned ll ull;
// typedef unsigned long long ull;
// typedef double db;
// typedef long double ld;
// typedef pair<ll,ll> PII;
// typedef pair<ll,ll> Pli;
// typedef pair<ll,ll> Pll;
// typedef vector<ll> VI;
// typedef vector<PII> VII;
// #define rep(i,a,b) for(ll i=(ll)a;i<=(ll)b;i++)
// #define per(i,a,b) for(ll i=(ll)a;i>=(ll)b;i--)
// #define REP(i,n) for(ll i=0;i<n;++i)
// #define fi first
// #define se second
// #define mp make_pair
// #define sz(a) (ll)(a).size()
// #define pb push_back 
// #define MOD 1000*1000*1000+7
// vector<long> a[100010];
// bool visited[100010]={false};
// long long ll c[100010];
// #define ll long long;
#define inf 1000000005

//__builtin_clz(x): the number of zeros at the beginning of the bit representation

//__builtin_ctz(x): the number of zeros at the end of the bit representation
 //__builtin_popcount(x): the number of ones in the bit representation
//__builtin_parity(x): the parity (even or odd) of the number of ones in the bit representation

//the following code creates a vector that contains the
//unique elements of the original vector in a sorted order
/*sort(v.begin(),v.end());
v.erase(unique(v.begin(),v.end()),v.end());*/

/*


vector<ll> tree[N];
ll M;
ll up[N][2];
vector<ll> lvl;

void binary_lifting(ll src, ll par) { //fills both level/depth array and up 2d array
    up[src][0] = par;
    for (ll i = 1; i < M; i++) {
        up[src][i] = up[up[src][i - 1]][i - 1];
    }
    for (ll child : tree[src])
        if (child != par) {
            lvl[child] = lvl[src] + 1;
            binary_lifting(child, src);
        }
}

this part as this converting input to input and indexing of int is not possible

ll lca(ll u, ll v) {
    if (u == v)
        return u;
    if (lvl[u] < lvl[v])
        swap(u, v);

    ll dif = lvl[u] - lvl[v];

    for (ll i = M; i >= 0; i--) {
        if ((dif >> i) & 1)
            u = up[u][i];
    }

    if (u == v)
        return u;

    for (ll i = M; i >= 0; i--) {
        if (up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        }
    }
    return up[u][0];
}

*/

/*

struct Matrix
{
    vector< vector<ll> > mat;
    ll n_rows, n_cols;

    Matrix() {}

    Matrix(vector< vector<ll> > values): mat(values), n_rows(values.size()),
        n_cols(values[0].size()) {}

    static Matrix identity_matrix(ll n)
    {
        vector< vector<ll> > values(n, vector<ll>(n, 0));
        for (ll i = 0; i < n; i++)
            values[i][i] = 1;
        return values;
    }

    Matrix operator*(const Matrix &other) const
    {
        ll n = n_rows, m = other.n_cols;
        vector< vector<ll> > result(n_rows, vector<ll>(n_cols, 0));
        for (ll i = 0; i < n; i++)
            for (ll j = 0; j < m; j++) {
                long long tmp = 0;
                for (ll k = 0; k < n_cols; k++) {
                    tmp = (tmp + ((mat[i][k] % mod) * (other.mat[k][j] % mod)) % mod) % mod;
                    while (tmp >= mod)
                        tmp -= mod;
                }
                result[i][j] = tmp % mod;
            }

        return move(Matrix(move(result)));
    }

    inline bool is_square() const
    {
        return n_rows == n_cols;
    }
};

Matrix pw(Matrix a, ll p) {
    Matrix result = Matrix::identity_matrix(a.n_cols);
    while (p > 0) {
        if (p & 1)
            result = a * result;
        a = a * a;
        p >>= 1;
    }
    return result;
}
*/


/*
ll maxSubArraySum(ll a[], ll size) 
{ 
    ll max_so_far = ll_MIN, max_ending_here = 0; 
  
    for (ll i = 0; i < size; i++) 
    { 
        max_ending_here = max_ending_here + a[i]; 
        if (max_so_far < max_ending_here) 
            max_so_far = max_ending_here; 
  
        if (max_ending_here < 0) 
            max_ending_here = 0; 
    } 
    return max_so_far; 
} */



/*void dfs(long x, ll &cst)
{
    visited[x]=1;
    cst=min(cst, c[x]);
    for(long i=0; i<a[x].size(); i++)
    {
        if(!visited[a[x][i]])
        dfs(a[x][i], cst);
    }
} */

/*
ll gcd (ll a, ll b) {
    if (b == 0)
        return a;
    else
        return gcd (b, a % b);
}
*/

/* ll bin_pow(ll x, ll e) {
    if (e == 0) {
        return 1;
    }
    if (e == 1) {
        return x;
    }
    ll y = bin_pow(x, e / 2);
    y = y * y;
    if (e % 2 == 0) {
        return y;
    }
    else {
        return y * x;
    }
} */

ll getSum(ll n){
    ll sum;
    /* Single line that calculates sum */
    for (sum = 0; n > 0; sum += n % 10, n /= 10);
    return sum;
}

ll exponetial(ll exponent , ll base){
    // cout<<exponent<<" "<<base<<"\n";
    ll result = 1;
    while (exponent != 0) {
    result *= base;
    --exponent;
    }
    return result;
}

void MainFunction(){
    ll a , b, c; cin>>a>>b>>c;

    vector<ll >vec;
    for(ll i = 1 ; i<=81; i++){
        // cout<<exponetial(a , i)<<"\n";
        ll  s = b*exponetial(a ,  i) + c;
        if(s>0 && getSum(s) == i){
            vec.push_back(s);
        } 
    }
    cout<<vec.size()<<"\n";
    for(ll i = 0; i<vec.size(); i++){
        cout<<vec[i]<<" ";
    }
    cout<<"\n";

    return ;
}

int main(){
    MainFunction();
}