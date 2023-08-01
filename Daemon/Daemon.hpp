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

// System includes
#include <iostream>
#include <chrono>

class Daemon : public DaemonThread
{
public:
    Daemon()
    {
        run();
    }
    ~Daemon() {}

    static void exitCallback()
    {
        std::cout << "Daemon shutting down...\n\n";
        DaemonThread DT;
        DT.waitThread(5000); //This requires to be replaced with real system checks on exit.
        #if defined (__linux__)
            std::cout << DAEMON_SYSTEM_STATUS_OFFLINE;
        #endif
        #if defined (_WIN32)||(_WIN64)
            std::cout<<"DAEMON OFFLINE\n\n";
        #endif
    }
private:
    bool initializeDaemon()
    {
        std::cout << DAEMON_VERSION_ << std::endl;
        std::cout << "Initializing Daemon...\n\n";

        while (messagePrinted == false)
        {
            if (!messagePrinted)
            {
                #if defined (__linux__)
                    std::cout << DAEMON_SYSTEM_STATUS_ONLINE;
                #endif
                #if defined (_WIN32)||(_WIN64)
                    std::cout<<"[DAEMON ONLINE]\n\n";
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

    void run()
    {
        initializeDaemon();
    }

private:
    bool messagePrinted = false;
};

#endif // DAEMON_H_
