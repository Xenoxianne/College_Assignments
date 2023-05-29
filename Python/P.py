def permutation(R):
    ebit_table = [
        16, 7, 20, 21,
        29, 12, 28, 17,
        1, 15, 23, 26,
        5, 18, 31, 10,
        2, 8, 24, 14,
        32, 27, 3, 9,
        19, 13, 30, 6,
        22, 11, 4, 25
    ]

    ebit = []
    for index in ebit_table:
        ebit.append(R[index - 1])

    return ebit


# Example usage
R = input('Enter: ')

ebit = permutation(R)

blocks = [ebit[i:i+4] for i in range(0, len(ebit), 4)]
for i, block in enumerate(blocks):
    print(f"{''.join(block)} ",end=" ")