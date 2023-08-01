/////////////////////////////////////////////////////////////////////////////
// Name:        fdebug.h
// Purpose:     Debugging functions -> fileman.h
// Author:      Lukas Jackson
// Modified by:
// Created:     7/15/2023
// Copyright:   (c) [2023] Lukas Jackson
// Licence:     GNU Public License (GPL)
/////////////////////////////////////////////////////////////////////////////
/*
Tools used inside compression files.
*/

#ifndef FDEBUG_H_
#define FDEBUG_H_

#include<stdio.h>

void printVar(const char* var)
{
    printf("%s %s", var, "\n");
}



#endif //FDEBUG_H_