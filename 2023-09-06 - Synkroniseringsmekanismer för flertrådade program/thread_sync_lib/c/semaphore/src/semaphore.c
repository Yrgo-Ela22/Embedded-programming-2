#include <semaphore.h>

static uint32_t semaphores = 0;

static inline bool semaphore_id_valid(const uint8_t sem_id) {
    return sem_id < SEMAPHORE_LIMIT;
}

static inline bool semaphore_taken(const uint8_t sem_id) {
    return semaphores & (1 << sem_id);
}

int32_t semaphore_reserve(const uint8_t sem_id) {
    if (semaphore_id_valid(sem_id)) {
        while (semaphore_taken(sem_id));
        semaphores |= (1 << sem_id);
        return SEMAPHORE_OPERATION_SUCCESS;
    } else {
        return SEMAPHORE_ID_INVALID;
    }
}

int32_t semaphore_release(const uint8_t sem_id) {
    if (semaphore_id_valid(sem_id)) {
        semaphores &= ~(1 << sem_id);
        return SEMAPHORE_OPERATION_SUCCESS;
    } else {
        return SEMAPHORE_ID_INVALID;
    }
}