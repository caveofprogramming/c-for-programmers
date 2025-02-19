import colorsys;
import random

for i in range(0, 20) :
    hue = random.uniform(0, 1)
    sat = random.uniform(0, 1)
    lig = random.uniform(0, 1)

    # Create some edge cases.
    if(i == 0):
        hue = 0
        sat = 0
        lig = 0
    elif(i == 2):
        hue = 1
        sat = 1
        lig = 1

    rgb = colorsys.hls_to_rgb(hue, lig, sat)

    red = round(0xFF * rgb[0])
    green = round(0xFF * rgb[1])
    blue = round(0xFF * rgb[2])

    print(f"{{ {red},{green},{blue},{hue:.4f},{sat:.4f},{lig:.4f} }},")


