//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//vector<long long> bubbleSort(vector<long long> arr) {
//    int n = arr.size();
//    for (int i = 0; i < n - 1; ++i) {
//        for (int j = 0; j < n - i - 1; ++j) {
//            if (arr[j] > arr[j + 1]) {
//                swap(arr[j], arr[j + 1]);
//            }
//        }
//    }
//    return arr;
//}
//
//vector<int> selectionSort(vector<int> arr) {
//    int n = arr.size();
//    for (int i = 0; i < n - 1; ++i) {
//        int minIdx = i;
//        for (int j = i + 1; j < n; ++j) {
//            if (arr[j] < arr[minIdx]) {
//                minIdx = j;
//            }
//        }
//        swap(arr[i], arr[minIdx]);
//    }
//    return arr;
//}
//
//int main() {
//    system("chcp 1251>null");
//    vector<long long> mobileNumbers = { 380671234567, 380631112233, 380961234567, 380661234567, 380671122334, 380501234567 };
//    vector<int> homeNumbers = { 1234567, 1112233, 2345678, 1223344, 3456789, 9876543 };
//
//    while (true) {
//        cout << "\nМеню:\n";
//        cout << "1. номер мобільним\n";
//        cout << "2. домашнім номерам)\n";
//        cout << "3. Вивести список користувачів\n";
//        cout << "4. Вихід\n";
//
//        int choice;
//        cin >> choice;
//
//        if (choice == 1) {
//            mobileNumbers = bubbleSort(mobileNumbers);
//            cout << "Мобільні номери відсортовано.\n";
//        }
//        else if (choice == 2) {
//            homeNumbers = selectionSort(homeNumbers);
//            cout << "Домашні номери відсортовано.\n";
//        }
//        else if (choice == 3) {
//            cout << "Мобільні номери: ";
//            for (long long num : mobileNumbers) {
//                cout << num << " ";
//            }
//            cout << "\nДомашні номери: ";
//            for (int num : homeNumbers) {
//                cout << num << " ";
//            }
//            cout << endl;
//        }
//        else if (choice == 4) {
//            cout << "Вихід\n";
//            break;
//        }
//        else {
//            cout << "Невірний вибір. Спробуйте ще раз\n";
//        }
//    }
//    return 0;
//}



#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

vector<int> customSort(vector<int> arr) {
    int n = arr.size();
    double avg = accumulate(arr.begin(), arr.end(), 0.0) / n;
    int limit = (avg > 0) ? (2 * n) / 3 : n / 3;

    vector<int> sortedPart(arr.begin(), arr.begin() + limit);
    sort(sortedPart.begin(), sortedPart.end());

    vector<int> reversedPart(arr.begin() + limit, arr.end());
    reverse(reversedPart.begin(), reversedPart.end());

    vector<int> result = sortedPart;
    result.insert(result.end(), reversedPart.begin(), reversedPart.end());
    return result;
}

int main() {
    vector<int> array = { 5, -1, 3, 10, -2, 7, -3, 6, -4, 9, 8, -5 };

    cout << "Оригінальний масив: ";
    for (int num : array) {
        cout << num << " ";
    }
    cout << endl;

    vector<int> result = customSort(array);

    cout << "Оброблений масив: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
