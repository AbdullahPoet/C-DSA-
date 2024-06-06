#include<bits/stdc++.h>

using namespace std;
using ll = long long;
#define endl "\n"


void build(int ind, int low, int high, int arr[], int seg[]) {
	if (low == high) {
		seg[ind] = arr[low];
		return;
	}

	int mid = (low + high) >> 1;
	build(2 * ind + 1, low, mid, arr, seg);
	build(2 * ind + 2, mid + 1, high, arr, seg);
	seg[ind] = max(seg[2 * ind + 1], seg[2 * ind + 2]);
}

int query(int ind, int low, int high, int l, int r, int seg[]) {
	// [l r low high]
	// [low high l r]
	if (r < low or l > high) return INT_MIN;

	// [l low high r]
	if (l <= low and r >= high) return seg[ind];

	// [low l high]
	// [low h high]
	int mid = (low + high) >> 1;
	int left_ = query(2 * ind + 1, low, mid, l, r, seg);
	int right_ =  query(2 * ind + 2, mid + 1, high, l, r, seg);
	return max(left_, right_);
}

void update(int ind, int low, int high, int i, int val, int seg[]) {
	if (low == high) {
		seg[ind] = val;
		return;
	}

	int mid = (low + high) >> 1;
	if (i <= mid) update(ind * 2 + 1, low, mid, i, val, seg);
	else update(ind * 2 + 2, mid + 1, high, i, val, seg);
	seg[ind] = max(seg[ind * 2 + 1], seg[ind * 2 + 2]);
}

int32_t main() {
	int n; cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int seg[4 * n];
	build(0, 0, n - 1, arr, seg);

	int q; cin >> q;
	while (q--) {
		int t; cin >> t;
		if (t == 1) {
			int l, r; cin >> l >> r;
			if (l > r) continue;
			cout << query(0, 0, n - 1, l, r, seg) << endl;
		}
		else {
			int i, val; cin >> i >> val;
			if (i >= n) continue;
			update(0, 0, n - 1, i, val, seg);
			arr[i] = val;
		}
	}
}

