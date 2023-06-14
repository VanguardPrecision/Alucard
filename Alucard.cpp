//Main Daemon header file.
#include"Daemon/Daemon.hpp"

int main(void)
{
    std::atexit(Daemon::exitCallback);
    boost::asio::io_context io_Context;
    Daemon runDaemon(io_Context);

    

    return 0;
}