#include <iostream>
#include <cmath>
using namespace std;

int binarySearch(int arr[], int l, int r, int x)
{
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (arr[m] == x)
            return m;
        if (arr[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}


int interpolationSearch(int arr[], int lo, int hi, int x)
{
    int pos;
    if (lo <= hi && x >= arr[lo] && x <= arr[hi]) {
        pos = lo
              + (((double)(hi - lo) / (arr[hi] - arr[lo]))
                 * (x - arr[lo]));
        if (arr[pos] == x)
            return pos;
        if (arr[pos] < x)
            return interpolationSearch(arr, pos + 1, hi, x);
        if (arr[pos] > x)
            return interpolationSearch(arr, lo, pos - 1, x);
    }
    return -1;
}

int searchJump(int* lista, int n, int find) {
    int block = (int)(sqrt(n));
    int index = 0;
    while (lista[min(block, n) - 1] < find) {
    index = block;
    block += (int)(sqrt(n));
    if (index >= n) return -1;
    }
    while (lista[index] < find) {
        index++;
        if (index == min(block, n)) return -1;
    }
      if (lista[index] == find) return index;
      return -1;
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

int linear(int tab[], int n, int key)
{
  for(int i = 0; i < n; i++)
    if(tab[i] == key) return i;

  return -1;
}

int sentinelSearch(int arr[], int n, int key)
{
    int last = arr[n - 1];
    arr[n - 1] = key;
    int i = 0;
    while (arr[i] != key)
        i++;
    arr[n - 1] = last;
    if ((i < n - 1) || (arr[n - 1] == key))
        return i;
    else
        return -1;
}
