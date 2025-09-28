#include <stdio.h>
int main() {
    int n, x;
    scanf("%d", &n);
    int arr[100];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    scanf("%d", &x);
    int i;
    for(i = n-1; (i >= 0 && arr[i] > x); i--) {
        arr[i+1] = arr[i];
    }
    arr[i+1] = x;
    n++;
    for(i=0; i<n; i++) printf("%d ", arr[i]);
    return 0;
}


