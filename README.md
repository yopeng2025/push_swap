# Push_Swap

Push_Swap is a 42 School project that implements an optimized sorting solution using exactly two stacks (A and B) with only 11 allowed operations:
- **Push** (`pa`, `pb`): Move top element from one stack to another
- **Swap** (`sa`, `sb`): Swap top two elements in a stack
- **Rotate** (`ra`, `rb`, `rr`): Shift stack elements up (cyclic), rr = ra + rb
- **Reverse Rotate** (`rra`, `rrb`, `rrr`): Shift stack elements down (cyclic), rrr = rra + rrb

The goal is to sort integers in stack A using the minimum number of operations.

## Algorithm Strategy

```c
// Small lists (2-4 elements):
// - Hardcoded optimal solutions
// - Minimal operations guaranteed

// Large lists (5+ elements):
// 1. Push 2 smallest to stack B
// 2. Find optimal positions using cost calculation
// 3. Move elements intelligently
// 4. Sort remaining 3 in stack A
// 5. Push all from B back to A

// Cost calculation:
// - Distance to target position
// - Opportunity for combined operations (rr, rrr)
```

## Architecture

### Data Structures

```c
typedef struct s_node {
    int content;
    struct s_node *next;
} t_node;

typedef struct s_stacks {
    t_node *head_a;           // Main stack
    t_node *head_b;           // Auxiliary stack
    t_value *value;           // Min/max values
    t_move *move;             // Operation counters
    t_fast *fast;             // Fast move calculations
} t_stacks;
```

### Core Algorithm

```c
void sort(t_stacks *stacks) {
    if (check_list_order(stacks))
        return;
    
    // Hardcoded optimized sorts for small lists
    if (ft_listsize_a(stacks->head_a) == 2)
        sort_two(stacks);
    else if (ft_listsize_a(stacks->head_a) == 3)
        sort_three(stacks, 1);
    else if (ft_listsize_a(stacks->head_a) == 4)
        sort_four(stacks);
    
    // Efficient algorithm for larger lists
    ft_push(stacks, 'b');      // Push 2 smallest to B
    ft_push(stacks, 'b');
    move_fast(stacks);          // Intelligent placement algorithm
    sort_three(stacks, 0);      // Final 3-element sort
    move_back_a(stacks);        // Return all to A
}
```

### Main Entry Point

```c
int main(int ac, char **av) {
    t_stacks stacks;
    
    check_input(ac, av);
    stacks.head_a = create_list_a(ac, av);
    stacks.head_b = NULL;
    check_double_int(stacks.head_a);
    sort(&stacks);
    free_all(&stacks);
    return (0);
}
```

## Stack Operations

```c
void ft_push(t_stacks *stacks, char c);      // pa/pb
void ft_swap(t_stacks *stacks, char c);      // sa/sb
void ft_rotate(t_stacks *stacks, char c);    // ra/rb/rr
void ft_rev_rotate(t_stacks *stacks, char c);// rra/rrb/rrr
```

## Usage

### Mandatory Program

```bash
# Compile (mandatory + bonus)
make
./push_swap 3 1 4 1 5
# Output:
# pb
# pb
# ra
# ra
# pa
# pa
```

### Bonus Checker

```bash
# Validate operations
./push_swap 3 1 4 1 5 | ./checker 3 1 4 1 5
# Output: OK or KO

# Direct operation sequence
echo "pb\npb\nra\nra\npa\npa" | ./checker 5 4 3 2 1
```

### Test Cases

```bash
# Already sorted
./push_swap 1 2 3
# Output: (empty)

# Reverse sorted
./push_swap 5 4 3 2 1
# Output: (optimal sequence)

# Two elements
./push_swap 2 1
# Output: sa

# Three elements
./push_swap 3 1 2
# Output: (2 operations max)
```

