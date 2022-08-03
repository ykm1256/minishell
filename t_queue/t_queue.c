#include <stdlib.h>
#include "t_queue.h"
#include "../minishell.h"

t_queue	*t_queue_new(char *str)
{
	t_queue	*q;

	q = malloc(sizeof(t_queue));
	ft_check_error();
	q->str = str;
	return (q);
}

void	t_queue_push(t_queue **head, t_queue *q)
{
	t_queue	*temp;

	if (*head == 0)
		*head = q;
	else
	{
		temp = *head;
		while (temp->next != 0)
			temp = temp->next;
		temp->next = q;
	}
}

char	*t_queue_pop(t_queue **head)
{
	t_queue	*temp;
	char	*ret;

	temp = *head;
	ret = temp->str;
	*head = (*head)->next;
	free(temp);
	return (ret);
}

int	t_queue_size(t_queue *q)
{
	int	ret;

	ret = 0;
	while (q != 0)
	{
		q = q->next;
		ret++;
	}
	return (ret);
}