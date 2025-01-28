#!/bin/bash

echo "=== Spark Optimizer Update Script ==="

# Компіляція програми
echo "Компіляція..."
gcc spark.c -o spark

if [ $? -eq 0 ]; then
    echo "Компіляція успішна!"
    
    # Додаємо зміни в git
    echo "Оновлення репозиторію..."
    git add spark.c
    git commit -m "Update: $(date '+%Y-%m-%d %H:%M:%S')"
    git push origin main
    
    echo "=== Все готово! ==="
    echo "Запустіть програму командою: sudo ./spark"
else
    echo "Помилка компіляції!"
    exit 1
fi
