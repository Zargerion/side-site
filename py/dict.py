MENU_DICT = {"First button": "Doing something", "Second button": "Doing something", 
             "Thirt Button": "Doing something","Fourth Button": "Doing something", "Fifth Button": "Doing something"}


list:list
list = [key for key in MENU_DICT]

for i in range(5):
    print(list[i])


    #print(key + ": " + MENU_DICT[key])