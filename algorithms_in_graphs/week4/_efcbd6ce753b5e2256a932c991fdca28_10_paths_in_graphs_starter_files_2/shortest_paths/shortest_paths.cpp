#include <iostream>
#include <limits>
#include <vector>
#include <queue>

using std::vector;
using std::queue;
using std::pair;
using std::priority_queue;
using std::numeric_limits;

void shortest_paths(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, vector<long long> &distance, vector<int> &reachable, vector<int> &shortest) {
  //write your code here
  vector<int> negative_set;
  	reachable[s] = 1;
  	distance[s] = 0;
    int current_index,next_index;
  	for (int i = 0; i < adj.size(); i++)
  	{
  		for (int j = 0; j < adj.size(); j++)
  		{
  			current_index = j;
  			if (distance[current_index]
  					!= numeric_limits<long long>::max())
  			{
  				for (int k = 0; k < adj[j].size(); k++)
  				{
  					next_index = adj[j][k];
  					if (distance[next_index]
  							> distance[current_index] + cost[current_index][k])
  					{
  						if (i == adj.size() - 1)
  						{
  							negative_set.push_back(next_index);
  						}
  						distance[next_index] = distance[current_index]
  								+ cost[current_index][k];
  						reachable[next_index] = 1;
  					}
  				}
  			}

  		}
  	}
    int node_index,current_node,adjNode;
  	for (int i = 0; i < negative_set.size(); i++)
  	{
  		node_index = negative_set[i];
  		if (shortest[node_index])
  		{
  			queue<int> visiting_queue;
  			visiting_queue.push(node_index);
  			while (!visiting_queue.empty())
  			{
  				current_node = visiting_queue.front();
  				shortest[current_node] = 0;
  				visiting_queue.pop();
  				for (int i = 0; i < adj[current_node].size(); i++)
  				{
  					adjNode = adj[current_node][i];
  					if (shortest[adjNode])
  					{
  						visiting_queue.push(adjNode);
  						shortest[adjNode] = 0;
  					}
  				}
  			}
  		}

  	}

}

int main() {
  int n, m, s;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  std::cin >> s;
  s--;
  vector<long long> distance(n, std::numeric_limits<long long>::max());
  vector<int> reachable(n, 0);
  vector<int> shortest(n, 1);
  shortest_paths(adj, cost, s, distance, reachable, shortest);
  for (int i = 0; i < n; i++) {
    if (!reachable[i]) {
      std::cout << "*\n";
    } else if (!shortest[i]) {
      std::cout << "-\n";
    } else {
      std::cout << distance[i] << "\n";
    }
  }
}
