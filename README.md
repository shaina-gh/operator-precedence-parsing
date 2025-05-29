# Operator Precedence Parsing 

## 🎯 Aim

To implement **Operator Precedence Parsing** in C — a bottom-up parsing technique used to analyze arithmetic expressions and determine their syntactic validity using a precedence table.

---

## ⚙️ Logic Overview

This program:

1. Accepts a set of terminal symbols.
2. Builds an operator precedence table (with relations `<`, `>`, `=`, `-`).
3. Accepts an input string (expression).
4. Parses the string by shifting and reducing according to the precedence relations.
5. Displays each step in the parsing process and finally accepts or rejects the string.

---

## 🧠 Explanation

- **Terminals**: Symbols like `+`, `*`, `i`, `$`, etc., are entered by the user.
- **Precedence Table**: A user-defined matrix indicating precedence relations between terminal pairs.
    - `<` : Shift
    - `>` : Reduce
    - `=` : Equal precedence
    - `-` : No relation (invalid)
- **Parsing Strategy**:
    - Begins with stack initialized to `$`.
    - Input string is appended with `$`.
    - The parser uses top of stack and current input symbol to decide:
        - **Shift** (push input symbol onto the stack),
        - **Reduce** (pop symbols from stack),
        - or **Accept/Reject** based on the table and parsing completion.

---

## 🧪 Sample Input/Output

### Input
```yaml
Enter the number of terminals: 4
Enter the terminals: +i*$
Enter the table values:
Enter the value for + +: >
Enter the value for + i: <
Enter the value for + *: <
Enter the value for + $: >
Enter the value for i +: >
Enter the value for i i: -
Enter the value for i *: >
Enter the value for i $: >
Enter the value for * +: >
Enter the value for * i: <
Enter the value for * *: >
Enter the value for * $: >
Enter the value for $ +: <
Enter the value for $ i: <
Enter the value for $ : <
Enter the value for $ $: -
Enter the input string: i+ii
```

### Output
```yaml
**** OPERATOR PRECEDENCE TABLE ****
+ i * $

. < < >
  i > - > >

. < > >
  $ < < < -

**** STACK INPUT STRING ACTION ****

$ i+ii$ Shift i
$i +ii$ Reduce
$ +ii$ Shift +
$+ ii$ Shift i
$+i *i$ Reduce
$+ i$ Shift *
$+ i$ Shift i
$+i $ Reduce
$+ $ Reduce
$+ $ Reduce
$ $ String is accepted
```
---

## 🌍 Real-World Applications

- **Compilers**: Parsing arithmetic and logical expressions using precedence rules.
- **Expression Evaluators**: In calculators or interpreters, for analyzing and evaluating expressions.
- **Syntax Checkers**: Quickly validating whether an expression conforms to defined grammatical rules.
- **Code Optimization Tools**: Helps in understanding how expressions are structured for optimizing code execution.
  
---
