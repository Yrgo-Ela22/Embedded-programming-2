#include <gtest/gtest.h>
#include <mutex.hpp>

namespace thread_sync = yrgo::thread_sync;

thread_sync::Mutex mutex{};

TEST(MutexTest, TryLock) {
    EXPECT_EQ(mutex.TryLock(), true);
    EXPECT_EQ(mutex.TryLock(), false);
    mutex.Unlock();
}

TEST(MutexTest, LockGuards) {
    if (1) {
        thread_sync::LockGuard lock_guard{mutex};
        EXPECT_EQ(mutex.TryLock(), false);
    }

    EXPECT_EQ(mutex. TryLock(), true);
    mutex.Unlock();
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
    return 0;
}