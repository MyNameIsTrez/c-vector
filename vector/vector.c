/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/06 15:57:06 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/20 10:30:41 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "vector.h"

////////////////////////////////////////////////////////////////////////////////

typedef struct s_vector_metadata
{
	size_t	count;
	size_t	size;
	size_t	element_size;
	void	*address;
}	t_vector_metadata;

typedef struct s_vectors_metadata
{
	size_t				count;
	t_vector_metadata	*metadata;
}	t_vectors_metadata;

static t_vectors_metadata	*get_vectors_metadata_ptr(void)
{
	static bool					did_init = false;
	static t_vectors_metadata	vectors_metadata;

	if (!did_init)
	{
		did_init = true;
		vectors_metadata.metadata = malloc(sizeof(t_vector_metadata));
		vectors_metadata.count = 1;
		vectors_metadata.metadata[0].address = vectors_metadata.metadata;
		vectors_metadata.metadata[0].count = 1;
		vectors_metadata.metadata[0].size = 1;
		vectors_metadata.metadata[0].element_size = sizeof(t_vector_metadata);
	}
	return (&vectors_metadata);
}

static t_vector_metadata	*vector_get_metadata(void *vector)
{
	t_vectors_metadata	*vectors_metadata;
	size_t				index;

	vectors_metadata = get_vectors_metadata_ptr();
	index = 0;
	while (index < vectors_metadata->count)
	{
		t_vector_metadata	*tmp = &vectors_metadata->metadata[index];
		(void)tmp;
		if (vectors_metadata->metadata[index].address == vector)
			return (&vectors_metadata->metadata[index]);
		index++;
	}
	return (NULL);
}

static void	vector_register(void *vector, size_t element_size, size_t size)
{
	t_vectors_metadata	*vectors_metadata;
	t_vector_metadata	metadata;

	vectors_metadata = get_vectors_metadata_ptr();
	vectors_metadata->count++;
	metadata.address = vector;
	metadata.count = 0;
	metadata.size = size;
	metadata.element_size = element_size;
	vector_push(&vectors_metadata->metadata, &metadata);
}

////////////////////////////////////////////////////////////////////////////////

void	*vector_new(size_t element_size)
{
	void	*vector;

	vector = malloc(1);
	if (vector == NULL)
		return (NULL);
	vector_register(vector, element_size, 0);
	return (vector);
}

void	vector_reserve(void *vector, size_t additional_elements)
{
	void				**vector_;
	t_vector_metadata	*metadata;

	vector_ = vector;
	metadata = vector_get_metadata(*vector_);
	metadata->size += additional_elements;
	// TODO: replace realloc with ft_realloc
	if (metadata == metadata->address)
	{
		metadata = realloc(metadata->address, metadata->size * metadata->element_size);
		metadata->address = metadata;
	}
	else
		metadata->address = realloc(metadata->address, metadata->size * metadata->element_size);
	*vector_ = metadata->address;
}

#include <string.h>

void	vector_push(void *vector, void *value_ptr)
{
	void				**vector_;
	t_vector_metadata	*metadata;

	vector_ = vector;
	metadata = vector_get_metadata(*vector_);
	if (metadata->count >= metadata->size)
	{
		if (metadata->size == 0)
			vector_reserve(vector, 1);
		else
			vector_reserve(vector, metadata->size); // maybe *0.5 (because additional)
	}
	metadata = vector_get_metadata(*vector_);
	// TODO: replace memcpy with ft_memcpy
	memcpy((*vector_) + metadata->count * metadata->element_size, value_ptr, metadata->element_size);
	metadata->count++;
}

////////////////////////////////////////////////////////////////////////////////
