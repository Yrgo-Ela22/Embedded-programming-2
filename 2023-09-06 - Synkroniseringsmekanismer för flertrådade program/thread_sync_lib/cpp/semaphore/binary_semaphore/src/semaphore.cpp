#include <semaphore.hpp>

namespace yrgo {
namespace thread_sync {

uint32_t Semaphore::semaphores_{};

int32_t Semaphore::Reserve(const uint8_t sem_id) {
    if (InvalidID(sem_id)) return kInvalidID;
    while (SemaphoreReserved(sem_id));
    SemaphoreSet(sem_id);
    return kOperationSuccess;
}

int32_t Semaphore::Release(const uint8_t sem_id) {
    if (InvalidID(sem_id)) return kInvalidID;
    SemaphoreClear(sem_id);
    return kOperationSuccess;
}

} /* namespace thread_sync */
} /* namespace yrgo */