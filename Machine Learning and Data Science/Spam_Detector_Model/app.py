import streamlit as st
import pickle
import numpy as np
from PIL import Image
import string
from nltk.corpus import stopwords
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
    return [word for word in nopunc.split() if word.lower() not in stopwords.words('english')]

model=pickle.load(open('model.pkl','rb'))
model1=pickle.load(open('model1.pkl','rb'))



#def predict_cancer_svm(f):
    #input=np.array([[message]])#.astype(np.float64)
    #prediction=model.predict(open('demofile3.txt','r')[0]
    #return prediction

def main():
    st.title("Built By CodeX MAIT")
    status = st.sidebar.radio("Know About Our Model's", ("Model 1", "Model 2"))
    if status == 'Model 2':
        st.sidebar.success('Model 1 Is Made By using Support Vector Machines And Has Testing Accuracy of 0.932')
    if status == 'Model 1':
        st.sidebar.info('Model 2 Is Made By using Naive Bayes classifier And Has Testing Accuracy of 0.978')

    html_temp = """
    <div style="background-color:#025246 ;padding:10px">
    <h1 style="color:white;text-align:center;">EMAIL DETECTION MODEL</h1>
    </div>
    """
    st.markdown(html_temp, unsafe_allow_html=True)
    img = Image.open("bg2.png")
    st.image(img, width=697)
    st.selectbox("Your Gender",["Male","Female","Others"])
    st.markdown("Fill Your Information Here")
    message = st.text_input("Add Your Mail Here to check")
    f = open('demofile3.txt', "w")
    f.write(message)
    f.close()
    st.warning('Click Here To Check Your Results')

    safe_html="""  
      <div style="background-color:#F4D03F;padding:10px >
       <h2 style="color:white;text-align:center;"> Hey,this is a ham Email Don't Delete It</h2>
       </div>
    """
    danger_html="""  
      <div style="background-color:#F08080;padding:10px >
       <h2 style="color:red ;text-align:center;"> Hey ,this is a spam Email Delete It</h2>
       </div>
    """

    if st.button("Model 1"):
        output=model.predict(open('demofile3.txt', "r"))[0]
        #output=predict_cancer_svm(message)
        st.success('')

        if output ==1:
            st.markdown(danger_html,unsafe_allow_html=True)

        else:
            st.markdown(safe_html,unsafe_allow_html=True)
            st.balloons()
    if st.button("Model 2"):
        output=model1.predict(open('demofile3.txt', "r"))[0]
        #output=predict_cancer_svm(message)
        st.success('')

        if output ==1:
            st.markdown(danger_html,unsafe_allow_html=True)

        else:
            st.markdown(safe_html,unsafe_allow_html=True)
            st.balloons()




if __name__=='__main__':
    main()