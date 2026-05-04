#include <iostream>
#include <vector>
#include <cstring>

int main() {
    std::vector<char*> memoryLedger;
    
    const size_t chunkSize = 100 * 1024 * 1024; 
    size_t totalAllocated = 0;

    std::cout << "Starting memory stress test." << std::endl;

    try {
        while (true) {
            
            char* newChunk = new char[chunkSize];

            std::memset(newChunk, 1, chunkSize);

            memoryLedger.push_back(newChunk);
            
            totalAllocated += chunkSize;
            std::cout << "Successfully committed: " << totalAllocated / (1024 * 1024) << " MB\n";
        }
        
    } catch (const std::bad_alloc& e) {
        std::cout << "\n[ALERT] System is entirely out of memory!" << std::endl;
        std::cout << "Exception caught: " << e.what() << std::endl;
        std::cout << "Total RAM locked down: " << totalAllocated / (1024 * 1024) << " MB\n";
    }

    std::cout << "\nReleasing memory back to the operating system..." << std::endl;
    for (char* chunk : memoryLedger) {
        delete[] chunk;
    }
    std::cout << "Memory freed. Exiting gracefully." << std::endl;

    return 0;
}