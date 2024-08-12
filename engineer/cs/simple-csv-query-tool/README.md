# Building the `exql` CSV Data Query Tool

Your task in this challenge is creating a tool to manipulate CSV data by using a simple SQL-like language.

## Key Concepts

Before we delve into the details, let's cover some important concepts:

- **CSV (Comma-Separated Values)**: CSV is a simple file format used to store tabular data. Each row in the file corresponds to a row in the table, and data fields within each row are separated by commas.
- **SQL (Structured Query Language)**: SQL is a powerful language used for managing and manipulating structured data in databases. It enables various operations like querying, inserting, updating, and deleting data.

## Your tasks

Your task is to develop a program named `exql` that can read CSV files and execute **SQL-like** queries on the data within. When executed with a specific query and CSV file name as parameters, the program should display the queried data on the screen. Here's an example of usage:

```bash
exql "SELECT * FROM data.csv"
```

In this example, the `exql` program will read the `data.csv` file and execute the `SELECT *` query, fetching all data from the file. The program will then display the retrieved data on the terminal.

To make it easier, we can assume that CSV files is always a table `M`x`N + 1`, with the first row contains column names, `M` is number of columns and `N` rows of data. All column names have [`snake_case`](https://en.wikipedia.org/wiki/Snake_case) format. For instance:

| id | first_name | last_name | age | major |
|---|---|---|--|--|
| #1 | Vinh | Nguyen Phuc | 22 | Computer Science |
| #2 | Quan | Nguyen Hong | 20 | Computer Engineering |
| #3 | Phu  | Nguyen Ngoc | 20 | Mechanical Engineering |

## Requirements

Your program should have these components:

- **Interactive shell**: User can enter queries to manipulate CSV data.
- **Query parser**: Translate SQL-like query strings into helpful information. The program should understand basic SQL-like syntax, including `SELECT`, `INSERT`, `DELETE`, `UPDATE` statements.
- **CSV Reading**: Design the program to read and interpret CSV files. Assume that the CSV files are properly formatted and include header rows.

The executable file `exql` must be:

- Run and compiled on Linux operating system
- Use C++ >= 17
- NO MEMORY LEAKS after program exit

The language description is at [here](./query-language-description.md).

## Learning Objectives

- Learn the fundamentals of SQL and its application for data querying.
- Enhance your programming skills by building a data manipulation tool.
- Gain practical experience with I/O operations for reading and processing CSV files.

## Timelines

The challenge will last for 6 weeks but may extend or conclude sooner based on your ability. You should report your work in each week by a document (can be [Notion](https://www.notion.so/) notes, markdown, PDF or MS Word files ...).

## Documents / Keywords

- Learn CPP: <https://www.learncpp.com/>
- CPP Roadmap for developers (advanced): <https://roadmap.sh/cpp>
- RAII
- Rule of zero, rules of three, rules of five
- Cpp Core Guidelines: <https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#main>
