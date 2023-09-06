#include <gtest/gtest.h>
#include <cstdint>
#include <chrono>
#include <thread>
#include <semaphore.h>

namespace {

inline void SemaphoreThread1(const uint8_t sem_id, const uint16_t&& delay_time_ms) {
    EXPECT_EQ(semaphore_reserve(sem_id), SEMAPHORE_OPERATION_SUCCESS);
    std::this_thread::sleep_for(std::chrono::milliseconds(delay_time_ms));
    EXPECT_EQ(semaphore_release(sem_id), SEMAPHORE_OPERATION_SUCCESS);
}

inline void SemaphoreThread2(const uint8_t sem_id, 
                             const uint16_t&& delay_time_ms, 
                             const uint16_t&& start_delay_ms) {
    std::this_thread::sleep_for(std::chrono::milliseconds(start_delay_ms));
    EXPECT_EQ(semaphore_reserve(sem_id), SEMAPHORE_OPERATION_SUCCESS);
    std::this_thread::sleep_for(std::chrono::milliseconds(delay_time_ms));
    EXPECT_EQ(semaphore_release(sem_id), SEMAPHORE_OPERATION_SUCCESS);
}

} /* namespace */

TEST(SemaphoreTest, SemID) {
    EXPECT_EQ(semaphore_reserve(SEMAPHORE_ID_MISC), SEMAPHORE_OPERATION_SUCCESS);
    EXPECT_EQ(semaphore_release(SEMAPHORE_ID_MISC), SEMAPHORE_OPERATION_SUCCESS);

    EXPECT_EQ(semaphore_reserve(SEMAPHORE_LIMIT), SEMAPHORE_ID_INVALID);
    EXPECT_EQ(semaphore_release(100), SEMAPHORE_ID_INVALID);
}

TEST(SemaphoreTest, RunThreads) {
    std::thread t1(SemaphoreThread1, SEMAPHORE_ID_MISC, 100);
    std::thread t2(SemaphoreThread2, SEMAPHORE_ID_MISC, 200, 25);
    t1.join();
    t2.join();
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}