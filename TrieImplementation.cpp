#include<bits/stdc++.h>
#define IOS  ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef long long ll;
using namespace std;
struct TrieNode{
	map<char, TrieNode*> child;
	bool isEndWord;
	TrieNode() {
		isEndWord = false;	
	}
};

void insert(TrieNode* node, string s){
	TrieNode* curr = node;
	for(int i = 0; i < s.size(); i++) {
		if(curr->child.find(s[i]) == curr->child.end()) curr->child[s[i]] = new TrieNode();
		curr = curr->child[s[i]];
	}
	curr->isEndWord = true;
}

bool search(TrieNode* node, string s){
	TrieNode* curr = node;
	for(int i = 0; i < s.size(); i++) {
		if(curr->child.find(s[i]) == curr->child.end()) return false;
		curr = curr->child[s[i]];
	}
	return curr->isEndWord;
}

void solve() {
	ll nodes, namesToSearch;
	cin >> nodes;
	string str;
	TrieNode* root = new TrieNode();
	for(int i = 0; i < nodes; i++){
		cin>>str;
		insert(root, str);
	}
	cin >> namesToSearch;
	for(int i = 0; i < namesToSearch; i++) {
		cin >> str;
		if(search(root, str)) cout << "String found" << endl;
    else cout << "String not found" << endl;
	}
    return ;     
}

int main()
{
	IOS
    ll t=1;
//    cin>>t;
    while(t--) {
	 solve();	
	}
    return 0;
}
