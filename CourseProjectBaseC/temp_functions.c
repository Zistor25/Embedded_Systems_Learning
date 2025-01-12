#include <stdio.h>
#include <unistd.h>
#include <inttypes.h>
#include <stdlib.h>

#include "temp_functions.h"

const char *jan = "jan";
const char *feb = "feb";
const char *mar = "mar";
const char *apr = "apr";
const char *may = "may";
const char *jun = "jun";
const char *jul = "jul";
const char *aug = "aug";
const char *sep = "sep";
const char *oct = "oct";
const char *nov = "nov";
const char *dec = "dec";

FILE *f_err_ptr;

// Функция вывода справки
void hlp_func(void)
{
    printf("\nThe program 'tempstat.exe' processes and parses CSV data files and\n");
    printf("allows to calculate [min] - minimum , [ave] - average  and [max] -\n");
    printf("maximum temperature for the selected period (year or mounth).\n");
    printf("If there are errors in the data file, they will be recorded in the file\n");
    printf("<Errors_in_data.txt> and will be not taken into account in calculations.\n\n");

    printf("List of options:\n");
    printf("-h  ..............Help.\n");
    printf("-f <file.csv>  ...Input name of CSV data file.\n");
    printf("-y  ..............Calculation of statistics for the year.\n");
    printf("-m <mounth>  .....Calculation of statistics for the selected month;\n");
    printf("                  input mounth as a 3 letter abbreviation <jan>, <feb>...<dec>.\n\n");

    printf("The use of keys '-f', '-y'(or '-m') is mandatory for calculating statistical data.\n");
    printf("Use only one key '-f <file.csv>' and only one key '-y' to obtain statistical data for the year.\n");
    printf("Use only one key '-f <file.csv>' and only one key '-m <mounth>' to obtain statistical data for the selected mounth.\n");
    printf("Use the keys only in the order specified above.\n\n");

    printf("Examples:\n");
    printf("temp.exe -h\n");
    printf("temp.exe -f data.csv -y\n");
    printf("temp.exe -f sensor.csv -m apr\n");
    printf("temp.exe -f temperature.csv -m jul\n");
}

// Функция вывода статистических данных за год
void stat_year(FILE *f)
{
    if (f == NULL)
    {
        printf("Error occured while opening data file!");
    }
    stat_data_y(read_sensor_data(f));
}

// Функция вычисления статистических данных(год)
void stat_data_y(sensor_data *top)
{
    // Массивы статистических данных. Элемент[0] - данные за год;  элементы [1...12] - данные по месяцам
    int16_t min[13] = {100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100};
    int16_t max[13] = {-100, -100, -100, -100, -100, -100, -100, -100, -100, -100, -100, -100, -100};
    float average[13] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    float sum[13] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int32_t counter[13] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    while (top)
    {
        (top->temperature < min[0]) ? (min[0] = top->temperature) : (min[0]);
        (top->temperature > max[0]) ? (max[0] = top->temperature) : (max[0]);
        (top->temperature < min[top->mounth]) ? (min[top->mounth] = top->temperature) : (min[top->mounth]);
        (top->temperature > max[top->mounth]) ? (max[top->mounth] = top->temperature) : (max[top->mounth]);

        sum[0] += top->temperature;
        counter[0]++;
        sum[top->mounth] += top->temperature;
        counter[top->mounth]++;

        top = pop(top);
    }

    for (int i = 0; i <= 12; i++)
    {
        average[i] = sum[i] / counter[i];
    }

    printf("\nAnnual temperature statistics:\n");
    printf("\tMin\tAve\tMax\n");
    printf("Jan\t%d\t%.2f\t%d\n", min[1], average[1], max[1]);
    printf("Feb\t%d\t%.2f\t%d\n", min[2], average[2], max[2]);
    printf("Mar\t%d\t%.2f\t%d\n", min[3], average[3], max[3]);
    printf("Apr\t%d\t%.2f\t%d\n", min[4], average[4], max[4]);
    printf("May\t%d\t%.2f\t%d\n", min[5], average[5], max[5]);
    printf("Jun\t%d\t%.2f\t%d\n", min[6], average[6], max[6]);
    printf("Jul\t%d\t%.2f\t%d\n", min[7], average[7], max[7]);
    printf("Aug\t%d\t%.2f\t%d\n", min[8], average[8], max[8]);
    printf("Sep\t%d\t%.2f\t%d\n", min[9], average[9], max[9]);
    printf("Oct\t%d\t%.2f\t%d\n", min[10], average[10], max[10]);
    printf("Nov\t%d\t%.2f\t%d\n", min[11], average[11], max[11]);
    printf("Dec\t%d\t%.2f\t%d\n", min[12], average[12], max[12]);
    printf("Year\t%d\t%.2f\t%d\n\n", min[0], average[0], max[0]);
}

// Функция вывода статистических данных за месяц
void stat_mounth(FILE *f, char *optarg)
{
    if (f == NULL)
    {
        printf("Error occured while opening data file!");
    }
    stat_data_m(read_sensor_data(f), optarg);
}

// Функция вычисления статистических данных(месяц)
void stat_data_m(sensor_data *top, char *optarg)
{
    // Определение выбранного месяца
    uint8_t mounth = 0;

    if (strlen(optarg) == 3)
    {
        if (strcmp(optarg, jan) == 0)
        {
            mounth = 1;
        }
        else if (strcmp(optarg, feb) == 0)
        {
            mounth = 2;
        }
        else if (strcmp(optarg, mar) == 0)
        {
            mounth = 3;
        }
        else if (strcmp(optarg, apr) == 0)
        {
            mounth = 4;
        }
        else if (strcmp(optarg, may) == 0)
        {
            mounth = 5;
        }
        else if (strcmp(optarg, jun) == 0)
        {
            mounth = 6;
        }
        else if (strcmp(optarg, jul) == 0)
        {
            mounth = 7;
        }
        else if (strcmp(optarg, aug) == 0)
        {
            mounth = 8;
        }
        else if (strcmp(optarg, sep) == 0)
        {
            mounth = 9;
        }
        else if (strcmp(optarg, oct) == 0)
        {
            mounth = 10;
        }
        else if (strcmp(optarg, nov) == 0)
        {
            mounth = 11;
        }
        else if (strcmp(optarg, dec) == 0)
        {
            mounth = 12;
        }
        else
        {
            printf("Error in mounth option. Use the key '-h' to get help.\n");
        }
    }
    else
    {
        printf("Error in mounth option. Use the key '-h' to get help.\n");
    }

    // Расчет и вывод статистических данных за месяц
    if (mounth != 0)
    {
        // Cтатистические данные
        int16_t min = 100;
        int16_t max = -100;
        float average = 0;

        float sum = 0;
        int32_t counter = 0;

        while (top)
        {
            if (top->mounth == mounth)
            {
                (top->temperature < min) ? (min = top->temperature) : (min);
                (top->temperature > max) ? (max = top->temperature) : (max);
                sum += top->temperature;
                counter++;
            }
            top = pop(top);
        }

        average = sum / counter;

        if (mounth == 1)
        {
            printf("\nTemperature statistics for January:\n");
        }
        if (mounth == 2)
        {
            printf("\nTemperature statistics for February:\n");
        }
        if (mounth == 3)
        {
            printf("\nTemperature statistics for March:\n");
        }
        if (mounth == 4)
        {
            printf("\nTemperature statistics for April:\n");
        }
        if (mounth == 5)
        {
            printf("\nTemperature statistics for May:\n");
        }
        if (mounth == 6)
        {
            printf("\nTemperature statistics for June:\n");
        }
        if (mounth == 7)
        {
            printf("\nTemperature statistics for July:\n");
        }
        if (mounth == 8)
        {
            printf("\nTemperature statistics for August:\n");
        }
        if (mounth == 9)
        {
            printf("\nTemperature statistics for September:\n");
        }
        if (mounth == 10)
        {
            printf("\nTemperature statistics for October:\n");
        }
        if (mounth == 11)
        {
            printf("\nTemperature statistics for November:\n");
        }
        if (mounth == 12)
        {
            printf("\nTemperature statistics for December:\n");
        }
        printf("Min: %d\n", min);
        printf("Ave: %.2f\n", average);
        printf("Max: %d\n", max);
    }
}

// Функция записи данных в стек
sensor_data *push(sensor_data *top, int16_t data_array[6])
{
    sensor_data *ptr = malloc(sizeof(sensor_data));
    ptr->year = data_array[0];
    ptr->mounth = data_array[1];
    ptr->day = data_array[2];
    ptr->hour = data_array[3];
    ptr->minute = data_array[4];
    ptr->temperature = data_array[5];
    ptr->next = top;
    return ptr;
}

// Функция извлечения данных из стека и освобождения памяти
sensor_data *pop(sensor_data *top)
{
    if (top == NULL)
    {
        return top;
    }
    sensor_data *ptr_next = top->next;
    free(top);
    return ptr_next;
}

// Функция проверки корректности данных
uint8_t data_check(int16_t data_array[], uint8_t parameter_length_array[], uint8_t error_array[])
{
    for (int i = 0; i <= 5; i++) // проверка корректности данных
    {
        switch (i)
        {
            case YEAR:
            {
                (parameter_length_array[i] == 4) ? error_array[i] : error_array[i]++;
                break;
            }
            case MOUNTH:
            {
                if (data_array[i] < 1 || data_array[i] > 12)
                {
                    error_array[i]++;
                }
                break;
            }
            case DAY:
            {
                if (data_array[1] == 1 || data_array[1] == 3 || data_array[1] == 5 || data_array[1] == 7 || data_array[1] == 8 || data_array[1] == 10 || data_array[1] == 12)
                {
                    if (data_array[2] < 1 || data_array[2] > 31)
                    {
                        error_array[i]++;
                    }
                }
                if (data_array[1] == 4 || data_array[1] == 6 || data_array[1] == 9 || data_array[1] == 11)
                {
                    if (data_array[2] < 1 || data_array[2] > 30)
                    {
                        error_array[i]++;
                    }
                }
                if (data_array[1] == 2)
                {
                    if ((data_array[0] % 4) == 0)
                    {
                        if (data_array[2] < 1 || data_array[2] > 29)
                        {
                            error_array[i]++;
                        }
                    }
                    else
                    {
                        if (data_array[2] < 1 || data_array[2] > 28)
                        {
                            error_array[i]++;
                        }
                    }
                }
                break;
            }
            case HOUR:
            {
                if (data_array[i] < 0 || data_array[i] > 23)
                {
                    error_array[i]++;
                }
                break;
            }
            case MINUTE:
            {
                if (data_array[i] < 0 || data_array[i] > 59)
                {
                    error_array[i]++;
                }
                break;
            }
            case TEMPERATURE:
            {
                if (data_array[i] < -99 || data_array[i] > 99)
                {
                    error_array[i]++;
                }
                break;
            }
        }
    }
    return (error_array[0] + error_array[1] + error_array[2] + error_array[3] + error_array[4] + error_array[5]);
}

// функция считывания данных из файла
sensor_data *read_sensor_data(FILE *f)
{
    sensor_data *top = NULL; // указатель на последний элемент стека

    char *err_file = "Error file.txt";

    char c;                        // считанный из файла символ
    char buffer[30];               // буферная строка(для последующей записи строки в файл с ощибками, если это необходимо)
    uint8_t buf_counter = 0;       // счетчик записываемого в буферную строку символа
    uint32_t line_counter = 0;     // счетчик считанных строк из файла
    uint32_t data_counter = 0;     // счетчик корректных строк
    uint8_t parameter_counter = 0; // счетчик обрабатываемого параметра
    uint32_t error_counter = 0;    // счетчик ошибочных строк

    int16_t data_array[6] = {0};             // Промежуточный массив записи данных 0-год, 1-месяц, 2-день, 3-час, 4-минута, 5-температура
    uint8_t parameter_length_array[6] = {0}; // Массив количества символов параметра 0-год, 1-месяц, 2-день, 3-час, 4-минута, 5-температура
    uint8_t error_array[6] = {0};            // Массив ошибок параметра 0-год, 1-месяц, 2-день, 3-час, 4-минута, 5-температура
    int8_t flag_minus = 0;

    do
    {
        c = fgetc(f);
        buffer[buf_counter++] = c;

        if (c == ' ')
        {
            c = '0';
        }
        if (c == '\n' || c == EOF) // переход к новой строке
        {
            if (data_check(data_array, parameter_length_array, error_array))
            {
                error_counter++;
                if (error_counter == 1)
                {
                    f_err_ptr = fopen("Errors_in_data.txt", "w");
                    if (f_err_ptr == NULL)
                    {
                        perror("Error occured while opening error file!");
                    }
                }
                fprintf(f_err_ptr, "%d:\t %s", (line_counter + 1), buffer);
                // printf("Error in line #%" PRIu32 "!\n", line_counter + 1);//                   РАСКОММЕНТИРОВАТЬ ДЛЯ ВЫВОДА НОМЕРА СТРОКИ С ОШИБКОЙ!
            }
            else
            {
                top = push(top, data_array);
                data_counter++;
            }

            line_counter++;        // счетчик строк
            parameter_counter = 0; // счетчик параметров
            flag_minus = 0;        // флаг отрицательной температуры

            data_array[YEAR] = data_array[MOUNTH] = data_array[DAY] = data_array[HOUR] =
                data_array[MINUTE] = data_array[TEMPERATURE] = 0;

            parameter_length_array[YEAR] = parameter_length_array[MOUNTH] =
                parameter_length_array[DAY] = parameter_length_array[HOUR] =
                    parameter_length_array[MINUTE] = parameter_length_array[TEMPERATURE] = 0;

            error_array[YEAR] = error_array[MOUNTH] = error_array[DAY] = error_array[HOUR] =
                error_array[MINUTE] = error_array[TEMPERATURE] = 0;

            buf_counter = 0;
        }

        else if (c == ';') // переход к новому параметру в строке
        {
            parameter_counter++;
        }

        else // ввод даты, времени и температуры
        {
            if (parameter_counter == TEMPERATURE)
            {
                if (c == '-')
                {
                    flag_minus = 1;
                }
                else if (c >= '0' && c <= '9')
                {
                    if (flag_minus)
                    {
                        data_array[5] = -(c - '0') + 10 * data_array[5];
                        parameter_length_array[5]++;
                    }
                    else
                    {
                        data_array[5] = (c - '0') + 10 * data_array[5];
                        parameter_length_array[5]++;
                    }
                }
                else
                {
                    error_array[5]++;
                }
            }
            else
            {
                if (c >= '0' && c <= '9') // ввод даты и времени
                {
                    data_array[parameter_counter] = (c - '0') + 10 * data_array[parameter_counter];
                    parameter_length_array[parameter_counter]++;
                }
                else
                {
                    error_array[parameter_counter]++;
                }
            }
        }
    } while (c != EOF);
    fclose(f);
    printf("\nFile reading results:\n");
    printf("total lines - %d;\nerrors - %d;\ncorrect data - %d.\n\n", line_counter, error_counter, data_counter);
    if (f_err_ptr != NULL)
    {
        fclose(f_err_ptr);
        printf("Lines with errors were written in the file <Errors_in_data.txt>.\n\n");
    }
    return top;
}