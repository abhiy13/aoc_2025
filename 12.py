def solve(input: list[str]):
    shapes = []
    grids = []

    i = 0
    while i < len(input):
        if input[i].count("x"):
            grids.append(input[i])
        elif input[i].count(":"):
            grid = input[i + 1: i + 4]
            shapes.append(grid)
            i += 3
        i += 1

    counts = []
    for shape in shapes:
        counts.append(sum([x.count("#") for x in shape]))

    res = 0

    for grid in grids:
        [rect, nums] = grid.split(":")
        area = int(rect.split("x")[0]) * int(rect.split("x")[1])
        for idx, value in enumerate(nums.strip().split(" ")):
            area -= int(value) * counts[idx]
        if area >= 0:
            res += 1
    print(res)


def read_input() -> list[str]:
    input = []
    try:
        with open("sin", "r") as file:
            input = [x.strip("\n") for x in file.readlines()]
    except FileNotFoundError:
        print("Error: The file 'input_file.txt' was not found.")

    return input


def main():
    solve(read_input())


if __name__ == "__main__":
    main()
