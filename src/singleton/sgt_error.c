


int *sgt_error()
{
    static int error;
    return &error;
}
int set_sgt_error(int error)
{
    *sgt_error() = error;
    return (1);
}