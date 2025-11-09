import java.util.Arrays;

public class BeadSort {
    // Сортировка бусинами (Bead Sort)

    public static void beadSort(int[] arr) {
        int max = Arrays.stream(arr).max().getAsInt();   // находим максимум
        int[] beads = new int[max * arr.length];         // создаем поле бусин

        for (int i = 0; i < arr.length; i++)             // размещаем бусины
            for (int j = 0; j < arr[i]; j++)
                beads[i * max + j] = 1;

        for (int j = 0; j < max; j++) {                  // "падение бусин"
            int sum = 0;
            for (int i = 0; i < arr.length; i++) {
                sum += beads[i * max + j];
                beads[i * max + j] = 0;
            }
            for (int i = arr.length - sum; i < arr.length; i++)
                beads[i * max + j] = 1;
        }

        for (int i = 0; i < arr.length; i++) {           // пересчитываем результат
            int count = 0;
            for (int j = 0; j < max && beads[i * max + j] == 1; j++)
                count++;
            arr[i] = count;
        }
    }

    public static void main(String[] args) {
        int[] arr = {5, 3, 1, 7, 4, 1, 1, 20};
        System.out.println("Исходный массив: " + Arrays.toString(arr));

        beadSort(arr);

        System.out.println("✅ Отсортированный массив: " + Arrays.toString(arr));

        /*
        Пример вывода:
        Исходный массив: [5, 3, 1, 7, 4, 1, 1, 20]
        ✅ Отсортированный массив: [1, 1, 1, 3, 4, 5, 7, 20]
        */
    }
}
