#include <iostream>
using namespace std;

void firstFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n];
    for(int i = 0; i < n; i++) allocation[i] = -1;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(blockSize[j] >= processSize[i]) {
                allocation[i] = j;
                blockSize[j] -= processSize[i];
                break;}}}

    cout << "\nFirst Fit Allocation:\n";
    for(int i = 0; i < n; i++) {
        cout << "Process " << i+1 << " (" << processSize[i] << ") -> ";
        if(allocation[i] != -1) cout << "Block " << allocation[i]+1 << "\n";
        else cout << "Not Allocated\n";
    }}

void bestFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n];
    for(int i = 0; i < n; i++) allocation[i] = -1;

    for(int i = 0; i < n; i++) {
        int bestIdx = -1;
        for(int j = 0; j < m; j++) {
            if(blockSize[j] >= processSize[i]) {
                if(bestIdx == -1 || blockSize[j] < blockSize[bestIdx])
                    bestIdx = j;
            }}
        if(bestIdx != -1) {
            allocation[i] = bestIdx;
            blockSize[bestIdx] -= processSize[i];
        }
    }
    cout << "\nBest Fit Allocation:\n";
    for(int i = 0; i < n; i++) {
        cout << "Process " << i+1 << " (" << processSize[i] << ") -> ";
        if(allocation[i] != -1) cout << "Block " << allocation[i]+1 << "\n";
        else cout << "Not Allocated\n";
    }
}
void worstFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n];
    for(int i = 0; i < n; i++) allocation[i] = -1;

    for(int i = 0; i < n; i++) {
        int worstIdx = -1;
        for(int j = 0; j < m; j++) {
            if(blockSize[j] >= processSize[i]) {
                if(worstIdx == -1 || blockSize[j] > blockSize[worstIdx])
                    worstIdx = j;
            }
        }
        if(worstIdx != -1) {
            allocation[i] = worstIdx;
            blockSize[worstIdx] -= processSize[i];
        }}

    cout << "\nWorst Fit Allocation:\n";
    for(int i = 0; i < n; i++) {
        cout << "Process " << i+1 << " (" << processSize[i] << ") -> ";
        if(allocation[i] != -1) cout << "Block " << allocation[i]+1 << "\n";
        else cout << "Not Allocated\n";
    }
}

int main() {
    int blockSize[] = {100, 500, 200, 300, 600};
    int processSize[] = {212, 417, 112, 426};
    int m = sizeof(blockSize) / sizeof(blockSize[0]);
    int n = sizeof(processSize) / sizeof(processSize[0]);

    int b1[m], b2[m], b3[m];
    for(int i = 0; i < m; i++) {
        b1[i] = b2[i] = b3[i] = blockSize[i];
    }

    firstFit(b1, m, processSize, n);
    bestFit(b2, m, processSize, n);
    worstFit(b3, m, processSize, n);

    return 0;
}

