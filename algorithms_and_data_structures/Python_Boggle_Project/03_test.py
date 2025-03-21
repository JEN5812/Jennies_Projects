from time import time

# loading the board from a file
def loadBoard(filename):
    # empty variable 
    board = []
    # opening file + reading
    with open(filename, 'r') as file:
        # removing spaces and splitting 
        for line in file:
            clear = line.strip()
            if clear:
                row = clear.split()
                board.append(row)
    return board 

# printing the board
def printBoard(board_object):
    # each row 
    for row in board_object:
        print(' '.join(row))
    print()

# taking all possible moves from the position
def possibleMoves(xy_pair, board_object):
    # using moves and initializing the pair
    moves = set()
    x, y = xy_pair
    # making sure length is correct
    row = len(board_object)
    col = len(board_object[0])
    # directions for board
    directions = [(-1,-1), (-1,0), (-1,1), (0,-1), (0,1), (1,-1), (1,0), (1,1)]
    # looping through the directions
    for dir_x, dir_y in directions:
        new_x = x + dir_x
        new_y = y + dir_y
        # updating coord for new moves
        if 0 <= new_x < row and 0 <= new_y < col:
            moves.add((new_x, new_y))
    return moves

# makes sure moves are possible and legal
def legalMoves(moves, path):
    return moves - set(path)

# reads the dict file and store words in a set
def readDictionary(filename):
    dic = set()
    prefixes = set()
    # opening file 
    with open(filename, 'r') as file:
        # strip and uppercase the letter
        for line in file:
            word = line.strip().upper()
            dic.add(word)
            for fix in range(1, len(word)):
                prefixes.add(word[:fix])
    return dic, prefixes

# examine current state and checks if it is a word
def examineState(myBoard, position, path, myDict):
    path.add(position)
    word = ''.join(myBoard[x][y] for x, y in path)
    if word in myDict:
        word_exists = 'Yes'
    else:
        word_exists = 'No'

    return(word, word_exists)

# checking if it is a prefix
def isPrefix(word, prefixes):
    return word in prefixes

# Using DFS to search doing it recursively 
def depth_search(x, y, path, word, myBoard, myDict, prefixes, found_words, total_moves):
    path.add((x, y))
    # if word is in dic it will add
    if word in myDict:
        found_words.add(word)
    # ensures we are at the right state
    examineState(myBoard, (x,y), path, myDict)

    # prune if prefix is not valid
    if not isPrefix(word, prefixes):
        # backtracking
        path.remove((x,y))
        return total_moves

    # getting all legal moves from position
    moves = legalMoves(possibleMoves((x, y), myBoard), path)

    # using recursion to ensure moves
    for (new_x, new_y) in moves:
        total_moves += 1
        total_moves = depth_search(new_x, new_y, path, word + myBoard[new_x][new_y], myBoard, myDict, prefixes, found_words, total_moves)

    path.remove((x,y))
    return total_moves

# running the board and searching for words
def runBoard(board_filename, dictionary_filename):
    # loading in board and dict 
    myBoard = loadBoard(board_filename)
    myDict, prefixes = readDictionary(dictionary_filename)
    # starting timer
    start_time = time()
    printBoard(myBoard)
    found_words = set()
    print("\nAnd we're off!")
    print("Running with cleverness ON")
    # search starts from each position
    total_moves = 0
    for row in range(len(myBoard)):
        # incrementing count
        total_moves += 1
        for col in range(len(myBoard[row])):
            total_moves += 1
            total_moves = depth_search(row, col, set(), myBoard[row][col], myBoard, myDict, prefixes, found_words, total_moves)

    end_time = time()
    elapsed_time = end_time - start_time

    print(f"All done\n\nSearched total of {total_moves} moves in {elapsed_time:.3f} seconds")
    
    # finding length of word
    words_found = {
        2: [], 
        3: [], 
        4: [], 
        5: []
    }

    for word in found_words:
        if 2<=len(word)<=5:
            words_found[len(word)].append(word)
    total_words = sum(len(v) for v in words_found.values())
    
    # sorting words by found length 
    print(f"\nWords found:\n2 -letter words: {', '.join(words_found[2])}")
    print(f"3 -letter words: {', '.join(words_found[3])}")
    print(f"4 -letter words: {', '.join(words_found[4])}")
    print(f"5 -letter words: {', '.join(words_found[5])}")
    
    # printing total words first then sorting
    print(f"\nFound {total_words} words in total.")
    all_words = sorted([word for word_list in words_found.values() for word in word_list])
    print(f"Alpha-sorted list words:\n{', '.join(all_words)}")

# given code 
runBoard("board_file_2.txt", "twl06.txt")
runBoard("board_file_3.txt", "twl06.txt")
runBoard("board_file_4.txt", "twl06.txt")
runBoard("board_file_5.txt", "twl06.txt")



