import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from sklearn import preprocessing
from sklearn.model_selection import train_test_split
from sklearn import linear_model
 
df=pd.read_csv('data.csv',header=None)
df.columns=['Score_1','Score_2','Admission'] 

print(df.head())
print(df.describe())

y=np.array(df['Admission'])
X=np.array(df.drop(['Admission'],1))

Sscaler=preprocessing.StandardScaler()
Xs=Sscaler.fit_transform(X)

LogisticR=linear_model.LogisticRegression()
LogisticR.fit(Xs,y)

print('Accuracy of Linear Regression Model is ',round(LogisticR.score(Xs,y)*100,2))

def prediction_response(Prediction):
    if Prediction==1:
        print('Yes,person will get admission in university')
    else:
        print('No ,person will not get admission in university')

a=float(input("enter marks for subject 1"))
b=float(input("enter marks for subject 2"))

Prediction=LogisticR.predict(Sscaler.transform(np.reshape([a,b],(1,-1))))[0]
print(prediction_response(Prediction))
