# Теоретическая часть

## Описание задачи
  Задача игрока заключается в том, чтобы «собрать кубик Рубика»: поворачивая грани куба, вернуть его в первоначальное состояние, когда каждая из граней состоит из квадратов одного цвета.
  
## Формальное описание
  С точки зрения математики перемещения отдельных кубиков при повороте граней кубика Рубика является перестановками конечного множества состояний отдельных кубиков (их положения и ориентации). Все возможные повороты граней образуют группу и, таким образом, необходимо вывести последовательность перестановок, необходимых для преобразования из любого множества в исходное.
  
## Описание основных подходов

1. Полный перебор
  Главный недостаток - количество различных состояний кубика примерно 43*10^18
2. Алгоритм бога
  Главный недостаток - такого алгоритма еще нет
3. Шаблонный алгоритм (Например:Fridrich, Roux, ZZ
  + прост в реализации
  + алгоритмы для всех шаблонов доступны
  - придется алгооритмы для всех шаблонов
  - приличное количество ходов
4. Генетический алгоритм - основан на эвристическом поиске
  + малое количество ходов
  - сложен в реализации
  - длительный поиск решения
  
## Описание метода
