//ALAN ADAME CSE202 17JAN17
#include <iostream>
#include <vector>

using std::vector;
/*
bool comp_rat (const vector<vector<int> >& vs){
  return (vs[0][0]/vs[0][1] > vs[1][0]/vs[1][1]);
//
}

vector<vector<int> > txform_1d_2d (vector<int> weights, vector<int> values){

  //vector<vector<int> > vec2d(weights.size(),vector <int> (values.size()));
  std::vector< std::vector< double > > vec2d( weights.size(), std::vector< double >( values.size() ) );
    for(int i=0; i<weights.size();i++){
        vec2d[i][i]   = weights[i];
        vec2d[i][i+1] = values[i];

      }

    return sort(vec2d.begin(),vec2d.end(),comp_rat);
}
*/


int get_index_of_max(vector<double> valperweight){
  int max=0;
  for(int i=0; i<valperweight.size();i++){
    if(valperweight[i]>=valperweight[max]) max=i;
  }
  return max;
}

double get_optimal_value(int capacity2, vector<int> weights, vector<int> values) {
  double value = 0.0;
  double capacity = capacity2 * 1.;
  vector<double> valperweight(values.size());

  int maxvalperweight =0;
  for(int i=0; i<valperweight.size();i++){
    valperweight[i] = (values[i]*1.)/(weights[i]*1.);
  }
  //sort(valperweight.begin(),valperweight.end());
  //maxvalperweight = valperweight.size()-1;
  maxvalperweight = get_index_of_max(valperweight);
  double frac = 0.;
  while (capacity > 0 && weights.size()>0 && values.size()>0 ) {
      if (capacity >= weights[maxvalperweight]) {
          capacity -= weights[maxvalperweight];
          value    += values[maxvalperweight];
          weights.erase(weights.begin()+ maxvalperweight);
          values.erase(values.begin()  + maxvalperweight);
          valperweight.erase(valperweight.begin()+ maxvalperweight);
        }
      else {
            frac      = capacity/(weights[maxvalperweight]*1.);
            capacity -= frac * weights[maxvalperweight];
            value    += frac * values[maxvalperweight];
            weights[maxvalperweight] -= frac * (weights[maxvalperweight]* 1.);
            values[maxvalperweight]  -= frac * (values[maxvalperweight]* 1.);
            return value;
       }
       maxvalperweight = get_index_of_max(valperweight);
  }

  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
