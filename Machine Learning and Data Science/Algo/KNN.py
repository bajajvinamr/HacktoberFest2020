import math


def EDistance(Instace1, Instance2, length):
    Distance = 0
    for i in range(length):
        Distance += pow((Instace1[i] - Instance2[i]), 2)
    return math.sqrt(Distance)


def getNeighbour(trainingfeature, trainingLabel, testInstance, k):
    if k > len(trainingfeature):
        k = len(trainingfeature)
    distance = []
    length = len(testInstance)
    for i in range(len(trainingfeature)):
        Dist = EDistance(trainingfeature[i], testInstance, length)
        distance.append([Dist, trainingLabel[i]])
    distance.sort(key=lambda x: x[0])
    Neighbour = []
    for i in range(k):
        Neighbour.append(distance[i][1])
    return Neighbour


def getResponse(Neighbour):
    ClassVotes = {}
    MaxVote = 0
    for vote in Neighbour:
        if vote in ClassVotes:
            ClassVotes[vote] += 1
        else:
            ClassVotes[vote] = 1
        if ClassVotes[vote] > MaxVote:
            MaxVote = ClassVotes[vote]
    for Class, vote in ClassVotes.items():
        if vote == MaxVote:
            return Class


def getAccuracy(TestingData, Predection):
    correct = 0
    for i in range(len(TestingData)):
        if TestingData[i] == Predection[i]:
            correct += 1
    return (correct / float(len(TestingData))) * 100


def main():
    from sklearn import datasets
    from sklearn.model_selection import train_test_split
    Iris = datasets.load_iris()
    feature = Iris['data']
    Label = Iris['target']
    X_train, X_test, y_train, y_test = train_test_split(
        feature,
        Label,
        test_size=0.33,
    )
    Predections = []
    k = 5
    for i in range(len(X_test)):
        Neighbour = getNeighbour(X_train, y_train, X_test[i], k)
        result = getResponse(Neighbour)
        Predections.append(result)
        print('> Predicted : ' + repr(result) +
              ' > Actual :' + repr(y_test[i]))
    accuracy = getAccuracy(y_test, Predections)
    print(" Accuracy : ", accuracy)


if __name__ == "__main__":
    main()
    exit(0)
