#include <bits/stdc++.h>
using namespace std;
 
// Segment tree for range maximum queries, plus functions to "jump" to 
// the rightmost (or leftmost) index in a given range where the value is at least X.
 
struct SegTree {
    int n;
    vector<int> tree;
    
    SegTree(int n_) : n(n_) {
        tree.resize(4*n, 0);
    }
    
    // Build the tree over arr[0..n-1]
    void build(vector<int> &arr, int idx, int l, int r){
        if(l == r){
            tree[idx] = arr[l];
            return;
        }
        int mid = (l+r)/2;
        build(arr, idx*2, l, mid);
        build(arr, idx*2+1, mid+1, r);
        tree[idx] = max(tree[idx*2], tree[idx*2+1]);
    }
    
    // Standard range maximum query.
    int query(int idx, int l, int r, int ql, int qr){
        if(ql > r || qr < l) return -1; // values are positive so -1 is safe.
        if(ql <= l && r <= qr) return tree[idx];
        int mid = (l+r)/2;
        int leftVal = query(idx*2, l, mid, ql, qr);
        int rightVal = query(idx*2+1, mid+1, r, ql, qr);
        return max(leftVal, rightVal);
    }
    
    // Find the rightmost index in [ql,qr] with value >= val.
    int findRightmost(int idx, int l, int r, int ql, int qr, int val){
        if(ql > r || qr < l) return -1;
        if(ql <= l && r <= qr){
            if(tree[idx] < val) return -1;
            if(l == r) return l;
            int mid = (l+r)/2;
            int rightAns = findRightmost(idx*2+1, mid+1, r, ql, qr, val);
            if(rightAns != -1) return rightAns;
            return findRightmost(idx*2, l, mid, ql, qr, val);
        }
        int mid = (l+r)/2;
        int rightAns = findRightmost(idx*2+1, mid+1, r, ql, qr, val);
        if(rightAns != -1) return rightAns;
        return findRightmost(idx*2, l, mid, ql, qr, val);
    }
    
    // Find the leftmost index in [ql,qr] with value >= val.
    int findLeftmost(int idx, int l, int r, int ql, int qr, int val){
        if(ql > r || qr < l) return -1;
        if(ql <= l && r <= qr){
            if(tree[idx] < val) return -1;
            if(l == r) return l;
            int mid = (l+r)/2;
            int leftAns = findLeftmost(idx*2, l, mid, ql, qr, val);
            if(leftAns != -1) return leftAns;
            return findLeftmost(idx*2+1, mid+1, r, ql, qr, val);
        }
        int leftAns = findLeftmost(idx*2, l, (l+r)/2, ql, qr, val);
        if(leftAns != -1) return leftAns;
        return findLeftmost(idx*2+1, (l+r)/2+1, r, ql, qr, val);
    }
};
 
// Global variables used by the check function.
int N, K;
vector<int> arr;  // the input array
int Lreq; // required subsequence length = N - K
 
// Given a candidate peak (an index in arr) that we want to use as the peak (and it must satisfy arr[i]>=p),
// we “simulate” a greedy process on the left of the peak. (We want to “jump backwards” and count how many 
// elements (from indices < peak) we can pick so that the element chosen 1st (closest to the peak) is at least p-1, 
// the 2nd (further left) is at least p-2, etc.)
int getLeftCount(int peak, int p, SegTree &st) {
    int cnt = 0;
    int pos = peak - 1;
    while(pos >= 0) {
        int req = p - (cnt + 1);
        // When req <= 1 every element qualifies.
        if(req <= 1) {
            cnt += (pos + 1);
            break;
        }
        int maxVal = st.query(1, 0, N-1, 0, pos);
        if(maxVal < req) break;
        int j = st.findRightmost(1, 0, N-1, 0, pos, req);
        if(j == -1) break;
        cnt++;
        pos = j - 1;
    }
    return cnt;
}
 
// Similarly, simulate greedy “jump–forward” for the right side.
int getRightCount(int peak, int p, SegTree &st) {
    int cnt = 0;
    int pos = peak + 1;
    while(pos < N) {
        int req = p - (cnt + 1);
        if(req <= 1) {
            cnt += (N - pos);
            break;
        }
        int maxVal = st.query(1, 0, N-1, pos, N-1);
        if(maxVal < req) break;
        int j = st.findLeftmost(1, 0, N-1, pos, N-1, req);
        if(j == -1) break;
        cnt++;
        pos = j + 1;
    }
    return cnt;
}
 
// Given a candidate p, check whether it is possible (by removing at most K elements)
// to obtain a subsequence of length Lreq that is p-towering.
bool checkP(int p, SegTree &st) {
    // try every candidate peak index (which must have arr[i]>=p)
    for (int i = 0; i < N; i++){
        if(arr[i] < p) continue;
        int leftC = getLeftCount(i, p, st);
        int rightC = getRightCount(i, p, st);
        if(leftC + 1 + rightC >= Lreq) return true;
    }
    return false;
}
 
// --- main solution function for one test case ---
 
void solveCase() {
    cin >> N >> K;
    arr.resize(N);
    int mx = 0;
    for (int i = 0; i < N; i++){
        cin >> arr[i];
        mx = max(mx, arr[i]);
    }
    Lreq = N - K;
    // Build the segment tree on arr.
    SegTree st(N);
    st.build(arr, 1, 0, N-1);
 
    // Binary search for the maximum p (p can be at most max(arr)).
    int lo = 1, hi = mx, ans = 1;
    while(lo <= hi){
        int mid = (lo + hi) / 2;
        if(checkP(mid, st)){
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    cout << ans << "\n";
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
    while(t--){
        solveCase();
    }
    return 0;
}
