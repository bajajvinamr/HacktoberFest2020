import pandas as pd
import matplotlib.pyplot as pt
import numpy as np
import seaborn as sns
from copy import copy
import plotly.express as px
import plotly.figure_factory as ff
import plotly.graph_objects as go


df=pd.read_csv('C:/Users/USER/Downloads/stock.csv')

def showplot(dfs,fig_title):
 dfs.plot(x='Date',figsize=(15,7),linewidth=3,title=fig_title)
pt.grid()
pt.show()

def normal(dfs):
 x=df.copy()
 for i in x.columns[1:]:
    x[i]=x[i]/x[i][0]
    return x

def interplot(dfs,title):
    fig=px.line(title=title)
    for i in dfs.columns[1:]:
     fig.add_scatter(x=dfs['Date'], y=dfs[i],name=i)
    fig.show()

a=dreturn(df)

showplot(a,'multiple stocks')

interplot(a,'multiple stocks')

cm=a.drop(columns=['Date']).corr()

pt.figure(figsize=(10,10))
ax=pt.subplot()
sns.heatmap(cm,annot=True,ax=ax)

a.hist(figsize=(10,10),bins=40);

dfhist=a.copy()

dfhist=dfhist.drop(columns=['Date'])
data=[]
for i in dfhist.columns:
    data.append(a[i].values)


fig=ff.create_distplot(data,dfhist.columns)
fig.show()
