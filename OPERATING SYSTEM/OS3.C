#include <stdio.h>
#include <sys/utsname.h>

void getKernelInfo() {
    struct utsname unameData;

    if (uname(&unameData) != 0) {
        perror("Error getting kernel information");
        return;
    }

    printf("Kernel Version: %s %s\n", unameData.sysname, unameData.release);
}

void getCpuInfo() {
    FILE *cpuinfo = fopen("/proc/cpuinfo", "r");
    char line[256];

    if (cpuinfo == NULL) {
        perror("Error opening /proc/cpuinfo");
        return;
    }

    printf("\nCPU Information:\n");

    while (fgets(line, sizeof(line), cpuinfo) != NULL) {
        printf("%s", line);
    }

    fclose(cpuinfo);
}

int main() {
    getKernelInfo();
    getCpuInfo();

    return 0;
}
