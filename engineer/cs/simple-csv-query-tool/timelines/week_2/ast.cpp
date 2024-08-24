#include <iostream>
#include <vector>
#include <string>

// Base class for SQL Statements
class Statement {
public:
  virtual ~Statement() = default;
  virtual std::string toString() const = 0;
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
    std::vector<Expression*> orderBy;'
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
