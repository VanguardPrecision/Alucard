/////////////////////////////////////////////////////////////////////////////
// Name:        Daemon.hpp
// Purpose:     Main daemon header file -> Krupt.cpp
// Author:      Lukas Jackson
// Modified by:
// Created:     6/6/2023
// Copyright:   (c) [2023] Lukas Jackson
// Licence:     GNU Public License (GPL)
/////////////////////////////////////////////////////////////////////////////
#ifndef DAEMON_HPP_
#define DAEMON_HPP_

// Daemon includes
#include "DaemonComponents/daemonThread.hpp"
#include "DaemonComponents/daemonLinkedList.hpp"
#include "DaemonComponents/Banner.hpp"

// Main includes
#include <boost/asio.hpp>

// System includes
#include <iostream>
#include <chrono>

class Daemon : public DaemonThread
{
public:
    Daemon(boost::asio::io_context &io_Context) : ioContext(io_Context)
    {
        run(io_Context);
    }
    ~Daemon() {}

    static void exitCallback()
    {
        std::cout << "Daemon shutting down...\n\n";
        DaemonThread DT;
        DT.waitThread(5000); //This should be replaced with real system checks on exit.
        #if defined (__linux__)
            std::cout << DAEMON_SYSTEM_STATUS_OFFLINE;
        #endif
        #if defined (_WIN32)||(_WIN64)
            std::cout<<"DAEMON OFFLINE";
        #endif
    }
private:
    bool initializeDaemon(boost::asio::io_context &io_Context)
    {
        std::cout << DAEMON_VERSION_ << std::endl;
        std::cout << "Initializing Daemon...\n\n";

        while (messagePrinted == false)
        {
            io_Context.run();
            io_Context.restart();

            if (!messagePrinted)
            {
                #if defined (__linux__)
                    std::cout << DAEMON_SYSTEM_STATUS_ONLINE;
                #endif
                #if defined (_WIN32)||(_WIN64)
                    std::cout<<"[DAEMON ONLINE]";
                #endif
                messagePrinted = true;
            }
            if (messagePrinted == true)
            {

                break;
            }
        }
        return true;
    }

    void run(boost::asio::io_context &io_Context)
    {
        initializeDaemon(io_Context);
    }

private:
    boost::asio::io_context &ioContext;
    bool messagePrinted = false;
};
#endif // DAEMON_H_
