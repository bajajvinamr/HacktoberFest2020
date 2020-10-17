import numpy as np
from flask import Flask,request,jsonify,render_template
import pickle
import pandas as pd
import datetime as dt
from datetime import datetime
from datetime import datetime as dt

app = Flask(__name__)
model = pickle.load(open('model.pkl','rb'))

@app.route('/')
def home():
    return render_template('index.html')


@app.route('/predict',methods =['POST'])
def predict():
    option = request.form['options']
    date = request.form['date']
    dat = date
    name = request.form['name']
    d = dt.strptime(date, '%d-%m-%Y').date()
    date = d.toordinal()
    date = np.array(date)
    date = date.reshape(-1,1)
    prediction = model.predict(date)
    output = int(prediction)
    if(option=="SVM"):
        output-=11587
    if(option=="HF"):
        output-=20102     
    if(output<0):
        output =0
    return render_template('index.html' , pred = "{}".format(output) , name="{}".format(name), model="{}".format(option), date = "{}".format(dat))

if __name__=="__main__":
    app.run(debug=True)
