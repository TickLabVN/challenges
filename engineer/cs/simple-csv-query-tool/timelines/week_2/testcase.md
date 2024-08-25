# Parser testcases

### 1. Parse Simple SELECT Statement

```sql
SELECT id, name FROM users;
```

```cpp
Statement::Select {
    columns: [
        Expression::Identifier("id"),
        Expression::Identifier("name")
    ],
    from: "users",
    where: nullptr,
    orderBy: []
}
```

```mermaid
flowchart TD
    S[Select]
    S --> C[Columns]
    S --> F[From]
    S --> W[Where]
    S --> O[Order By]

    C --> IDENTIFIER1[Identifier] --> ID[id]
    C --> IDENTIFIER2[Identifier] --> NAME[name]
    F --> USERS[users]
    W --> NONE[null]
    O --> EMPTY["[]"]
```

### 2. Parse SELECT Statement with Wildcard

```sql
SELECT * FROM users;
```

```cpp
Statement::Select {
    columns: [
        Expression::Wildcard
    ],
    from: "users",
    where: nullptr,
    orderBy: []
}
```

```mermaid
flowchart TD
    S[Select]
    S --> C[Columns]
    S --> F[From]
    S --> W[Where]
    S --> O[Order By]

    C --> WC[Wildcard]
    F --> USERS[users]
    W --> NONE[null]
    O --> EMPTY["[]"]
```

### 3. Parse SELECT Statement with WHERE Clause

```sql
SELECT id, price, discount FROM products WHERE price >= 100;
```

```cpp
Statement::Select {
    columns: [
        Expression::Identifier("id"),
        Expression::Identifier("price"),
        Expression::Identifier("discount")
    ],
    from: "products",
    where: Expression::BinaryOperation {
        left: Expression::Identifier("price"),
        op: BinaryOperator::GtEq,
        right: Expression::Value(Value::Number(100))
    },
    orderBy: []
}
```

```mermaid
flowchart TD
    S[Select]
    S --> C[Columns]
    S --> F[From]
    S --> W[Where]
    S --> O[Order By]

    C --> IDENTIFIER1[Identifier] --> ID[id]
    C --> IDENTIFIER2[Identifier] --> PRICE[price]
    C --> IDENTIFIER3[Identifier] --> DISCOUNT[discount]
    
    F --> PRODUCTS[products]

    W --> EXPR1[(BinaryOperation)]
    EXPR1 --> LEFT[Left] --> IDENTIFIER4[Identifier] --> VALUE1[price]
    EXPR1 --> OP[Op] --> OPERATOR[BinaryOperator] --> VALUE2[/GtEq/]
    EXPR1 --> RIGHT[Right] --> VALUE3[Value] --> NUMBER[Number] --> VALUE_NUMBER[100]

    O --> EMPTY["[]"]
```

### 4. Parse SELECT Statement with Expressions

```sql
SELECT id, price, discount, price * discount / 100
FROM products
WHERE 100 <= price AND price < 1000 OR discount < 10 + (2 * 20);
```

```cpp
Statement::Select {
    columns: [
        Expression::Identifier("id"),
        Expression::Identifier("price"),
        Expression::Identifier("discount"),
        Expression::BinaryOperation {
            left: Expression::BinaryOperation {
                left: Expression::Identifier("price"),
                op: BinaryOperator::Mul,
                right: Expression::Identifier("discount")
            },
            op: BinaryOperator::Div,
            right: Expression::Value(Value::Number(100))
        }
    ],
    from: "products",
    where: Expression::BinaryOperation {
        left: Expression::BinaryOperation {
            left: Expression::BinaryOperation {
                left: Expression::Value(Value::Number(100)),
                op: BinaryOperator::LtEq,
                right: Expression::Identifier("price")
            },
            op: BinaryOperator::And,
            right: Expression::BinaryOperation {
                left: Expression::Identifier("price"),
                op: BinaryOperator::Lt,
                right: Expression::Value(Value::Number(1000))
            }
        },
        op: BinaryOperator::Or,
        right: Expression::BinaryOperation {
            left: Expression::Identifier("discount"),
            op: BinaryOperator::Lt,
            right: Expression::BinaryOperation {
                left: Expression::Value(Value::Number(10)),
                op: BinaryOperator::Plus,
                right: Expression::Nested(
                    Expression::BinaryOperation {
                        left: Expression::Value(Value::Number(2)),
                        op: BinaryOperator::Mul,
                        right: Expression::Value(Value::Number(20))
                    }
                )
            }
        }
    },
    orderBy: []
}
```

```mermaid
flowchart TD
    S[Select]
    S --> C[Columns]
    S --> F[From]
    S --> W[Where]
    S --> O[Order By]

    C --> IDENTIFIER1[Identifier] --> ID[id]
    C --> IDENTIFIER2[Identifier] --> PRICE[price]
    C --> IDENTIFIER3[Identifier] --> DISCOUNT[discount]
    C --> EXPR1[(BinaryOperation)]
    EXPR1 --> LEFT1[Left] --> LEFT1_VALUE[(BinaryOperation)]
    EXPR1 --> OPERATOR1[Op] --> OPERATOR1_VALUE[BinaryOperator] --> OP1[/Div/]
    EXPR1 --> RIGHT1[Right] --> RIGHT1_VALUE[Value] --> NUMBER1[Number] --> NUMBER1_VALUE[100] 
    LEFT1_VALUE --> LEFT2[Left] --> LEFT2_IDENTIFIER[Identifier] --> LEFT2_VALUE[price]
    LEFT1_VALUE --> OP2[Op] --> OP2_OPERATOR[BinaryOperator] --> OP2_VALUE[/Mul/]
    LEFT1_VALUE --> RIGHT2[Right] --> RIGHT2_IDENTIFIER[Identifier] --> RIGHT2_VALUE[discount]
    
    F --> PRODUCTS[products]

    W --> OP3[(BinaryOperation)]
    OP3 --> LEFT3[(BinaryOperation)]
    OP3 --> OP4[/Or/]
    OP3 --> RIGHT4[(BinaryOperation)]

    LEFT3 --> LEFT4[(BinaryOperation)]
    LEFT3 --> OP5[/And/]
    LEFT3 --> RIGHT5[(BinaryOperation)]
    
    LEFT4 --> LEFT5[Value] --> NUMBER2[100]
    LEFT4 --> OP6[/LtEq/]
    LEFT4 --> RIGHT6[price]

    RIGHT5 --> LEFT6[price]
    RIGHT5 --> OP7[/Lt/]
    RIGHT5 --> RIGHT7[Value] --> NUMBER3[1000]

    RIGHT4 --> LEFT7[discount]
    RIGHT4 --> OP8[/Lt/]
    RIGHT4 --> RIGHT8[(BinaryOperation)]

    RIGHT8 --> LEFT8[Value] --> NUMBER4[10]
    RIGHT8 --> OP9[/Plus/]
    RIGHT8 --> RIGHT9[(Nested BinaryOperation)]

    RIGHT9 --> LEFT9[Value] --> NUMBER5[2]
    RIGHT9 --> OP10[/Mul/]
    RIGHT9 --> RIGHT10[Value] --> NUMBER6[20]

    O --> EMPTY["[]"]
```

### 5. Parse Select Statement with Order By

```sql
SELECT name, email FROM users ORDER BY email;
```

```cpp
Statement::Select {
    columns: [
        Expression::Identifier("name"),
        Expression::Identifier("email")
    ],
    from: "users",
    where: nullptr,
    order_by: [
        Expression::Identifier("email")
    ]
}
```

```mermaid
flowchart TD
    S[Select]
    S --> C[Columns]
    S --> F[From]
    S --> W[Where]
    S --> O[Order By]

    C --> NAME[name]
    C --> EMAIL[email]
    F --> USERS[users]
    W --> NONE[null]
    O --> EMAIL_ORDER[email]
```

### 6. Parse CREATE TABLE Statement

```sql
CREATE TABLE users (
    id INT PRIMARY KEY,
    name VARCHAR(255),
    email VARCHAR(255) UNIQUE
);
```

```cpp
Statement::Create {
    name: "users",
    columns: [
        Column::primaryKey("id", DataType::Int),
        Column::newColumn("name", DataType::Varchar(255)),
        Column::unique("email", DataType::Varchar(255))
    ]
}
```

```mermaid
flowchart TD
    C[Create]
    C --> N[Name]
    C --> CL[Columns]

    N --> USERS[users]
    
    CL --> ID[id]
    CL --> NAME[name]
    CL --> EMAIL[email]

    ID --> INT[Int]
    ID --> PK[PrimaryKey]

    NAME --> VARCHAR1["Varchar(255)"]
    
    EMAIL --> VARCHAR2["Varchar(255)"]
    EMAIL --> UNIQUE[Unique]
```

### 7. Parse Simple UPDATE Statement

```sql
UPDATE users SET is_admin = 1;
```

```cpp
Statement::Update {
    table: "users",
    columns: [
        Assignment {
            identifier: "is_admin",
            value: Expression::Value(Value::Number(1)),
        }
    ],
    where: nullptr,
}
```

```mermaid
flowchart TD
    U[Update]
    U --> T[Table]
    U --> C[Columns]
    U --> W[Where]

    T --> USERS[users]

    C --> ASSIGN[Assignment]
    ASSIGN --> ID[is_admin]
    ASSIGN --> VAL[1]

    W --> NONE[null]
```

### 8. Parse UPDATE Statement with WHERE Clause

```sql
UPDATE products
SET price = price - 10, discount = 15, stock = 10
WHERE price > 100;
```

```cpp
Statement::Update {
    table: "products",
    columns: [
        Assignment {
            identifier: "price",
            value: Expression::BinaryOperation {
                left: Expression::Identifier("price"),
                op: BinaryOperator::Minus,
                right: Expression::Value(Value::Number(10)),
            }
        },
        Assignment {
            identifier: "discount",
            value: Expression::Value(Value::Number(15))
        },
        Assignment {
            identifier: "stock",
            value: Expression::Value(Value::Number(10))
        }
    ],
    where: Expression::BinaryOperation {
        left: Expression::Identifier("price"),
        op: BinaryOperator::Gt,
        right: Expression::Value(Value::Number(100)),
    }
}
```

```mermaid
flowchart TD
    U[Update]
    U --> T[Table]
    U --> C[Columns]
    U --> W[Where]

    T --> PRODUCTS[products]

    C --> ASSIGN1[Assignment]
    C --> ASSIGN2[Assignment]
    C --> ASSIGN3[Assignment]

    ASSIGN1 --> PRICE[price]
    ASSIGN1 --> VALUE1[(BinaryOperation)]
    VALUE1 --> LEFT1[price]
    VALUE1 --> OP1[-]
    VALUE1 --> RIGHT1[10]

    ASSIGN2 --> DISCOUNT[discount]
    ASSIGN2 --> VALUE2[15]

    ASSIGN3 --> STOCK[stock]
    ASSIGN3 --> VALUE3[10]

    W --> EXPR1[(BinaryOperation)]
    EXPR1 --> LEFT2[price]
    EXPR1 --> OP2[>]
    EXPR1 --> RIGHT2[100]
```

### 9. Parse DELETE Statement

```sql
DELETE FROM products;
```

```cpp
Statement::Delete {
    from: "products",
    where: nullptr
}
```

```mermaid
flowchart TD
    D[Delete]
    D --> F[From]
    D --> W[Where]

    F --> PRODUCTS[products]
    W --> NONE[null]
```

### 10. Parse DELETE Statement with WHERE Clause

```sql
DELETE FROM products WHERE price > 5000;
```

```cpp
Statement::Delete {
    from: "products",
    where: Expression::BinaryOperation {
        left: Expression::Identifier("price"),
        op: BinaryOperator::Gt,
        right: Expression::Value(Value::Number(5000)),
    }
}
```

```mermaid
flowchart TD
    D[Delete]
    D --> F[From]
    D --> W[Where]

    F --> PRODUCTS[products]

    W --> EXPR1[(BinaryOperation)]
    EXPR1 --> LEFT[price]
    EXPR1 --> OP[>]
    EXPR1 --> RIGHT[5000]
```

### 11. Parse INSERT Statement

```sql
INSERT INTO users (id, name, email) VALUES (1, "Test", "test@test.com");
```

```cpp
Statement::Insert {
    into: "users",
    columns: [
        "id",
        "name",
        "email"
    ],
    values: [
        Expression::Value(Value::Number(1)),
        Expression::Value(Value::String("Test")),
        Expression::Value(Value::String("test@test.com"))
    ]
}
```

```mermaid
flowchart TD
    I[Insert]
    I --> INTO[Into]
    I --> C[Columns]
    I --> V[Values]

    INTO --> USERS[users]

    C --> ID[id]
    C --> NAME[name]
    C --> EMAIL[email]

    V --> VAL1[1]
    V --> VAL2["Test"]
    V --> VAL3["test@test.com"]
```

### 12. Parse INSERT Statement without Specified Columns

```sql
INSERT INTO users VALUES (1, "Test", "test@test.com");
```

```cpp
Statement::Insert {
    into: "users",
    columns: [],
    values: [
        Expression::Value(Value::Number(1)),
        Expression::Value(Value::String("Test")),
        Expression::Value(Value::String("test@test.com"))
    ]
}
```

```mermaid
flowchart TD
    I[Insert]
    I --> INTO[Into]
    I --> C[Columns]
    I --> V[Values]

    INTO --> USERS[users]

    C --> EMPTY[empty array]

    V --> VAL1[1]
    V --> VAL2["Test"]
    V --> VAL3["test@test.com"]
```

### 13. Parse DROP TABLE Statement

```sql
DROP TABLE test;
```

```cpp
Statement::Drop("test")
```

```mermaid
flowchart TD
    D[Drop]
    D --> T[test]
```

### 14. Parse Multiple Statements

```sql
DROP TABLE test;
UPDATE users SET is_admin = 1;
SELECT * FROM products;
```

```cpp
[
    Statement::Drop("test"),
    Statement::Update {
        table: "users",
        columns: [
            Assignment {
                identifier: "is_admin",
                value: Expression::Value(Value::Number(1)),
            }
        ],
        where: nullptr,
    },
    Statement::Select {
        columns: [
            Expression::Wildcard
        ],
        from: "products",
        where: nullptr,
        orderBy: [],
    }
]
```

```mermaid
flowchart TD
    M[Multiple Statements]

    M --> D[Drop]
    M --> U[Update]
    M --> S[Select]

    D --> T[test]

    U --> TABLE[Table]
    U --> COL[Columns]
    U --> W_UPDATE[Where]

    TABLE --> USERS[users]

    COL --> ASSIGN[Assignment]
    ASSIGN --> ID[is_admin]
    ASSIGN --> NUM[1]

    W_UPDATE --> NONE_UPDATE[null]

    S --> C[Columns]
    S --> F[From]
    S --> W_SELECT[Where]
    S --> O[Order By]

    C --> WC[*]
    F --> PRODUCTS[products]
    W_SELECT --> NONE_SELECT[null]
    O --> EMPTY[empty array]
```

### 15. Parse Arithmetic Operator Precedence

```cpp
price * discount / 100 < 10 + 20 * 30
```

```cpp
Expression::BinaryOperation {
    left: Expression::BinaryOperation {
        left: Expression::BinaryOperation {
            left: Expression::Identifier("price"),
            op: BinaryOperator::Mul,
            right: Expression::Identifier("discount")
        },
        op: BinaryOperator::Div,
        right: Expression::Value(Value::Number(100))
    },
    op: BinaryOperator::Lt,
    right: Expression::BinaryOperation {
        left: Expression::Value(Value::Number(10)),
        op: BinaryOperator::Plus,
        right: Expression::BinaryOperation {
            left: Expression::Value(Value::Number(20)),
            op: BinaryOperator::Mul,
            right: Expression::Value(Value::Number(30))
        }
    }
}
```

```mermaid
flowchart TD
    OP1[(BinaryOperation)]
    OP2[(BinaryOperation)]
    OP3[(BinaryOperation)]
    OP4[(BinaryOperation)]

    OP1 --> LEFT1[(BinaryOperation)]
    OP1 --> OP5[<]
    OP1 --> RIGHT1[(BinaryOperation)]

    LEFT1 --> LEFT2[(BinaryOperation)]
    LEFT1 --> OP2["/"]
    LEFT1 --> RIGHT2[100]

    LEFT2 --> LEFT3[price]
    LEFT2 --> OP3[*]
    LEFT2 --> RIGHT3[discount]

    RIGHT1 --> LEFT4[10]
    RIGHT1 --> OP4[+]
    RIGHT1 --> RIGHT4[(BinaryOperation)]

    RIGHT4 --> LEFT5[20]
    RIGHT4 --> OP6[*]
    RIGHT4 --> RIGHT5[30]
```

### 16. Parse Nested Arithmetic Precedence

```sql
price * discount >= 10 - (20 + 50) / (2 * (4 + (1 - 1)))
```

```cpp
Expression::BinaryOperation {
    left: Expression::BinaryOperation {
        left: Expression::BinaryOperation {
            left: Expression::Identifier("price"),
            op: BinaryOperator::Mul,
            right: Expression::Identifier("discount")
        },
        op: BinaryOperator::GtEq,
        right: Expression::BinaryOperation {
            left: Expression::Value(Value::Number(10)),
            op: BinaryOperator::Minus,
            right: Expression::BinaryOperation {
                left: Expression::Nested(
                    Expression::BinaryOperation {
                        left: Expression::Value(Value::Number(20)),
                        op: BinaryOperator::Plus,
                        right: Expression::Value(Value::Number(50)),
                    }
                ),
                op: BinaryOperator::Div,
                right: Expression::Nested(
                    Expression::BinaryOperation {
                        left: Expression::Value(Value::Number(2)),
                        op: BinaryOperator::Mul,
                        right: Expression::Nested(
                            Expression::BinaryOperation {
                                left: Expression::Value(Value::Number(4)),
                                op: BinaryOperator::Plus,
                                right: Expression::Nested(
                                    Expression::BinaryOperation {
                                        left: Expression::Value(Value::Number(1)),
                                        op: BinaryOperator::Minus,
                                        right: Expression::Value(Value::Number(1)),
                                    }
                                )
                            }
                        )
                    }
                )
            }
        }
    },
    op: BinaryOperator::GtEq,
    right: Expression::BinaryOperation {
        left: Expression::Value(Value::Number(10)),
        op: BinaryOperator::Minus,
        right: Expression::BinaryOperation {
            left: Expression::Nested(
                Expression::BinaryOperation {
                    left: Expression::Value(Value::Number(20)),
                    op: BinaryOperator::Plus,
                    right: Expression::Value(Value::Number(50)),
                }
            ),
            op: BinaryOperator::Div,
            right: Expression::Nested(
                Expression::BinaryOperation {
                    left: Expression::Value(Value::Number(2)),
                    op: BinaryOperator::Mul,
                    right: Expression::Nested(
                        Expression::BinaryOperation {
                            left: Expression::Value(Value::Number(4)),
                            op: BinaryOperator::Plus,
                            right: Expression::Nested(
                                Expression::BinaryOperation {
                                    left: Expression::Value(Value::Number(1)),
                                    op: BinaryOperator::Minus,
                                    right: Expression::Value(Value::Number(1)),
                                }
                            )
                        }
                    )
                }
            )
        }
    }
}
```

```mermaid
flowchart TD
    OP1[(BinaryOperation)]
    OP2[(BinaryOperation)]
    OP3[(BinaryOperation)]
    OP4[(BinaryOperation)]
    OP5[(BinaryOperation)]
    OP6[(BinaryOperation)]
    OP7[(BinaryOperation)]

    OP1 --> LEFT1[(BinaryOperation)]
    OP1 --> OP8[>=]
    OP1 --> RIGHT1[(BinaryOperation)]

    LEFT1 --> LEFT2[price]
    LEFT1 --> OP2[*]
    LEFT1 --> RIGHT2[discount]

    RIGHT1 --> LEFT3[10]
    RIGHT1 --> OP3[-]
    RIGHT1 --> RIGHT3[(BinaryOperation)]

    RIGHT3 --> LEFT4[(Nested)]
    RIGHT3 --> OP4["/"]
    RIGHT3 --> RIGHT4[(Nested)]

    LEFT4 --> OP5[(BinaryOperation)]
    LEFT4 --> LEFT5[20]
    LEFT4 --> OP6[+]
    LEFT4 --> RIGHT5[50]

    RIGHT4 --> OP7[(BinaryOperation)]
    RIGHT4 --> LEFT6[2]
    RIGHT4 --> OP8[*]
    RIGHT4 --> RIGHT6[(Nested)]

    RIGHT6 --> OP9[(BinaryOperation)]
    RIGHT6 --> LEFT7[4]
    RIGHT6 --> OP10[+]
    RIGHT6 --> RIGHT7[(Nested)]

    RIGHT7 --> OP11[(BinaryOperation)]
    RIGHT7 --> LEFT8[1]
    RIGHT7 --> OP12[-]
    RIGHT7 --> RIGHT8[1]
```
