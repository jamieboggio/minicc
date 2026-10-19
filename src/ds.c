#include "ds.h"

#include <stdint.h>
#include <stdlib.h>

bool tokenlist_init(tokenlist_t* list, size_t init_cap)
{
    if (list == NULL || init_cap == 0 || list->token_array != NULL) {
        return false;
    }

    token_t* new_data = malloc(init_cap * sizeof(token_t));
    if (new_data == NULL) {
        return false;
    }
    list->token_array = new_data;
    list->size = 0;
    list->capacity = init_cap;
    return true;
}

static inline bool is_full(tokenlist_t list)
{
    return list.size == list.capacity;
}

bool append(tokenlist_t* list, token_t in_token)
{
    if (list == NULL) {
        return false;
    }
    if (list->token_array == NULL && !tokenlist_init(list, DEFAULT_SIZE)) {
        return false;
    }
    if (is_full(*list)) {
        size_t cur_size_bytes = sizeof(token_t) * list->size;
        size_t new_size_bytes =
            cur_size_bytes > SIZE_MAX / 2 ? SIZE_MAX : (2 * cur_size_bytes);
        token_t* new_data = realloc(list->token_array, new_size_bytes);
        if (new_data == NULL) {
            return false;
        }
        list->token_array = new_data;
        list->capacity = cur_size_bytes / sizeof(token_t);
    }
    list->token_array[list->size++] = in_token;
    return true;
}

bool pop(tokenlist_t* list, token_t* out_token)
{
    if (list == NULL) {
        return false;
    }
    if (list->token_array == NULL || list->size == 0 || list->capacity == 0) {
        return false;
    }
    list->size--;
    if (out_token != NULL) {
        *out_token = list->token_array[list->size];
    }
    return true;
}

void tokenlist_free(tokenlist_t* list)
{
    if (list != NULL) {
        if (list->token_array != NULL) {
            free(list->token_array);
            list->token_array = NULL;
        }
        list->size = 0;
        list->capacity = 0;
    }
}
