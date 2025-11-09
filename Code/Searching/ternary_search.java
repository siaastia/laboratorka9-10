public class TernarySearch {
    // Тернарный поиск (Ternary Search)

    public static int ternarySearch(int[] arr, int left, int right, int target) {
        if (right >= left) {
            int mid1 = left + (right - left) / 3;              // первая точка деления
            int mid2 = right - (right - left) / 3;             // вторая точка деления

            System.out.println("Проверяем mid1=" + mid1 + " (" + arr[mid1] + "), mid2=" + mid2 + " (" + arr[mid2] + ")");

            if (arr[mid1] == target) return mid1;              // если нашли в первой
            if (arr[mid2] == target) return mid2;              // если нашли во второй

            if (target < arr[mid1])                            // если элемент меньше mid1
                return ternarySearch(arr, left, mid1 - 1, target);
            else if (target > arr[mid2])                       // если больше mid2
                return ternarySearch(arr, mid2 + 1, right, target);
            else                                                // иначе в среднем диапазоне
                return ternarySearch(arr, mid1 + 1, mid2 - 1, target);
        }
        return -1;
    }

    public static void main(String[] args) {
        int[] arr = {1, 4, 7, 10, 13, 16, 19, 22, 25};
        int target = 13;

        System.out.print("Исходный массив: ");
        for (int num : arr) System.out.print(num + " ");
        System.out.println("\nИскомое значение: " + target);

        int result = ternarySearch(arr, 0, arr.length - 1, target);

        if (result != -1)
            System.out.println("✅ Элемент найден на индексе " + result + ", значение " + arr[result]);
        else
            System.out.println("❌ Элемент не найден");

        /*
        Пример вывода:
        Исходный массив: 1 4 7 10 13 16 19 22 25 
        Искомое значение: 13
        Проверяем mid1=2 (7), mid2=6 (19)
        Проверяем mid1=4 (13), mid2=5 (16)
        ✅ Элемент найден на индексе 4, значение 13
        */
    }
}
