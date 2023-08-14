#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <buffer_size_MB>\n", argv[0]);
        return 1;
    }

    size_t buffer_size_MB = atoi(argv[1]);
    size_t num_elements = buffer_size_MB * 1024 * 1024 / sizeof(int);
    int *buffer = (int *)malloc(num_elements * sizeof(int));

    if (buffer == NULL) {
        perror("Memory allocation failed");
        return 1;
    }

        for (size_t i = 0; i < num_elements; i++) {
        buffer[i] = i;
    }

    clock_t start_time = clock();
    for (size_t i = 0; i < num_elements; i++) {
        buffer[i] = buffer[i] + 1;
    }

    clock_t end_time = clock();
    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    double speed_MBps = (buffer_size_MB * 2) / elapsed_time;

    printf("Memory read-write test completed.\n");
    printf("Buffer size: %zu MB\n", buffer_size_MB);
    printf("Time taken: %.6f seconds\n", elapsed_time);
    printf("Speed: %.2f MB/s\n", speed_MBps);

    free(buffer);

    return 0;
}
	
