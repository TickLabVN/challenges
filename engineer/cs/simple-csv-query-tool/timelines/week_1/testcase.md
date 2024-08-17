# Lexer testcases

## Test case 1: Tokenize Simple SELECT Statement
**SQL Input:**
```sql
SELECT id, name FROM users;
```
**Expected Result:**
```cpp
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
```

