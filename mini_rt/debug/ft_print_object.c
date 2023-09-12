/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_object.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinagaki <sinagaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 22:12:53 by soma              #+#    #+#             */
/*   Updated: 2023/09/11 19:27:08 by sinagaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"
#include "include.h"

static void	ft_print_sphere(t_object *object);
static void	ft_print_plane(t_object *object);
static void	ft_print_cylinder(t_object *object);

void	ft_print_object(t_object *object)
{
	while (object != NULL)
	{
		if (object->type == SPHERE)
			ft_print_sphere(object);
		else if (object->type == PLANE)
			ft_print_plane(object);
		else if (object->type == CYLINDER)
			ft_print_cylinder(object);
		object = object->next;
	}
}

static void	ft_print_sphere(t_object *object)
{
	printf("sphere\n");
	if (object == NULL)
	{
		printf("  (null)");
		return ;
	}
	ft_print_vector(object->pos);
	printf("  radius: %f\n", object->diameter);
	ft_print_color(object->color);
}

static void	ft_print_plane(t_object *object)
{
	printf("plane\n");
	if (object == NULL)
	{
		printf("  (null)");
		return ;
	}
	ft_print_vector(object->pos);
	ft_print_vector(object->dir);
	ft_print_color(object->color);
}

static void	ft_print_cylinder(t_object *object)
{
	printf("cylinder\n");
	if (object == NULL)
	{
		printf("  (null)");
		return ;
	}
	ft_print_vector(object->pos);
	ft_print_vector(object->dir);
	printf("  diameter: %f\n", object->diameter);
	printf("  height: %f\n", object->height);
	ft_print_color(object->color);
}