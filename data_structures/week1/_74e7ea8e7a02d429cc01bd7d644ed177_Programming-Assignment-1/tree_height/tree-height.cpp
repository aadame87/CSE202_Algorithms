#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <vector>


class Node
{
public:
  Node( int v )
    : key( v )
    , children()
  {
  }

  Node( const Node &n )
    : key( n.key )
    , children( n.children )
  {
  }

  void add_child( int key ) { children.push_back(key); }

  int size() const { return children.size(); }

  int key;
  std::vector< int > children;
};
/*

#if defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#endif

class Node;

class Node {
public:
    int key;
    Node *parent;
    std::vector<Node *> children;

    Node() {
      this->parent = NULL;
    }

    void setParent(Node *theParent) {
      parent = theParent;
      parent->children.push_back(this);
    }
};


int main_with_large_stack_space() {
  std::ios_base::sync_with_stdio(0);
  long long n;
  std::cin >> n;

  //std::vector<Node> nodes;
  std::vector<long long> nodes;
  nodes.resize(n);
  std::fill(nodes.begin(), nodes.end(), 0);
  for (long long child_index = 0; child_index < n; child_index++) {
    long long parent_index;
    std::cin >> parent_index;
    if (parent_index >= 0) nodes[parent_index]++;
      //nodes[child_index].setParent(&nodes[parent_index]);
    //nodes[child_index].key = child_index;
  }
  long long maxHeight2=nodes.size()-1;
  for (long long i = 0; i < n; i++) {
      if (nodes[i]>1) maxHeight2-=nodes[i]-1;
      //nodes[child_index].setParent(&nodes[parent_index]);
    //nodes[child_index].key = child_index;
  }
/*
  // Replace this code with a faster implementation
  int maxHeight = 0;
  for (int leaf_index = 0; leaf_index < n; leaf_index++) {
    int height = 0;
    for (Node *v = &nodes[leaf_index]; v != NULL; v = v->parent)
      height++;
    maxHeight = std::max(maxHeight, height);
  }
*//*
  if (n%2>0)
    std::cout << maxHeight2+1 << std::endl;
  else std::cout<< maxHeight2<<std::endl;

  return 0;
}

int main (int argc, char **argv)
{
#if defined(__unix__) || defined(__APPLE__)
  // Allow larger stack space
  const rlim_t kStackSize = 16 * 1024 * 1024;   // min stack size = 16 MB
  struct rlimit rl;
  int result;

  result = getrlimit(RLIMIT_STACK, &rl);
  if (result == 0)
  {
      if (rl.rlim_cur < kStackSize)
      {
          rl.rlim_cur = kStackSize;
          result = setrlimit(RLIMIT_STACK, &rl);
          if (result != 0)
          {
              std::cerr << "setrlimit returned result = " << result << std::endl;
          }
      }
  }

#endif
  return main_with_large_stack_space();
}
*/

class TreeHeight
{
  int n;
  std::vector< int > parent;
  std::map< int, Node * > nodes;
  Node *node;

public:
  ~TreeHeight()
  {
    for ( const auto &n : nodes )
    {
      delete n.second;
    }
  }

  void read()
  {
    std::cin >> n;
    parent.resize( n );
    for ( int i = 0; i < n; i++ )
      {
        std::cin >> parent[ i ];
      }
  }

  int compute_height()
  {
    construct_tree();
    return max_depth( node );
  }

private:
  int max_depth( Node *n )
  {
    if ( n == nullptr ) return 0;

    if ( n->size() == 0 ) return 1;

    int max = 0;
    int curr_max_depth;
    for ( int i = 0; i < n->size(); ++i )
    {
      curr_max_depth = max_depth( nodes[n->children[i]] );
      if ( curr_max_depth > max ) max = curr_max_depth;
    }
    return max + 1;
  }

  void construct_tree()
  {
    for ( int i = 0; i < n; ++i )
    {
      nodes[ i ] = new Node( i );
    }
    int p;
    for ( int i = 0; i < n; ++i )
    {
      p = parent[ i ];
      if ( p != -1 ) nodes[ p ]->add_child( i );
      else node = nodes[ i ];
    }
  }
};

int main()
{
  std::ios_base::sync_with_stdio( 0 );
  TreeHeight tree;
  tree.read();
  std::cout << tree.compute_height() << std::endl;
  return 0;
}
