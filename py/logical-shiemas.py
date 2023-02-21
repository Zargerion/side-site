import os
import sys
import time

from pytimedinput import timedInput


class Lamp:
    def __init__(self, color, signal, power, turn: False):
        self.turn = turn
        self.signal = signal
        self.power = power
        if self.turn and self.power:
            self.light = "Fire"
        else:
            self.light = "Dark"
        if self.turn:
            self.color = color
        else:
            self.color = "No color"

    def change_turn(self):
        if self.turn and self.power:
            self.turn = False
        elif self.power:
            self.turn = True
        return self.turn

    def get_turn(self):
        return self.turn


class SignalGenerator:
    def __init__(self):
        self.signal = "A"

    def make_signal(self):
        return self.signal


class PowerGenerator:
    def __init__(self):
        self.power = True

    def make_power(self):
        return self.power


class Comparator:
    def __init__(self, first, second):
        self.first = first
        self.second = second

    def compare_less(self):
        if self.first < self.second:
            return True


class ColorGenerator:
    def __init__(self):
        self.color_list = ['White', 'Blue', 'Green', 'Red', 'Yellow']

    def change_color(self):
        color = self.color_list[0]
        if color == self.color_list[0]:
            self.color_list = self.color_list[1:] + self.color_list[:1]
            return self

    def get_color(self):
        color = self.color_list[0]
        return color


def data_outs():
    a_dict = {variable: value for variable, value in lamp_1.__dict__.items()}
    data_out = ''.join('{}: {}\n'.format(key, val) for key, val in a_dict.items())
    sys.stdout.write(data_out)


def arrow():
    sys.stdout.flush()
    for i in range(43):
        sys.stdout.write("\r{0}>".format("=" * i))
        sys.stdout.flush()
        time.sleep(0.003)


DOING = True


def directing(ncc):
    global lamp_1
    txt = timedInput('-*#@ Lamp Controller And Matrix Animation @#*--*#{', timeout=0.016)
    if txt == ('q', True):
        global DOING
        DOING = False
        return DOING
    elif txt == ('w', True):
        ncc = ncc.change_color()
        lamp_1 = Lamp(n_color.get_color(), SignalGenerator().make_signal(), PowerGenerator().make_power(),
                      lamp_1.get_turn())
    elif txt == ('s', True):
        lamp_1 = Lamp(n_color.get_color(), SignalGenerator().make_signal(), PowerGenerator().make_power(),
                      lamp_1.change_turn())


def from_int_num_to_first_digit_of_bin(n: int) -> str:
    f_d = '{:032b}'.format(n)[31]
    return f_d


def o(f_d: int) -> str:
    if from_int_num_to_first_digit_of_bin(f_d) == '1':
        a = '##'
    else:
        a = "--"
    return a

def crutch_setter(gwg_crutch_f, no_f):
    """Best function ever I have seen ;)"""
    if gwg_crutch_f == no_f:
        print(gwg_crutch_f, no_f)
        global CRUTCH
        CRUTCH = '--'
        return CRUTCH



no = 00000000000000000000000000000000
gwg_crutch = no
qq = no
qw = no
qe = no
qt = no
qy = no
qu = no
qi = no
qo = no
qp = no

lamp_1 = Lamp("White", SignalGenerator().make_signal(), PowerGenerator().make_power(), turn=False)
n_color = ColorGenerator()
CRUTCH = 'False'

while DOING is True:

    # clears terminal
    os.system('cls||clear')

    # organizes directing
    directing(n_color)

    # gets and outs the data
    data_outs()

    # outs animation on the mini matrix
    crutch_setter(gwg_crutch, no)

    if CRUTCH == '--':
        gwg_crutch = 2863311530
        qq = 399388572
        qw = 613763370
        qe = 348924312
        qt = 2547986366
        qy = 4177129971
        qu = 2489133242
        qi = 400502718
        qo = 663113484
        qp = 400502718
        CRUTCH = 'False'

    gwg_crutch = int(bin(gwg_crutch >> 1), 2)
    qq = int(bin(qq >> 1), 2)
    qw = int(bin(qw >> 1), 2)
    qe = int(bin(qe >> 1), 2)
    qt = int(bin(qt >> 1), 2)
    qy = int(bin(qy >> 1), 2)
    qu = int(bin(qu >> 1), 2)
    qi = int(bin(qi >> 1), 2)
    qo = int(bin(qo >> 1), 2)
    qp = int(bin(qp >> 1), 2)
    
    print('-*#@[ '+'{:032b}'.format(qy)+'|~ @)>=o ]@#*-')

    print(o(qq) + o(qw) + o(qe) + '\n' +
          o(qt) + o(qy) + o(qu) + '\n' +
          o(qi) + o(qo) + o(qp)
          )

    # draws cool animation of arrow
    arrow()