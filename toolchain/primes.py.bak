PRIMES_TO_FIND = 100
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

        num_digits = 0
        number_shifter = number_to_check
        while number_shifter > 0:
            number_shifter //= 10
            num_digits = num_digits + 1
        number_shifter = number_to_check
        output_buffer = [' '] * 80
        while number_shifter > 0:
            digit = number_shifter % 10
            output_buffer[num_digits - 1] = digit + 48
            num_digits = num_digits - 1
            number_shifter //= 10
        for ch in output_buffer:
            if ch != ' ':
                print(chr(ch), end = '')
        print()
        primes_found = primes_found + 1
    number_to_check = number_to_check + 1
