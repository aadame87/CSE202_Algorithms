#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>       /* floor */

using std::vector;
/*
bool inv_compare (int a, int b){

  return (a > b);
}

long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right) {
  long long number_of_inversions = 0;
  if (right <= left + 1) return number_of_inversions;
  size_t ave = left + (right - left) / 2;
  number_of_inversions += get_number_of_inversions(a, b, left, ave);
  number_of_inversions += get_number_of_inversions(a, b, ave, right);

  //write your code here
  //number_of_inversions+=merge(a,b,left,ave+1,right);
  return number_of_inversions;
}
*/
//long long mergeSort2(vector<long long> a,  vector<long long> b, long long left, long long right);
//long long merge(vector<long long> a, vector<long long> b, long long left, long long mid, long long right);

/*long long mergeSort2(vector<long long> a, vector<long long> b, long long left, long long right)
{
  long long mid=0;
  long long inv_count = 0;
  if (right > left)
  {
    mid = left+ (right - left)/2;
    inv_count  = mergeSort2(a, b, left, mid);
    inv_count += mergeSort2(a, b, mid+1, right);
    inv_count += merge(a, b, left, mid+1, right);
  }
  return inv_count;
}
*/
/*
long long merge(vector<long long> a, vector<long long> b, long long left, long long mid, long long right)
{
  long long i, j, k;
  long long inv_count = 0;

  i = left;
  j = mid;
  k = left;

  while ((i <= mid - 1) && (j <= right))
  {
    if (a[i] <= a[j])
    {
      //b[k++] = a[i++];
      k++;
      i++;
    }
    else
    {
      //b[k++] = a[j++];
      k++;
      j++;
      inv_count += (mid - i);
    }
  }

  //while (i <= mid - 1) {b[k++] = a[i++];}
  //while (j <= right) {b[k++] = a[j++];}
  //for (i=left; i <= right; i++) {a[i] = b[i];}

  return inv_count;
}
*/
long long merge(vector<int> &a, vector<int> &b, size_t left, size_t mid, size_t right) {
	    size_t i = left, j = mid, k = left;
        long long count = 0;
        while (i <= mid -1 && j <= right) {
            if (a[i] <= a[j]) {
                b[k] = a[i];
				i++;
				k++;
            } else {
                b[k] = a[j];
				count += mid - i;
				j++;
				k++;
            }
        }
        while (i <= mid - 1) {
            b[k] = a[i];
            i++;
            k++;
        }
        while (j <= right) {
            b[k] = a[j];
            j++;
            k++;
        }
		for (i=left; i <= right; i++)
			a[i] = b[i];
        return count;
}

long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right) {
  long long number_of_inversions = 0;
  if (right <= left) return number_of_inversions;
  size_t mid = left + (right - left) / 2;
  number_of_inversions += get_number_of_inversions(a, b, left, mid);
  number_of_inversions += get_number_of_inversions(a, b, mid+1, right);
  number_of_inversions += merge(a, b, left, mid+1, right);
  return number_of_inversions;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  vector<int> b(a.size());
  std::cout << get_number_of_inversions(a, b, 0, a.size()-1) << '\n';
}

/*
int main() {
  long long n;
  std::cin >> n;
  vector<long long> a(n);
  for (long long i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  vector<long long> b(a.size());
  std::cout << mergeSort2(a, b, 0, a.size()-1) << '\n';
}
*/
