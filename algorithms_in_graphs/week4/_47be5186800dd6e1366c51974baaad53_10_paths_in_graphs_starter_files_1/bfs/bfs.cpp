#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits>
#include <unordered_map>


using std::vector;
using std::queue;

int distance(vector<vector<int> > &adj, int s, int t) {
  //write your code here

  std::unordered_map< int, int > dist;
  std::unordered_map< int, int > prev;

  for ( size_t i = 0; i < adj.size(); ++i )
  {
    dist[ i ] = std::numeric_limits< int >::infinity();
    prev[ i ] = -1;
  }

  queue< int > q;

  q.push( s );
  dist[ s ] = 0;

  while ( !q.empty() )
  {
    auto u = q.front();
    q.pop();
    const auto &es = adj[ u ];

    for ( auto e : es )
    {
      if ( dist[ e ] == std::numeric_limits< int >::infinity() )
      {
        q.push( e );
        dist[ e ] = dist[ u ] + 1;
        prev[ e ] = u;
      }
    }
  }

  if ( prev[ t ] == -1 )
    return -1;

  vector< int > result;

  while ( t != s )
  {
    result.push_back( t );
    t = prev[ t ];
  }

  std::reverse( result.begin(), result.end() );

  return result.empty() ? -1 : result.size();
  //return -1;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, s, t);
}
