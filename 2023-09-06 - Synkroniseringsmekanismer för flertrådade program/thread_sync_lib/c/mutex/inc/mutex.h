/********************************************************************************
 * @brief Library containing functionality for using mutexes.
 ********************************************************************************/
#pragma once 

#ifdef __cplusplus
extern "C" {
#endif

#include <stdlib.h>
#include <stdbool.h>

/********************************************************************************
 * @brief Struct for implementation of mutexes.
 ********************************************************************************/
struct mutex;

/********************************************************************************
 * @brief Provides a reference to a new mutex.
 * 
 * @return
 *        Reference to a new mutex or a nullptr if the mutex could not be created
 *        due to insufficient free memory.
 ********************************************************************************/
struct mutex* mutex_new(void);

/********************************************************************************
 * @brief Deletes referenced mutex by releasing allocated resources and sets
 *        the associated pointer to null. Potential locks are unlocked before
 *        deletion.
 * 
 * @param self
 *        Reference to the pointer associated with the mutex.
 ********************************************************************************/
void mutex_delete(struct mutex** self);

/********************************************************************************
 * @brief Indicates if the mutex if blocked by another thread.
 * 
 * @param self
 *        Reference to the mutex.
 * @return
 *        True if the mutex is blocked, else false.
 ********************************************************************************/
bool mutex_blocked(const struct mutex* self);

/********************************************************************************
 * @brief Locks mutex. The calling thread is blocked until the mutex is available.
 * 
 * @param self
 *        Reference to the mutex.
 ********************************************************************************/
void mutex_lock(struct mutex* self);

/********************************************************************************
 * @brief Unlocks mutex so it becomes available for other threads.
 * 
 * @param self
 *        Reference to the mutex.
 ********************************************************************************/
void mutex_unlock(struct mutex* self);

/********************************************************************************
 * @brief Tries to lock mutex, which is done only if the mutex is available.
 *        The calling thread is not blocked if the mutex is unavailable.
 * 
 * @param self
 *        Reference to the mutex.
 * @return
 *        True if the mutex was locked, else false.
 ********************************************************************************/
bool mutex_try_lock(struct mutex* self);

#ifdef __cplusplus
}
#endif