#!/bin/bash

echo "=== Встановлення Spark Optimizer в систему ==="

# Перевіряємо чи запущено від root
if [ "$EUID" -ne 0 ]; then 
    echo "Цей скрипт потрібно запускати з правами root (sudo)!"
    exit 1
fi

# Створюємо директорії
echo "Створення директорій..."
install -d /usr/share/spark-optimizer
install -d /usr/local/bin

# Компілюємо програму
echo "Компіляція програми..."
gcc spark.c -o spark-optimizer

# Копіюємо файли
echo "Копіювання файлів..."
install -m 755 spark-optimizer /usr/local/bin/
install -m 644 spark-optimizer.desktop /usr/share/applications/
install -m 644 icon.png /usr/share/spark-optimizer/

# Створюємо файл політики для pkexec
echo "Налаштування прав доступу..."
cat > /usr/share/polkit-1/actions/com.spark.optimizer.policy << EOF
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE policyconfig PUBLIC
 "-//freedesktop//DTD PolicyKit Policy Configuration 1.0//EN"
 "http://www.freedesktop.org/standards/PolicyKit/1/policyconfig.dtd">
<policyconfig>
  <action id="com.spark.optimizer.run">
    <description>Run Spark Optimizer</description>
    <message>Authentication is required to run Spark Optimizer</message>
    <icon_name>spark-optimizer</icon_name>
    <defaults>
      <allow_any>auth_admin</allow_any>
      <allow_inactive>auth_admin</allow_inactive>
      <allow_active>auth_admin</allow_active>
    </defaults>
    <annotate key="org.freedesktop.policykit.exec.path">/usr/local/bin/spark-optimizer</annotate>
    <annotate key="org.freedesktop.policykit.exec.allow_gui">true</annotate>
  </action>
</policyconfig>
EOF

# Оновлюємо кеш desktop файлів
echo "Оновлення кешу..."
update-desktop-database /usr/share/applications

echo "=== Встановлення завершено! ==="
echo "Тепер ви можете знайти Spark Optimizer в меню програм"
echo "або запустити командою: spark-optimizer"
