#include <memory.h>
#include <builtin.h>

void memory_copy(char *src, char *dest, int num_bytes) 
{
  for (int i = 0; i < num_bytes; i++)
    *(dest + i) = *(src + i);
}

static int block_allocated = 0;

static unsigned char heap[HEAP_SIZE];

Block blocks[MAX_ALOCATION_ALLOWED];

void *heap_alloc(int num_bytes)
{
  void *address = NULL;

  if (block_allocated == MAX_ALOCATION_ALLOWED)
    return NULL;

  if (block_allocated == 0) {
    blocks[0].heap_index = 0;
    blocks[0].size = num_bytes;
    block_allocated++;
    return &heap[0];
  }

  for (int i = block_allocated; i > 0; i--) {
    Block curr = blocks[i - 1];
    int top_idx = curr.heap_index + curr.size - 1;

    int bottom_idx = HEAP_SIZE;
    if (i != block_allocated)
      bottom_idx = blocks[i].heap_index;

    int available_size = bottom_idx - top_idx;
    if (available_size >= num_bytes) {
      blocks[block_allocated].heap_index = top_idx + 1;
      blocks[block_allocated].size = num_bytes;

      heap_blocks_sort();
      return &heap[blocks[block_allocated++].heap_index];
    }
  }

  // Could not reserve enough space
  return address;
}

void heap_free(void *ptr) {
  for (int i = 0; i < block_allocated; i++) {
    if (&heap[blocks[i].heap_index] == ptr) {
      Block temp = blocks[i];
      blocks[i] = blocks[block_allocated - 1];
      blocks[block_allocated - 1] = temp;
      heap_blocks_sort();
      block_allocated--;
      return;
    }
  }
}

void heap_blocks_sort() {
  for (int i = 0; i < block_allocated - 1; i++)
    for (int j = 0; j < block_allocated - i - 1; j++)
      if (blocks[j].heap_index > blocks[j + 1].heap_index) {
        Block temp = blocks[j];
        blocks[j] = blocks[j + 1];
        blocks[j + 1] = temp;
      }
}