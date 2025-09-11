#include <iostream>
#include <vector>
#include <list>
#include <iomanip>
using namespace std;

const int DISK_SIZE = 20;
const int BLOCK_SIZE = 1;

struct Block {
    int blockNumber;
    Block* next;
    bool allocated;
    
    Block(int num) : blockNumber(num), next(nullptr), allocated(false) {}
};
struct File {
    string name;
    int size;
    int startBlock;
    Block* head;
    
    File(string n, int s) : name(n), size(s), startBlock(-1), head(nullptr) {}
};
class ContiguousAllocator {
private:
    vector<bool> disk;
    vector<File> files;
    
public:
    ContiguousAllocator() : disk(DISK_SIZE, false) {}
    
    bool createFile(string name, int size) {
        int start = -1;
        int count = 0;
        for (int i = 0; i < DISK_SIZE; i++) {
            if (!disk[i]) {
                if (count == 0) start = i;
                count++;
                if (count == size) break;
            } else {
                count = 0;
                start = -1;
            }
        }
        if (count < size) {
            cout << "Error: Not enough contiguous space for file '" << name << "'\n";
            return false;
        }
        for (int i = start; i < start + size; i++) {
            disk[i] = true;
        }
        File newFile(name, size);
        newFile.startBlock = start;
        files.push_back(newFile);
        cout << "File '" << name << "' created starting at block " << start << endl;
        return true;
    }
    
    bool deleteFile(string name) {
        for (auto it = files.begin(); it != files.end(); it++) {
            if (it->name == name) {
                for (int i = it->startBlock; i < it->startBlock + it->size; i++) {
                    disk[i] = false;
                }
                cout << "File '" << name << "' deleted\n";
                files.erase(it);
                return true;
            }
        }
        cout << "Error: File '" << name << "' not found\n";
        return false;
    }
    
    void displayDisk() {
        cout << "Contiguous Disk Status:\n";
        cout << "Blocks: ";
        for (int i = 0; i < DISK_SIZE; i++) {
            cout << setw(2) << i << " ";
        }
        cout << "\nStatus: ";
        for (int i = 0; i < DISK_SIZE; i++) {
            cout << setw(2) << (disk[i] ? "X" : "F") << " ";
        }
        cout << "\n\n";
    }
    
    void displayFiles() {
        cout << "Files in Contiguous System:\n";
        for (const auto& file : files) {
            cout << "File: " << file.name << ", Size: " << file.size 
                 << ", Start: " << file.startBlock << endl;
        }
        cout << endl;
    }
};

class LinkedListAllocator {
private:
    vector<Block*> disk;
    list<File> files;
    Block* freeList;
    
public:
    LinkedListAllocator() {
        for (int i = 0; i < DISK_SIZE; i++) {
            disk.push_back(new Block(i));
        }
        freeList = disk[0];
        Block* current = freeList;
        for (int i = 1; i < DISK_SIZE; i++) {
            current->next = disk[i];
            current = current->next;
        }
    }
    
    ~LinkedListAllocator() {
        for (auto block : disk) {
            delete block;
        }
    }
    
    bool createFile(string name, int size) {
        if (getFreeBlockCount() < size) {
            cout << "Error: Not enough free blocks for file '" << name << "'\n";
            return false;
        }
        File newFile(name, size);
        Block* current = nullptr;
        Block* prev = nullptr;
        for (int i = 0; i < size; i++) {
            if (freeList == nullptr) break;
            Block* allocatedBlock = freeList;
            freeList = freeList->next;
            allocatedBlock->next = nullptr;
            allocatedBlock->allocated = true;
            if (newFile.head == nullptr) {
                newFile.head = allocatedBlock;
                current = allocatedBlock;
            } else {
                current->next = allocatedBlock;
                current = current->next;
            }
        }
        files.push_back(newFile);
        cout << "File '" << name << "' created with linked allocation\n";
        return true;
    }
    
    bool deleteFile(string name) {
        for (auto it = files.begin(); it != files.end(); it++) {
            if (it->name == name) {
                Block* current = it->head;
                while (current != nullptr) {
                    current->allocated = false;
                    Block* nextBlock = current->next;
                    current->next = freeList;
                    freeList = current;
                    current = nextBlock;
                }
                cout << "File '" << name << "' deleted\n";
                files.erase(it);
                return true;
            }
        }
        cout << "Error: File '" << name << "' not found\n";
        return false;
    }
    
    int getFreeBlockCount() {
        int count = 0;
        Block* current = freeList;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }
    
    void displayDisk() {
        cout << "Linked List Disk Status:\n";
        cout << "Block#: ";
        for (int i = 0; i < DISK_SIZE; i++) {
            cout << setw(2) << i << " ";
        }
        cout << "\nStatus: ";
        for (int i = 0; i < DISK_SIZE; i++) {
            cout << setw(2) << (disk[i]->allocated ? "X" : "F") << " ";
        }
        cout << "\n\n";
    }
    
    void displayFiles() {
        cout << "Files in Linked List System:\n";
        for (const auto& file : files) {
            cout << "File: " << file.name << ", Size: " << file.size 
                 << ", Blocks: ";
            Block* current = file.head;
            while (current != nullptr) {
                cout << current->blockNumber;
                if (current->next != nullptr) cout << "->";
                current = current->next;
            }
            cout << endl;
        }
        cout << endl;
    }
    
    void displayFreeList() {
        cout << "Free List: ";
        Block* current = freeList;
        while (current != nullptr) {
            cout << current->blockNumber;
            if (current->next != nullptr) cout << "->";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    cout << "FILE STORAGE ALLOCATION TECHNIQUES\n";
    cout << "==================================\n\n";
    cout << "CONTIGUOUS ALLOCATION\n";
    cout << "=====================\n";
    ContiguousAllocator contiguous;
    contiguous.createFile("file1", 3);
    contiguous.createFile("file2", 5);
    contiguous.createFile("file3", 4);
    contiguous.displayDisk();
    contiguous.displayFiles();
    contiguous.deleteFile("file2");
    contiguous.displayDisk();
    cout << "\nLINKED LIST ALLOCATION\n";
    cout << "======================\n";
    LinkedListAllocator linkedList;
    linkedList.createFile("doc1", 3);
    linkedList.createFile("doc2", 5);
    linkedList.createFile("doc3", 4);
    linkedList.displayDisk();
    linkedList.displayFiles();
    linkedList.displayFreeList();
    linkedList.deleteFile("doc2");
    linkedList.displayDisk();
    linkedList.displayFreeList();
    return 0;
}