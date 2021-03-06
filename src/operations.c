/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdoogls <jbdoogls@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 15:24:20 by jbdoogls          #+#    #+#             */
/*   Updated: 2020/06/01 18:46:15 by jbdoogls         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int			handle_s(t_stack **stack)
{
	int		tmp;

	if ((*stack)->head && (*stack)->head->next)
	{
		tmp = (*stack)->head->val;
		(*stack)->head->val = (*stack)->head->next->val;
		(*stack)->head->next->val = tmp;
		return (0);
	}
	return (1);
}

int			handle_p(t_stack **from, t_stack **to)
{
	if (*from)
	{
		push_front(to, pop_front(from));
		return (0);
	}
	return (1);
}

int			handle_r(t_stack **stack)
{
	if ((*stack)->head && (*stack)->head->next)
	{
		push_back(stack, pop_front(stack));
		return (0);
	}
	return (1);
}

int			handle_rr(t_stack **stack)
{
	if ((*stack)->head && (*stack)->head->next)
	{
		push_front(stack, pop_back(stack));
		return (0);
	}
	return (1);
}

int			parse_operations(char *op, t_frame *st)
{
	int		len;
	int		ret;

	len = ft_strlen(op);
	if (len == 2 && (!ft_strcmp(op, "sa") || !ft_strcmp(op, "ss")))
		ret = handle_s(&st->a);
	if (len == 2 && (!ft_strcmp(op, "sb") || !ft_strcmp(op, "ss")))
		ret = handle_s(&st->b);
	if (len == 2 && !ft_strcmp(op, "pa"))
		ret = handle_p(&st->b, &st->a);
	if (len == 2 && !ft_strcmp(op, "pb"))
		ret = handle_p(&st->a, &st->b);
	if (len == 2 && (!ft_strcmp(op, "ra") || !ft_strcmp(op, "rr")))
		ret = handle_r(&st->a);
	if (len == 2 && (!ft_strcmp(op, "rb") || !ft_strcmp(op, "rr")))
		ret = handle_r(&st->b);
	if (len == 3 && (!ft_strcmp(op, "rra") || !ft_strcmp(op, "rrr")))
		ret = handle_rr(&st->a);
	if (len == 3 && (!ft_strcmp(op, "rrb") || !ft_strcmp(op, "rrr")))
		ret = handle_rr(&st->b);
	return (ret);
}
