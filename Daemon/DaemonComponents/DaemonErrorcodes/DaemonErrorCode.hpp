/////////////////////////////////////////////////////////////////////////////
// Name:        DaemonErrorCode.hpp
// Purpose:     header source for daemon error codes.
// Author:      Lukas Jackson
// Modified by:
// Created:     6/12/2023
// Copyright:   (c) [2023] Lukas Jackson
// Licence:     GNU Public License (GPL)
/////////////////////////////////////////////////////////////////////////////
#ifndef DAEMON_ERRORCODE_HPP_
#define DAEMON_ERRORCODE_HPP_

//*Each group of macros are labeled with their file name and below them have debugging labeled in red for developers.


//*daemonThread.hpp [DAEMONTHREAD_HPP_]
#define DAEMON_THREAD_GENERAL_ERR "DTG_1000"
#define DAEMON_THREAD_RESOURCE_ERR "DTR_1000"
#define DAEMON_THREAD_CONNECTION_ERR "DTC_1000"

//*daemonThread debugging errors and exceptions. | DAEMON_THREAD_DEBUG
#ifdef DAEMON_THREAD_DEBUG_ //![FOR SOFTWARE ENGINEERS]
    #define DAEMON_THREAD_EXCEPTION_ERR_ "DDTC_1000" 
    #define DAEMON_THREAD_GENERAL_EXCEPTION_
    #define DAEMON_THREAD_CRIT_EXCEPTION_
#endif //DAEMON_THREAD_DEBUG


#endif //DAEMON_ERRORCODE_HPP_