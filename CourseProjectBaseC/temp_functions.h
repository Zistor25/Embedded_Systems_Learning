#include <stdio.h>
#include <unistd.h>
#include <inttypes.h>

#define YEAR 0
#define MOUNTH 1
#define DAY 2
#define HOUR 3
#define MINUTE 4
#define TEMPERATURE 5

typedef struct info
{
    uint16_t year;
    uint8_t mounth;
    uint8_t day;
    uint8_t hour;
    uint8_t minute;
    int8_t temperature;
    struct info* next;
} sensor_data;

// Функция проверки корректности данных
uint8_t data_check(int16_t data_array[], uint8_t parameter_length_array[], uint8_t error_array[]);

// Функция считывания данных из файла
sensor_data* read_sensor_data(FILE *f);

// Функция записи данных в стек
sensor_data* push(sensor_data* top, int16_t data_array[6]);

// Функция извлечения данных из стека и освобождения памяти
sensor_data* pop(sensor_data* top);

// Функция вычисления статистических данных за год
void stat_data_y(sensor_data* top);

// Функция вывода статистических данных за год
void stat_year(FILE *f);

// Функция вычисления статистических данных за месяц
void stat_data_m(sensor_data *top, char *optarg);

// Функция вывода статистических данных за месяц
void stat_mounth(FILE *f, char *optarg);

// Функция вывода справки
void hlp_func(void);