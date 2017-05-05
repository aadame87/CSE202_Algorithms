#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int const Letters =    4;
int const NA      =   -1;

struct Node
{
	int next [Letters];
	bool patternEnd;

	Node ()
	{
		fill (next, next + Letters, NA);
		patternEnd = false;
	}
};

typedef vector<Node> trie;

int letterToIndex (char letter)
{
	switch (letter)
	{
		case 'A': return 0; break;
		case 'C': return 1; break;
		case 'G': return 2; break;
		case 'T': return 3; break;
		default: assert (false); return -1;
	}
}

trie build_trie(const vector<string> & patterns) {
  trie t;
  Node root;
  t.push_back(root);
  for(const string& p : patterns){
  	size_t current_node = 0;
  	for(size_t i = 0; i < p.length(); ++i){
  		size_t next_i = letterToIndex(p[i]);
  		if(t[current_node].next[next_i] != NA)
  			current_node = t[current_node].next[next_i];
  		else{
  			Node tmp;
  			t.push_back(tmp);
  			t[current_node].next[next_i] = t.size()-1;
  			current_node = t[current_node].next[next_i];
  		}
  	}
  	t[current_node].patternEnd = true;
  }
  return t;
}

vector <int> solve (const string& text, int n, const vector <string>& patterns)
{
	vector <int> result;
  trie t = build_trie(patterns);

	// write your code here
	for(size_t i = 0; i < text.length(); ++i){
	size_t current_node = 0;
	size_t current_symbol = i;
	while(true){
		if(t[current_node].patternEnd){
			result.push_back(i);
			break;
		}
		else if(current_symbol < text.length() and t[current_node].next[letterToIndex(text[current_symbol])] != NA){
			current_node = t[current_node].next[letterToIndex(text[current_symbol])];
			current_symbol++;}
		else
			break;
	}
}

	return result;
}

int main (void)
{
	string text;
	cin >> text;

	int n;
	cin >> n;

	vector <string> patterns (n);
	for (int i = 0; i < n; i++)
	{
		cin >> patterns[i];
	}

	vector <int> ans;
	ans = solve (text, n, patterns);

	for (int i = 0; i < (int) ans.size (); i++)
	{
		cout << ans[i];
		if (i + 1 < (int) ans.size ())
		{
			cout << " ";
		}
		else
		{
			cout << endl;
		}
	}

	return 0;
}
