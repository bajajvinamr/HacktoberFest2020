#importing libraries
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns
#reading dataset
df = pd.read_csv (r'data.csv')
#deleting columns which have any Nan values
df = df.dropna(axis = 1)
#Encoding 'diagnosis' column as label
from sklearn.preprocessing import LabelEncoder
labelencoder_Y = LabelEncoder()
df.iloc[:,1] = labelencoder_Y.fit_transform(df.iloc[:,1].values)
#Spliting values into dependent(All columns except 'diagnosis') and independent data
X = df.iloc[: , 2:31].values
Y = df.iloc[: , 1].values
#Split the data into 75% training data and 25% testing data
from sklearn.model_selection import train_test_split
X_train , X_test , Y_train , Y_test = train_test_split(X,Y, test_size = 0.25 , random_state = 0)
#Scaling the data into a common range(Feature Scaling)
from sklearn.preprocessing import StandardScaler
sc = StandardScaler()
X_train = sc.fit_transform(X_train)
X_test = sc.fit_transform(X_test)
#Create a function for the models
def models(X_train,Y_train):

  #Logistic Regression
  from sklearn.linear_model import LogisticRegression
  log = LogisticRegression(random_state = 0)
  log.fit(X_train,Y_train)

  #Decision Tree
  from sklearn.tree import DecisionTreeClassifier
  tree = DecisionTreeClassifier(criterion = 'entropy' , random_state = 0)
  tree.fit(X_train, Y_train)

  #Random Forest Classifier
  from sklearn.ensemble import RandomForestClassifier
  forest = RandomForestClassifier(n_estimators = 10, criterion = 'entropy' , random_state = 0)
  forest.fit(X_train,Y_train)

  #Print the models accuracy on the training data
  print('[0] Logistic Regression Training Accuracy:', log.score(X_train,Y_train))
  print('[1] Decision Tree Classifier Training Accuracy:', tree.score(X_train,Y_train))
  print('[2] Random Forest Classifier Training Accuracy:', forest.score(X_train,Y_train))

  return log,tree,forest
model = models(X_train,Y_train)
#Creating .pkl files for 3 models
import joblib
joblib.dump(model[0], "model_LG.pkl")
