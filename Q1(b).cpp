#include <iostream>
using namespace std;
int main() {
    while (true) {
    int n;

    cout << "Enter a positive integer: ";
    cin >> n;

    cout << "Factors of " << n << ": ";

    for (int i = 1; i <= n; ++i) {
        if (n % i == 0) {
            cout << i << " ";
        }
    }
        cout<<endl;
    
        cout << "1. Continue" << endl;
        cout << "2. Quit" << endl;
        
    int choice;
        cout << "Enter your choice (1 or 2): ";
        cin >> choice;

        if (choice == 1) {
            cout << "Continuing..." << endl;
        } else if (choice == 2) {
            cout << "Quitting..." << endl;
            break;  
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
