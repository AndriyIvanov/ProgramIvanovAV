Проект написан на С++ в Visual Studio 2017.
Для запуска проекта в Visual Studio (версия 2012 и позже) необходимо создать новый проект
в Visual Studio и подключить в него все файлы (файлы *.h и *.срр).

Для запуска программы без Visual Studio запустите прилагаемый файл Durak.exe (запакован в архив Durak.rar).

Если при первом запуске программы некорректно отображаются значки мастей карт, необходимо в консоли изменить шрифт 
по-умолчанию на (Точечные шрифты, размер 12х16).

Программа тестировалась на работоспособность в следующих операционных системах:
1) Windows 10 (64 bit);
2) Windows 7 Максимальная SP1 (64 bit).

О программе:
Программа раздает карты аналогично игре "Дурак" и определяет, у какого игрока лучшая комбинация.
Алгоритм определения лучшей комбинации:
- сравниваются старшие козырные карты. Побеждает игрок с самой старшей козырной картой.
- если козырные карты отсутствуют у всех игроков, сравнивается сумма старших карт по всем мастям.