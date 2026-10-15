#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <windows.h>
#include <psapi.h>
using namespace std;

ULONGLONG start_tick = 0;
void start_monitor() {
    start_tick = GetTickCount64();
}
void stop_report() {
    ULONGLONG endTick = GetTickCount64();
    ULONGLONG duration = endTick - start_tick;
    PROCESS_MEMORY_COUNTERS pmc;
    long long memoryKB = -1;
    if (GetProcessMemoryInfo(GetCurrentProcess(), &pmc, sizeof(pmc))) {
        memoryKB = pmc.WorkingSetSize / 1024; 
    }
    cout << "\n === Performance Report ===\n";
    cout << "Time taken: " << duration << " ms\n";
    if (memoryKB >= 0) {
        cout << "Consumed memory : " << memoryKB << " KB ("
            << (memoryKB / 1024.0) << " MB)\n";
    }
    else {
        cout << " Memory read failure \n";
    }
    cout << "============================\n";
}

int main() {
    start_monitor(); 

    int i = 1;
    while (i<=100) {
        cout << "hello";
        i++;
    }
    cout << "\n\n";
    stop_report();
}