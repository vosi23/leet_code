#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*

As a part of the larger application the Descriptor structure was created to hold basic data about each program.
However the methods for allocating and deallocating the structure are incomplete.

Finish the allocate_and_initialize_descriptor and deallocate_descriptor functions.

The allocate_and_initialize_descriptor should:
- allocate memory for the new descriptor struct
- set id in the struct to the parameter id
- set name_length in the struct to the length of string of which the name parameter points
- the name in the struct should point to a copy of the string to which the name parameter points

The deallocate_descriptor function should free all memory that was allocated by allocate_and_initialize_descriptor function.

*/

typedef struct Descriptor
{
    int id;
    int name_length;
    char *name;
} Descriptor;

Descriptor *allocate_and_initialize_descriptor(int id, const char *name) 
{
    Descriptor *descriptor = (Descriptor *)malloc(sizeof(Descriptor));
    if (descriptor == NULL)
    {
        printf("Memory allocation failed for descriptor.\n");
        return NULL;
    }

    descriptor->id = id;

    descriptor->name_length = strlen(name);

    descriptor->name = (char *)malloc((descriptor->name_length + 1) * sizeof(char));
    if (descriptor->name == NULL)
    {
        printf("Memory allocation failed for name.\n");
        free(descriptor);
        return NULL;
    }
    strcpy(descriptor->name, name);

    return descriptor;
}

void deallocate_descriptor(Descriptor *descriptor)
{
    if (descriptor != NULL)
    {
        if (descriptor->name != NULL)
        {
            free(descriptor->name);
        }
        free(descriptor);
    }
}

int main()
{
    Descriptor *descriptor = allocate_and_initialize_descriptor(2, "File");
    if (descriptor != NULL)
    {
        printf("Id: %d, name length: %d, name: %s\n", descriptor->id, descriptor->name_length, descriptor->name);
        deallocate_descriptor(descriptor);
    }
    return 0;
}

