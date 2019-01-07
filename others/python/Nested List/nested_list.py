lowest = sec_lowest = 999
stud_grades = []
lowest_stud = sec_lowest_stud = []
for _ in range(int(raw_input())):
    name = raw_input()
    score = float(raw_input())
    stud_grades.append([name, score])

    if score < lowest:  # new lowest score
        sec_lowest = lowest                 # prev lowest becomes second lowest
        lowest = score                      # update new lowest score
        if sec_lowest == 999:
            sec_lowest = lowest
        sec_lowest_stud = lowest_stud       # list of lowest studs is now list of 2nd lowest stud
        lowest_stud = []                    # new lowest stud list
        lowest_stud.append(name)   # add the new entry
        #print('lowest is now', lowest, "second is", sec_lowest)
    elif score < sec_lowest:    # new second lowest (but still less than lowest)
        sec_lowest = score                      # update 2nd lowest score
        sec_lowest_stud = []                    # discard prev 2nd lowest stud list
        sec_lowest_stud.append(name)   # add new entry
        print("second is now", sec_lowest, [name,score])
    elif score == lowest:
        lowest_stud.append(name)
        #print("added lowest another", [name, score])
    elif score == sec_lowest:   # another sec lowest student
        sec_lowest_stud.append(name)
        #print("added 2nd lowest another", [name, score])

sec_lowest_stud.sort()
for name in sec_lowest_stud:
    print(name)