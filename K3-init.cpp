// w kompilacji dodac -DLOCAL

#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
template <class T, class U> auto &operator<<(ostream &out, pair<T, U> a) { return out << "(" << a.first << ", " << a.second << ")"; }
template <class T, class = class enable_if<!is_same<T, string>(), class T::iterator>::type> auto &operator<<(ostream &out, T a) {
    out << "{";
    bool fi = 1;
    for(auto b : a) {
        if(fi) {out<<b; fi=0;}
        else out<<", "<<b;
    }
    return out << "}";
}

template <class T, class X, class Y> auto &operator<<(ostream &out, const priority_queue<T,X,Y>& a) {auto b = a; vector<T> v; while(!b.empty()) {v.push_back(b.top()); b.pop();} return out<<v; }
void dump(){
   cerr << "\e[39m"<<"\n";
}
template <class T, class... Ts> void dump(T a, Ts... x) {
   cerr << a << ", ";
   dump(x...);
}
#define debug(...) cerr << "\e[91m"<<__func__<<":"<<__LINE__<<"\t"<<"[" #__VA_ARGS__ "]: ", dump(__VA_ARGS__)
#else
#define debug(...) ;
#endif

template<class C> C reversed(C c) {reverse(c.begin(),c.end()); return c;}
#define rep(i, n) for(int i=0;i<(int)(n);i++)
#define all(X) (X).begin(), (X).end()

typedef long long ll;
typedef pair<int,int> pii;

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}
