/********************************************************************************
 * @brief Library containing functionality for using semaphores.
 ********************************************************************************/
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>

/********************************************************************************
 * @brief Semaphore attributes.
 * 
 * @param SEMAPHORE_LIMIT
 *        The maximum number of concurrent semaphores.
 * @param SEMAPHORE_ID_MIN
 *        The lowest permitted semaphore ID.
 * @param SEMAPHORE_ID_MAX
 *        The highest permitted semaphore ID.
 ********************************************************************************/
#define SEMAPHORE_LIMIT  32U
#define SEMAPHORE_ID_MIN 0U
#define SEMAPHORE_ID_MAX SEMAPHORE_LIMIT - 1U

/********************************************************************************
 * @brief Semaphore identifiers for shared resources.
 * 
 * @param SEMAPHORE_ID_IO
 *        Semaphore for I/O resources, such as printing.
 * @param SEMAPHORE_ID_SHARED_MEMORY
 *        Semaphore for shared memory, such as variables.
 * @param SEMAPHORE_ID_MISC
 *        Semaphore for miscellaneous resources.
 ********************************************************************************/
#define SEMAPHORE_ID_IO            0U
#define SEMAPHORE_ID_SHARED_MEMORY 1U
#define SEMAPHORE_ID_MISC          2U

/********************************************************************************
 * @brief Semaphore result codes.
 * 
 * @param SEMAPHORE_OPERATION_SUCCESS
 *        Indicates that semaphore reservation or release operation succeeded.
 * @param SEMAPHORE_ID_INVALID
 *        Indicates an invalid semaphore ID was specified (ID >= 32).
 ********************************************************************************/
#define SEMAPHORE_OPERATION_SUCCESS  0
#define SEMAPHORE_ID_INVALID        -1

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
int32_t semaphore_reserve(const uint8_t sem_id);

/********************************************************************************
 * @brief Releases semaphore with specified ID.
 * 
 * @param sem_id
 *        The ID of the semaphore.
 * @return
 *        Success code 0 upon reserved semaphore, else error code -1 if an
 *        invalid semaphore ID was specified.
 ********************************************************************************/
int32_t semaphore_release(const uint8_t sem_id);

#ifdef __cplusplus
}
#endif