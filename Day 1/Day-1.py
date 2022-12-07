fi = open("input.txt", "r+")
fo = open("output.txt", "w+")
elf_count = 0
elf_list = [0]
for line in fi.readlines():
    line = line[:-1]
    if line == "":
        elf_count += 1
        elf_list.append(0)
    else:
        elf_list[elf_count] += int(line)

elf_list.sort()
fo.write(f"{elf_list[-1]}\n")
fo.write(f"{elf_list[-1] + elf_list[-2] + elf_list[-3]}")
