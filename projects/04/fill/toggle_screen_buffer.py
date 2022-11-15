
#Toggling simulation of blackening/whitening sreen on Hack Platform Before Committing it to Assembly!!
WHITE = 0
BLACK = -1 # 2-Complement of (Base10 1) == (Base2 0000000000000001) = (Base2 1111111111111111) =  (Base10 (2^16/2)) - 1 = 32,767 which is (-1) 
KEYBOARD_MEMORY_MAPP_ADDR = 24576
SCREEN_BUFFER_START = 16384
SCREEN_BUFFER_END = 24575
KEYBOARD_MEMORY_MAPP_ADDR = 24576

MAX_ADDRESS_VALUE_ON_HACK_PLATFORM = 65535

HACK_MEMORY_BUFFER = [0] * MAX_ADDRESS_VALUE_ON_HACK_PLATFORM

########### TEST FUNCTION ###########
def validate_screen_buffer_color_value(color_val):
    for i in range(SCREEN_BUFFER_START, SCREEN_BUFFER_END + 1):
        if(HACK_MEMORY_BUFFER[i] != color_val):
            print("Address at index " + str(i) + " is not set to " + str(color_val) + " !")
            return False
    print("SCREEN BUFFER IS VALID!")
    return True

#####################################


def set_screen_buffer(color_val):
    cout = 0
    for i in range(SCREEN_BUFFER_START, SCREEN_BUFFER_END + 1):
        HACK_MEMORY_BUFFER[i] = color_val
        cout+=1
    assert cout == (SCREEN_BUFFER_END - SCREEN_BUFFER_START) + 1

def blacken_screen():
    set_screen_buffer(BLACK)


def whiten_screen():
    set_screen_buffer(WHITE)


def main():
    # simulating a key press for N cycles
    key_pressed = 5 
    while(key_pressed):
        blacken_screen()
        key_pressed-=1

    print("MEMORY BUFFER AFTER BLACKENING: ", HACK_MEMORY_BUFFER)
    assert validate_screen_buffer_color_value(BLACK)
    print("NO KEY PRESSED!! WHITENING SCREEN...")
    whiten_screen()
    print("MEMORY BUFFER AFTER WHITENING: ", HACK_MEMORY_BUFFER)
    assert validate_screen_buffer_color_value(WHITE)



if __name__ == "__main__":
    main() 
