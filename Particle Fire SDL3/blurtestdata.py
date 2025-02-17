import random

def generate_random_number():
    # Generate a random number between 0 and 0xFFFFFF (16777215 in decimal)
    random_number = random.randint(0, 0xFFFFFF)
    
    # Shift the number left by 8 bits to ensure the last two digits are 00
    random_number = random_number << 8
    
    return random_number

print("int TESTDATA[] = ")
print("{")
for x in range(5):
    print("\t", end="")
    for y in range(4):
        number = generate_random_number()
        print(f'0x{number:08x}, ', end=" ")
    print()
print("};")

