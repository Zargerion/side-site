# S

class User:
    var = 0
    def __init__(self, cls, name, password):
        cls.var += 1
        self.id = cls.var
        self.name = name
        self.password = password

oleg = User(User, name = "oleg", password = "password1")
andrew = User(User, name = "andrew", password = "password2")

class UserPrinter:
    @staticmethod
    def printIt(*users):
        for user in users:
            print(user.id, user.name, user.password) 

UserPrinter.printIt(oleg, andrew)
print("++++++++++++++++++++++++++++++++++++++++++++++")

# O

from abc import abstractmethod

class Attacks():
    @abstractmethod
    def attack():
        """Some attack"""
        pass
    

class Weapon(Attacks):
    def __init__(self, damage, range):
        self.damage = damage
        self.range = range

class Sword(Weapon):
    def __init__(self, name, damage, range):
        super().__init__(damage, range)
        self.name = name

    def attack(self):
        print("You did sword damage:", self.damage)

class Bow(Weapon):
    def __init__(self, name, damage, range):
        super().__init__(damage, range)
        self.name = name

    def attack(self):
        print("You did bow damage:", self.damage)

class Character:
    def __init__(self, name, weapon):
        self.name = name
        self.weapon = weapon

    def attack(self):
        self.weapon.attack()

    def changeWeapon(self, weapon):
        self.weapon = weapon

    def hi(self):
        print("My name is", self.name, "and I have", 
              self.weapon.name, "with damage",  
              self.weapon.damage, "and", self.weapon.range, 
              "range.")

greatSword = Sword("Great Sword", 50, 2)
yourCharacter = Character("You", greatSword)
yourCharacter.hi()
yourCharacter.attack()
longBow = Bow("Long Bow", 20, 7)
yourCharacter.changeWeapon(longBow)
yourCharacter.hi()
yourCharacter.attack()
print("++++++++++++++++++++++++++++++++++++++++++++++")

# L

class Animals:
    @abstractmethod
    def speak():
        """Some speak"""
        pass

class Dog(Animals):
    @abstractmethod
    def speak():
       print("Wof!")

class Cat(Animals):
    @abstractmethod
    def speak():
        print("Meow!")

print(Dog.speak())
print(Cat.speak())
print("++++++++++++++++++++++++++++++++++++++++++++++")

# I

class Attack:
    @abstractmethod
    def attack():
        pass

class Reload:
    @abstractmethod
    def reload():
        pass

class BigGun(Attack, Reload):
    def reload():
        print("Reload!")
    
    def attack():
        print("Attack!")

class Katana(Attack):
    def attack():
        print("Attack!")

biggun = BigGun
biggun.attack()
biggun.reload()

katana = Katana
katana.attack()
print("++++++++++++++++++++++++++++++++++++++++++++++")

# D

class APIMusic:
    @abstractmethod
    def getTracks():
        pass

class ClientMusic(APIMusic):
    def __init__(self, client):
        self.client = client
    
    def getTracks(self):
        self.client.getTracks()
    
    def changeClient(self, new_client):
        self.client = new_client
    

class YandexMusic(APIMusic):
    def getTracks():
        print("Got YandexAPI.")

class SpotifyMusic(APIMusic):
    def getTracks():
        print("Got SpotifyAPI.")

class YouTubeMusic(APIMusic):
    def getTracks():
        print("Got YouTubeAPI.")

api = ClientMusic(YandexMusic) 
api.getTracks()
api.changeClient(SpotifyMusic)
api.getTracks()
api.changeClient(YouTubeMusic)
api.getTracks()

