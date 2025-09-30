

int	*sgt_error(void)
{
	static int	error;

	return (&error);
}
int	set_sgt_error(int error)
{
	*sgt_error() = error;
	return (1);
}