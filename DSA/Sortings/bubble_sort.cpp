// BRUTE
class BubbleSort {
public:
    void bubble_sort(vector<int>& arr) {
        int n = arr.size();
        for (int i = n - 1; i >= 0; i--) {  //Use two nested loops to iterate over the array
            for (int j = 0; j <= i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]); //Swap arr[i] with arr[j+1]
                }
            }
        }
        cout << "After Using Bubble Sort:\n";
        for (int num : arr) {
            cout << num << " ";
        }
        cout << endl;
    }
};

// OPTIMAL
class BubbleSort {
public:
    void bubble_sort(vector<int>& arr) {
        int n = arr.size();
        for (int i = n - 1; i >= 0; i--) {
            int didSwap = 0; //Use two nested loops to iterate over the array
            for (int j = 0; j <= i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);  //Swap arr[j+1] with arr[i]
                    didSwap = 1;
                }
            }
            if (didSwap == 0) {
                break;
            }
        }

        cout << "After Using Bubble Sort:\n";
        for (int num : arr) {
            cout << num << " ";
        }
        cout << endl;
    }
};
