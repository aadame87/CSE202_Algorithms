//Alan Adame cse202 23 jan17
#include <algorithm>
#include <iostream>
#include <vector>
#include <math.h>       /* floor */

using std::vector;

int get_freq(vector<int> &a, int left, int right, int key){

  int count =0;
  for(int i=left;i<=right;i++){
      if (a[i]==key) count++;
  }
  return count;

}

int get_majority_element(vector<int> &a, int left, int right) {

  //if (left == right) return -1;
  //if (left + 1 == right) return a[left];
  if (left > right) return -1;
  if (left == right) return a[left];
  int mid = left+(right-left)/2;

  int l = get_majority_element(a,left,mid);
  int r = get_majority_element(a,mid+1,right);
  int freq;
  if (r>=0 && l <0){
    freq=get_freq(a, left, right, r);
    if (freq>(right-left+1)/2) return r;
    else return -1;
  }
  else if (r<0 && l>=0){
    freq=get_freq(a, left, right, l);
    if (freq>(right-left+1)/2) return l;
    else return -1;
  }
  else if (r>=0 && l>=0) {
    int freq2;
    freq=get_freq(a, left, right, r);
    freq2=get_freq(a, left, right, l);
    if (freq>(right-left+1)/2) return r;
    else if (freq2>(right-left+1)/2) return l;
    else return -1;
  }
  else return -1;



  //printf("%d\n",l);
  //printf("%d\n",r);

  /*
  if (l==r) return l;

  int count =0;
  for(int i=0;i<a.size();i++){
      if (a[i]==l) count++;
  }
  if (count>(mid+1)) return l;

  count =0;
  for(int i=0;i<a.size();i++){
      if (a[i]==r) count++;
  }
  if (count>(mid+1)) return r;
*/
/*
  int temp=0,count=0;
  for (int i=left;i<mid;i++){
      if (i==left) {
        temp = a[i];
        count=1; }
      else if (temp ==a[i]) count++;
      else count--;
  }
  if (count> mid/2) return 1;
    for (int i=mid+1;i<right;i++){
        if (i==mid+1) {
          temp = a[i];
          count=1; }
        else if (temp ==a[i]) count++;
        else count--;
      }
    if (count>mid/2) return 1;
    else return -1;

  }*/
   //return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  //sort(a.begin(),a.end());
  std::cout << (get_majority_element(a, 0, a.size()-1) != -1) << '\n';
}
