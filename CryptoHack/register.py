s = [[j for j in i] for i in 'WHQDJ QSHEII YDJQSJ FHQSJYSU'.split()]
for _ in range(ord('A'), ord('Z') + 1):
    for l in s:
        for i in range(len(l)):
            print(l[i], end = '')
            l[i] = chr(ord(l[i]) + 1) if ord(l[i]) != ord('Z') else 'A'
        print('  ', end = '')
    print()