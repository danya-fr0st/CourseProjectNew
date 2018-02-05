#ifndef ROM_MEMORY_H
#define ROM_MEMORY_H

#include "iostream"
#include "string"
#include "vector"
#include <iomanip>
#include <fstream>
#include "byte.h"
#include "word.h"
#include "dword.h"
#include "memory.h"
#include "stack_block.h"
#include <cmath>

/*!
    \brief Класс симуляции

    Реализация работы с регистрами и обработка входящих данных
    */
class ROM_memory
{
    word EAX;
    word EBX;
    word ECX;
    word EDX;

    dword CR0;
    dword CR1;
    dword CR2;
    dword CR3;

    byte f_CR0;
    byte f_CR1;
    byte f_CR2;
    byte f_CR3;

    word flags;

    stack_block Stack;
    memory data;
    memory callret;
    memory labels;

public:
    ROM_memory() = default;
    /*!
    \brief Возврат значения.
    Возвращает байт по строке
    \param title Возвращает ссылку на байт для пользования
    */
    byte &return_by_string(const std::string &);
    /*!
    \brief Возврат значения.
    Возвращает регистр по строке
    \param title Возвращает ссылку на word для пользования
    */
    word &return_reg_by_string(const std::string &);
    dword& return_spec_reg_by_string(const std::string &title); //возвращает регистр специального назначения по строке и ссылку на dword
    /*!
    \brief Пересылка данных.
    mov приемник, источник.
    Базовая команда пересылки данных. Копирует содержимое источника в приемник, источник не изменяется.
    \param in приемник
    \param out источник
    */
    void mov(const std::string &, const std::string &);
    /*!
    \brief Сложение данных.
    add приемник, источник.
    Складывает содержимое источника и приемника, результат записывается в приемник, источник не изменяется.
    \param in приемник
    \param out источник
    */
    void add(const std::string &, const std::string &);
    /*!
    \brief Вычитание данных.
    sub приемник, источник.
    Вычитает содержимое источника из приемника, результат записывается в приемник, источник не изменяется.
    \param in приемник
    \param out источник
    */
    void sub(const std::string &, const std::string &);
    /*!
    \brief Операция xor.
    xor приемник, источник.
    Выполняет операцию xor источника и приемника, результат записывается в приемник, источник не изменяется.
    \param in приемник
    \param out источник
    */
    void xor_(const std::string &, const std::string &);
    /*!
    \brief Операция and.
    and приемник, источник.
    Выполняет операцию xor источника и приемника, результат записывается в приемник, источник не изменяется.
    \param in приемник
    \param out источник
    */
    void and_(const std::string &, const std::string &);
    /*!
    \brief Пересылка данных.
    cmp приемник, источник.
    Выполняет операцию сравнения источника и приемника, результат не изменяется, источник не изменяется.
    \param in приемник
    \param out источник
    \return 1 - равны, иначе - 0
    /*!
    \brief Функция для сравнения операндов
    */
    bool cmp(const std::string &, const std::string &);
    /*!
    \brief Функция для добавления переменных
    */
    void add_integer(int, const std::string &);
    /*!
    \brief Запись в stack_block.
    push источник.
    Записывает значение во временную память.
    \param in источник
    */
    void push(const std::string &);
    /*!
    \brief Возврат из stack_block.
    pop приемник.
    Возвращает значение из временной памяти.
    \param in приемник
    \return Байт, слово, или двйоное слово
    */
    void pop(const std::string &);
    /*!
    \brief Функция для работы с процедурами
    */
    void call(int);
    /*!
    \brief Функция, проверяюшая пользовательский код в файле перед компиляцией
    */
    int comp(const std::string &);
    /*!
    \brief Функция для обработки пользовательских данных
    */
    bool parser(const std::string &);
    /*!
    \brief Функция для проверки данных в файле и последующая работа с ними
    */
    bool file_parser(std::string filename);
    /*!
    \brief
    Проверка на наличие названий частей регистров
    */
    bool validator_parts(const std::string &);
    /*!
    \brief
    Проверка названия регистра
    */
    bool validator_reg(const std::string &);
    /*!
    \brief
    Проверка названия служебного регистра
    */
    bool validator_cr_reg(const std::string &);
    /*!
    \brief
    Проверка названий команд, у которых два входных параметра
    */
    bool validator_command_double(const std::string &);
    /*!
    \brief
    Проверка названий команд, у которых один входной параметр
    */
    bool validator_command(const std::string &);
    /*!
    \brief
    Проверка на наличие проверяемого названия в пользовательских переменных
    */
    bool validator_title(const std::string &);
    /*!
    \brief
    Проверка на наличие меток call-ret
    */
    bool validator_callret_title(const std::string &);
    /*!
    \brief
    Проверка на наличие меток jne
    */
    bool validator_labels(const std::string &);
    /*!
    \brief
    Проверка на принадлежность параметра к типу int
    */
    bool isint(const std::string &);
    /*!
    \brief
    Проверка на четность числа единиц (флаг PF)
    */
    void parity(const std::string &);
    /*!
    \brief
    Проверка на 0 (флаг OF)
    */
    void zero(const std::string &in);
    /*!
    \brief
    Проверка на наличие флага
    */
    void flags_check(const std::string &in);
    word& return_flags_by_string(const std::string &title); //возвращение флагов

};
/*!
\brief Оператор вывода.
Выводит значение word
*/
std::ostream & operator<<(std::ostream &out, word &rhs);
#endif

