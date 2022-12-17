import math
fi = open("input.txt", "r+")
fo = open("output.txt", "w+")
lists = []

def read_list():
    global l, ptr
    ptr += 1
    templist = []
    value = ""
    while l[ptr] != ']':
        if l[ptr] == ',':
            if value != ']' and value != '':
                templist.append(int(value))
            value = ""
        elif l[ptr] == '[':
            templist.append(read_list())
        else:
            value = value + l[ptr]
        ptr += 1
    if value != '':
        templist.append(int(value))
    return templist

def list_comparison(left : list, right : list):
    result = 0 
    i = 0
    for i in range(min([len(left), len(right)])):
        if type(left[i]) == type(right[i]):
            if type(left[i]) == type(0):
                if left[i] > right[i]:
                    result = -1
                elif left[i] < right[i]:
                    result = 1
            else:
                result = list_comparison(left[i], right[i])
        else:
            if type(left[i]) == type(0):
                result = list_comparison([left[i]], right[i])
            else:
                result = list_comparison(left[i], [right[i]])
        if result != 0:
            return result
    if len(left) < len(right):
        result = 1
    elif len(left) > len(right):
        result = -1
    return result

def bubblesort():
    #I'm so done with this
    for i in range(len(lists)):
        for j in range(i, 0, -1):
            if list_comparison(lists[j - 1], lists[j]) != 1:
                lists[j - 1], lists[j] = lists[j], lists[j - 1]

if __name__ == "__main__":
    global l, ptr
    ans = 0
    ptr = 0
    value = ""
    while True:
        temp_list = []
        l = fi.readline()[1:-2] + ','
        if l == 'end,':
            break
        ptr = 0
        while ptr < len(l):
            if l[ptr] == ',':
                if value != ']' and value != '':
                    temp_list.append(int(value))
                value = ""
            elif l[ptr] == '[':
                temp_list.append(read_list())
                ptr += 1
            else:
                value = value + l[ptr]
            ptr += 1
        lists.append(temp_list)
        temp_list = []
        l = fi.readline()[1:-2] + ','
        if l == 'end,':
            break
        ptr = 0
        while ptr < len(l):
            if l[ptr] == ',':
                if value != ']' and value != '':
                    temp_list.append(int(value))
                value = ""
            elif l[ptr] == '[':
                temp_list.append(read_list())
                ptr += 1
            else:
                value = value + l[ptr]
            ptr += 1
        lists.append(temp_list)
        fi.readline()
    lists.append([[2]])
    lists.append([[6]])
    bubblesort()
    decoder = 1
    for i in range(len(lists)):
        if lists[i] == [[2]]:
            decoder *= i + 1
        if lists[i] == [[6]]:
            decoder *= i + 1
    #don't even bother running, just debug right here and read the value of the decoder
    fo.write(f"{decoder}")
    pass
    