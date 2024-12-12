#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int disks = 2 * n;
    string* arr = new string[disks];
    
    for (int i = 0; i < disks; i++) {
        if (i % 2 == 0) {
            arr[i] = "White";
        }
        else {
            arr[i] = "Black";
        }
    }
     cout << "arr before loop: ";
     for (int i = 0; i < disks; i++) {
            cout << arr[i] << " ";
     }
     cout << endl;


    for (int j = 0; j < disks; j++) {
        while (j <disks-1 &&arr[j] == "Black" && arr[j+1] == "White") {
            swap(arr[j], arr[j + 1]);
            cout << "arr after swapping: ";
            for (int i = 0; i < disks; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
            if (j > 0) {
                j--;
            }
        }
        
    }
    cout << "arr after loop: ";
    for (int i = 0; i < disks; i++) {
        cout << arr[i] << " ";
    }
}
