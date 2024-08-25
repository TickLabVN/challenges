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

    C --> ID[id]
    C --> NAME[name]
    F --> USERS[users]
    W --> NONE[null]
    O --> EMPTY[empty array]
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

    C --> WC[*]
    F --> USERS[users]
    W --> NONE[null]
    O --> EMPTY[empty array]
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

    C --> ID[id]
    C --> PRICE[price]
    C --> DISCOUNT[discount]
    
    F --> PRODUCTS[products]

    W --> EXPR1[(BinaryOperation)]
    EXPR1 --> LEFT[price]
    EXPR1 --> OP[/GtEq/]
    EXPR1 --> RIGHT[100]

    O --> EMPTY[empty array]
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

    C --> ID[id]
    C --> PRICE[price]
    C --> DISCOUNT[discount]
    C --> EXPR1[(BinaryOperation)]
    EXPR1 --> LEFT1[(BinaryOperation)]
    EXPR1 --> OP1[/Div/]
    EXPR1 --> RIGHT1[100]
    LEFT1 --> LEFT2[price]
    LEFT1 --> OP2[/Mul/]
    LEFT1 --> RIGHT2[discount]
    
    F --> PRODUCTS[products]

    W --> OP3[(BinaryOperation)]
    OP3 --> LEFT3[(BinaryOperation)]
    OP3 --> OP4[/Or/]
    OP3 --> RIGHT4[(BinaryOperation)]

    LEFT3 --> LEFT4[(BinaryOperation)]
    LEFT3 --> OP5[/And/]
    LEFT3 --> RIGHT5[(BinaryOperation)]
    
    LEFT4 --> LEFT5[100]
    LEFT4 --> OP6[/LtEq/]
    LEFT4 --> RIGHT6[price]

    RIGHT5 --> LEFT6[price]
    RIGHT5 --> OP7[/Lt/]
    RIGHT5 --> RIGHT7[1000]

    RIGHT4 --> LEFT7[discount]
    RIGHT4 --> OP8[/Lt/]
    RIGHT4 --> RIGHT8[(BinaryOperation)]

    RIGHT8 --> LEFT8[10]
    RIGHT8 --> OP9[/Plus/]
    RIGHT8 --> RIGHT9[(Nested BinaryOperation)]

    RIGHT9 --> LEFT9[2]
    RIGHT9 --> OP10[/Mul/]
    RIGHT9 --> RIGHT10[20]

    O --> EMPTY[empty array]
```
