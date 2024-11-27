#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

int main() {
    int n,x;
    cin >> n >> x;
    int* arr =  new int[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int cant = 0, start = 0, end = 0, sum = 0;
    while(end < n){
        while(end < n && sum < x){
            sum += arr[end];
            end++;
        }
        while(start <= end && sum > x){
            sum -= arr[start];
            start++;
        }
        if(sum == x){
            cant++;
            sum -= arr[start];
            start++;
        }
    }
    cout << cant;
    return 0;
}