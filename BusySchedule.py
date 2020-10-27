from datetime import time
n = input()
while int(n) > 0:
    appsam = []
    appspm = []
    for x in range(0, int(n)):
        temp = input();
        #print("Reading in: " + temp)
        temp = temp.split()
        if temp[1] == "a.m.":
            appsam.insert(x, temp[0])
        else:
            appspm.insert(x, temp[0])
    count = 0
    times = []
    for atime in appsam:
        temp = atime.split(':')
        if temp[0] == "12":
            temp[0] = '0'
        times.insert(count, time(int(temp[0]), int(temp[1])))
        ++count
    times.sort()
    for val in times:
        val = str(val).split(':')
        if val[0][0] == '0':
            val[0] = val[0][1:len(val[0])]
        if val[0] == '0':
            print("12", end="")
        else:
            print(val[0], end="")
        print(':', end="")
        print(val[1], end="")
        print(" a.m.")
    
    count = 0
    del times
    times = []
    for atime in appspm:
        temp = atime.split(':')
        if temp[0] == "12":
            temp[0] = '0'
        times.insert(count, time(int(temp[0]), int(temp[1])))
        ++count
    times.sort()
    for val in times:
        val = str(val).split(':')
        if val[0][0] == '0':
            val[0] = val[0][1:len(val[0])]
        if val[0] == '0':
            print("12", end="")
        else:
            print(val[0], end="")
        print(':', end="")
        print(val[1], end="")
        print(" p.m.")
        
    
    del appsam
    del appspm
    n = input()
    if int(n) > 0:
        print()