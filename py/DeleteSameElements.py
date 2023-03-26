my_list = [1, 2, 3, 4, 3, 2]
my_list = list(set(my_list)) # set == hash table this is not red-black-tree set in c++
print(my_list) # [1, 2, 3, 4]

my_list = [1, 2, 3, 4, 5, 5, 6, 6]
new_list = []

for i in my_list:
    if i not in new_list:
        new_list.append(i)

print(new_list)