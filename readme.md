
# Push_swap - Optimized Sorting with Greedy Algorithm

**A highly efficient stack-sorting project that explores algorithmic complexity, data structures, and the optimization of move sequences to sort data with a restricted set of operations.**

## 🧠 Key Learning Objectives

* **🟢 Algorithm Optimization**: Implementing a **Greedy Strategy** that calculates the cost of moving each element and executes the cheapest operation.
* **🔵 Data Structures**: Managing doubly linked lists to represent Stack A and Stack B.
* **🟡 Complexity Analysis**: Minimizing the total number of operations ($sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrrr$) to meet strict performance benchmarks.
* **🔴 Input Validation**: Building a robust parser to handle duplicates, non-integer values, and integer overflows.


## 📂 Project Breakdown

### 🟢 Part 1: Parsing & Stack Initialization
* **Goal**: Convert command-line arguments into a functional linked list.
* **Concepts**:
    * **Error Handling**: Validating `check_input` for non-numeric characters and `check_double_int` for duplicates.
    * **Stack Creation**: Building the initial `head_a` list while preserving the input order.

### 🔵 Part 2: The Greedy Sorting Logic
* **Goal**: Sort Stack A using Stack B as a temporary workspace with minimum moves.
* **Concepts**:
    * **Cost Calculation**: For every number in Stack A, calculate the sum of rotations required to position it correctly in Stack B.
    * **The "Cheapest Link"**: Iterating through the stack to find the element with the lowest combined cost (e.g., combining `ra` and `rb` into `rr` to save steps).
    * **Final Alignment**: Rotating Stack A at the end to ensure the smallest number is at the top.

### 🟡 Part 3: Bonus (Checker Implementation)
* **Goal**: Create a separate program to verify the sorting results.
* **Features**:
    * **Instruction Reading**: Using `get_next_line` to read operations from standard input.
    * **Execution Simulation**: Applying the operations to the stacks and checking if Stack A is sorted and Stack B is empty.
    * **Result Output**: Displaying `OK` if the instructions correctly sort the stack, or `KO` otherwise.

### 🔴 Part 4: Technical Polish
* **Goal**: Stability and memory management.
* **Concepts**:
    * **Memory Integrity**: Using `free_all_bonus` to ensure no memory leaks occur, regardless of whether the program exits normally or via an error.
    * **Efficient Operations**: Ensuring the rotation logic is optimized for both small sets (3-5 numbers) and large sets (100-500 numbers).



## 🚀 Technical Requirements
  * 100 numbers: < 700 moves
  * 500 numbers: < 5500 moves


## 🛠️ Compilation

### 1. Mandatory Part (The Sorter)
Compiles the `push_swap` executable:
```bash
make
./push_swap 3 2 1 0
```

### 2. Bonus Part (The Checker)
```bash
make bonus
ARG="3 2 1 0"; ./push_swap $ARG | ./checker $ARG
```
### 3. Testing (100 & 500 Numbers)
for Bash user
```bash
# 100 numbers
ARG=$(seq 1 100 | shuf); ./push_swap $ARG | ./checker $ARG

# 500 numbers
ARG=$(seq 1 500 | shuf); ./push_swap $ARG | ./checker $ARG
```

for Zsh user
```bash
# 100 numbers
ARG=$(seq 1 100 | shuf | tr '\n' ' ')
./push_swap ${=ARG} | ./checker ${=ARG}

# 500 numbers
ARG=$(seq 1 500 | shuf | tr '\n' ' ')
./push_swap ${=ARG} | ./checker ${=ARG}
```

### 4. Error Handling
The program must display Error\n to stderr for invalid inputs
```bash
./push_swap a b c           # Non-numeric
./push_swap 2147483648      # Overflow
./push_swap 1 2 2           # Duplicates
./push_swap ""              # Empty string
```

### 5. Memory Management
```bash
# Test error cases for leaks
valgrind --leak-check=full --show-leak-kinds=all ./push_swap 1 2 2 >/dev/null
valgrind --leak-check=full --show-leak-kinds=all ./push_swap 1 a 3 >/dev/null

# Test Checker for leaks (Empty/Invalid instructions)
printf "hello\n" | valgrind --leak-check=full ./checker 2 1 3 >/dev/null
printf "" | valgrind --leak-check=full ./checker 1 2 3 >/dev/null

# Full sorting leak check
ARG="3 2 1 0"; ./push_swap $ARG | valgrind --leak-check=full ./checker $ARG >/dev/null
```
