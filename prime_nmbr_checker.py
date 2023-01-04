def isprime(number:int ) -> bool: # takes an integer and returns a boolean
    even = not number % 2 # assigns True if number is even, False otherwise
    if number == 2: # 2 is an even but is prime
        return True # so we check it explicitly
    elif even or number == 1: # if the number is even or 1
        return False          # prime numbers cannot be even so need to checking further
    
    # loop from 3 to the half of the number taking a step of 2 each time
    for i in range(3, number//2, 2):
        # if a factor is found, that'll mean it's not a prime
        if not number % i:
            return False
    # return True if the loop didn't break
    else:
        return True

print(isprime(9))
