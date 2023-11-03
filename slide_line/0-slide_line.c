#include <stdlib.h>
#include <stdio.h>

#include "slide_line.h"

/**
 * slide_line - Slide and merge integers in a line.
 * @line: Pointer to the line of integers.
 * @size: Number of elements in the line.
 * @direction: Direction to slide (SLIDE_LEFT or SLIDE_RIGHT).
 * Return: 1 on success, 0 on failure.
 */
int slide_line(int *line, size_t size, int direction)
{
    size_t i;
    int j;

    if (line == NULL || (direction != SLIDE_LEFT && direction != SLIDE_RIGHT))
        return 0;

    if (direction == SLIDE_LEFT) {
        for (i = 0; i < size; i++) {
            if (line[i] != 0) {
                for (j = (int)i + 1; j < (int)size; j++) {
                    if (line[j] != 0) {
                        if (line[i] == line[j]) {
                            line[i] *= 2;
                            line[j] = 0;
                            break;
                        } else {
                            break;
                        }
                    }
                }
            }
        }
    } else if (direction == SLIDE_RIGHT) {
        for (i = size - 1; (int)i < (int)size; i--) {
            if (line[i] != 0) {
                for (j = (int)i - 1; j >= 0; j--) {
                    if (line[j] != 0) {
                        if (line[i] == line[j]) {
                            line[i] *= 2;
                            line[j] = 0;
                            break;
                        } else {
                            break;
                        }
                    }
                }
            }
        }
    }

    for (i = 0, j = 0; i < size; i++) {
        if (line[i] != 0) {
            if (direction == SLIDE_LEFT) {
                line[j] = line[i];
            } else {
                line[size - 1 - j] = line[i];
            }
            if (j != (int)i) {
                line[i] = 0;
            }
            j++;
        }
    }

    return 1;
}
