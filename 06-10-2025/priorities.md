| Operand        | Description                | Precedence | Associativity     |
|----------------|---------------------------|------------|-------------------|
| ()             | Function call, grouping    | Highest    | left to right     |
| []             | Array subscript            | Highest    | left to right     |
| .              | Member access              | Highest    | left to right     |
| ->             | Member access via pointer  | Highest    | left to right     |
| ++, --         | Post-increment/decrement   | High       | left to right     |
| ++, --         | Pre-increment/decrement    | High       | right to left     |
| +, -           | Unary plus/minus           | High       | right to left     |
| !, ~           | Logical/bitwise NOT        | High       | right to left     |
| *              | Multiplication             | Medium     | left to right     |
| /              | Division                   | Medium     | left to right     |
| %              | Modulus                    | Medium     | left to right     |
| +              | Addition                   | Medium     | left to right     |
| -              | Subtraction                | Medium     | left to right     |
| <<, >>         | Bitwise shift              | Medium     | left to right     |
| <, <=, >, >=   | Relational                 | Medium     | left to right     |
| ==, !=         | Equality                   | Medium     | left to right     |
| &              | Bitwise AND                | Medium     | left to right     |
| ^              | Bitwise XOR                | Medium     | left to right     |
| \|             | Bitwise OR                 | Medium     | left to right     |
| &&             | Logical AND                | Low        | left to right     |
| \|\|           | Logical OR                 | Low        | left to right     |
| ?:             | Conditional                | Low        | right to left     |
| =, +=, -=, *=, /=, %=, &=, ^=, \|=, <<=, >>= | Assignment | Lowest     | right to left     |
| ,              | Comma                      | Lowest     | left to right     |