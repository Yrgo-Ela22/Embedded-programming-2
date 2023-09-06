/********************************************************************************
 * @brief Library for providing counting semaphores.
 ********************************************************************************/
#pragma once

#include <cstdint>

namespace yrgo {
namespace thread_sync {

/********************************************************************************
 * @brief Class for utilizing counting semaphores of an arbitrary max count.
 ********************************************************************************/
template <uint32_t kNumSemaphores>
class CountingSemaphore {
  static_assert(kNumSemaphores > 0, "The number of semaphores cannot be set to 0!");

  public:
    /********************************************************************************
     * @brief Creates new counting semaphore.
     ********************************************************************************/
    CountingSemaphore(void) = default;

    /********************************************************************************
     * @brief Provides the number of reserved semaphores.
     * 
     * @return
     *        The number of reserved semaphores.
     ********************************************************************************/
    uint32_t NumReservedSemaphores(void) const { return counter_; }

    /********************************************************************************
     * @brief Provides the number of available semaphores.
     * 
     * @return
     *        The number of available semaphores.
     ********************************************************************************/
    uint32_t NumAvailableSemaphores(void) const { return kNumSemaphores - counter_; }

    /********************************************************************************
     * @brief Indicates if all semaphores are reserved.
     * 
     * @return
     *        True if all semaphores are reserved, else false.
     ********************************************************************************/
    bool AllSemaphoresReserved(void) const { return counter_ >= kNumSemaphores; }

    /********************************************************************************
     * @brief Reserves semaphore. The calling thread is blocked until a semaphore 
     *        is available.
     ********************************************************************************/
    void Reserve(void) {
        while (counter_ >= kNumSemaphores);
        counter_++;
    }

    /********************************************************************************
     * @brief Releases semaphore.
     ********************************************************************************/
    void Release(void) { if (counter_) counter_--; }

  private:
    uint32_t counter_{};
};

} /* namespace thread_sync */
} /* namespace yrgo */