/////////////////////////////////////////////////////////////////////////////
// Name:        fileman.h
// Purpose:     File manipulation main header -> Alucard.cpp
// Author:      Lukas Jackson
// Modified by:
// Created:     7/20/2023
// Copyright:   (c) [2023] Lukas Jackson
// Licence:     GNU Public License (GPL)
/////////////////////////////////////////////////////////////////////////////
/*
This file is dedicated to various file compression algorithms used by the damon.
Any files pertaining to file compression or its tools will be stored either here or in the fattr.hpp file.
You can create folder(s) to store additional functionality for use in future addons.
*/

#ifndef FILEMAN_H_
#define FILEMAN_H_

// System includes
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Zip includes
#include <zip.h>

// Utility includes
#include "fdebug.h"
#include "fattr.h"

/*
Defines a buffer meant for compression stream.
*/
#define BUFFER_SIZE (128 * 1024)

/*
    When providing arguments to argv, source_file will be where you input file is located in your system directory
    and destination is where you wish for the file to be written to.

    It first parses the input to extract the given file name in the directory (example, /home/diablo/Desktop/Test.txt ->
    Test.zip within the /home/diablo/Desktop/ directory.)

    This function return 0 upon success, but can be modified to return anything else.

    Most of the code inside are just checks to ensure things are valid and workng.
*/
int zip_file_contents(const char *source_file, const char *destination)
{
    /*
    -------- VERIFY THE EXISTENCE OF A GIVEN FILE INSIDE A DIRECTORY -----------
    Verify that the file exists in the given directory by utilizing the findSize function
    and opening and calculating the size of the file.
    If the function returns anything larger than one, we then know that the source file is not empty
    and thus we can continue with the rest of the function.

    */
    long int size = findSize(source_file);
    if (size == 0)
        return -1;

    const char *source_file2 = parseDircontents(source_file);

    zip_t *archive = zip_open(destination, ZIP_CREATE | ZIP_TRUNCATE, nullptr);
    if (!archive)
    {
        fprintf(stderr, "Could not open archive.\n");
        return -1;
    }

    zip_source_t *source = zip_source_file(archive, source_file, 0, -1);
    if (!source)
    {
        fprintf(stderr, "Could not create source from archive.\n");
        zip_close(archive);
        return -1;
    }

    int result = zip_file_add(archive, source_file2, source, ZIP_FL_ENC_UTF_8);
    if (result < 0)
    {
        fprintf(stderr, "Could not add file to archive.\n");
        zip_close(archive);
        return -1;
    }

    zip_close(archive);
    return 0;
}

/*
    Expects a zip archive (or the equivalent) as input for source_file. The file can be provided with a directory,
    but it is too redundant to repeatedly type directories in, so I'll come up with a solution.

    The output_dir requires the output directory of where the extracted file will be created.

    As of 7/30/2023, there are no measures in place to verify if a file already exists before attempted to write to the dir.
    This returns the total size of the extracted file, so do with that or change it if need be.
*/
int extract_file(const char *source_file, const char *output_dir)
{
    /*
    -------- VERIFY THE EXISTENCE OF A GIVEN FILE INSIDE A DIRECTORY -----------
    Verify that the file exists in the given directory by utilizing the findSize function
    and opening and calculating the size of the file.
    If the function returns anything larger than one, we then know that the source file is not empty
    and thus we can continue with the rest of the function.

    */
    long int size = findSize(source_file);
    if (size == 0)
    {
        fprintf(stderr, "File not found. ");
        exit(-1);
    }

    int error;
    zip_t *archive = zip_open(source_file, 0, &error);
    if (archive == nullptr)
    {
        fprintf(stderr, "Failed to open source file: %s\n", zip_strerror(archive));
        return -1;
    }

    int num_entries = zip_get_num_entries(archive, 0);
    long int total_size = 0;

    for (int i = 0; i < num_entries; ++i)
    {
        struct zip_stat entry_info;
        if (zip_stat_index(archive, i, 0, &entry_info) != 0)
        {
            fprintf(stderr, "Could not retrieve information for entry at index %d: %s\n", i, zip_strerror(archive));
            continue;
        }

        char *buffer = new char[entry_info.size];
        if (!buffer)
        {
            fprintf(stderr, "Memory allocation failed for entry at index %d\n", i);
            continue;
        }

        zip_file *file = zip_fopen_index(archive, i, ZIP_FL_NODIR);
        if (!file)
        {
            fprintf(stderr, "Failed to open file at index %d: %s\n", i, zip_strerror(archive));
            delete[] buffer;
            continue;
        }

        zip_int64_t bytes_read = zip_fread(file, buffer, entry_info.size);
        if (bytes_read < 0)
        {
            fprintf(stderr, "Failed to read file at index %d: %s\n", i, zip_file_strerror(file));
            zip_fclose(file);
            delete[] buffer;
            continue;
        }

        std::string output_file_path = std::string(output_dir) + "/" + entry_info.name;
        std::ofstream outfile(output_file_path, std::ios::binary);
        if (!outfile.is_open())
        {
            fprintf(stderr, "Failed to open output file for writing: %s\n", entry_info.name);
            zip_fclose(file);
            delete[] buffer;
            continue;
        }

        outfile.write(buffer, bytes_read);
        total_size += bytes_read;

        outfile.close();
        zip_fclose(file);
        delete[] buffer;
    }
    const char *source_file2 = parseDircontents(source_file);
    zip_close(archive);
    return total_size;
}

#endif // FILEMAN_H_