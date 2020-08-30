PRIMES_TO_FIND = 4
primes_found = 0
number_to_check = 2

divisor = 2
remainder = 0

prime = 0


while primes_found < PRIMES_TO_FIND:


    divisor = 2
    prime = 1
    while divisor < number_to_check:

        remainder = number_to_check

        while remainder >= divisor:
            remainder = remainder - divisor



        if remainder == 0:
            divisor = number_to_check
            prime = 0


        if remainder > 0:
            divisor = divisor + 1




    if prime == 1:



        print(number_to_check)
        primes_found = primes_found + 1


    number_to_check = number_to_check + 1
