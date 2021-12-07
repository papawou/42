#include "cmd.h"

typedef struct s_node
{
	enum e_move move;
	struct s_node *parent;
	struct s_node *childs[];
} t_node;


t_node *create_node(t_node *parent, enum e_move move)
{
	t_node *tmp;

	tmp = malloc(sizeof(t_node));
	tmp->move = move;
	tmp->parent = parent;
	tmp->childs = NULL;

	return tmp;
}

void add_childs(t_node *parent, enum e_move moves[], int size)
{
	parent->childs = malloc(size + 1);
	parent->childs[size] = 0;
	
}