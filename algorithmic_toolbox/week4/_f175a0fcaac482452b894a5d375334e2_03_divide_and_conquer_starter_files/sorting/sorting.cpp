#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <climits>

using std::vector;
using std::swap;

int partition2(vector<int> &a, int l, int r) {
  int x = a[l];
  int j = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);
  return j;
}


void partition3(vector<int> &a, int low, int high, int &i, int &j)
{
    if (high - low <= 1)
    {
        if (a[high] < a[low])
            swap(a[high], a[low]);
        i = low;
        j = high;
        return;
    }

    int mid = low;
    int pivot = a[high];
    while (mid <= high)
    {
        if (a[mid]<pivot)
            swap(a[low++], a[mid++]);
        else if (a[mid]==pivot)
            mid++;
        else if (a[mid]>pivot)
            swap(a[mid], a[high--]);
    }

    i = low-1;
    j = mid;
}


void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }
/*
  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  int m = partition2(a, l, r);

  randomized_quick_sort(a, l, m - 1);
  randomized_quick_sort(a, m + 1, r);*/
  int i,j;
  partition3 (a, l, r, i, j);
  randomized_quick_sort(a,l,i);
  randomized_quick_sort(a,j,r);

}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}
