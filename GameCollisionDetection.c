#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TABLE_SIZE 100
#define CELL_SIZE 10
#define MAX_OBJECTS 100

// Object structure
typedef struct Object {
    int id;
    int x, y;
    struct Object* next;
} Object;

Object* hashTable[TABLE_SIZE];

// Hash function
int hashFunction(int x, int y) {
    int hx = x / CELL_SIZE;
    int hy = y / CELL_SIZE;
    return (hx + hy * 31) % TABLE_SIZE;
}

// Initialize
void initTable() {
    for (int i = 0; i < TABLE_SIZE; i++)
        hashTable[i] = NULL;
}

// Insert
void insert(int id, int x, int y) {
    int index = hashFunction(x, y);

    Object* newObj = (Object*)malloc(sizeof(Object));
    newObj->id = id;
    newObj->x = x;
    newObj->y = y;

    newObj->next = hashTable[index];
    hashTable[index] = newObj;
}

// Distance check (actual collision)
int isCollision(int x1, int y1, int x2, int y2) {
    int dx = x1 - x2;
    int dy = y1 - y2;

    int distSq = dx * dx + dy * dy;

    int radius = 5; // fixed radius for all objects
    return distSq <= (radius * radius);
}

// Check collisions
void checkCollisions(int id, int x, int y) {
    int baseX = x / CELL_SIZE;
    int baseY = y / CELL_SIZE;

    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {

            int nx = baseX + dx;
            int ny = baseY + dy;

            int index = (nx + ny * 31) % TABLE_SIZE;
            if (index < 0) index += TABLE_SIZE;

            Object* temp = hashTable[index];

            while (temp != NULL) {
                if (temp->id != id) {

                    // REAL collision check
                    if (isCollision(x, y, temp->x, temp->y)) {
                        printf("Collision between Object %d and Object %d\n",
                               id, temp->id);
                    }
                }
                temp = temp->next;
            }
        }
    }
}

// Free memory
void freeTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Object* temp = hashTable[i];
        while (temp != NULL) {
            Object* t = temp;
            temp = temp->next;
            free(t);
        }
        hashTable[i] = NULL;
    }
}

// Main
int main() {
    int n;

    printf("Enter number of objects: ");
    scanf("%d", &n);

    int x[MAX_OBJECTS], y[MAX_OBJECTS];

    initTable();

    for (int i = 0; i < n; i++) {
        printf("Enter x y for Object %d: ", i + 1);
        scanf("%d %d", &x[i], &y[i]);

        insert(i + 1, x[i], y[i]);
    }

    printf("\n--- Collision Results ---\n");

    for (int i = 0; i < n; i++) {
        checkCollisions(i + 1, x[i], y[i]);
    }

    freeTable();

    return 0;
}