/********************************************************************************
 * @brief Library containing functionality for using semaphores.
 ********************************************************************************/
#pragma once

#include <cstdint>

namespace yrgo {
namespace thread_sync {

class Semaphore {
  public:

    /********************************************************************************
     * @brief Semaphore attributes.
     * 
     * @param kLimit
     *        The maximum number of concurrent semaphores.
     * @param kMin
     *        The lowest permitted semaphore ID.
     * @param kMax
     *        The highest permitted semaphore ID.
     ********************************************************************************/
    static constexpr uint8_t kLimit{32};
    static constexpr uint8_t kMin{0};
    static constexpr uint8_t kMax{kLimit - 1};

    /********************************************************************************
     * @brief Semaphore identifiers for shared resources.
     * 
     * @param kIo
     *        Semaphore for I/O resources, such as printing.
     * @param kSharedMemory
     *        Semaphore for shared memory, such as variables.
     * @param kMisc
     *        Semaphore for miscellaneous resources.
     ********************************************************************************/
    struct ID {
        static constexpr uint8_t kIo{0};
        static constexpr uint8_t kSharedResources{1};
        static constexpr uint8_t kMisc{2};
    };

    /********************************************************************************
     * @brief Semaphore result codes.
     * 
     * @param kOperationSuccess
     *        Indicates that semaphore reservation or release operation succeeded.
     * @param kInvalidID
     *        Indicates an invalid semaphore ID was specified (ID >= 32).
     ********************************************************************************/
    static constexpr int32_t kOperationSuccess{0};
    static constexpr int32_t kInvalidID{-1};

    /********************************************************************************
     * @brief Creates new semaphore.
     ********************************************************************************/
    Semaphore(void) = default;

    /********************************************************************************
     * @brief Reserves semaphore with specified ID. The calling thread is blocked
     *        until the semaphore is available.
     * 
     * @param sem_id
     *        The ID of the semaphore.
     * @return
     *        Success code 0 upon reserved semaphore, else error code -1 if an
     *        invalid semaphore ID was specified.
     ********************************************************************************/
    static int32_t Reserve(const uint8_t sem_id);

    /********************************************************************************
     * @brief Reserves semaphore with specified ID. The calling thread is blocked
     *        until the semaphore is available.
     * 
     * @param sem_id
     *        The ID of the semaphore.
     * @return
     *        Success code 0 upon released semaphore, else error code -1 if an
     *        invalid semaphore ID was specified.
     ********************************************************************************/
    static int32_t Release(const uint8_t sem_id);

  private:

    /********************************************************************************
     * @brief Private member variables.
     * 
     * @param semaphores_
     *        Contains 32 binary semaphores.
     ********************************************************************************/
    static uint32_t semaphores_;

    /********************************************************************************
     * @brief Indicates if specified semaphore ID is invalid.
     * 
     * @param sem_id
     *        The ID of the semaphore.
     * @return
     *        True if specified semaphore ID is invalid, else false.
     ********************************************************************************/
    static constexpr bool InvalidID(const uint8_t sem_id) {
        return sem_id >= kLimit;
    }

    /********************************************************************************
     * @brief Indicates if specified semaphore is reserved.
     * 
     * @param sem_id
     *        The ID of the semaphore.
     * @return
     *        True if specified semaphore ID is reserved, else false.
     ********************************************************************************/
    static bool SemaphoreReserved(const uint8_t sem_id) {
        return semaphores_ & (1ULL << sem_id);
    }

    /********************************************************************************
     * @brief Sets specified semaphore to indicate that the semaphore is reserved.
     * 
     * @param sem_id
     *        The ID of the semaphore.
     ********************************************************************************/
    static void SemaphoreSet(const uint8_t sem_id) {
        semaphores_ |= (1ULL << sem_id);
    }

    /********************************************************************************
     * @brief Clears specified semaphore to indicate that the semaphore is released.
     * 
     * @param sem_id
     *        The ID of the semaphore.
     ********************************************************************************/
    static void SemaphoreClear(const uint8_t sem_id) {
        semaphores_ &= ~(1ULL << sem_id);
    }
};

} /* namespace thread_sync */
} /* namespace yrgo */