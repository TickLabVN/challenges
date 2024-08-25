#include <iostream>
#include <vector>
#include <string>

// Base class for SQL Statements
class Statement {
public:
  virtual ~Statement() = default;
  virtual std::string toString() const = 0;
};

// Base class for all expressions
class Expression {
public:
    virtual ~Expression() = default;
    virtual std::string toString() const = 0;
};

// Enum class for SQL binary operators
enum class BinaryOperator { Eq, Neq, Lt, LtEq, Gt, GtEq, Plus, Minus, Mul, Div, And, Or };

// Enum class for SQL unary operators
enum class UnaryOperator { Plus, Minus };

// Enum class for SQL constraints
enum class Constraint {
    PrimaryKey,
    Unique
};

// Derived class for CREATE statements
class Create : public Statement {
private:
  std::string name; // table name
  std::vector<Column> columns; // table columns
public:
  std::string toString() const {  /* TODO */ }
};

// Derived class for SELECT statements
class Select : public Statement {
private:
    std::vector<Expression*> columns;
    std::string from;
    Expression* where;
    std::vector<Expression*> orderBy;
public:
  std::string toString() const {  /* TODO */ }
};

// Derived class for DELETE statements
class Delete : public Statement {
private:
    std::string from;
    Expression* where;
public:
  std::string toString() const {  /* TODO */ }
};

// Derived class for UPDATE statements
class Update : public Statement {
private:
    std::string table;
    std::vector<Assignment*> columns;
    Expression* where;
public:
  std::string toString() const {  /* TODO */ }
};

// Derived class for INSERT statements
class Insert : public Statement {
private:
    std::string into;
    std::vector<std::string> columns;
    std::vector<Expression*> values;
public:
  std::string toString() const {  /* TODO */ }
};

// Derived class for DROP statement
class Drop : public Statement {
private:
  std::string name; // table name
public:
  std::string toString() const {  /* TODO */ }
};

// Class to represent an Assignment in SQL
class Assignment {
private:
  std::string identifier;  // The column name or identifier
  Expression* value;       // The expression assigned to the column
};

// Class to represent a Column in SQL
class Column {
private:
  std::string name;                      // The name of the column
  DataType dataType;                     // The data type of the column
  std::vector<Constraint*> constraints;  // Constraints on the column
  Column(const std::string& name, DataType dataType, std::vector<Constraint*> constraints);
public:
  // Static method to create a new Column without constraints
  static Column newColumn(const std::string& name, DataType dataType);
  // Static method to create a Column with PrimaryKey constraint
  static Column primaryKey(const std::string& name, DataType dataType);
  // Static method to create a Column with Unique constraint
  static Column unique(const std::string& name, DataType dataType);
};

// Derived class for identifiers
class Identifier : public Expression {
private:
  std::string ident;
public:
  std::string toString() const {  /* TODO */ }
};

// Derived class for values
class Value : public Expression {
private:
  Type type;
  std::string str_val;
  bool bool_val;
  int64_t num_val;
public:
  enum class Type { String, Bool, Number };
  std::string toString() const {  /* TODO */ }
}

// Derived class for wildcards
class Wildcard : public Expression {
public:
    std::string toString() const {  /* TODO */ }
};

// Derived class for binary operations
class BinaryOperation : public Expression {
private:
  Expression* left;
  BinaryOperator op;
  Expression* right;
public:
  std::string toString() const {  /* TODO */ }
};

// Derived class for unary operations
class UnaryOperation : public Expression {
private:
  UnaryOperator op;
  Expression* expr;
public:
  std::string toString() const {  /* TODO */ }
};

// Derived class for nested expressions
class Nested : public Expression {
private:
  Expression* expr;
public:
  std::string toString() const {  /* TODO */ }
};

// Class for SQL data types
class DataType {
private:
  Type type;
  size_t size; // Used for VARCHAR, example: VARCHAR(50), VARCHAR(100), VARCHAR(255)
public:
  enum class Type { Int, Bool, Varchar };
};
