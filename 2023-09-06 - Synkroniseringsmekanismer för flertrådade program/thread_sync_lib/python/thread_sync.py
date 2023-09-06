""" @brief Library containing functionality for thread synchronization 
           mechanisms in the form of mutexes and semaphores. 
"""
from ctypes import *

class Semaphore:
    """ @brief Class for implementation of semaphores. """
    
    """ @brief Semaphore parameters. 
    
        @param LIMIT
               The maximum number of concurrent semaphores.
        @param SEM_ID_MIN  
               The minimum permitted semaphore ID.
        @param SEM_ID_MAX   
               The maximum permitted semaphore ID.
    """
    LIMIT     : int = 32
    SEM_ID_MIN: int = 0
    SEM_ID_MAX: int = LIMIT - 1

    """ @brief Semaphore result codes.
    
        @param SUCCESSFUL_OPERATION
               Indicates that semaphore reservation or release operation succeeded.
        @param INVALID_SEMAPHORE_ID 
               Indicates an invalid semaphore ID was specified (ID >= 32).    
    """
    SUCCESSFUL_OPERATION: int = 0
    INVALID_SEM_ID      : int = -1
    
    """ @brief Semaphore identifiers for shared resources.
    
        @param IO
               Semaphore for I/O resources, such as printing.
        @param SHARED_MEMORY
               Semaphore for shared memory, such as variables.
        @param MISC
               Semaphore for miscellaneous resources. 
    """
    class ID:
        IO           : int = 0
        SHARED_MEMORY: int = 1
        MISC         : int = 2
    
    def reserve(self, sem_id: int) -> bool:
        """ @brief Reserves semaphore with specified id. The calling thread
                   is blocked until the semaphore is available.
              
            @param sem_id
                   The ID of the semaphore.
            @return
                   Success code 0 upon reserved semaphore, else error code -1
                   if an invalid semaphore ID was specified.             
        """
        assert isinstance(sem_id, int), "Invalid type specified for lock ID!"
        if (self.__invalid_sem_id(sem_id)):
            return self.INVALID_SEM_ID
        while (self.__reserved(sem_id)): pass
        self.__implement_reserve(sem_id)
        return self.SUCCESSFUL_OPERATION
    
    def release(self, sem_id: int) -> bool:
        """ @brief Releases semaphore with specified ID so that it becomes
                   available for other threads. 
        
            @param sem_id
                   The ID of the semaphore.
            @return
                   Success code 0 upon released semaphore, else error code -1
                   if an invalid semaphore ID was specified.       
        """
        assert isinstance(sem_id, int), "Invalid type specified for lock ID!"
        if (self.__invalid_sem_id(sem_id)):
            return self.INVALID_SEM_ID
        self.__implement_release(sem_id)
        return self.SUCCESSFUL_OPERATION
    
    """ @brief Privateember variables 
    
        @param __semaphores
               Contains 32 binary semaphores.
    """
    __semaphores: c_uint32 = c_uint32(0)
    
    def __invalid_sem_id(self, sem_id: int) -> bool:
        """ @brief Indicates if specified semaphore ID is invalid.
        
            @param sem_id
                   The ID of the semaphore.
            @return
                   True if specified semaphore ID is invalid, else false.
        """
        return True if sem_id < 0 or sem_id >= self.LIMIT else False
    
    def __reserved(self, sem_id: int) -> bool:
        """ @brief Indicates if specified semaphore ID is reserved.
        
            @param sem_id
                   The ID of the semaphore.
            @return
                   True if the semaphore is reserved, else false.
        """
        return bool(self.__semaphores.value & (1 << sem_id))
    
    def __implement_reserve(self, sem_id: int) -> None:
        """ @brief Sets specified semaphore to indicate that the semaphore is reserved.
         
            @param sem_id
                   The ID of the semaphore.
        """
        self.__semaphores.value |= (1 << sem_id)
        return
    
    def __implement_release(self, sem_id: int) -> None:
        """ @brief Clears specified semaphore to indicate that the semaphore is released.
         
            @param sem_id
                   The ID of the semaphore.
        """
        self.__semaphores.value &= ~(1 << sem_id)
        return

class Mutex:
    """ @brief Class for implementation of mutexes. """
     
    def __init__(self) -> None:
        """ @brief  Creates new mutex. """
        self.__blocked = False
        return
        
    def lock(self) -> None:
        """ @brief Locks mutex. The calling thread is blocked until the mutex is available. """
        while self.__blocked: pass
        self.__blocked = True 
        return
        
    def unlock(self) -> None:
        """ @brief Unlocks mutex so it becomes available for other threads. """
        self.__blocked = False
        return
        
    def try_lock(self) -> bool:
        """ @brief Tries to lock mutex, which is done only if the mutex is available.
                   The calling thread is not blocked if the mutex is unavailable.
                   
            @return
                   True if the mutex was locked, else false.
        """
        if not self.__blocked:
            self.__blocked = True
            return True
        else:
            return False

