class Tree():
    def _init_(self, letter=None):
        self.letter = letter
        self.children = {}
        self.leaf = False

# add a word, letter by letter
    def add(self, word):
        if len(word):
            letter = word[0]
            word = word[1:]a
            if letter not in self.children:
                self.children[letter] = Tree(letter)
            return self.children[letter].add(word)

        else:
            self.leaf = True
            return self
        return

# Locate a letter in the tree
    def search(self, letter):
        if letter not in self.children:
            return None
        return self.children[letter]

# Function for the actual word solver


def findWord(self, board, tree, validated, row, col, path=None, currLetter=None, word=None):
    letter = board[row][col]
    if path is None or currLetter is None or word is None:
        currLetter = tree.search(letter)
        path = [(row, col)]
        word = letter
    else:
        currLetter = currLetter.search(letter)
        path.append((row, col))
        word = word + letter

    # Base cases
    # denotes prefix does not exist in dictionary
    if currLetter is None:
        return
    # denotes a valid word
    if currLetter.leaf:
        validated.add(word)

    # recursive call
    for r in range(row-1, row+2):
        for c in range(col-1, col+2):
            if(r >= 0 and c >= 0 and c < 4 and r != row and c != col and (r, c) not in path):
                # [:] denotes the entire 'path' or 'word' from default start to end
                findWord(board, tree, validated, r, c,
                         path[:], currLetter, word[:])

    # set to store strings that match the valid words found in the dictionary
    validated = set()

    # call the findWord function from each grid
    for row in range(0, 4):
        for col in range(0, 4):
            findWord(board, tree, validated, row, col, None, None, None)

    # print out valid words
    for word in sorted(validated):
        if len(word) > 2:
            print(word)


def main():

    # initialize game board based on user input
    board = []
    for i in range(0, 4):
        board.append([])
        for j in range(0, 4):
            # strip() removes all the leading anf trailing characters and white spaces
            board[i].append(input().strip().upper())

    # print board
    for i in range(0, 4):
        for j in range(0, 4):
            # end is used so that all characters are printed together
            print(board[i][j], end=" ")
            print()

    # load dictionary
    dict = open('dictionary-yawl.text', "r")

    tree = Tree()
    for line in dict:
        # rstrip() only removes the trailing characters
        word = line.rstrip()
        tree.add(word)
