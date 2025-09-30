
#include "checker.h"

/*
	return 0 if success
	return err if fail
*/
int	parser(int argc, char *argv[], char *env[])
{
	int *error;

	error = sgt_error();
	if (quick_verif(argc, argv, env))
		return (*error);
	if (hard_verif(argv))
		return (*error);
	return (0);
}
