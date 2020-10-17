
import pandas as pd
import numpy as np
from sklearn.model_selection import train_test_split
df1=pd.read_csv('stopwords')
b=[]
def func(df1):
    for i in df1['words']:
        b.append(i)
func(df1)       
import string
df = pd.read_csv('emails.csv')
def func(a):
    t=a.split(':')[1]
    t.lstrip()
    a=t
    return a
df['message']=df['text'].apply(func)
df.drop('text',axis=1,inplace=True)

def text_process(mess):
    """
    Takes in a string of text, then performs the following:
    1. Remove all punctuation
    2. Remove all stopwords
    3. Returns a list of the cleaned text
    """
    # Check characters to see if they are in punctuation
    nopunc = [char for char in mess if char not in string.punctuation]

    # Join the characters again to form the string.
    nopunc = ''.join(nopunc)

    # Now just remove any stopwords
    return [word for word in nopunc.split() if word.lower() not in b]
#messages['message'].head(5).apply(text_process)
from sklearn.feature_extraction.text import CountVectorizer
from sklearn.feature_extraction.text import TfidfTransformer
from sklearn.naive_bayes import MultinomialNB

from sklearn.pipeline import Pipeline
from sklearn.svm import SVC
param_grid = {'C': [0.1,1, 10, 100, 1000], 'gamma': [1,0.1,0.01,0.001,0.0001], 'kernel': ['rbf']}
from sklearn.model_selection import GridSearchCV


pipeline = Pipeline([
    ('bow', CountVectorizer(analyzer=text_process)),  # strings to token integer counts
    ('tfidf', TfidfTransformer()),  # integer counts to weighted TF-IDF scores
    ('classifier', MultinomialNB()),  # train on TF-IDF vectors w/ Naive Bayes classifier
])
model = Pipeline([
    ('bow', CountVectorizer(analyzer=text_process)),  
    ('tfidf', TfidfTransformer()),
    ('classifier',GridSearchCV(SVC(),param_grid,refit=True,verbose=3)),
])


msg_train,msg_test,label_train,label_test=train_test_split(df['message'],
                                                           df['spam'],
                                                          test_size=0.3)
pipeline.fit(msg_train,label_train)
model.fit(msg_train,label_train)
predictions = pipeline.predict(msg_test)
import pickle
pickle.dump(pipeline,open('model.pkl','wb'))
pickle.dump(model,open('model1.pkl','wb'))
