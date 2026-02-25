#include <iostream>
using namespace std;

// Function to find survivor position
int josephus(int n, int k) {
    int result = 0;   // Base case for n = 1

    for (int i = 2; i <= n; i++) {
        result = (result + k) % i;
    }

    return result + 1;   // Convert from 0-based to 1-based indexing
}

int main() {
    int n, k;

    cout << "Enter number of people (n): ";
    cin >> n;

    cout << "Enter step count (k): ";
    cin >> k;

    int survivor = josephus(n, k);

    cout << "The survivor is at position: " << survivor << endl;

    return 0;
}