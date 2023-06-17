# Alucard Daemon

![AlucardInterface](https://github.com/VanguardPrecision/Alucard/assets/111693121/fa430bbb-2e2e-4c0d-857c-c53248d1d4b9)

# This branch uses only the C/C++ standard libraries, so building with boost won't be required.


This repo is supported by most operating systems out there and building it very simple.

# Build without Microsft Visual Studio

1.Clone the repo with the command: **git clone https://github.com/VanguardPrecision/Alucard.git**

2.change into the directory once finished: **cd Alucard**

3.make a folder named build: **mkdir build**

4.change into the build directory: **cd build**

5.run the CMake command: **cmake ..**

6.run make when the files are generated: **make**


# Build with Microsoft Visual Studio

**NOTE:** In the CMakeLists.txt you must change the CMAKE_SUPPRESS_REGENERATION to OFF in order to generate the solution file.

1.Clone the repo with the command: **git clone https://github.com/VanguardPrecision/Alucard.git**

2.change into the directory once finished: **cd Alucard**

3.make a folder named build: **mkdir build**

4.change into the build directory: **cd build**

5.run the CMake command: **cmake ..**

6.run the solution with **Visual Studio**

7.build the solution **Build** - **Build Solution** or **CTRL+Shift+B**

**And you should be finished!!!**

# Summary
Alucard, being a lightweight tool, can be easily integrated into various projects. You can utilize it as a template for existing projects or initialize entirely new repositories.
The repository comprises a single folder that includes the main daemon header file. Within the folder, you will find the DaemonComponents file, which contains the daemonThread.hpp, daemonLinkedList, and the Banner.

# daemonThread.hpp
The daemonThread is self-explanatory in its functionality. It operates autonomously, eliminating the need for extensive initialization. The daemonThread class is passed to the main Daemon class, where it is invoked accordingly.

# daemonLinkedList.hpp
DaemonLinkedList is used for history related events and it utilizes a linked list to extend it's flexibility with both user data and background processes. This is where the user input is passed to and processed for the session. This requires to be set up for now since it does not have any user input processing. 

# Banner.hpp
I have defined a banner for both Linux and Windows type operating system. The file contains macros that detect the system OS and defines the necessary banner. For Linux users, they have a more colorful experience because I am utilizing ASCII color codes to define the connection status of the daemon. The banner itself is also defined and is placed at the top of the file during initialization. Windows does not support most of the Linux additions so I gave it the standard until I can find a way to add more color.

# DaemonErrorcodes/DaemonErrorCode.hpp
This file contains a general definition for the error codes will be defined throughout the lifespan of the repo. I may overhaul it if I get any ideas but for now it will remain this way.

# Usage
To get started with general usage, all you need to do is create the boost io_context and initialize the daemon by calling it's constructor with the io_context. Then that is it.

