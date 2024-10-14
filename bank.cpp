#include <iostream>
#include <vector>

// Declare global vectors to store Available resources, Max, Allocation, and Need matrices
std::vector<int> Available;       // Available resources for each resource type
std::vector<std::vector<int>> Max;       // Maximum resources that each process may request
std::vector<std::vector<int>> Allocation; // Resources currently allocated to processes
std::vector<std::vector<int>> Need;       // Resources that each process still needs to complete its task

// Function to calculate the Need matrix based on Max and Allocation matrices
void calculate_need(int n, int m) {
    // Compute the Need matrix for each process and resource type
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            Need[i][j] = Max[i][j] - Allocation[i][j];
        }
    }

    // Debugging: Print the Need matrix for verification
    std::cout << "Need matrix after calculation:" << std::endl;
    for (const auto& row : Need) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}

// Function to check if the system is in a safe state
bool is_safe(int n, int m) {
    std::vector<int> Work = Available;  // Initialize the Work vector with Available resources
    std::vector<bool> Finish(n, false); // Initialize the Finish vector to track finished processes

    int finished_count = 0;
    while (finished_count < n) { // Continue until all processes are finished or system is unsafe
        bool found = false;
        // Iterate through each process
        for (int i = 0; i < n; ++i) {
            if (!Finish[i]) {  // Check if the process is not finished yet
                bool can_allocate = true;
                // Check if the process can be allocated resources based on its Need and Available resources
                for (int j = 0; j < m; ++j) {
                    if (Need[i][j] > Work[j]) {  // If Need > Available, the process cannot be finished
                        can_allocate = false;
                        break;
                    }
                }
                if (can_allocate) {
                    // Allocate resources to the process and mark it as finished
                    std::cout << "Process " << i << " can be finished." << std::endl;
                    for (int j = 0; j < m; ++j) {
                        Work[j] += Allocation[i][j];
                    }
                    Finish[i] = true;
                    ++finished_count;
                    found = true;
                }
            }
        }
        // If no process can be finished, the system is in an unsafe state
        if (!found) {
            std::cout << "System is NOT in a safe state!" << std::endl;
            return false;
        }
    }
    // If all processes are finished successfully, the system is in a safe state
    std::cout << "System is in a safe state!" << std::endl;
    return true;
}

// Main function to input data and execute the Banker's algorithm
int main() {
    int n, m;  // Declare variables for the number of processes and resource types

    // Input the number of processes and resource types from the user
    std::cout << "Enter the number of processes: ";
    std::cin >> n;

    std::cout << "Enter the number of resources: ";
    std::cin >> m;

    // Resize vectors to store data based on user input
    Available.resize(m); 
    Max.resize(n, std::vector<int>(m)); 
    Allocation.resize(n, std::vector<int>(m)); 
    Need.resize(n, std::vector<int>(m));

    // Input Available resources, Max, and Allocation matrices from the user
    std::cout << "Enter available resources for each type (separated by spaces in matrice form):" << std::endl;
    for (int i = 0; i < m; ++i) {
        std::cin >> Available[i];
    }

    std::cout << "Enter maximum resources required for each process (in matrice form):" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << "Enter maximum resources for process " << i << ":" << std::endl;
        for (int j = 0; j < m; ++j) {
            std::cin >> Max[i][j];
        }
    }

    std::cout << "Enter allocated resources for each process (in matrice form):" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << "Enter allocated resources for process " << i << ":" << std::endl;
        for (int j = 0; j < m; ++j) {
            std::cin >> Allocation[i][j];
        }
    }

    // Validate inputs to ensure Max[i][j] <= Available[j] and Allocation[i][j] <= Max[i][j]
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (Max[i][j] > Available[j]) {
                std::cerr << "Error: Maximum resource request exceeds available resources! System is in an unsafe state." << std::endl;
                return 1;  // Exit with error code 1
            }
            if (Allocation[i][j] > Max[i][j]) {
                std::cerr << "Error: Allocated resources exceed maximum resources! System is in an unsafe state." << std::endl;
                return 1;  // Exit with error code 1
            }
        }
    }

    // Calculate the Need matrix for each process
    calculate_need(n, m);

    // Check if the system is in a safe state using Banker's algorithm
    is_safe(n, m);

    return 0;  // Return 0 to indicate successful execution
}




