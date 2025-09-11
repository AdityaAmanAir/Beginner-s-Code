#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <climits>

using namespace std;

struct Process {
    int id;
    int arrivalTime;
    int burstTime;
    int startTime;
    int completionTime;
    int waitingTime;
    int turnaroundTime;
};

bool compareArrival(const Process &a, const Process &b) {
    return a.arrivalTime < b.arrivalTime;
}

bool compareBurst(const Process &a, const Process &b) {
    return a.burstTime < b.burstTime;
}

void calculateMetrics(vector<Process> &processes) {
    for (auto &p : processes) {
        p.turnaroundTime = p.completionTime - p.arrivalTime;
        p.waitingTime = p.turnaroundTime - p.burstTime;
    }
}

void printResults(const vector<Process> &processes) {
    cout << "\nProcess ID | Arrival Time | Burst Time | Start Time | Completion Time | Waiting Time | Turnaround Time\n";
    cout << "---------------------------------------------------------------------------------------------------\n";
    
    int totalWaiting = 0, totalTurnaround = 0;
    
    for (const auto &p : processes) {
        totalWaiting += p.waitingTime;
        totalTurnaround += p.turnaroundTime;
        cout << setw(10) << p.id << " | "
             << setw(12) << p.arrivalTime << " | "
             << setw(10) << p.burstTime << " | "
             << setw(10) << p.startTime << " | "
             << setw(15) << p.completionTime << " | "
             << setw(12) << p.waitingTime << " | "
             << setw(15) << p.turnaroundTime << endl;
    }
    cout << "\nAverage Waiting Time: " << (float)totalWaiting / processes.size() << endl;
    cout << "Average Turnaround Time: " << (float)totalTurnaround / processes.size() << endl;
}

void FCFS(vector<Process> processes) {
    cout << "\n=== FCFS Scheduling ===\n";
    sort(processes.begin(), processes.end(), compareArrival);
    
    int currentTime = 0;
    for (auto &p : processes) {
        if (currentTime < p.arrivalTime) {
            currentTime = p.arrivalTime;
        }
        p.startTime = currentTime;
        p.completionTime = currentTime + p.burstTime;
        currentTime = p.completionTime;
    }calculateMetrics(processes);
    printResults(processes);
}

void SJF(vector<Process> processes) {
    cout << "\n=== SJF Scheduling ===\n";
    sort(processes.begin(), processes.end(), compareArrival);
    
    int n = processes.size();
    int currentTime = 0;
    int completed = 0;
    vector<bool> isCompleted(n, false);
    
    while (completed != n) {
        int idx = -1;
        int minBurst = INT_MAX;
        
        for (int i = 0; i < n; i++) {
            if (!isCompleted[i] && processes[i].arrivalTime <= currentTime && processes[i].burstTime < minBurst) {
                minBurst = processes[i].burstTime;
                idx = i;}
        }if (idx != -1) {
            processes[idx].startTime = currentTime;
            processes[idx].completionTime = currentTime + processes[idx].burstTime;
            processes[idx].waitingTime = processes[idx].startTime - processes[idx].arrivalTime;
            processes[idx].turnaroundTime = processes[idx].completionTime - processes[idx].arrivalTime;
            
            currentTime = processes[idx].completionTime;
            isCompleted[idx] = true;
            completed++;
        } else {
            currentTime++;}
    }printResults(processes);
}

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;
    
    vector<Process> processes(n);
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        cout << "Enter arrival time for process " << i + 1 << ": ";
        cin >> processes[i].arrivalTime;
        cout << "Enter burst time for process " << i + 1 << ": ";
        cin >> processes[i].burstTime;}
    FCFS(processes);
    SJF(processes);
    return 0;
}