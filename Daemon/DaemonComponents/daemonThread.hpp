/////////////////////////////////////////////////////////////////////////////
// Name:        daemonThread.hpp
// Purpose:     daemon threading components for main Daemon.hpp
// Author:      Lukas Jackson
// Modified by:
// Created:     6/7/2023
// Copyright:   (c) [2023] Lukas Jackson
// Licence:     GNU Public License (GPL)
/////////////////////////////////////////////////////////////////////////////
#ifndef DAEMONTHREAD_HPP_
#define DAEMONTHREAD_HPP_

//error code dependencies.
#include"DaemonErrorcodes/DaemonErrorCode.hpp"

// Project dependencies
#include <boost/thread.hpp>
#include <boost/chrono.hpp>
#include <boost/functional.hpp>

//System includes
#include<stdio.h>
#include<thread>

class DaemonThread
{
public:
    DaemonThread() {}

    ~DaemonThread() {}

    void waitThread(int seconds)
    {
        boost::this_thread::sleep_for(boost::chrono::milliseconds(seconds));
    }

    template <typename Func, typename... Args>
    void callFunction(Func &&func, Args &&...args)
    {
        std::thread t(std::forward<Func>(func), std::forward<Args>(args)...);

        t.join();
    }

    template <typename Func, typename... Args>
    void initializeThread(Func &&func, Args &&...args)
    {
        boost::thread t(boost::forward<Func>(func), boost::forward<Args>(args)...);
        if(t.joinable())
        {
            printf("%s", "\nThread is joinable... [JOINING]\n\n");
            t.join();
            printf("%s", "\n\nSuccessfully joined [MAIN] thread [SUCCESS]\n\n");
        }
        else{
            printf("%s", DAEMON_THREAD_CONNECTION_ERR);
        }
    }
private:
};
#endif // DAEMONTHREAD_H_
