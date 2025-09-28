#include <stdio.h>
int binarySearch(int arr[], int l, int r, int x) {
    while(l <= r) {
        int mid = l + (r - l) / 2;
        if(arr[mid] == x) return mid;
        if(arr[mid] < x) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}
int main() {
    int n, x;
    scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    scanf("%d", &x);
    int res = binarySearch(arr, 0, n-1, x);
    printf("%d\n", res);
    return 0;
}


