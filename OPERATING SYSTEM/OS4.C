#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

void getMemoryInfo() {
    FILE *meminfo = fopen("/proc/meminfo", "r");
    char line[MAX_LINE_LENGTH];

    if (meminfo == NULL) {
        perror("Error opening /proc/meminfo");
        exit(EXIT_FAILURE);
    }

    printf("Memory Information:\n");

    while (fgets(line, sizeof(line), meminfo) != NULL) {
        // Print the entire content of /proc/meminfo
        printf("%s", line);
    }

    fclose(meminfo);
}

int main() {
    getMemoryInfo();

    return 0;
}
