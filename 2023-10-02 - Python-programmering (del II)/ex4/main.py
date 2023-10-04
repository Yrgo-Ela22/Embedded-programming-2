"""
" @brief Exercise 4 - File I/O with uppercase conversion.
"""

def file_retrieve(file_path):
    """
    " @brief Retrieves content of specified file.
    "
    " @param file_path
    "        Path to the file to read from.
    " @return
    "        List with content retrieved from the file.
    """
    buffer = []
    with open(file_path, "r") as file:
        buffer = file.readlines()
    return buffer

def file_write(file_path, data):
    """
    " @brief Writes content stored in referenced list to file.
    "
    " @param file_path
    "        Path to the destination file.
    " @param data
    "        List containing the data to write.
    """
    with open(file_path, "w") as file:
        for i in data:
            file.write(str(i))

def file_to_upper(indata, outdata):
    """ 
    " @brief Reads content from specified input file and writes in uppercase to specified output file.
    "
    " @param indata
    "        Path to input file.
    " @param outdata
    "        Path to output file.
    """
    data = file_retrieve(indata)    
    for i in range(len(data)):
        data[i] = data[i].upper()
    file_write(outdata, data)    

def main():
    """ 
    " @brief Reads content from "input.txt" and writes the content in uppercase to "output.txt".
    """
    file_to_upper("input.txt", "output.txt")
    return 

if __name__ == "__main__":
    main()