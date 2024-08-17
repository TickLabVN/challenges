# Week 1
In this week, we will implement:
- Command-Line Interface
- SQL Lexer

## Command-Line Interface
The goal is to create a command-line tool named `exql` that allows users to run SQL queries directly from the terminal. For example, running the command:
```sh
./exql "SELECT id, first_name, last_name, email FROM personnel.csv"
```
should execute the SQL query on the specified CSV file.

To start, we'll build a simple program that can accept and display SQL queries from the command line. Here's an example of how the CLI might look:
```sh
> ./exql "SELECT id, first_name, last_name, email FROM personnel.csv"
Executing query: SELECT id, first_name, last_name, email FROM personnel.csv
```
This setup will lay the foundation for implementing the SQL lexer, which will parse and process the SQL queries in later steps.

## SQL Lexer
The SQL Lexer is responsible for breaking down SQL queries (stream of characters) into individual tokens (stream of tokens), these tokens form the basis for further analysis (SQL parser). This process is known as lexical analysis or tokenization.

### Steps to Implement

1. **Define Tokens**:  
- Begin by defining the tokens your lexer will recognize. These tokens are represented using an `enum` or similar structure.
  ```cpp
  enum class TokenType {
    ...
  };
  
  class Token {
  public:
      TokenType type;
      std::string value;
  };
  ```
- Tokens include:
  - **Keywords**: Reserved SQL words related to:
    - Data Manipulation Language (DML): insert, update, delete.
    - Data Query Language (DQL): select.
    - Data Definition Language (DDL): create, drop.
    
    ***<ins>Note</ins>***: The implementation will not include support for foreign keys, transactions, nested queries, joins, or database creation.
  - **Identifiers**: Names of columns, tables.
  - **Literals**: Values like strings, numbers and boolean values (TRUE, FALSE).
  - **Operators**: Symbols such as `=`, `!=`, `<`, `>`, `+`, `-`, `*`, `/`,...
  - **Separators**: Characters like commas `,`, semicolons `;`, parentheses `(` and `)`.
  - **Whitespace**: Spaces, tabs, and newlines that separate tokens.

2. **Implement Token Parsing Functions**:

    Write functions to handle parsing of each token type. For example:
  - **Keywords and Identifiers**:
    ```cpp
    Token tokenizeKeywordOrIdentifier(){
      // Logic to tokenize keywords or identifiers
    }
    ```
  - **Literals**:
    ```cpp
    Token tokenizeString(){
      // Logic to tokenize string literals
    }

    Token tokenizeNumber(){
      // Logic to tokenize number literals
    }

    Token tokenizeBoolean() {
      // Logic to tokenize boolean literals
    }
    ```
  - **Operators and Separators:**:
    ```cpp
    Token tokenizeOperatorOrSeparator() {
      // Logic to tokenize operators and separators
    }
    ```
3. **Handle Errors**:

    Implement error handling for unexpected or unsupported tokens. Define the `ErrorKind` enum and `TokenizerError` class with `Location` included:
    ```cpp
    enum class ErrorKind {
      UnexpectedOrUnsupportedToken,
      UnexpectedWhileParsingOperator,
      OperatorNotClosed,
      StringNotClosed,
      Other
    };
    
    struct Location {
      size_t line; // Line number starting at 1
      size_t col;  // Column number starting at 1
    };
    
    class TokenizerError {
    public:
      ErrorKind kind;
      Location location; // Location of the error
      std::string input; // Input string that caused the error
    };
    ```
4. **Testing**:

     Test the lexer with various SQL queries to ensure it correctly identifies and processes tokens. Please check some testcases in 
  

