RAM_SIZE_BYTES = 8000000

ram_usage = [False] * 8000000 # If ram_usage[address] is True, then address is reserved.

def reserveRAMRegion(size):
