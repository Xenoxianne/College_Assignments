def permutation(R):
    ebit_table = [
        32, 1, 2, 3, 4, 5,
        4, 5, 6, 7, 8, 9,
        8, 9, 10, 11, 12, 13,
        12, 13, 14, 15, 16, 17,
        16, 17, 18, 19, 20, 21, 
        20, 21, 22, 23, 24, 25,
        24, 25, 26, 27, 28, 29,
        28, 29, 30, 31, 32, 1
    ]

    ebit = []
    for index in ebit_table:
        ebit.append(R[index - 1])

    return ebit


# Example usage
R = input('Enter R: ')

ebit = permutation(R)

blocks = [ebit[i:i+6] for i in range(0, len(ebit), 6)]
for i, block in enumerate(blocks):
    print(f"{''.join(block)} ",end=" ")
