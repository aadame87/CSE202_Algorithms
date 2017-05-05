#include <ios>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <utility>
#include <functional>

using namespace std;

struct Edge {
    int from;
    int to;
};

struct ConvertGSMNetworkProblemToSat {
    int numVertices;
    int numEdges;
    int max_freq=3;
    //vector<Edge> edges;
    vector<pair<int,int> > edges;

    ConvertGSMNetworkProblemToSat(int n, int m) :
        numVertices(n),
        numEdges(m)
    {  }

    vector<vector<int> > generate_freqs(){
      vector<vector<int> > freqs(numVertices, vector<int>(3,0));
      for (int i=0; i <numVertices; ++i){
          for(int j = 0; j<max_freq; ++j){

            freqs[i][j] = i*max_freq+j+1;

          }
        return freqs;
      }

    }

    void printEquisatisfiableSatFormula() {
        // This solution prints a simple satisfiable formula
        // and passes about half of the tests.
        // Change this function to solve the problem.
        //cout << "3 2" << endl;
        //cout << "1 2 0" << endl;
        //cout << "-1 -2 0" << endl;
        //cout << "1 -2 0" << endl;

        vector<vector<int> > freqs=generate_freqs();

        cout<<3*numEdges+4*numVertices<<" "<<3*numVertices<<endl;
        for (int i=0;i<numVertices;++i){
          cout << freqs[i][0]<<" " <<freqs[i][1]<< " "<<freqs[i][2]<<" 0"<<  endl;
          cout <<  -freqs[i][0]<< " "<<-freqs[i][1]<<" 0"<< endl;
          cout << -freqs[i][1] << " " << -freqs[i][2] << " 0" << endl;
          cout << -freqs[i][2] << " " << -freqs[i][0] << " 0" << endl;
          cout << "1 -2 0" << endl;

        }
        /*
        for(auto p : edges){
            for(int j = 0; j < 3; ++j){
            cout << -freqs[p.first][j] << " " << -freqs[p.second][j] << " 0" << endl;
          }
        }
        */
    }
};

int main() {
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    ConvertGSMNetworkProblemToSat converter(n, m);
    for (int i = 0; i < m; ++i) {
        int from, to;
        //cin >> converter.edges[i].from >> converter.edges[i].to;
        cin>>from >> to;
        auto p = std::make_pair(from-1,to-1);
        converter.edges.push_back(p);
    }

    converter.printEquisatisfiableSatFormula();

    return 0;
}
