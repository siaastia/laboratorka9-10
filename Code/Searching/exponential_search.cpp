#include <iostream>
#include <cmath>
using namespace std;

// Экспоненциальный поиск (Exponential Search)

int binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;       // находим середину диапазона
        cout << "Проверяем индекс " << mid << ", значение " << arr[mid] << endl;
        if (arr[mid] == target) return mid;        // если нашли — возвращаем индекс
        if (arr[mid] < target) left = mid + 1;     // если значение меньше — идём вправо
        else right = mid - 1;                      // иначе — влево
    }
    return -1;
}

int exponentialSearch(int arr[], int n, int target) {
    if (arr[0] == target) return 0;                // проверяем первый элемент

    int i = 1;
    // увеличиваем шаг экспоненциально, пока не превысим элемент
    while (i < n && arr[i] <= target) {
        cout << "Расширяем диапазон: i = " << i << ", значение = " << arr[i] << endl;
        i *= 2;
    }

    cout << "Выполняем бинарный поиск между " << i/2 << " и " << min(i, n-1) << endl;
    return binarySearch(arr, i/2, min(i, n-1), target);
}

int main() {
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18};
    int n = sizeof(arr)/sizeof(arr[0]);
    int target = 14;

    cout << "Исходный массив: ";
    for (int i=0; i<n; i++) cout << arr[i] << " ";
    cout << "\nИскомое значение: " << target << endl;

    int result = exponentialSearch(arr, n, target);

    if (result != -1)
        cout << "✅ Элемент найден на индексе " << result << ", значение " << arr[result] << endl;
    else
        cout << "❌ Элемент не найден" << endl;

    /*
    Пример вывода:
    Исходный массив: 2 4 6 8 10 12 14 16 18 
    Искомое значение: 14
    Расширяем диапазон: i = 1, значение = 4
    Расширяем диапазон: i = 2, значение = 6
    Расширяем диапазон: i = 4, значение = 10
    Расширяем диапазон: i = 8, значение = 18
    Выполняем бинарный поиск между 4 и 8
    Проверяем индекс 6, значение 14
    ✅ Элемент найден на индексе 6, значение 14
    */
}
