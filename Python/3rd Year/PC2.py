def permute_pc2(c_block, d_block):
    pc2_table = [
        14, 17, 11, 24, 1, 5,
        3, 28, 15, 6, 21, 10,
        23, 19, 12, 4, 26, 8,
        16, 7, 27, 20, 13, 2,
        41, 52, 31, 37, 47, 55,
        30, 40, 51, 45, 33, 48,
        44, 49, 39, 56, 34, 53,
        46, 42, 50, 36, 29, 32
    ]

    combined = c_block + d_block
    subkeys = []
    for index in pc2_table:
        subkeys.append(combined[index - 1])

    return subkeys


# Example usage
c_block = input('Enter C: ')
d_block = input('Enter D: ')

subkeys = permute_pc2(c_block, d_block)

blocks = [subkeys[i:i+6] for i in range(0, len(subkeys), 6)]
for i, block in enumerate(blocks):
    print(f"Block {i+1}: {''.join(block)}")