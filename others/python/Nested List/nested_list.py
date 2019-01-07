if __name__ == '__main__':
    stud_list = []
    lowest = sec_lowest = 999
    for _ in range(int(input())):
        name = input()
        score = float(input())
        stud_list.append([name, score])

        if score < lowest:
            sec_lowest = lowest
            lowest = score
        elif score < sec_lowest and score != lowest:
            sec_lowest = score
        #print('lowest is:', lowest, 'second is:', sec_lowest)

    #print('lowest is:', lowest, 'second is:', sec_lowest)

    sec_lowest_studs = []
    for stud in stud_list:
        if (sec_lowest == stud[1]):
            sec_lowest_studs.append(stud[0])

    sec_lowest_studs.sort()
    for name in sec_lowest_studs:
        print(name)
