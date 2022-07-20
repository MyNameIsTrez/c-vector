# c-vector

This repository showcases how I've implemented vectors in C.

## Running

1. Git clone this repository.
2. Open this repository in VS Code.
3. Go to the Run and Debug tab in VS Code and use the dropdown menu at the top to select what example program you want to run.
4. Run the program and see the terminal output.

## Motivation

C arrays have the best performance but don't dynamically grow, while linked lists dynamicaly grow but are very slow due to memory not being contiguous with them. C++ vectors dynamically grow and are fast, so it has the best of both worlds.

```c
int	main(void)
{
	int	*ints;
	int	v;

	ints = vector_new(sizeof(int));

	vector_reserve(&ints, 1);

	v = 1;
	vector_push(&ints, &v);
	v = 2;
	vector_push(&ints, &v);
	v = 3;
	vector_push(&ints, &v);

	printf("%d%d%d\n", ints[0], ints[1], ints[2]);

	return (EXIT_SUCCESS);
}
```
