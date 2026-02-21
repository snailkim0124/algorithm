#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

struct Node {
	int data;
	Node* left;
	Node* right;
	
	Node(int val) : data(val), left(NULL), right(NULL) {}
};

int n, k;
string order;
set<string> s;

Node* insert(Node* root, int val) {
	if (root == NULL) return new Node(val);

	if (val < root->data) {
		root->left = insert(root->left, val);
	}
	else if (val > root->data) {
		root->right = insert(root->right, val);
	}

	return root;
}

void inorder(Node* root) {
	if (root != NULL) {
		inorder(root->left);
		cout << root->data << " ";
		inorder(root->right);
	}
}

void postorder(Node* root) {
	if (root != NULL) {
		postorder(root->left);
		postorder(root->right);
		//cout << root->data << " ";
		order += root->data + '0';
	}
}

void preorder(Node* root) {
	if (root != NULL) {
		cout << root->data << " ";
		preorder(root->left);
		preorder(root->right);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		vector<ll> tmp;
		map<ll, ll> mp;
		for (int j = 0; j < k; j++) {
			ll num;
			cin >> num;
			tmp.push_back(num);
		}

		// 좌표 압축
		vector<ll> tmp2 = tmp;
		sort(all(tmp2));
		ll idx = 0;
		for (int j = 0; j < tmp2.size(); j++) {
			mp[tmp2[j]] = ++idx;
		}

		for (int j = 0; j < tmp.size(); j++) {
			tmp[j] = mp[tmp[j]];
		}

		Node* root = NULL;
		for (auto it : tmp) {
			root = insert(root, it);
		}

		/*cout << "inorder : ";
		inorder(root);
		cout << "\n";

		cout << "postorder : ";
		postorder(root);
		cout << "\n";

		cout << "preorder : ";
		preorder(root);
		cout << "\n";
		cout << "============\n";*/

		postorder(root);
		s.insert(order);
		order = "";
	}

	cout << s.size() << "\n";

	//for (auto it : v) {
	//	for (auto it2 : it) {
	//		cout << it2 << " ";
	//	}
	//	cout << "\n";
	//}

	
	
	return 0;
}