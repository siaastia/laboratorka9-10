# Блочная (корзинная) сортировка (Bucket Sort)

def bucket_sort(arr):
    max_val = max(arr)                           # максимальное значение
    min_val = min(arr)                           # минимальное значение
    bucket_count = len(arr)                      # количество корзин
    buckets = [[] for _ in range(bucket_count)]  # создаем корзины

    for num in arr:
        index = int((num - min_val) / (max_val - min_val + 1) * (bucket_count - 1))
        buckets[index].append(num)               # помещаем элемент в корзину
        print(f"Элемент {num} попадает в корзину {index}")

    sorted_arr = []
    for i, bucket in enumerate(buckets):
        print(f"Корзина {i} до сортировки: {bucket}")
        sorted_bucket = sorted(bucket)           # сортируем корзину встроенной функцией
        print(f"Корзина {i} после сортировки: {sorted_bucket}")
        sorted_arr.extend(sorted_bucket)         # добавляем отсортированные элементы

    return sorted_arr


arr = [42, 32, 33, 52, 37, 47, 51]
print("Исходный массив:", arr)
result = bucket_sort(arr)
print("✅ Отсортированный массив:", result)

"""
Пример вывода:
Исходный массив: [42, 32, 33, 52, 37, 47, 51]
Элемент 42 попадает в корзину 4
...
✅ Отсортированный массив: [32, 33, 37, 42, 47, 51, 52]
"""
