#!/usr/bin/python3
'''
Determines if all boxes can be unlock
'''


def canUnlockAll(boxes):
    '''
Determines if all boxes can be unlock
'''
    new_list = [0]

    for index in new_list:
        for num in boxes[index]:
            if num not in new_list and num < len(boxes):
                new_list.append(num)

    return len(new_list) == len(boxes)
