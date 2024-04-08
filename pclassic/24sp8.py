def check(board, r, c, rowDict, colDict):
    val = board[r][c]
    col = True
    row = True

    for i in range(len(board[0])):
        if not ((r in rowDict.keys() and rowDict[r] == True) or board[r][i] in [val, 'w']):
            row = False
            continue
    
    for i in range(len(board)):
        if not ((c in colDict.keys() and colDict[c] == True) or board[i][c] in [val, 'w']):
            col = False
            continue

    rowDict[r] = row
    colDict[c] = col
    return row, col

def change(board, r, c, elimRow=True):
    val = board[r][c]
    if elimRow:
        board[r] = ['w'] * len(board[0])
        return [0, r + 1, val]
    else:
        for i in range(len(board)):
            board[i][c] = 'w'
        return [1, c + 1, val]

def modifyGrid(positions,grid, myStack, rowDict, colDict):
    for r, c in positions:
        if grid[r][c] in [1, 2]:
            validRow, validCol = check(grid, r, c, rowDict, colDict)
            if validRow:
                myStack.append(change(grid, r, c))
            if validCol:
                myStack.append(change(grid, r, c, elimRow=False))
    return grid

def findRealColor(grid):
    found = False
    for r in range(len(grid)):
        for c in range(len(grid[0])):
            if grid[r][c] in [1, 2]:
                return True
            
def findPositions(grid):
    positions = []
    for r in range(len(grid)):
        for c in range(len(grid[0])):
            if grid[r][c] in [1, 2]:
                positions.append((r, c))
    return positions


def printGrid(grid):
    for r in reversed(grid):
        print(" ".join(str(e) for e in r))



t = int(input())
for t in range(t):
    n = int(input())
    grid = []
    myStack = []
    rowDict = {}
    colDict = {}


    for i in range(n):
        grid.append(list(map(int, input().split())))

    positions = findPositions(grid)

    grid = modifyGrid(positions, grid, myStack, rowDict, colDict)
    
    if findRealColor(grid):
        print(-1)
    else:
        print(len(myStack))
        printGrid(myStack)

    
    
                

    