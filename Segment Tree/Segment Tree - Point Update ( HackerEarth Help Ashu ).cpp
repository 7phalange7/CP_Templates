/*
    Author      : SHIVAM SAHU
    Institution : IIT PATNA
    Country     : INDIA
*/

#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;

// PRAGMA reduces execution time a little
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("O3")
#pragma GCC target ("avx")

// The typedef is used to give data type a new name
// #define in C is a directive which is used to #define alias(shortcuts)
typedef long long ll;
typedef long double ld;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

#define f(i,n)          for(int i=0;i<n;i++)
#define F(i,a,n)        for(int i=a;i<n;i++)
#define fo(i,a,b)       for(int i=a;i<=b;i++)
#define arrin(a,n)      for(int i=0;i<n;i++)cin>>a[i]
#define arrout(a,n)     for(int i=0;i<n;i++)cout<<a[i]<<" "
#define print2d(a,n,m)  for(int i=0;i<n;i++){for(int j=0;j<m;j++)cout<<a[i][j]<<" ";cout<<"\n";}
#define w(x)            int x; cin>>x; while(x--)

#define ff              first
#define ss              second
#define int             long long
#define double          long double
#define eb              emplace_back
#define pb              push_back
#define pf              push_front
#define popb            pop_back
#define popf            pop_front
#define mp              make_pair
#define rt              return
#define br              break
#define ct              continue
#define elif            else if

#define dbg             cout<<"\nhuehue\n"
#define sayy            cout<<"YES\n"
#define sayn            cout<<"NO\n"
#define debug(a)        cerr << #a << ": " << a << endl


#define pii             pair<int,int>  // ( p.first , p.second )
#define pss             pair<string,string>

#define mii             map<int,int> // ( insert(key,value), begin(), end(), size(), empty() )
#define mci             map<char, int>
#define msi             map<string, int>
#define mss             map<string, string>
#define umii            unordered_map<int,int>
// Itertating over a map m ==>> for( auto i : m ){ cout<<i.first<<" "<<i.second<<endl; }

#define vi              vector<int>  // ( size(), resize(), begin(), end(), empty() )
#define vb              vector<bool>
#define vii             vector<pair<int,int>>
#define vvi             vector<vector<int>>

#define si              set<int>  // stores in ascending order // ( insert(), size(), empty(), begin(), end() )
#define sid             set<int, greater<int> >  // stores in descending order
#define sii             set<pair<int,int>>

#define li              list <int> // ( pb(), pf(), popb(), popf(), reverse(), sort(), empty(), size(),
//  remove(), front(), back() insert() )

#define maxheap         priority_queue<int>  // by default, max heap ( push(), pop(), top(), empty(), size() )
#define minheap         priority_queue<int,vi,greater<int>>  // min heap ( push(), pop(), top(), empty(), size() )


#define setbits(x)      __builtin_popcountll(x) // return the count of set bits
#define startzeroes(x)  __builtin_clzll(x) //return the count the leading zeros of the integer(clz=count leading zero’s)
#define endzeroes(x)    __builtin_ctzll(x) // used to count the trailing zeros of the given integer(ctz = count trailing zeros)

#define ps(x,y)         fixed<<setprecision(y)<<x  // (always prefer double) works with float and double..ps(x,y)=x with y digits after decimal
#define dma(a,n,type)   type *a=new type[n];  // dynamic memory allocation (Example : type*a = new int[n]; )

const int inf   = numeric_limits<int>::max();
const double pi = 3.1415926535898;
const int mod   = 1000000007;
const int lim   = 1000006;

#define all(v)          v.begin(),v.end()
#define sum(v)          accumulate(v.begin(),v.end(),(ll)0)
#define asum(a,n)       accumulate(a,a+n,(ll)0)
#define rev(v)          reverse(v.begin(),v.end());
//  stoi() function - converts string to integer ( Example- int x = stoi(s) )
//  stoll() funtion - converts string to long long ( Example- long long x = stoll(s) )
//  to_string() function - converts integer to string ( Example- string s = to_string(x) )


void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
}

// lim = 10*6, array for taking input
int a[lim];

// Array for storing the Segment Tree ( odd, even )
// size should be 4*n, so making it of 4 * 10^6+
pair<int, int> segtree[4 * lim];

// These 3 parameters are always there in any Segment Tree function
// s_ind = segment index
// ss = segment start
// se = segment end

// qs = query start
// qe = qeuery end
// qi = query index


// Function to make the segment tree array before processing queries
void build(int s_ind, int ss, int se) {

    // when segment has only 1 element
    if (ss == se) {

        if (a[ss] % 2 == 1)
            segtree[s_ind] = {1, 0};
        else
            segtree[s_ind] = {0, 1};

        return;
    }

    int mid = (ss + se) / 2;

    // left subtree
    build(2 * s_ind, ss, mid);

    // right subtree
    build(2 * s_ind + 1, mid + 1, se);

    // getting the result from left subtree and right subtree
    segtree[s_ind].first = segtree[2 * s_ind].first + segtree[2 * s_ind + 1].first;
    segtree[s_ind].second = segtree[2 * s_ind].second + segtree[2 * s_ind + 1].second;


}

// Function for point update a value at index qi with value val - O(log(N))
void update(int s_ind, int ss, int se, int qi, int val) {

    // case of leaf node
    if (ss == se) {

        if (val % 2 == 1)
            segtree[s_ind] = {1, 0};
        else
            segtree[s_ind] = {0, 1};

        // updating the value in the input array also
        a[qi] = val;
        return;
    }

    int mid = (ss + se) / 2;

    // if index qi ( which to be updated ) lies in the left subtree, else call for the right subtree
    if (qi <= mid)
        update(2 * s_ind, ss, mid, qi, val);
    else
        update(2 * s_ind + 1, mid + 1, se, qi, val);

    // updating the segment tree after the update has been done
    segtree[s_ind].first = segtree[2 * s_ind].first + segtree[2 * s_ind + 1].first;
    segtree[s_ind].second = segtree[2 * s_ind].second + segtree[2 * s_ind + 1].second;

    return;

}


// Function to answer a query in O(logN) time ( brute force takes O(N) to process a single query )
int query(int s_ind, int ss, int se, int qs, int qe, int q_type) {

    // completely outside
    if (qs > se or qe < ss)
        return 0;

    // completely inside
    if (ss >= qs and se <= qe) {
        if (q_type == 1)
            return segtree[s_ind].second;
        else
            return segtree[s_ind].first;
    }

    int mid = (ss + se) / 2;

    // getting the result from the left subtree and right subtree and return the sum
    return (query(2 * s_ind, ss, mid, qs, qe, q_type) + query((2 * s_ind) + 1, mid + 1, se, qs, qe, q_type));

}


int32_t main()
{

    fio;
    int n;
    cin >> n;

    fo(i, 1, n)
    cin >> a[i];

    // Building the segment tree array
    build(1, 1, n);

    // number of queries
    int q;
    cin >> q;
    while (q--) {

        int type;
        cin >> type;

        if (type == 0) {
            int i, x;
            cin >> i >> x;

            // if replacing even number with even or replacing odd number with odd, then no effect on result
            if (a[i] % 2 == x % 2)
                continue;
            else
                update(1, 1, n, i, x);

        }
        else
        {
            int qs, qe;
            cin >> qs >> qe;
            cout << query(1, 1, n, qs, qe, type) << endl;

        }

    }

}
