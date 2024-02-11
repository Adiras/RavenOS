/* Memory management API */

#ifndef MEMORY_H
#define MEMORY_H

#define HEAP_SIZE 1024
#define MAX_ALOCATION_ALLOWED 100

/**
 * Copies n bytes of memory from the source address to the destination address.
 *
 * @param src Pointer to the source memory location.
 * @param dest Pointer to the destination memory location.
 * @param num_bytes Number of bytes to copy.
 */
void memory_copy(char *src, char *dest, int num_bytes);

/**
 * @brief Allocates n bytes of memory on the heap.
 *
 * @param num_bytes The number of bytes to allocate.
 * @return A pointer to the beginning of the allocated memory block, or NULL if allocation fails.
 */
void *heap_alloc(int num_bytes);

/**
 * @brief Frees memory allocated on the heap.
 *
 * @param ptr A pointer to the memory block to be freed.
 */
void heap_free(void *ptr);

typedef struct {
    int heap_index;
    int size;
} Block;

#endif