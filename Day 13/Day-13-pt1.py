import math
fi = open("input.txt", "r")
fo = open("output.txt", "w")
list1 = []
list2 = []

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

if __name__ == "__main__":
    global l, ptr
    list_count = 1
    ans = 0
    ptr = 0
    value = ""
    while True:
        list1 = []
        list2 = []
        l = fi.readline()[1:-2] + ','
        if l == 'end,':
            break
        ptr = 0
        while ptr < len(l):
            if l[ptr] == ',':
                if value != ']' and value != '':
                    list1.append(int(value))
                value = ""
            elif l[ptr] == '[':
                list1.append(read_list())
                ptr += 1
            else:
                value = value + l[ptr]
            ptr += 1
        l = fi.readline()[1:-2] + ','
        ptr = 0
        while ptr < len(l):
            if l[ptr] == ',':
                if value != ']' and value != '':
                    list2.append(int(value))
                value = ""
            elif l[ptr] == '[':
                list2.append(read_list())
                ptr += 1
            else:
                value = value + l[ptr]
            ptr += 1
        if list_comparison(list1, list2) == 1:
            ans += list_count
        list_count += 1
        fi.readline()
    #for some reason you need to specifically debug this line for the thing to write into file.
    fo.write(f"{ans}\n")
    