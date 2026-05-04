#include <iostream>
#include <thread>
#include <vector>
#include <atomic>
#include <chrono>

std::atomic<bool> keepRunning(true);

void cpuIntensiveTask() {
    volatile double dummy = 0.0; 
    
    while (keepRunning) {
        dummy += 1.1;
        if (dummy > 1000000.0) {
            dummy = 0.0;
        }
    }
}

int main() {
    
    unsigned int numCores = std::thread::hardware_concurrency();
    if (numCores == 0) numCores = 4;

    std::cout << "Detected " << numCores << " logical CPU cores." << std::endl;
    std::cout << "Revving CPU to 100% for 10 seconds." << std::endl;

    std::vector<std::thread> threads;

    for (unsigned int i = 0; i < numCores; ++i) {
        threads.push_back(std::thread(cpuIntensiveTask));
    }
    
    

    std::this_thread::sleep_for(std::chrono::seconds(10));

    std::cout << "\n10 seconds reached. Engaging kill switch..." << std::endl;
    keepRunning = false;


    for (auto& t : threads) {
        t.join();
    }

    std::cout << "All threads stopped. CPU returning to normal." << std::endl;

    return 0;
}