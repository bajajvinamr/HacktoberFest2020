import math
import random
import csv


def loadcsv(filename):
    lines = csv.reader(open(filename,'r'))
    dataset = list(lines)
    for i in range(len(dataset)):
        dataset[i] = [float(x) for x in dataset[i]]
    return dataset


def splitDataset(dataset, ratio):
    trainSize = int(len(dataset) * ratio)
    trainset = []
    copy = list(dataset)
    while len(trainset) < trainSize:
        index = random.randrange(len(copy))
        trainset.append(copy.pop(index))
    return [trainset, copy]


def seperateByClass(dataset):
    seperated = {}
    for i in range(len(dataset)):
        vector = dataset[i]
        if vector[-1] not in seperated:
            seperated[vector[-1]] = []
        seperated[vector[-1]].append(vector)
    return seperated


def mean(numbers):
    return sum(numbers) / float(len(numbers))


def stdev(numbers):
    avg = mean(numbers)
    variance = sum(pow(x - avg, 2) for x in numbers)/float(len(numbers) - 1)
    return math.sqrt(variance)


def summarize(dataset):
    summaries = [(mean(attribute), stdev(attribute))
                 for attribute in zip(* dataset)]
    del summaries[-1]
    return summaries


def summarizeByClass(dataset):
    seperated = seperateByClass(dataset)
    summaries = {}
    for classvlaue, instance in seperated.items():
        summaries[classvlaue] = summarize(instance)
    return summaries


def calculateProbablity(x, mean, stdev):
    exponent = math.exp(-(math.pow(x-mean, 2)/(2*math.pow(stdev, 2))))
    return (1/(math.sqrt(2*math.pi)*stdev))*exponent


def calculateClassProbablity(summaries, inputvector):
    probablites = {}
    for classvalue, classSummaries in summaries.items():
        probablites[classvalue] = 1
        for i in range(len(classSummaries)):
            mean, stdev = classSummaries[i]
            x = inputvector[i]
            probablites[classvalue] *= calculateProbablity(x, mean, stdev)
        return probablites


def predict(summaries, inputVector):
    probablites = calculateClassProbablity(summaries, inputVector)
    bestLabel, bestProb = None, -1
    for classValue, probablity in probablites.items():
        if bestLabel is None and probablity > bestProb:
            bestProb = probablity
            bestLabel = classValue
    return bestLabel


def getPredection(summaries, testSet):
    predections = []
    for i in range(len(testSet)):
        result = predict(summaries, testSet[i])
        predections.append(result)
    return predections


def getAccuracy(testdata, predections):
    correct = 0
    for i in range(len(testdata)):
        if testdata[i][-1] == predections[i]:
            correct += 1
    return round((correct/float(len(testdata))) * 100, 2)


def main():
    splitratio = 0.7
    filename = 'pima-india-diabities-data.csv'
    dataset = loadcsv(filename)
    trainingset, testingset = splitDataset(dataset, splitratio)
    print(' Split{0} rows into train = {1} rows and test = {2} rows'.format(
        len(dataset), len(trainingset), len(testingset)))
    summaries = summarizeByClass(trainingset)
    predections = getPredection(summaries,  testingset)
    accuracy = getAccuracy(testingset, predections)
    print(' Accuracy: {0}%'.format(accuracy))


if __name__ == "__main__":
    main()
    exit(0)
