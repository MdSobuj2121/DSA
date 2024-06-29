#include<bits/stdc++.h>
using namespace std;
// Basic GCD function
int gcd(int a, int b){
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
// Basic LCM function
int lcm(int a, int b){
    return (a / gcd(a, b)) * b;
}
// Check if a number is prime
bool is_prime(int n){
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}
// Sieve of Eratosthenes to generate primes up to n
vector<bool> sieve(int n){
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return is_prime;
}
int main(){
    int n;
    cin >> n;
    vector<pair<int, int>> p;
    for(int i=0; i<n; i++){
        int x, y;
        cin >> x >> y;
        p.push_back(make_pair(x, y));
    }
    for(auto it: p){
        cout << gcd(it.first, it.second) << "\n";
    }
    return 0;
}