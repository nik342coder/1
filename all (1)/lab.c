#include "lab.h"

// Определение функции
void lab1() {
    float s;    // сумма ряда (result)
    float x;    // значение x (input)
    int n;      // количество элементов (input)
    int i;      // счетчик элементов (counter)
    int m;      // знак элемента (sign: +1/-1)
    float t;    // текущий элемент (term)
    int p;      // степень x (power)
    int f;      // факториал (factorial)

    printf("n=");
    scanf("%d", &n);
    
    // проверка (сразу после ввода n)
    if (n <= 0) {
        printf("Ошибка: n должно быть > 0\n");
    }

    printf("x=");
    scanf("%f", &x);

    // Инициализация переменных
    s = 1.0;
    m = -1;
    t = 1.0;
    p = 0;
    f = 1;

    // Цикл for с сохранением условия (i < n)
    for (i = 1; i < n; i++) 
    {
        p = p + 2;
        f = f * (p - 1) * p;
        t = t * x * x / ((p - 1) * p);
        t = t * m;
        s = s + t;
        m = m * -1;
    }

    printf("n = %d, s = %f\n", n, s);
}


double cut_cone(double H, double R, double D)
    {
        if (H <= 0 || R <= 0 || D < 0 || D > H) return -1;
        double r = R * (H - D) / H;
        return PI * H / 3.0 * (R * R + R * r + r * r);
    }

void lab2() {
    double H, R, D;
    printf("H, R, D: ");
    scanf("%lf %lf %lf", &H, &R, &D);

    double V = cut_cone(H, R, D);
    if (V >= 0) printf("V = %.2lf\n", V);
    else printf("Ошибка ввода данных\n");
    
}

// Проверяет, есть ли в слове подряд идущие одинаковые буквы
static int hasRepeatedLetters(const char *word) {
    if (word[0] == '\0')   // Пустая строка

    for (int i = 1; word[i] != '\0'; i++) {
        if (word[i] == word[i - 1]) {
            return 1;  // Найдены повторяющиеся символы
        }
    }
    
}

// Подсчитывает количество слов с повторяющимися буквами
int countWordsWithRepeatedLetters(const char *str) {
    int count = 0;
    char buffer[256];  // Буфер для хранения текущего слова
    int bufferIndex = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n') {
            if (bufferIndex > 0) {  // Если слово не пустое
                buffer[bufferIndex] = '\0';
                if (hasRepeatedLetters(buffer)) {
                    count++;
                }
                bufferIndex = 0;  // Сброс буфера
            }
        } else {
            buffer[bufferIndex++] = str[i];  // Заполнение буфера
        }
    }

    // Проверка последнего слова (если строка не заканчивается пробелом)
    if (bufferIndex > 0) {
        buffer[bufferIndex] = '\0';
        if (hasRepeatedLetters(buffer)) {
            count++;
        }
    }

    return count;
}

void lab3() {
    char input[MAX_INPUT_SIZE];
    printf("Введите строку: ");
    fgets(input, MAX_INPUT_SIZE, stdin);  // Безопасный ввод

    int result = countWordsWithRepeatedLetters(input);
    printf("Количество слов с повторяющимися буквами: %d\n", result);

    
}


// Проверяет, содержит ли слово подряд идущие одинаковые буквы
static int has_double_chars(const char *word) {
    for (int i = 1; word[i] != '\0'; i++) {
        if (word[i] == word[i-1]) {
            return 1;
        }
    }
    
}

// Основная функция фильтрации
void filter_words_with_doubles(char *str) {
    char result[1000] = {0};
    char word[100];
    int word_index = 0;
    int result_index = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        // Проверка на букву через ASCII-коды
        if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')) {
            word[word_index++] = str[i];
        } else {
            word[word_index] = '\0';
            if (word_index > 0 && has_double_chars(word)) {
                // Ручное копирование слова
                for (int j = 0; word[j] != '\0'; j++) {
                    result[result_index++] = word[j];
                }
                result[result_index++] = ' ';
            }
            word_index = 0;
        }
    }

    // Обработка последнего слова
    word[word_index] = '\0';
    if (word_index > 0 && has_double_chars(word)) {
        for (int j = 0; word[j] != '\0'; j++) {
            result[result_index++] = word[j];
        }
    }

    // Копирование результата обратно
    for (int i = 0; result[i] != '\0'; i++) {
        str[i] = result[i];
    }
    str[result_index] = '\0';
}

void lab4() {
    char input[MAX_INPUT];
    int i = 0;
    
    printf("Введите строку: ");
    fgets(input, MAX_INPUT, stdin);
    
    // Удаление символа новой строки вручную
    while (input[i] != '\n' && input[i] != '\0') {
        i++;
    }
    input[i] = '\0';
    
    filter_words_with_doubles(input);
    
    printf("Результат: %s\n", input);
    
    
}

// Находит номер пары соседних элементов с максимальной суммой
int find_max_sum_pair(const int *array, int size) {
    if (size < 2) {
        return -1; // Недостаточно элементов для пары
    }

    int max_sum = array[0] + array[1];
    int max_index = 0;

    for (int i = 1; i < size - 1; i++) {
        int current_sum = array[i] + array[i + 1];
        if (current_sum > max_sum) {
            max_sum = current_sum;
            max_index = i;
        }
    }

    return max_index; // Возвращает индекс первого элемента пары
}


void lab5() {
    int array[SIZE];

    // Ввод массива
    printf("Введите %d целых чисел:\n", SIZE);
    for (int i = 0; i < SIZE; i++) {
        scanf("%d", &array[i]);
    }

    // Нахождение пары с максимальной суммой
    int pair_index = find_max_sum_pair(array, SIZE);

    if (pair_index == -1) {
        printf("Недостаточно элементов для пары.\n");
    } else {
        printf("Пара соседних элементов с максимальной суммой: %d и %d\n", 
               array[pair_index], array[pair_index + 1]);
        printf("Номер первого элемента пары: %d\n", pair_index);
    }

    
}

// Создаёт матрицу rows × cols
int** create_matrix(int rows, int cols) {
    int **matrix = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
    }
    return matrix;
}

// Освобождает память матрицы
void free_matrix(int **matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

// Обнуляет столбцы, где чётных элементов больше, чем нечётных
void zero_columns_with_more_evens(int **matrix, int rows, int cols) {
    for (int j = 0; j < cols; j++) {
        int even_count = 0;
        int odd_count = 0;

        // Подсчёт чётных и нечётных в столбце j
        for (int i = 0; i < rows; i++) {
            if (matrix[i][j] % 2 == 0) {
                even_count++;
            } else {
                odd_count++;
            }
        }

        // Если чётных больше — обнуляем столбец
        if (even_count > odd_count) {
            for (int i = 0; i < rows; i++) {
                matrix[i][j] = 0;
            }
        }
    }
}

void lab6() {
    int rows, cols;

    // Ввод размеров матрицы
    printf("Введите количество строк (N): ");
    scanf("%d", &rows);
    printf("Введите количество столбцов (K): ");
    scanf("%d", &cols);

    // Создание матрицы
    int **matrix = create_matrix(rows, cols);

    // Ввод матрицы
    printf("Введите элементы матрицы (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Обнуление нужных столбцов
    zero_columns_with_more_evens(matrix, rows, cols);

    // Вывод результата
    printf("Матрица после обработки:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Освобождение памяти
    free_matrix(matrix, rows);

    
}