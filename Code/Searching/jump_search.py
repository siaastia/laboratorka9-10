import math

# Поиск скачками (Jump Search)

def jump_search(arr, target):
    n = len(arr)                            # длина массива
    step = int(math.sqrt(n))                # оптимальный шаг (√n)
    prev = 0                                # предыдущий индекс

    # Идём скачками, пока не превысим искомое значение
    while prev < n and arr[min(step, n) - 1] < target:
        print(f"Прыгаем на индекс {min(step, n) - 1}, значение {arr[min(step, n) - 1]}")
        prev = step
        step += int(math.sqrt(n))
        if prev >= n:
            return -1                       # если выходим за границы — не найден

    # Линейный поиск в найденном диапазоне
    print(f"Выполняем линейный поиск от {prev} до {min(step, n) - 1}")
    for i in range(prev, min(step, n)):
        print(f"Проверяем индекс {i}, значение {arr[i]}")
        if arr[i] == target:
            return i
    return -1


# Демонстрация работы
arr = [1, 3, 5, 7, 9, 11, 13, 15, 17, 19]
target = 13
print("Исходный массив:", arr)
print("Искомое значение:", target)

result = jump_search(arr, target)

if result != -1:
    print(f"✅ Элемент найден на индексе {result}, значение {arr[result]}")
else:
    print("❌ Элемент не найден")

"""
Пример вывода:
Исходный массив: [1, 3, 5, 7, 9, 11, 13, 15, 17, 19]
Искомое значение: 13
Прыгаем на индекс 3, значение 7
Прыгаем на индекс 6, значение 13
Выполняем линейный поиск от 3 до 6
Проверяем индекс 6, значение 13
✅ Элемент найден на индексе 6, значение 13
"""
