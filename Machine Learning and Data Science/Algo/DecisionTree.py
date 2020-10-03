"""
Decisio tree is build using CART Algorithm
"""

training_data = [
    ['Green', 3, 'Mango'],
    ['Yellow', 3, 'Mango'],
    ['Red', 1, 'Grape'],
    ['Red', 1, 'Grape'],
    ['Yellow', 3, 'Lemon']
]

header = ['color', 'daimeter', 'label']


def unique_value(rows, col):
    # Returns unique value in a column from a dataset
    return set([row[col] for row in rows])


def class_count(rows):
    """
    This function is used to count the label in the datasets
    """
    Count = {}
    for row in rows:
        label = row[-1]
        if label in Count:
            Count[label] += 1
        else:
            Count[label] = 1
    return Count


def isnumeric(value):
    return isinstance(value, int) or isinstance(value, float)


class Question:
    """ A Question is used to partiton a dataset. """

    def __init__(self, column, value):
        self.column = column
        self.value = value

    def match(self, example):
        # Compare the feature in an example  to the feature value in this Question
        val = example[self.column]
        if isnumeric(val):
            return val >= self.value
        else:
            return val == self.value

    def __repr__(self):
        # this is just a helper method to print
        # the question in a readable format
        conditon = "=="
        if isnumeric(self.value):
            conditon = ">="
        return "Is %s %s %s " % (
            header[self.column], conditon, str(self.value)
        )


def partiton(rows, question):
    # Partions a dataset

    true_rows, false_rows = [], []
    for row in rows:
        if question.match(row):
            true_rows.append(row)
        else:
            false_rows.append(row)
    return true_rows, false_rows


def gini(rows):
    # calculate the gini impurity for a list of rows
    counts = class_count(rows)
    impurity = 1
    for value in counts:
        prob_of_value = counts[value] / float(len(rows))
        impurity -= prob_of_value ** 2
    return impurity


def info_gain(left, right, current_uncertanity):
    # The uncertanity of the starting node minus the weighted impurity of the two child nodes.
    p = float(len(left)) / (len(left) + len(right))
    return current_uncertanity - p * gini(left) - (1 - p) * gini(right)


def find_best_split(rows):
    best_gain = 0
    best_question = None
    current_uncertanity = gini(rows)
    n_features = len(rows[0]) - 1  # Last Column is for label
    for col in range(n_features):
        values = unique_value(rows, col)
        for val in values:
            question = Question(col, val)
            true_rows, false_rows = partiton(rows, question)
            if len(true_rows) == 0 or len(false_rows) == 0:
                continue
            gain = info_gain(true_rows, false_rows, current_uncertanity)
            if gain >= best_gain:
                best_gain, best_question = gain, question
    return best_gain, best_question


class Leaf:
    """
    This hold a  dictionary of class (e.g., "Mango") -> number
    of times it appears in the row from the training data that reach this leaf.
    """

    def __init__(self, rows):
        self.predection = class_count(rows)


class Decision_Node:
    """
     A Decision node asks a question.
     This hold a refrence to the question, and to the two child nodes.
    """

    def __init__(self, question, true_branch, false_branch):
        self.question = question
        self.true_branch = true_branch
        self.false_branch = false_branch


def build_tree(rows):
    """ Build the Tree """

    # try partitioning the dataset on each of the unique attribute,
    # Calculate the information gain,
    # and return the qustion that produces the highest gain.
    gain, Question = find_best_split(rows)
    #  Base Case : no furher info gain
    # since we can ask no furthe question we return a leaf
    if gain == 0:
        return Leaf(rows)
    # if we reach here then there is a useful feature/ value to partion to

    true_rows, false_rows = partiton(rows, Question)

    # recursevly build the true branch
    true_brach = build_tree(true_rows)

    # recursevly build a false branch
    false_brach = build_tree(false_rows)

    return Decision_Node(Question, true_brach, false_brach)


def print_tree(node, spacing=''):
    """ World's most elegant tree printing function """
    # Base Case we have reached a leaf
    if isinstance(node, Leaf):
        print(spacing + "Predict", node.predection)
        return

    # print the question at this node
    print(spacing + str(node.question))

    # call this function Reccursively on the true branch
    print(spacing + '--> True:')
    print_tree(node.true_branch, spacing + " ")

    # Call this function recursevly in the false brach
    print(spacing + "--> False:")
    print_tree(node.false_branch, spacing + " ")


def classify(row, node):
    # Base Case we've reached a leaf
    if isinstance(node, Leaf):
        return node.predection

    # Decide wether to follow the  true-brach or the false-brach
    # Compare the feature /  value stored in the node,
    # to the example we are considering
    if node.question.match(row):
        return classify(row, node.true_branch)
    else:
        return classify(row, node.false_branch)


def print_leaf(counts):
    total = sum(counts.values())*1.0
    probs = {}
    for lbl in counts.keys():
        probs[lbl] = str(int(counts[lbl]) / total * 100) + "%"
    return probs


if __name__ == "__main__":
    my_tree = build_tree(training_data)
    print_tree(my_tree)

    # Testing Data
    testing_data = [
        ['Green', 3, 'Mango'],
        ['Yellow', 4, 'Mango'],
        ['Red', 2, 'Grape'],
        ['Red', 1, 'Grape'],
        ['Yellow', 3, 'Lemon'],
    ]
    for row in testing_data:
        print(
            "Actual: %s , Predicted %s" %
            (row[-1], print_leaf(classify(row, my_tree)))
        )
