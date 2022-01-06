#!/usr/bin/python3

'''
Minimum Operations.
'''

def minOperations(n):
    '''Minimum Operations'''

    operations = 0
    string = 'H'
    copy = ''
    aux = False

    if type(n) == int and n > 0:
        for i in range(n):
            if len(string) != n:
                if aux is False:
                    copy = string
                    aux = True
                else:
                    string += copy
                    if n % len(string) == 0:
                        aux = False
                operations += 1
            else:
                break

    return operations
