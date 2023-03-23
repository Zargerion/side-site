my_dict = {'a': 1, 'b': 2}
value = my_dict['a'] # 1
value = my_dict.get('a') # 1

my_dict = {'a': 1, 'b': 2}
search_value = 2
for key, value in my_dict.items():
    if value == search_value:
        print(key) # 'b'