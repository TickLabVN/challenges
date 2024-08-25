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
    W --> OP[>=]
    OP --> PRICE2[price]
    OP --> NUM[100]
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
    C --> EXPR[(price * discount / 100)]
    F --> PRODUCTS[products]
    W --> OP1[<=]
    OP1 --> VAL100[100]
    OP1 --> PRICE2[price]
    W --> AND[AND]
    AND --> OP2[<]
    OP2 --> PRICE3[price]
    OP2 --> VAL1000[1000]
    AND --> OR[OR]
    OR --> OP3[<]
    OP3 --> DISCOUNT2[discount]
    OP3 --> PLUS[+]
    PLUS --> VAL10[10]
    PLUS --> NESTED[(2 * 20)]
    O --> EMPTY[empty array]
```
