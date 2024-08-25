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
    order_by: []
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
    order_by: []
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
