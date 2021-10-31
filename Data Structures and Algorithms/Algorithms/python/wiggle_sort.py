"""
This is the Leetcode problem 324 - Wiggle sort II

Sort the array in a fashion that [0, 3, 1, 4, 2, 3] or indexes: 0 > 1 < 2 > 3 < 4
"""


def wiggle_sort(nums):
    """
    Sort the array in a stupid way
    """
    # Check for empty arr
    if len(nums) in [0, 1]:
        return
    # Duplicate the arr to save th beginning state
    arr = []  
    for el in nums:
        arr.append(el)
    # Our index starts at the middle
    j = (len(arr) - 1) // 2
    # sort the arr
    arr = sorted(arr)
    # If sorted arr middle els are the same we go from bigger to smaller
    if arr[j] == arr[j + 1]:
        for i in range(0, len(arr), 2):
            nums[i] = arr[j]
            j -= 1
    # Else from smaller to bigger
    else:
        j = 0
        for i in range(0, len(arr), 2):
            nums[i] = arr[j]
            j += 1
    # Just the elements from index 1 to end with the step 2
    j = 0
    for i in range(1, len(arr), 2):
        nums[i] = arr[::-1][j]
        j += 1


if __name__ == "__main__":
    test = [1, 2, 3, 4, 5]

    print(wiggle_sort(test))
    print(test)