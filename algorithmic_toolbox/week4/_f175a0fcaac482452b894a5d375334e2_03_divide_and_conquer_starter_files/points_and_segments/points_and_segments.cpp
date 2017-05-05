#include <iostream>
#include <vector>
#include <math.h>       /* floor */
#include <algorithm>
#include <climits>
#include <cassert>

using std::vector;



struct Segment {
  int start, end;
};

bool compare_start (Segment i,Segment j) { return (i.start < j.start); }
bool compare_end (Segment i,Segment j) { return (i.end < j.end); }

int search_start(vector<Segment> segments, int left, int right, int point) {
        int pos = -1;
        while (left <= right) {
            if (left == right) {
                Segment p = segments[left];
                if (p.start <= point) {pos = left;}
                break;
            }
            int mid = left + (right - left) / 2;
            Segment p = segments[mid];
            if (p.start <= point) {
                pos = mid;
                left = mid + 1;
            } else if (p.start > point) {right = mid;}

        }
        return pos;
}

int search_end(vector<Segment> segments, int left, int right, int point) {
        if (segments.empty()) return -1;

        if (left == right) {return segments[left].end >= point ? left : -1;}

        int mid = left + (right - left) / 2;
        Segment p = segments[mid];

        if (p.end >= point) {return search_end(segments, left, mid, point);}
        else return search_end(segments, mid + 1, right, point);
}


bool seg_compare ( Segment a, Segment b){
  return (a.start < b.start);
}

int binary_search(vector<Segment> &workingSegs,int left, int right, int x) {
//printf("made it\n");
  if (left > right) return  -1;

  int mid = floor(left + (right - left)/2);

  if (x>=workingSegs[mid].start && x<= workingSegs[mid].end) {
    //printf("vec size before: %lu\n",workingSegs.size());
    workingSegs.erase(workingSegs.begin()+mid,workingSegs.begin()+mid+1);
    //printf("vec size after: %lu\n",workingSegs.size());
    return mid;}

  else if (x<workingSegs[mid].start) return binary_search(workingSegs, left,mid-1,x);

  else return binary_search(workingSegs,mid+1, right,x);
}

/*

vector<int> fast_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());
  vector<Segment> segments(starts.size());
  for (int i=0; i<starts.size(); i++){
    segments[i].start=starts[i];
    segments[i].end=ends[i];
  }
  sort(segments.begin(),segments.end(),seg_compare);
  //sort(points.begin(),points.end());
  int i=0;
  int j=0;
  vector<Segment> workingSegs=segments;
  int prev_match=-1;
  int match_index=-1;
  while(i<=points.size()){
        if (points[i]<workingSegs[0].start || points[i]>workingSegs[workingSegs.size()-1].end) {
          workingSegs=segments;
          i++;}
        else if(binary_search(workingSegs, 0 ,workingSegs.size()-1, points[i])!=-1)
            cnt[i]++;
        else {
          workingSegs=segments;
          i++;
          }
  }
  return cnt;
}

*/

//using both segment searches
vector<int> fast_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
    vector<int> cnt(points.size());
    vector<Segment> segments(starts.size());
    for (size_t i = 0; i < segments.size(); ++i) {
        segments[i].start = starts[i];
        segments[i].end = ends[i];
    }
    sort(segments.begin(), segments.end(), compare_start);
    for (int i = 0; i < points.size(); i++) {
        int pos = search_start(segments, 0, segments.size() - 1, points[i]);
        if (pos != -1) {
            vector<Segment> head(pos+1);
            for(size_t i = 0; i < pos+1; ++i) {
                head[i].start = segments[i].start;
                head[i].end = segments[i].end;
            }
            sort(segments.begin(), segments.end(), compare_end);
            pos = search_end(head, 0, head.size() - 1, points[i]);
            int c = pos != -1 ? head.size() - pos : 0;
            cnt[i] = c;
        }
        else cnt[i] = 0;
    }
    return cnt;
}

vector<int> naive_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());
  for (size_t i = 0; i < points.size(); i++) {
    for (size_t j = 0; j < starts.size(); j++) {
      cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
    }
  }
  return cnt;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<int> starts(n), ends(n);
  for (size_t i = 0; i < starts.size(); i++) {
    std::cin >> starts[i] >> ends[i];
  }
  vector<int> points(m);
  for (size_t i = 0; i < points.size(); i++) {
    std::cin >> points[i];
  }
  //use fast_count_segments
  vector<int> cnt = fast_count_segments(starts, ends, points);
  for (size_t i = 0; i < cnt.size(); i++) {
    std::cout << cnt[i] << ' ';
  }
}
