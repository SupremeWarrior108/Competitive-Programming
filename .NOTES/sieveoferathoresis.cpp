#include <iostream>
#include <vector>
using namespace std;

// Function to perform the Sieve of Eratosthenes
void sieveOfEratosthenes(int n) {
    // Step 1: Create a boolean vector `isPrime` of size (n+1)
    // Initialize all elements as true, indicating all numbers are potentially prime
    vector<bool> isPrime(n + 1, true);

    // Step 2: Set `isPrime[0]` and `isPrime[1]` to false as 0 and 1 are not prime numbers
    isPrime[0] = isPrime[1] = false;

    // Step 3: Start iterating from 2 to sqrt(n) (as any composite number up to n will have a factor <= sqrt(n))
    for (int p = 2; p * p <= n; p++) {
        // Step 4: Check if `p` is marked as prime
        if (isPrime[p]) {
            // Step 5: Mark all multiples of `p` (p*p, p*p + p, p*p + 2p, ...) as not prime
            for (int multiple = p * p; multiple <= n; multiple += p) {
                isPrime[multiple] = false;
            }
        }
    }

    // Step 6: Output all primes up to n
    cout << "Prime numbers up to " << n << " are: ";
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            cout << i << " ";
        }
    }
    cout << endl;
}

// Main function to run the sieve
int main() {
    int n;
    cout << "Enter the number up to which you want primes: ";
    cin >> n;
    
    // Call the sieve function
    sieveOfEratosthenes(n);

    return 0;
}
