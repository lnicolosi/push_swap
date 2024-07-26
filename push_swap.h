#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <unistd.h>
# include <stddef.h>

typedef struct	s_node
{
	int				value;
	int				current_position;
	int				final_index;
	int				push_price;
	bool			above_median;
	bool			cheapest;
	struct s_node	*target_node;
	struct s_node	*next;
	struct s_node	*prev;
}				t_node;

// ft_split
char	**ft_split(char *str, char separator);

// error free
void	free_matrix(char **argv);
void	error_free(t_node **a, char **argv, bool flag_argc_2);
void	free_stack(t_node **stack);
int		error_repetition(t_node *a, int nbr);
int		error_syntax(char *str_nbr);

// stack creation
void	stack_init(t_node **a, char **argv, bool flag_argc_2);
void	init_nodes(t_node *a, t_node *b);
void	set_current_position(t_node *stack);
void	set_price(t_node *a, t_node *b);
void	set_cheapest(t_node *b);

// stack utils
void	append_node(t_node **stack, int nbr);
t_node	*find_last_node(t_node *head);
t_node	*find_smallest(t_node *stack);
t_node	*return_cheapest(t_node *stack);
int		stack_len(t_node *stack);


#endif
