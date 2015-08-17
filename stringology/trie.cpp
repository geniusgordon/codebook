#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

struct TrieNode {
	TrieNode* to[26];
	bool word;

	TrieNode() {
		word = false;
		memset(to, 0, sizeof(to));
	}
};

struct Trie {
	TrieNode* root;

	Trie () {
		root = new TrieNode();
	}

	~Trie() {
		freeNode(root);
	}

	void freeNode(TrieNode* ptr) {
		for (int i = 0; i < 26; i++) {
			if (ptr->to[i])
				freeNode(ptr->to[i]);
		}
		delete ptr;
	}

	void insert(string& s) {
		TrieNode* ptr = root;
		for (int i = 0; i < s.length(); i++) {
			if (!ptr->to[s[i]-'a'])
				ptr->to[s[i]-'a'] = new TrieNode();
			ptr = ptr->to[s[i]-'a'];
		}
		ptr->word = true;
	}

	bool contain(string& s) {
		TrieNode* ptr = root;
		for (int i = 0; i < s.length(); i++) {
			if (!ptr->to[s[i]-'a'])
				return false;
			ptr = ptr->to[s[i]-'a'];
		}
		return ptr->word;
	}
};

