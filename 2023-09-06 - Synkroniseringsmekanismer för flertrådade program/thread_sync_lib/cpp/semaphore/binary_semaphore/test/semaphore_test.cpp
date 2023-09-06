#include <gtest/gtest.h>
#include <cstdint>
#include <chrono>
#include <thread>
#include <semaphore.hpp>

using namespace yrgo::thread_sync;

namespace {

inline void SemaphoreThread1(const uint8_t sem_id, const uint16_t&& delay_time_ms) {
    EXPECT_EQ(Semaphore::Reserve(sem_id), Semaphore::kOperationSuccess);
    std::this_thread::sleep_for(std::chrono::milliseconds(delay_time_ms));
    EXPECT_EQ(Semaphore::Release(sem_id), Semaphore::kOperationSuccess);
}

inline void SemaphoreThread2(const uint8_t sem_id, 
                             const uint16_t&& delay_time_ms, 
                             const uint16_t&& start_delay_ms) {
    std::this_thread::sleep_for(std::chrono::milliseconds(start_delay_ms));
    EXPECT_EQ(Semaphore::Reserve(sem_id), Semaphore::kOperationSuccess);
    std::this_thread::sleep_for(std::chrono::milliseconds(delay_time_ms));
    EXPECT_EQ(Semaphore::Release(sem_id), Semaphore::kOperationSuccess);
}

} /* namespace */

TEST(SemaphoreTest, SemID) {
    EXPECT_EQ(Semaphore::Reserve(Semaphore::ID::kMisc), Semaphore::kOperationSuccess);
    EXPECT_EQ(Semaphore::Release(Semaphore::ID::kMisc), Semaphore::kOperationSuccess);

    EXPECT_EQ(Semaphore::Reserve(Semaphore::kLimit), Semaphore::kInvalidID);
    EXPECT_EQ(Semaphore::Release(100), Semaphore::kInvalidID);
}

TEST(SemaphoreTest, RunThreads) {
    std::thread t1(SemaphoreThread1, Semaphore::ID::kMisc, 100);
    std::thread t2(SemaphoreThread2, Semaphore::ID::kMisc, 200, 25);
    t1.join();
    t2.join();
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}