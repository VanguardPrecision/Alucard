/////////////////////////////////////////////////////////////////////////////
// Name:        fattr.hpp
// Purpose:     File attributes -> fileman.h
// Author:      Lukas Jackson
// Modified by:
// Created:     7/15/2023
// Copyright:   (c) [2023] Lukas Jackson
// Licence:     GNU Public License (GPL)
/////////////////////////////////////////////////////////////////////////////
/*
File utilities included into fileman.h or other user specific files in the future.
*/

#ifndef FATTR_HPP_
#define FATTR_HPP_

//System includes
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


/*
Creates a pointer and seeks to the end of the file and returns the size of all contents inside.
*/
long int findSize(const char *file_name)
{
    FILE *fp = fopen(file_name, "rb");

    if (!fp)
    {
        fprintf(stderr, "File not found\n");
        return -1;
    }
    fseek(fp, 0L, SEEK_END);

    long int res = ftell(fp);

    fclose(fp);
    printf("%s %ld %s", "Size of", res, "bytes\n");
    return res;
}

/*
Parses incoming directories to extract only the file in question.
*/
const char* parseDircontents(const char* file_path) {
    const char* file_name;
    // Extract file name
    file_name = strrchr(file_path, '/');
    if (file_name != NULL) {
        file_name++;  // Skip the '/'
        printf("File Name: %s\n", file_name);
    } else {
        printf("Invalid file path.\n");
    }

    // Extract directory path
    char directory_path[256];

    size_t directory_length = file_name - file_path;
    strncpy(directory_path, file_path, directory_length);

    directory_path[directory_length] = '\0';
    
    printf("Directory Path: %s\n", directory_path);

    return file_name;
}

#endif // FATTR_HPP_