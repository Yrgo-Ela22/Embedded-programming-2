#include <gtest/gtest.h>
#include <mutex.h>

static struct mutex* mutex = mutex_new();

TEST(MutexTest, TryLock) {
    EXPECT_EQ(mutex_try_lock(mutex), true);
    EXPECT_EQ(mutex_try_lock(mutex), false);
    mutex_unlock(mutex);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}