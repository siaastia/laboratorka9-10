#include <iostream>
#include <vector>
using namespace std;

// Блинная сортировка (Pancake Sort)

void flip(vector<int>& arr, int i) {
    int start = 0;
    while (start < i) {                         // переворачиваем элементы от 0 до i
        swap(arr[start], arr[i]);
        start++;
        i--;
    }
}

int findMax(const vector<int>& arr, int n) {
    int maxIndex = 0;
    for (int i = 1; i < n; i++)                 // ищем индекс максимального элемента
        if (arr[i] > arr[maxIndex])
            maxIndex = i;
    return maxIndex;
}

void pancakeSort(vector<int>& arr) {
    for (int curr_size = arr.size(); curr_size > 1; --curr_size) {
        int maxIndex = findMax(arr, curr_size); // находим максимум
        cout << "Максимум " << arr[maxIndex] << " на позиции " << maxIndex << endl;

        if (maxIndex != curr_size - 1) {
            flip(arr, maxIndex);                // переворачиваем до максимума
            flip(arr, curr_size - 1);           // переворачиваем весь диапазон
        }

        cout << "Текущее состояние: ";
        for (int num : arr) cout << num << " ";
        cout << endl;
    }
}

int main() {
    vector<int> arr = {23, 10, 20, 11, 12, 6, 7};
    cout << "Исходный массив: ";
    for (int n : arr) cout << n << " ";
    cout << endl;

    pancakeSort(arr);

    cout << "✅ Отсортированный массив: ";
    for (int n : arr) cout << n << " ";
    cout << endl;

    /*
    Пример вывода:
    Исходный массив: 23 10 20 11 12 6 7
    Максимум 23 на позиции 0
    ...
    ✅ Отсортированный массив: 6 7 10 11 12 20 23
    */
}
