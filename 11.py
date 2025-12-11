EMPTY_KEY = "EMPTY_KEY"


def solve_part1(input: list[str]):
    mapping = {}
    G = [[] for _ in range(10000)]

    mapping["you"] = 0
    mapping["out"] = 1
    idx = 2

    def get(x: str):
        nonlocal idx
        if mapping.get(x, EMPTY_KEY) == EMPTY_KEY:
            mapping[x] = idx
            idx += 1
        return mapping[x]

    for line in input:
        spl = line.split(":")
        x = get(spl[0].strip())
        for y in line[1:].split(" "):
            G[x].append(get(y.strip()))

    memo = [-1 for _ in range(idx + 1)]

    def dfs(x: int):
        nonlocal G
        if x == 1:
            return 1
        if memo[x] != -1:
            return memo[x]

        fx = 0
        for y in G[x]:
            fx += dfs(y)
        memo[x] = fx
        return fx

    print(dfs(0))


# part 2
def solve(input: list[str]):
    mapping = {}
    G = [[] for _ in range(10000)]

    mapping["svr"] = 0
    mapping["out"] = 1
    mapping["dac"] = 2
    mapping["fft"] = 3
    idx = 4

    def get(x: str):
        nonlocal idx
        if mapping.get(x, EMPTY_KEY) == EMPTY_KEY:
            mapping[x] = idx
            idx += 1
        return mapping[x]

    for line in input:
        spl = line.split(":")
        x = get(spl[0].strip())
        for y in spl[1][1:].split(" "):
            G[x].append(get(y.strip()))

    memo = [[[-1, -1], [-1, -1]] for _ in range(idx + 1)]

    print(mapping)

    def dfs(x: int, dac: int, fft: int):
        nonlocal G
        if x == 1 and dac == 1 and fft == 1:
            return 1
        if x == 1:
            return 0
        if memo[x][dac][fft] != -1:
            return memo[x][dac][fft]

        fx = 0
        for y in G[x]:
            ndac = min(1, dac + int(y == 2))
            nfft = min(1, fft + int(y == 3))
            fx += dfs(y, ndac, nfft)
        memo[x][dac][fft] = fx
        return fx

    print(dfs(0, 0, 0))


def read_input() -> list[str]:
    input = []
    try:
        with open("sin", "r") as file:
            input = file.readlines()
    except FileNotFoundError:
        print("Error: The file 'input_file.txt' was not found.")

    return input


def main():
    solve(read_input())


if __name__ == "__main__":
    main()
