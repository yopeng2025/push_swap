NAME        = push_swap
BONUS_NAME  = checker

CC          = cc
CFLAGS      = -Wall -Wextra -Werror -Iinclude -Ilibft -MMD -MP

OBJ_DIR     = obj
PS_OBJ_DIR  = $(OBJ_DIR)/ps
BN_OBJ_DIR  = $(OBJ_DIR)/bn

LIBFT_DIR   = libft
LIBFT_A     = $(LIBFT_DIR)/libft.a
LFT_CFLAGS  = -Wall -Wextra -Werror -I. -I../include

# ---------------------------------------------------------------
PS_SRCS = \
src/check_double.c \
src/check_fast_move.c \
src/check_input.c \
src/check_list_order.c \
src/check_max_min_a.c \
src/check_max_min_b.c \
src/free_exit.c \
src/linked_list_a.c \
src/linked_list_b.c \
src/main.c \
src/move_back_a.c \
src/move_fast.c \
src/new_elem_a.c \
src/new_elem_b.c \
src/new_max_a.c \
src/new_max_min_b.c \
src/new_min_a.c \
src/push.c \
src/rev_rotate.c \
src/rotate.c \
src/sort2.c \
src/sort3.c \
src/sort4.c \
src/sort.c \
src/swap.c

BN_SRCS = \
src_bonus/checker.c \
src_bonus/check_input_bonus.c \
src_bonus/execute_bonus.c \
src_bonus/free_bonus.c \
src_bonus/linked_list_a_bonus.c \
src_bonus/linked_list_b_bonus.c \
src_bonus/push_bonus.c \
src_bonus/rev_rotate_bonus.c \
src_bonus/rotate_bonus.c \
src_bonus/swap_bonus.c

# ---------------------- objects & deps --------------------------
PS_OBJS = $(PS_SRCS:src/%.c=$(PS_OBJ_DIR)/%.o)
BN_OBJS = $(BN_SRCS:src_bonus/%.c=$(BN_OBJ_DIR)/%.o)

PS_DEPS = $(PS_OBJS:.o=.d)
BN_DEPS = $(BN_OBJS:.o=.d)

# ----------------------------------------------------------------
all: $(NAME) $(BONUS_NAME)

mandatory: $(NAME)
bonus: $(BONUS_NAME)

$(NAME): $(PS_OBJS) $(LIBFT_A)
	$(CC) $(CFLAGS) $(PS_OBJS) $(LIBFT_A) -o $@

$(BONUS_NAME): $(BN_OBJS) $(LIBFT_A)
	$(CC) $(CFLAGS) $(BN_OBJS) $(LIBFT_A) -o $@

$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR) CFLAGS='$(LFT_CFLAGS)'

# -----------------------------------------------------------------
$(PS_OBJ_DIR)/%.o: src/%.c | $(PS_OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BN_OBJ_DIR)/%.o: src_bonus/%.c | $(BN_OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(PS_OBJ_DIR) $(BN_OBJ_DIR):
	mkdir -p $@

# ------------------------------------------------------------------
clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all mandatory bonus clean fclean re

-include $(PS_DEPS) $(BN_DEPS)