Banker's Algorithm Simulation
This project implements a simulation of the Banker's Algorithm for Deadlock Avoidance as part of the CST2555 Operating Systems module coursework.
Project Description
The Banker's Algorithm is a deadlock avoidance algorithm used in operating systems. This simulation demonstrates how the algorithm works in allocating resources to processes while avoiding deadlock situations.
Features

Simulates multiple processes and resource types
Implements resource allocation and request handling
Determines system safety state
Handles new resource requests

Video Demonstration
A detailed explanation of the implementation and a demonstration of the program can be found in this video:
https://youtu.be/pzSRijvrtaY?si=ppw7_TbOB-dNOyte

Getting Started
Prerequisites

C++ compiler (GCC recommended)
Make (optional, for easier compilation)

Installation

Clone the repository:
git clone https://github.com/your-username/bankers-algorithm-simulation.git

Navigate to the project directory:
Copycd bankers-algorithm-simulation


Usage
To compile and run the program:

Compile the source code:
g++ Bank.cpp

Run the program:
./banK
or
./a.exe

Follow the on-screen prompts to input the number of processes, resources, and their respective values.

For a detailed example of how to run the program and interpret the output, please refer to the video demonstration linked above. The video provides a step-by-step guide on inputting data and understanding the results of the Banker's Algorithm simulation.
Algorithm Overview

Initialize system state with available resources and maximum resource needs for each process
Calculate the need matrix
Check if the system is in a safe state
Process new resource requests:

Check if the request can be granted
If yes, temporarily allocate resources and check for system safety
If safe, grant the request; otherwise, deny it
