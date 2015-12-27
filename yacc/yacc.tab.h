/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_YACC_TAB_H_INCLUDED
# define YY_YY_YACC_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INTEGER = 258,
    DATABASE = 259,
    SHOW = 260,
    DATABASES = 261,
    TABLES = 262,
    CHECK = 263,
    IN = 264,
    IDENTIFIER = 265,
    INSERT = 266,
    INTO = 267,
    VALUES = 268,
    YIN = 269,
    VALUEIT = 270,
    CREATE = 271,
    TABLE = 272,
    PRIMARY = 273,
    KEY = 274,
    TYPE = 275,
    NULLL = 276,
    IS = 277,
    KIND = 278,
    IOKIND = 279,
    SELECT = 280,
    FROM = 281,
    WHERE = 282,
    EXPRESSION = 283,
    JOIN = 284,
    ON = 285,
    USE = 286,
    IF = 287,
    EXISTS = 288,
    DROP = 289,
    JUDGEOP = 290,
    CONNOP = 291,
    UPDATE = 292,
    SET = 293,
    DESC = 294,
    DELETE = 295,
    OPERATOR = 296
  };
#endif

/* Value type.  */


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_YACC_TAB_H_INCLUDED  */
