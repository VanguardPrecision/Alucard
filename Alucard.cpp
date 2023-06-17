//Main Daemon header file.
#include"Daemon/Daemon.hpp"

int main(void)
{
    std::atexit(Daemon::exitCallback);

    Daemon Alucard;
    return 0;
}