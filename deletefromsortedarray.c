#include <stdio.h>
int main() {
    int n, x;
    scanf("%d", &n);
    int arr[100];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    scanf("%d", &x);
    int pos = -1, i;
    for(i=0; i<n; i++) {
        if(arr[i] == x) {
            pos = i;
            break;
        }
    }
    if(pos == -1) {
        for(i=0; i<n; i++) printf("%d ", arr[i]);
        return 0;
    }
    for(i=pos; i<n-1; i++) arr[i] = arr[i+1];
    n--;
    for(i=0; i<n; i++) printf("%d ", arr[i]);
    return 0;
}

