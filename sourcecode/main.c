#include "command.h"

int main(int ac, char **av)
{
    state_t data[] = { DATA_INIT };
    (void)ac; (void)av;
    
    shell_loop(data, av);
    
    return (0);
}

