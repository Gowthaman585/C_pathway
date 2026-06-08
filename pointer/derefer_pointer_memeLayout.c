#include <stdlib.h>
#include <stdio.h>

int main() {
    // ==========================================
    // 1. USING 'deref_pointer' (No Asterisk)
    // Purpose: Create/Manage the master block
    // ==========================================
    int** deref_pointer = calloc(2, sizeof(int*)); 
    
    printf("--- LAYER 2: Master Pointer ---\n");
    printf("Base Address of Cabinet (deref_pointer): %p\n\n", (void*)deref_pointer);


    // ==========================================
    // 2. USING '*deref_pointer' (One Asterisk)
    // Purpose: Access and Change the Shelf Addresses
    // ==========================================
    // We break into Layer 1 to assign actual book arrays to our slots
    *(deref_pointer + 0) = calloc(3, sizeof(int)); // Shelf 0 holds 3 books
    *(deref_pointer + 1) = calloc(3, sizeof(int)); // Shelf 1 holds 3 books

    printf("--- LAYER 1: The Shelf Slots (Values inside slots) ---\n");
    printf("Slot 0 holds address (*(deref_pointer+0)): %p\n", (void*)*(deref_pointer + 0));
    printf("Slot 1 holds address (*(deref_pointer+1)): %p\n\n", (void*)*(deref_pointer + 1));


    // ==========================================
    // 3. USING '**deref_pointer' (Two Asterisks)
    // Purpose: Access and Change the Actual Book Values
    // ==========================================
    // We smash through both walls to write data directly into the books
    **(deref_pointer + 0) = 150;                  // Sets Book 0 on Shelf 0 to 150 pages
    *(*(deref_pointer + 0) + 1) = 280;            // Sets Book 1 on Shelf 0 to 280 pages
    **(deref_pointer + 1) = 410;                  // Sets Book 0 on Shelf 1 to 410 pages

    printf("--- LAYER 0: The Actual Book Pages ---\n");
    printf("Shelf 0, Book 0 pages (**(deref_pointer+0)):   %d\n", **(deref_pointer + 0));
    printf("Shelf 0, Book 1 pages (*(*(deref_pointer+0)+1)): %d\n", *(*(deref_pointer + 0) + 1));
    printf("Shelf 1, Book 0 pages (**(deref_pointer+1)):   %d\n\n", **(deref_pointer + 1));


    // Clean up all memory blocks starting from bottom layers up
    free(*(deref_pointer + 0));
    free(*(deref_pointer + 1));
    free(deref_pointer);

    return 0;
}
