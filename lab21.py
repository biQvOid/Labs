# 9. Удлинение имен файлов до указанной длины заданным знаком

import os
import sys
file_name = str(input())  # имя файла
new_len = int(input())  # длина, до которой удлиняем имя файла
symbol = str(input())  # знак, которым удлиняем имя файла
if os.path.isfile(file_name) is not True:  # проверка является ли аргумент файлом или нет
    print("Указанного файла не существует")
    sys.exit()
if new_len < len(file_name):  # проверка, не пытаемся ли мы укоротить имя файла
    print("Попытка уменьшить длину имени файла")
    sys.exit()
diff = new_len - len(file_name)  # число символов, на которое нужно удлинить имя файла
os.rename(file_name, file_name + symbol * diff)  # переименовываем файл с новым удлиненным заданным знаком именем
