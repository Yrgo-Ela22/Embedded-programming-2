""" @brief Example program where a mutex is used for thread synchronization. """
import thread_sync
import threading

""" @brief Mutex used for I/O-resources. """
mutex = thread_sync.Mutex() 

def delay_ms(delay_time_ms: int | float) -> None:
    """ @brief Delays the calling thread with specified delay time in milliseconds. 
 
        @param delay_time_ms
               Specified delay time in milliseconds.
    """
    import time 
    assert isinstance(delay_time_ms, int | float), "Invalid type for delay time!"
    assert delay_time_ms >= 0, "Delay time cannot be less than 0!"
    time.sleep(delay_time_ms / 1000.0)
    return
 
def run_thread(thread_id: int, delay_time_ms: int) -> None:
    """ @brief Runs specified thread continuously, where a thread message is printed.
               A mutex is used to reserve the I/O resources before the print.
               After each print, the thread is blocked during specified delay time
               set via the thread parameters.
 
        @param thread_id
               Unique thread identifier.
        @param delay_time_ms
               Delay time between each print in milliseconds.
    """
    assert isinstance(thread_id, int), "Invalid type for thread ID!"
    assert thread_id >= 0, "Thread ID must be set to a natural integer!"
    while 1:
        mutex.lock()
        print("Running thread with ID " + str(thread_id) + "!\n")
        mutex.unlock()
        delay_ms(delay_time_ms)
    return

def main() -> None:
    """ @brief Creates three threads and corresponding thread parameters. 
               The threads are set to continuously run until the program is 
               terminated.
    """
    t1 = threading.Thread(target=run_thread, args=(0, 500,))
    t2 = threading.Thread(target=run_thread, args=(1, 1000,)) 
    t3 = threading.Thread(target=run_thread, args=(2, 2000,))
    
    t1.start()
    t2.start()
    t3.start()
    
    t1.join()
    t2.join()
    t3.join()
    return
    
if __name__ == "__main__":
    """ @brief If this is the startup script, the main function is called
               to start the program. 
    """
    main()