f = open("temp.txt", "w")

def writeObj(type: int, x: int, y: int, ani_set_id: int):
    f.write(f'{type}\t')
    f.write(f'{x}\t')
    f.write(f'{y}\t')
    f.write(f'{ani_set_id}\n')

writeObj(2, 0, 416, 23)

for i in range(1, 38):
    writeObj(2, i*16, 416, 24)

writeObj(2, 38*16, 416, 25)

f.close()