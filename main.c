#include "shell.h"

int main(int argc, char argv[])
{
typedef struct comm;
comm [] =
{
{"ls" = comm_ls;},
{"cd" = comm_cd;},
{"mkdir" = comm_mkdir;},
{"cat" = comm_cat;}
};
}
}