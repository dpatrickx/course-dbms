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
    GROUPOP = 265,
    GROUP = 266,
    BY = 267,
    IDENTIFIER = 268,
    INSERT = 269,
    INTO = 270,
    VALUES = 271,
    YIN = 272,
    VALUEIT = 273,
    CREATE = 274,
    TABLE = 275,
    PRIMARY = 276,
    KEY = 277,
    TYPE = 278,
    NULLL = 279,
    IS = 280,
    KIND = 281,
    IOKIND = 282,
    SELECT = 283,
    FROM = 284,
    WHERE = 285,
    EXPRESSION = 286,
    JOIN = 287,
    ON = 288,
    USE = 289,
    IF = 290,
    EXISTS = 291,
    DROP = 292,
    JUDGEOP = 293,
    CONNOP = 294,
    UPDATE = 295,
    SET = 296,
    DESC = 297,
    DELETE = 298,
    OPERATOR = 299
  };
#endif

/* Value type.  */


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_YACC_TAB_H_INCLUDED  */
