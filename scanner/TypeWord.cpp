//
// Created by 3crabs on 12.09.2020.
//

#ifndef DEFS_H
#define DEFS_H

enum TypeWord {

    // типы данных
    VOID,
    DOUBLE,
    INT,
    BOOL,
    CHAR,
    SHORT,
    LONG,
    TRUE,
    FALSE,
    RETURN,

    // Знаки арифметических операций
    PLS,
    MNS,
    DIV,
    MOD,
    MUL,
    INC,
    DEC,

    // Ключевые слова
    WHILE,
    IF,
    ELSE,
    SWITCH,
    CASE,
    BREAK,
    DEFAULT,

    // Идентификатор
    ID,

    // Знаки сравнений
    LESS,
    LARGER,
    LESS_EQUAL,
    LARGER_EQUAL,
    EQUAL,
    NOT_EQUAL,
    EQUAL_EQUAL,

    // Специальные знаки
    POINT_COMMA,
    OPEN_KRUGLAY,
    CLOSE_KRUGLAY,
    OPEN_FIGURNAY,
    CLOSE_FIGURNAY,
    COMMA,
    POINT_POINT,

    // константы
    CONST_DEC,
    CONST_HEX,
    CONST_CHAR,
    CONST_STR,

    // Конец файла
    END_OF_FILE,

    // Ошибочный символ
    ERROR,
};

#endif // DEFS_H
