/////////////////////////////////////////////////////////////////////////////
// Name:        Banner.hpp
// Purpose:     Alucard daemon identification & version control
// Author:      Lukas Jackson
// Modified by:
// Created:     6/13/2023
// Copyright:   (c) [2023] Lukas Jackson
// Licence:     GNU Public License (GPL)
/////////////////////////////////////////////////////////////////////////////
#ifndef BANNER_HPP_
#define BANNER_HPP_

// Linux macro.
#if defined(__linux__)
    #define DAEMON_BANNER_NAME                                                                                                                                                  \
        " ▄▄▄       ██▓     █    ██  ▄████▄   ▄▄▄       ██▀███  ▓█████▄ \n"                                       \
        "▒████▄    ▓██▒     ██  ▓██▒▒██▀ ▀█  ▒████▄    ▓██ ▒ ██▒▒██▀ ██▌\n"                 \
        "▒██  ▀█▄  ▒██░    ▓██  ▒██░▒▓█    ▄ ▒██  ▀█▄  ▓██ ░▄█ ▒░██   █▌\n"                       \
        "░██▄▄▄▄██ ▒██░    ▓▓█  ░██░▒▓▓▄ ▄██▒░██▄▄▄▄██ ▒██▀▀█▄  ░▓█▄   ▌\n"   \
        " ▓█   ▓██▒░██████▒▒▒█████▓ ▒ ▓███▀ ░ ▓█   ▓██▒░██▓ ▒██▒░▒████▓ \n" \
        " ▒▒   ▓▒█░░ ▒░▓  ░░▒▓▒ ▒ ▒ ░ ░▒ ▒  ░ ▒▒   ▓▒█░░ ▒▓ ░▒▓░ ▒▒▓  ▒ \n"                       \
        "  ▒   ▒▒ ░░ ░ ▒  ░░░▒░ ░ ░   ░  ▒     ▒   ▒▒ ░  ░▒ ░ ▒░ ░ ▒  ▒ \n"                                             \
        "  ░   ▒     ░ ░    ░░░ ░ ░ ░          ░   ▒     ░░   ░  ░ ░  ░ \n"                                                                 \
        "      ░  ░    ░  ░   ░     ░ ░            ░  ░   ░        ░    \n"                                                                               \
        "                           ░                            ░       \n"
    #define DAEMON_VERSION_ DAEMON_BANNER_NAME"\e[1;37mVersion 1.0 (c)Lukas Jackson, VanguardPrecision 2023\n\n\e[1;36mLINUX kernel detected\n\e[0m"
    #define DAEMON_SYSTEM_STATUS_ONLINE "\e[1;32mDAEMON ONLINE\n\n\e[0m"
    #define DAEMON_SYSTEM_STATUS_OFFLINE "\e[1;31mDAEMON OFFLINE\n\n\e[0m"
#endif

#if defined  (_WIN32) || (_WIN64)

    #define DAEMON_VERSION_ "ALUCARD Version 1.0 (c)Lukas Jackson, VanguardPrecision 2023\n\n"
#endif

#endif // BANNER_HPP_
