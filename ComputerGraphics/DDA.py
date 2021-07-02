
# Importing Image from PIL package
from PIL import Image

def DDA(x1 ,y1 ,x2 ,y2):

    dx = x2 - x1
    dy = y2 - y1
    #calculate steps required for generating pixels
    if (abs(dx) > abs(dy)):
        step = abs(dx);
    else:
        step = abs(dy)
    
    #increment in x and y for each steps

    Xinc = dx / step
    Yinc = dy / step

    #define pixel position for each step

    x = x1
    y = y1

    image = Image.new('RGB', (500, 500))

    for i in range(0, step):
        image.putpixel( (round(x), round(y)), (255, 255, 255, 0))
        x = x + Xinc
        y = y + Yinc
    
    image.save('DDA.png')

    return image


#Define the starting and ending coordinates
line = DDA(2, 14, 450, 498)
line.show()





	


