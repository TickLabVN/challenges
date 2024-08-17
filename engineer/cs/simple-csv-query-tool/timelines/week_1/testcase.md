# Lexer testcases

### 1. Tokenize Simple SELECT Statement

```sql
SELECT id, name FROM users;
```

```cpp
Ok({
    Token::Keyword(Keyword::Select),
    Token::Whitespace(Whitespace::Space),
    Token::Identifier("id"),
    Token::Comma,
    Token::Whitespace(Whitespace::Space),
    Token::Identifier("name"),
    Token::Whitespace(Whitespace::Space),
    Token::Keyword(Keyword::From),
    Token::Whitespace(Whitespace::Space),
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
    Token::Whitespace(Whitespace::Space),
    Token::Identifier("id"),
    Token::Comma,
    Token::Whitespace(Whitespace::Space),
    Token::Identifier("price"),
    Token::Comma,
    Token::Whitespace(Whitespace::Space),
    Token::Identifier("discount"),
    Token::Whitespace(Whitespace::Space),
    Token::Keyword(Keyword::From),
    Token::Whitespace(Whitespace::Space),
    Token::Identifier("products"),
    Token::Whitespace(Whitespace::Space),
    Token::Keyword(Keyword::Where),
    Token::Whitespace(Whitespace::Space),
    Token::Identifier("price"),
    Token::Whitespace(Whitespace::Space),
    Token::GtEq,
    Token::Whitespace(Whitespace::Space),
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
    Token::Whitespace(Whitespace::Space),
    Token::Identifier("name"),
    Token::Comma,
    Token::Whitespace(Whitespace::Space),
    Token::Identifier("email"),
    Token::Whitespace(Whitespace::Space),
    Token::Keyword(Keyword::From),
    Token::Whitespace(Whitespace::Space),
    Token::Identifier("users"),
    Token::Whitespace(Whitespace::Space),
    Token::Keyword(Keyword::Order),
    Token::Whitespace(Whitespace::Space),
    Token::Keyword(Keyword::By),
    Token::Whitespace(Whitespace::Space),
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
    Token::Whitespace(Whitespace::Space),
    Token::Identifier("id"),
    Token::Comma,
    Token::Whitespace(Whitespace::Space),
    Token::Identifier("name"),
    Token::Whitespace(Whitespace::Space),
    Token::Keyword(Keyword::From),
    Token::Whitespace(Whitespace::Space),
    Token::Identifier("users"),
    Token::Whitespace(Whitespace::Space),
    Token::Keyword(Keyword::Where),
    Token::Whitespace(Whitespace::Space),
    Token::Identifier("age"),
    Token::Whitespace(Whitespace::Space),
    Token::GtEq,
    Token::Whitespace(Whitespace::Space),
    Token::Number("20"),
    Token::Whitespace(Whitespace::Space),
    Token::Keyword(Keyword::And),
    Token::Whitespace(Whitespace::Space),
    Token::Identifier("age"),
    Token::Whitespace(Whitespace::Space),
    Token::LtEq,
    Token::Whitespace(Whitespace::Space),
    Token::Number("30"),
    Token::Whitespace(Whitespace::Space),
    Token::Keyword(Keyword::Or),
    Token::Whitespace(Whitespace::Space),
    Token::Identifier("is_admin"),
    Token::Whitespace(Whitespace::Space),
    Token::Eq,
    Token::Whitespace(Whitespace::Space),
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
    Token::Whitespace(Whitespace::Space),
    Token::Keyword(Keyword::Table),
    Token::Whitespace(Whitespace::Space),
    Token::Identifier("users"),
    Token::Whitespace(Whitespace::Space),
    Token::LeftParen,
    Token::Identifier("id"),
    Token::Whitespace(Whitespace::Space),
    Token::Keyword(Keyword::Int),
    Token::Whitespace(Whitespace::Space),
    Token::Keyword(Keyword::Primary),
    Token::Whitespace(Whitespace::Space),
    Token::Keyword(Keyword::Key),
    Token::Comma,
    Token::Whitespace(Whitespace::Space),
    Token::Identifier("name"),
    Token::Whitespace(Whitespace::Space),
    Token::Keyword(Keyword::Varchar),
    Token::LeftParen,
    Token::Number("255"),
    Token::RightParen,
    Token::Comma,
    Token::Whitespace(Whitespace::Space),
    Token::Identifier("is_admin"),
    Token::Whitespace(Whitespace::Space),
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
    Token::Whitespace(Whitespace::Space),
    Token::Identifier("products"),
    Token::Whitespace(Whitespace::Space),
    Token::Keyword(Keyword::Set),
    Token::Whitespace(Whitespace::Space),
    Token::Identifier("code"),
    Token::Whitespace(Whitespace::Space),
    Token::Eq,
    Token::Whitespace(Whitespace::Space),
    Token::String("promo"),
    Token::Comma,
    Token::Whitespace(Whitespace::Space),
    Token::Identifier("discount"),
    Token::Whitespace(Whitespace::Space),
    Token::Eq,
    Token::Whitespace(Whitespace::Space),
    Token::Number("10"),
    Token::Whitespace(Whitespace::Space),
    Token::Keyword(Keyword::Where),
    Token::Whitespace(Whitespace::Space),
    Token::Identifier("price"),
    Token::Whitespace(Whitespace::Space),
    Token::Lt,
    Token::Whitespace(Whitespace::Space),
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
    Token::Whitespace(Whitespace::Space),
    Token::Keyword(Keyword::Into),
    Token::Whitespace(Whitespace::Space),
    Token::Identifier("users"),
    Token::Whitespace(Whitespace::Space),
    Token::LeftParen,
    Token::Identifier("name"),
    Token::Comma,
    Token::Whitespace(Whitespace::Space),
    Token::Identifier("email"),
    Token::Comma,
    Token::Whitespace(Whitespace::Space),
    Token::Identifier("age"),
    Token::Comma,
    Token::Whitespace(Whitespace::Space),
    Token::Identifier("is_admin"),
    Token::RightParen,
    Token::Whitespace(Whitespace::Space),
    Token::Keyword(Keyword::Values),
    Token::Whitespace(Whitespace::Space),
    Token::LeftParen,
    Token::String("Test"),
    Token::Comma,
    Token::Whitespace(Whitespace::Space),
    Token::String("test@test.com"),
    Token::Comma,
    Token::Whitespace(Whitespace::Space),
    Token::Number("20"),
    Token::Comma,
    Token::Whitespace(Whitespace::Space),
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

### 9.
