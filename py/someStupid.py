# a = False

# def test():
#  global a
#  a = True
#  return a

class Work:

    def __init__(self, time: int, strength: int, brain: int):
        self.__time = time
        self.__strength = strength
        self.__brain = brain

    @property  # call method as attribute without ()
    def work_ratio(self) -> []:
        try:
            sum_means_full_percent = self.__time + self.__strength + self.__brain
            a = self.__time / sum_means_full_percent * 100
            b = self.__strength / sum_means_full_percent * 100
            c = self.__brain / sum_means_full_percent * 100
            return [a, b, c]
        except Exception:
            print('Try again. Need 3 value like integer.')
        finally:
            print('Good luck!')


dev_work = Work(12, 3, 15)
print(dev_work.work_ratio)
print(Work(12, 2, 1).work_ratio)