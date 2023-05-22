def permute_pc1(input_bits):
    pc1_table = [
        57, 49, 41, 33, 25, 17, 9,
        1, 58, 50, 42, 34, 26, 18,
        10, 2, 59, 51, 43, 35, 27,
        19, 11, 3, 60, 52, 44, 36,
        63, 55, 47, 39, 31, 23, 15,
        7, 62, 54, 46, 38, 30, 22,
        14, 6, 61, 53, 45, 37, 29,
        21, 13, 5, 28, 20, 12, 4
    ]

    output_bits = []
    for index in pc1_table:
        output_bits.append(input_bits[index - 1])

    return output_bits


# Example usage
input_bits = input('Enter your bits: ')
output_bits = permute_pc1(input_bits)
output_bits = ''.join(output_bits)

print("Input (64-bit):", input_bits)
print("Output (56-bit):", output_bits)