from typing import List
import matplotlib.pyplot as pp

file = open('output.txt', mode='r', encoding='utf8')
rangeStart = float(file.readline())
rangeEnd = float(file.readline())
numOfBin = int(file.readline())
file.readline()
areasLines = file.readlines()
file.close()
areas = [float(area.removesuffix('\n')) for area in areasLines]
binStep = (rangeEnd - rangeStart) / (numOfBin - 1)
x = [rangeStart + x * binStep for x in range(0, 100, 1)]
pp.bar(x, areas)
pp.xlabel('theta, degrees')
pp.ylabel('S, mm^2')
pp.show()  
