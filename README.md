# Push_swap - Efficient Stack Sorting

This project consists of implementing a **custom sorting algorithm**, focusing on low-level programming, manual memory management, and **algorithmic complexity**. The goal is to sort a set of integers using two stacks and a limited set of operations with the **minimum number of actions** possible.

## 📋 Project Overview
The challenge involves two stacks, **a** and **b**. Stack **a** begins with a random list of unique integers, while stack **b** starts empty. To sort the numbers in ascending order in stack **a**, the program must output the shortest sequence of instructions.

### 🛠️ Sorting Operations
You have 11 specific instructions at your disposal to manipulate the stacks:
*   **Push:** `pa` (push to a), `pb` (push to b).
*   **Swap:** `sa` (swap top 2 of a), `sb` (swap top 2 of b), `ss` (both).
*   **Rotate:** `ra` (shift up a), `rb` (shift up b), `rr` (both).
*   **Reverse Rotate:** `rra` (shift down a), `rrb` (shift down b), `rrr` (both).

## 🚀 Usage

### Compilation
The project includes a **Makefile** that compiles the source files using `cc` with the flags `-Wall -Wextra -Werror`. Use the following rules:
*   `make`: Compiles the `push_swap` program.
*   `make clean`: Removes object files.
*   `make fclean`: Removes object files and the binary.
*   `make re`: Recompiles the entire project.

### Running the Program
To run the program, provide a list of integers as arguments:
```bash
./push_swap 2 1 3 6 5 8
```
The program will output the sequence of instructions to sort the stack. You can also verify the output using the **checker** (if compiled) or the provided `checker_OS`:
```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_OS $ARG
```

## 📊 Benchmarks
The efficiency of the algorithm is measured by the number of operations performed:
*   **100 random numbers:** Must be sorted in fewer than **700 operations**.
*   **500 random numbers:** Must be sorted in no more than **5500 operations**.

## 🧠 What I Learned
*   **Algorithmic Complexity (Big O):** Understanding how different algorithms perform as data scales.
*   **Data Structures:** Practical application of stacks and their manipulation.
*   **Manual Memory Management:** Ensuring all heap-allocated memory is properly freed to avoid **memory leaks**.
*   **Rigor and Problem Solving:** Developing logic that handles edge cases, such as duplicates or non-integer inputs, while adhering to strict project constraints.

## ⚠️ Project Constraints
This project was developed following 42 School's strict rules:
*   **Strict Norminette formatting**.
*   **No memory leaks** are tolerated.
*   **No global variables** allowed.
*   Use of a limited set of standard library functions: `read`, `write`, `malloc`, `free`, and `exit`.

## 👨‍💻 Author
**mateferr** (Mateus Leite)  
42 Lisboa Student
