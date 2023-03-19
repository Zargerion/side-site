my_list = [1, 2, 3, 4, 5]
new_list = my_list.copy() # O(n)

list1 = [1, 2, 3]
list2 = [4, 5, 6]
new_list = list1 + list2 # O(n)


n = 1000
matrix = [[0] * n for i in range(n)] # O(n^2)

list1 = [1, 2, 3]
list2 = ['a', 'b', 'c']
all_pairs = [(i, j) for i in list1 for j in list2] # O(n^2)


my_list = [1, 2, 3, 4, 5]
x = my_list[0] # O(1)

my_dict = {'a': 1, 'b': 2, 'c': 3}
x = my_dict['a'] # O(1)