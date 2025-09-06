#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

#define LIMIT 1024
#define BUFFER 256

typedef struct {
    int child;
    int parent;
} ProcessNode;

int fetch_parent_pid(int pid) {
    char filePath[64];
    snprintf(filePath, sizeof(filePath), "/proc/%d/status", pid);

    FILE *file = fopen(filePath, "r");
    if (!file) return -1;

    char line[BUFFER];
    int ppid = -1;

    while (fgets(line, sizeof(line), file)) {
        if (strncmp(line, "PPid:", 5) == 0) {
            sscanf(line + 5, "%d", &ppid);
            break;
        }
    }
    fclose(file);
    return ppid;
}

void show_hierarchy(ProcessNode *nodes, int total, int root, int depth) {
    for (int i = 0; i < depth; i++) printf("    ");
    printf("%d\n", root);

    for (int i = 0; i < total; i++) {
        if (nodes[i].parent == root) {
            show_hierarchy(nodes, total, nodes[i].child, depth + 1);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <pid1> <pid2> ...\n", argv[0]);
        return EXIT_FAILURE;
    }

    int watchList[LIMIT];
    int watchCount = argc - 1;

    for (int i = 0; i < watchCount; i++) {
        watchList[i] = atoi(argv[i + 1]);
    }

    while (1) {
        system("clear");  

        ProcessNode processes[LIMIT];
        int size = 0;

        for (int i = 0; i < watchCount; i++) {
            int pid = watchList[i];
            if (kill(pid, 0) == -1) continue; 

            int parent = fetch_parent_pid(pid);
            if (parent == -1) continue;

            processes[size].child = pid;
            processes[size].parent = parent;
            size++;
        }

        for (int i = 0; i < size; i++) {
            int isOrphan = 1;
            for (int j = 0; j < size; j++) {
                if (processes[i].parent == processes[j].child) {
                    isOrphan = 0;
                    break;
                }
            }
            if (isOrphan) {
                show_hierarchy(processes, size, processes[i].child, 0);
            }
        }

        fflush(stdout);
        sleep(1);
    }

    return EXIT_SUCCESS;
}
