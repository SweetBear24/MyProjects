
#!/bin/bash


echo "Дата: $(date +"%d-%m-%Y");"
echo
echo "Имя учетной записи: $(whoami);"
echo "Доменное имя ПК:    $(hostname);"
echo


processor=$(lscpu)
# processor_model=$(echo "$processor" | grep "Имя модели"  | sed 's/Имя модели: [ \t]*//')
processor_model=$(echo "$processor" | sed -n 's|^Имя модели:[ \t]*||p')
processor_architecture=$(echo "$processor" | sed -n 's|^Архитектура:[ \t]*||p')
processor_clock_frequency=$(echo "$processor" | sed -n 's|^CPU MHz:[ \t]*||p')
processor_cores=$(echo "$processor" | sed -n 's|^CPU(s):[ \t]*||p')
processor_threads_per_core=$(grep -m1 "siblings" /proc/cpuinfo | awk -F: '{print $2}' | tr -d ' ')
current_frquency=$(echo "$processor_info" | grep "CPU MHz" | awk '{print $3}')

echo "Процессор:"
echo "  • Модель                          – $processor_model"
echo "  • Архитектура                     – $processor_architecture"
echo "  • Тактовая частота                – $processor_clock_frequency MHz"
echo "  • Текущая тактовая частота:       – $current_frequncy MHz"
echo "  • Количество ядер                 – $processor_cores"
echo "  • Количество потоков на одно ядро – $processor_threads_per_core"
echo


RAM=$(free -h)
RAM_all=$(echo "$RAM"  | grep "Mem" | awk '{ print $2 }')
RAM_available=$(echo "$RAM"  | grep "Mem" | awk '{ print $7 }')
SWAP_all=$(echo "$RAM"  | grep "Swap" | awk '{ print $2 }')
SWAP_available=$(echo "$RAM"  | grep "Swap" | awk '{ print $4 }')

#echo "Оперативная память:"
#echo "  • Всего    – $RAM_all"
#echo "  • Доступно – $RAM_available"
#echo 
# Информация о кэше L1
l1_data_cache=$(lscpu | grep "L1d cache" | awk '{print $3}')
# Информация о кэше L2
l2_cache=$(lscpu | grep "L2 cache" | awk '{print $3}')
# Информация о кэше L3
l3_cache=$(lscpu | grep "L3 cache" | awk '{print $3}')
memory_info=$(free -h | awk 'NR==2{print "  • Всего: " $2} NR==2{print "  • Доступно: " $7}')
# Выводим информацию о памяти


echo "Информация о оперативной памяти:"
echo "  • Cache L1: $l1_data_cache"
echo "  • Cache L2: $l2_cache"
echo "  • Cache L3: $l3_cache"
echo "$memory_info"
echo

hardDrive=$(df -h 2> /dev/null| grep '/$')
hardDrive_all=$(echo "$hardDrive" | awk '{ print $2 }')
hardDrive_available=$(echo "$hardDrive" | awk '{ print $4 }')
hardDrive_root=$(echo "$hardDrive" | awk '{ print $1 }')
hardDrive_count=$(lsblk | grep -E "^[├└]─" | wc -l)
#disk="/dev/null"
# Используем 'parted' для анализа разделов на диске
#parted_output=$(parted $disk print)
# Извлекаем информацию о неразмеченном пространстве, исключая заголовок
#unallocated_space=$(echo "$parted_output" | grep "unallocated" | awk '{print $3}')
# Используем 'swapon' для получения информации о swap-пространстве
swap_info=$(swapon -s)
# Извлекаем размер всего swap-пространства, исключая заголовок
total_swap_size=$(echo "$swap_info" | tail -n +2 | awk '{sum+=$3} END{print sum}')
# Используем 'free' для получения информации о памяти, включая swap
memory_info=$(free -h)
# Извлекаем доступное swap-пространство
available_swap=$(echo "$memory_info" | awk '/Swap:/ {print $3}')


echo "Жесткий диск:"
echo "  • Всего    – $hardDrive_all"
echo "  • Доступно – $hardDrive_available"
echo "  • Количество разделов жесткого диска: $hardDrive_count"
echo "  • Смонтировано в корневую директорию / – $hardDrive_root"
echo "  • Объем неразмеченного пространства на диске $disk: $unallocated_space"
echo "  • SWAP всего    – $total_swap_size KB"
echo "  • SWAP доступно – $available_swap KB"
echo


networkNames=$(ip address show | awk '/^[0-9]+:/ { print $2 }' | sed 's|:||')
# Выполняем тест скорости с помощью speedtest-cli и сохраняем результат в файл
#speedtest-cli --simple > speedtest_result.txt
# Извлекаем максимальную скорость из файла
#max_speed=$(cat speedtest_result.txt | grep "Download" | awk '{print $2}')

echo "Сетевые интерфейсы:"
echo "  • Количество сетевых интерфейсов – $(echo $networkNames | wc -w)"
#echo "  • Максимальная скорость соединения: $max_speed Mbit/s"
speedtest-cli --simple --share | awk '/^Ping:/ { ping=$2 } /^Download:/ { download=$2 } /^Upload:/ { upload=$2 } END { printf("  • Download: %s Mbit/s, Ping: %s ms, Upload: %s Mbit/s\n", download, ping, upload) }'
echo 

# Получение списка всех активных сетевых интерфейсов
interfaces=$(ip link show | grep -oE '^[0-9]+: [a-zA-Z0-9]+' | awk '{print $2}')
# Проверка стандарта связи для каждого интерфейса
for interface in $interfaces; do
    if [[ "$interface" == "lo" ]]; then
        # Пропускаем интерфейс "lo" (loopback)
        continue
    fi
    # Проверка, является ли интерфейс беспроводным (Wi-Fi) или проводным (Ethernet)
    if iwconfig "$interface" &> /dev/null; then
        standard="Wi-Fi"
    elif ifconfig "$interface" &> /dev/null; then
        standard="Ethernet"
    else
        standard="Неизвестно"
    fi
    echo "Интерфейс: $interface, Стандарт связи: $standard"
done

temp=$(mktemp)
num=0
for name in $networkNames; do
    num=$(($num + 1))
    mac=$(ip address show "$name" | grep 'link' | awk 'NR==1{print $2}')
    ip=$(ip address show "$name" | grep 'inet' | awk 'NR==1{print $2}')    
    echo "$num|$name|$mac|$ip" >> $temp
done
column -t -s '|' -N '#','Имя сетевого интерфейса','МАС адрес','IP адрес' $temp
rm $temp
