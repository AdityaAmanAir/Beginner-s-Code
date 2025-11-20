# 1. Encapsulation
# Bundling data and methods, controlling access.
class Account:
    def __init__(self):
        self.__balance = 0
    
    def deposit(self, amount):
        if amount > 0:
            self.__balance += amount
    
    def get_balance(self):
        return self.__balance

# 2. Inheritance
# Creating new classes from existing ones.    
class Animal:
    def speak(self):
        pass

class Dog(Animal):
    def speak(self):
        return "Woof"    
    
# 3. Polymorphism
# Same interface, different implementations.
def make_sound(animal):
    return animal.speak()

dog = Dog()
print(make_sound(dog))  # "Woof"  

# 4. Abstraction
# Hiding complex reality, showing only essentials.
from abc import ABC, abstractmethod

class Shape(ABC):
    @abstractmethod
    def area(self):
        pass

class Circle(Shape):
    def __init__(self, radius):
        self.radius = radius
    
    def area(self):
        return 3.14 * self.radius ** 2