/////////////////////////////////////////////////////////////////////////////
// Name:        Alucard.cpp
// Purpose:     Alucard main entry point
// Author:      Lukas Jackson
// Modified by:
// Created:     6/7/2023
// Copyright:   (c) [2023] Lukas Jackson
// Licence:     GNU Public License (GPL)
/////////////////////////////////////////////////////////////////////////////


//System includes
#include <iostream>

//Daemon includes
#include "Daemon/Daemon.hpp"

//Utilities
#include "cmds/fileman/fileman.h"


int main(int argc, char *argv[])
{
    if (argc <= 2)
    {
        std::cerr << "Insufficient args provided. type -h or -help for more.\n\n";
        return 1;
    }

    std::string command = argv[1];
    if (command == "-C")
    {
        std::string subcommand = argv[2];
        if (subcommand == "filecompress")
        {
            if (argc < 5)
            {
                std::cerr << "Insufficient number of arguments for filecompress.\n\n";
                return 1;
            }
            const char *file = argv[3];
            const char *destination = argv[4];
            auto ret = zip_file_contents(file, destination);
            if (ret == 0)
            {
                return 0;
            }
        }
        else if (subcommand == "extract")
        {
            if (argc < 4)
            {
                std::cerr << "Insufficient number of arguments for filedecompress.\n";
                return 1;
            }
            else if(argc > 5)
            {
                std::cerr<<"Too many arguments provided for filedecompress.\n";
                return -1;
            }
            const char *file = argv[3];
            const char *dest = argv[4];
            extract_file(file, dest);

            return 0;
        }

        else
        {
            std::cerr << "Unknown subcommand: " << subcommand << std::endl;
            return 1;
        }
    }
    else if (command == "filesize")
    {
        const char *file_name = argv[2];
        auto ret = findSize(file_name);

        if (ret == 0)
        {
            return 0;
        }
    }

    else
    {
        std::cerr << "Unknown command: " << command << std::endl;
        return 1;
    }

    return 0;
}

