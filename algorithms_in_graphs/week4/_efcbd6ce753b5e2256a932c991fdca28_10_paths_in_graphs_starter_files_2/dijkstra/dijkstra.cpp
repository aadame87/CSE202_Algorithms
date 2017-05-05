#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using std::vector;
using std::queue;
using std::pair;
using std::priority_queue;
using std::numeric_limits;

const int inf = numeric_limits<int>::max();

struct Node {
  int index, distance;
  Node(int a = 0, int b = 0): index(a), distance(b) {}
};

struct cmp {
	bool operator()(Node u, Node v){
		return u.distance > v.distance;
	}
};
int distance(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, int t) {
  //write your code her
  vector<int> dist(adj.size(), inf);
  dist[s] = 0;
  priority_queue<Node, vector<Node>, cmp> pq;
  pq.push(Node(s, dist[s]));

  Node u;
  int u_index,v;
  while(!pq.empty()) {
	u = pq.top();
	pq.pop();
	u_index = u.index;
    for (int i = 0; i < adj[u_index].size(); i++) {
	     v = adj[u_index][i];
	      if(dist[v] > dist[u_index] + cost[u_index][i]) {
	         dist[v] = dist[u_index] + cost[u_index][i];
           pq.push(Node(v, dist[v]));
	        }
	  }
  }
  if(dist[t] == inf) return -1;

  return dist[t];
  //return -1;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, cost, s, t);
}
