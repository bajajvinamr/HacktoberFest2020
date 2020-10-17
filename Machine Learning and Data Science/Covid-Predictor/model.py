#Importing libraries
import pandas as pd
import pickle
import datetime as dt
import numpy as np
from sklearn.linear_model import LinearRegression
from sklearn.model_selection import train_test_split

#Read CSV file
covid = pd.read_csv('covid.csv')
india_case = covid[covid["location"]=="India"]

#Changing Date-Time format
india_case['date'] = pd.to_datetime(india_case['date'])
india_case['date'] = india_case['date'].map(dt.datetime.toordinal)

#Dependent(X) and Not dependent(y)
X = np.array(india_case['date'])
y = np.array(india_case['total_cases'])

#Splitting the data into training and testing dataset
X_train,X_test,y_train,y_test = train_test_split(X,y,test_size = 0.3 , random_state = 9)


#Reshaping the model into (1) column and unknown(-1) rows
X_train = np.array(X_train).reshape(-1,1)
y_train = np.array(y_train).reshape(-1,1)

#Training the model
model = LinearRegression()
model.fit(X_train,y_train)
print(model.predict([[737491]]))

#Creating pickle file
pickle.dump(model,open('model.pkl','wb'))
