def main():
    jar = Jar()
    print("Capacity:", str(jar.capacity))
    jar.deposit(10)
    print(str(jar))
    jar.withdraw(4)
    print(str(jar))

class Jar:
    def __init__(self, capacity=12):
        if capacity < 0:
            raise ValueError("Invalid capacity")
        self._capacity = capacity
        self._n = 0

    def __str__(self):
        return "🍪" * self._n

    def deposit(self, n):
        if self._n + n > self._capacity:
            raise ValueError("Exceeds capacity")
        self._n += n

    def withdraw(self, n):
        if n > self._n:
            raise ValueError("Not enough cookies left")
        self._n -= n

    @property
    def capacity(self):
        return self._capacity

    @property
    def size(self):
        return self._n

main()