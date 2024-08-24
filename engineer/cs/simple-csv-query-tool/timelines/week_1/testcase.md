# Lexer testcases

### 1. Tokenize Simple SELECT Statement

```sql
SELECT id, name FROM users;
```

```cpp
Ok({
    Token::Keyword(Keyword::Select),
    Token::Identifier("id"),
    Token::Comma,
    Token::Identifier("name"),
    Token::Keyword(Keyword::From),
    Token::Identifier("users"),
    Token::SemiColon,
    Token::Eof
})
```
### 2. Tokenize SELECT Statement with WHERE Clause

```sql
SELECT id, price, discount FROM products WHERE price >= 100;
```

```cpp
Ok({
    Token::Keyword(Keyword::Select),
    Token::Identifier("id"),
    Token::Comma,
    Token::Identifier("price"),
    Token::Comma,
    Token::Identifier("discount"),
    Token::Keyword(Keyword::From),
    Token::Identifier("products"),
    Token::Keyword(Keyword::Where),
    Token::Identifier("price"),
    Token::GtEq,
    Token::Number("100"),
    Token::SemiColon,
    Token::Eof
})
```

### 3. Tokenize SELECT Statement with ORDER BY

```sql
SELECT name, email FROM users ORDER BY email;
```

```cpp
Ok({
    Token::Keyword(Keyword::Select),
    Token::Identifier("name"),
    Token::Comma,
    Token::Identifier("email"),
    Token::Keyword(Keyword::From),
    Token::Identifier("users"),
    Token::Keyword(Keyword::Order),
    Token::Keyword(Keyword::By),
    Token::Identifier("email"),
    Token::SemiColon,
    Token::Eof
})
```

### 4. Tokenize SELECT with WHERE and Logical Operators

```sql
SELECT id, name FROM users WHERE age >= 20 AND age <= 30 OR is_admin = 1;
```

```cpp
Ok({
    Token::Keyword(Keyword::Select),
    Token::Identifier("id"),
    Token::Comma,
    Token::Identifier("name"),
    Token::Keyword(Keyword::From),
    Token::Identifier("users"),
    Token::Keyword(Keyword::Where),
    Token::Identifier("age"),
    Token::GtEq,
    Token::Number("20"),
    Token::Keyword(Keyword::And),
    Token::Identifier("age"),
    Token::LtEq,
    Token::Number("30"),
    Token::Keyword(Keyword::Or),
    Token::Identifier("is_admin"),
    Token::Eq,
    Token::Number("1"),
    Token::SemiColon,
    Token::Eof
})
```

### 5. Tokenize CREATE TABLE Statement

```sql
CREATE TABLE users (id INT PRIMARY KEY, name VARCHAR(255), is_admin BOOL);
```

```cpp
Ok({
    Token::Keyword(Keyword::Create),
    Token::Keyword(Keyword::Table),
    Token::Identifier("users"),
    Token::LeftParen,
    Token::Identifier("id"),
    Token::Keyword(Keyword::Int),
    Token::Keyword(Keyword::Primary),
    Token::Keyword(Keyword::Key),
    Token::Comma,
    Token::Identifier("name"),
    Token::Keyword(Keyword::Varchar),
    Token::LeftParen,
    Token::Number("255"),
    Token::RightParen,
    Token::Comma,
    Token::Identifier("is_admin"),
    Token::Keyword(Keyword::Bool),
    Token::RightParen,
    Token::SemiColon,
    Token::Eof
})
```

### 6. Tokenize UPDATE Statement

```sql
UPDATE products SET code = "promo", discount = 10 WHERE price < 100;
```

```cpp
Ok({
    Token::Keyword(Keyword::Update),
    Token::Identifier("products"),
    Token::Keyword(Keyword::Set),
    Token::Identifier("code"),
    Token::Eq,
    Token::String("promo"),
    Token::Comma,
    Token::Identifier("discount"),
    Token::Eq,
    Token::Number("10"),
    Token::Keyword(Keyword::Where),
    Token::Identifier("price"),
    Token::Lt,
    Token::Number("100"),
    Token::SemiColon,
    Token::Eof
})
```

### 7. Tokenize INSERT INTO Statement

```sql
INSERT INTO users (name, email, age, is_admin) VALUES ("Test", "test@test.com", 20, TRUE);
```

```cpp
Ok({
    Token::Keyword(Keyword::Insert),
    Token::Keyword(Keyword::Into),
    Token::Identifier("users"),
    Token::LeftParen,
    Token::Identifier("name"),
    Token::Comma,
    Token::Identifier("email"),
    Token::Comma,
    Token::Identifier("age"),
    Token::Comma,
    Token::Identifier("is_admin"),
    Token::RightParen,
    Token::Keyword(Keyword::Values),
    Token::LeftParen,
    Token::String("Test"),
    Token::Comma,
    Token::String("test@test.com"),
    Token::Comma,
    Token::Number("20"),
    Token::Comma,
    Token::Keyword(Keyword::True),
    Token::RightParen,
    Token::SemiColon,
    Token::Eof
})
```

### 8. Tokenize Single Quoted String

```sql
'single quoted "string"'
```

```cpp
Ok({
    Token::String("single quoted \"string\""),
    Token::Eof
})
```

### 9. Tokenize Incorrect NEQ Operator

```sql
SELECT * FROM table WHERE column ! other
```

```cpp
Err({
    ErrorKind::UnexpectedWhileParsingOperator(' ', Token::Neq),
    Location{1, 35},
    "SELECT * FROM table WHERE column ! other"
})
```

### 10. Tokenize Unclosed NEQ Operator

```sql
SELECT * FROM table WHERE column !
```

```cpp
Err({
    ErrorKind::OperatorNotClosed(Token::Neq),
    Location{1, 35},
    "SELECT * FROM table WHERE column !"
})
```

### 11. Tokenize Unclosed Double-Quoted String

```sql
SELECT * FROM table WHERE string = "not closed
```

```cpp
Err({
    ErrorKind::StringNotClosed,
    Location{1, 47},
    "SELECT * FROM table WHERE string = \"not closed"
})
```

### 12. Tokenize Unclosed Single-Quoted String

```sql
SELECT * FROM table WHERE string = 'not closed
```

```cpp
Err({
    ErrorKind::StringNotClosed,
    Location{1, 47},
    "SELECT * FROM table WHERE string = \'not closed"
})
```

### 13. Tokenize Unsupported Token

```sql
SELECT * FROM ^ WHERE unsupported = 1;
```

```cpp
Err({
    ErrorKind::UnexpectedOrUnsupportedToken('^'),
    Location{1, 15},
    "SELECT * FROM table WHERE ^ unsupported = 1;"
})
```
