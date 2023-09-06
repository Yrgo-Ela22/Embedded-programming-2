#include <mutex.h>

struct mutex {
    bool blocked;
};

struct mutex* mutex_new(void) {
    struct mutex* self = (struct mutex*)malloc(sizeof(struct mutex));
    if (!self) return 0;
    self->blocked = false;
    return self;
}

void mutex_delete(struct mutex** self) {
    if (self) {
        free(*self);
        *self = 0;
    }
}

bool mutex_blocked(const struct mutex* self) {
    return self->blocked;
}

void mutex_lock(struct mutex* self) {
    while (self->blocked);
    self->blocked = true;
}

void mutex_unlock(struct mutex* self) {
    self->blocked = false;
}

bool mutex_try_lock(struct mutex* self) {
    if (!self->blocked) {
        self->blocked = true;
        return true;
    } else {
        return false;
    }
}