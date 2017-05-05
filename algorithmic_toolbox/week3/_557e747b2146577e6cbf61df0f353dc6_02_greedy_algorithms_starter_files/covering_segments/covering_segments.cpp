//ALAN ADAME CSE202 19JAN17
#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment {
  int start, end;
};

bool seg_compare ( Segment a, Segment b){

  return (a.end < b.end);
}

vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;
  sort(segments.begin(),segments.end(),seg_compare);
  int optInt=0;
  int xi=0;
  while (optInt< segments.size()) {
      points.push_back(segments[optInt].end);
      xi=segments[optInt].end;
      optInt++;
      while (optInt < segments.size() && xi >= segments[optInt].start && xi <= segments[optInt].end)
       {optInt++;}

  }
/*
  for (size_t i = 0; i < segments.size(); ++i) {
    points.push_back(segments[i].start);
    points.push_back(segments[i].end);
  }*/
  return points;
}


int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
