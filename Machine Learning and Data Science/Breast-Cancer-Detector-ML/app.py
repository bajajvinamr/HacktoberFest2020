import streamlit as st
import pickle
import numpy as np
from PIL import Image

model2=pickle.load(open('modellr.pkl','rb'))
model4=pickle.load(open('modelrf.pkl','rb'))
model3=pickle.load(open('modellr.pkl','rb'))
model1=pickle.load(open('modellr.pkl','rb'))

def predict_cancer_svm(mean_radius,mean_texture,mean_perimeter,mean_area,mean_smoothness,mean_compactness,mean_concavity,mean_concavepoints,mean_symmetry,mean_fractaldimension):
    input=np.array([[mean_radius,mean_texture,mean_perimeter,mean_area,mean_smoothness,mean_compactness,mean_concavity,mean_concavepoints,mean_symmetry,mean_fractaldimension]])#.astype(np.float64)
    prediction=model1.predict(input)
    pred=prediction
    return float(pred)

def predict_cancer_tree(mean_radius,mean_texture,mean_perimeter,mean_area,mean_smoothness,mean_compactness,mean_concavity,mean_concavepoints,mean_symmetry,mean_fractaldimension):
    input=np.array([[mean_radius,mean_texture,mean_perimeter,mean_area,mean_smoothness,mean_compactness,mean_concavity,mean_concavepoints,mean_symmetry,mean_fractaldimension]])#.astype(np.float64)
    prediction=model3.predict(input)
    pred=prediction
    return float(pred)
def predict_cancer_rf(mean_radius,mean_texture,mean_perimeter,mean_area,mean_smoothness,mean_compactness,mean_concavity,mean_concavepoints,mean_symmetry,mean_fractaldimension):
    input=np.array([[mean_radius,mean_texture,mean_perimeter,mean_area,mean_smoothness,mean_compactness,mean_concavity,mean_concavepoints,mean_symmetry,mean_fractaldimension]])#.astype(np.float64)
    prediction=model4.predict(input)
    pred=prediction
    return float(pred)

def main():
    st.title("Built By CodeX MAIT")
    status=st.sidebar.radio("Know About Our Model's",("Model 1","Model 2","Model 3"))
    if status=='Model 1':
        st.sidebar.success('Model 1 Is Made By using Support Vector Machines And Has Testing Accuracy of 0.913')
    if status == 'Model 2':
        st.sidebar.info('Model 2 Is Made By using Decision Tree Classifier And Has Testing Accuracy of 0.932')
    if status == 'Model 3':
         st.sidebar.warning('Model 3 Is Made By Using Random Forest Classifier And Has Testing Accuracy of 0.967')
    bar= st.sidebar.selectbox("Choose PLot", ["PairPlot", "CountPlot"])
    if bar=="PairPlot":
        st.success('Pair Plot Showing Relation Between Different Parameters Responsible For Breast Cancer According To Our Data Set')
        img = Image.open("pairplot.png")
        st.image(img,width=500)
    if bar=="CountPlot":
        st.success('CountPlot of People with Malignant VS Belign Cells According To Our Data Set')
        img = Image.open("countplot.png")
        st.image(img,width=500)

    html_temp = """
    <div style="background-color:#025246 ;padding:10px">
    <h1 style="color:white;text-align:center;">Breast Cancer Detection Model</h1>
    </div>
    """
    st.markdown(html_temp, unsafe_allow_html=True)
    img = Image.open("main.jpeg")
    st.image(img, width=698)
    st.selectbox("Your Gender",["Male","Female","Others"])
    st.markdown("Fill Your Information Here")
    mean_radius = st.text_input("Mean Radius")
    mean_texture = st.text_input("Mean Texture")
    mean_perimeter = st.text_input("Mean Perimeter")
    mean_area = st.text_input("Mean Area")
    mean_smoothness = st.text_input("Mean Smoothness")
    mean_compactness = st.text_input("Mean Compactness")
    mean_concavity = st.text_input("Mean Concavity")
    mean_concavepoints = st.text_input("Mean Concave Points")
    mean_symmetry = st.text_input("Mean Symmetry")
    mean_fractaldimension = st.text_input("Mean Fractal Dimension")
    st.warning('Click Here To Check Your Results')

    safe_html="""  
      <div style="background-color:#F4D03F;padding:10px >
       <h2 style="color:white;text-align:center;"> Hey,You Are Not Diagnosed With Breast Cancer</h2>
       </div>
    """
    danger_html="""  
      <div style="background-color:#F08080;padding:10px >
       <h2 style="color:red ;text-align:center;"> Hey ,You Are Diagnosed with Malignant Breast Cancer</h2>
       </div>
    """

    if st.button("Model 1"):
        output=predict_cancer_rf(mean_radius,mean_texture,mean_perimeter,mean_area,mean_smoothness,mean_compactness,mean_concavity,mean_concavepoints,mean_symmetry,mean_fractaldimension)
        st.success('')

        if output ==1:
            st.markdown(danger_html,unsafe_allow_html=True)

        else:
            st.markdown(safe_html,unsafe_allow_html=True)
            st.balloons()


    if st.button("Model 2"):
        output=predict_cancer_rf(mean_radius,mean_texture,mean_perimeter,mean_area,mean_smoothness,mean_compactness,mean_concavity,mean_concavepoints,mean_symmetry,mean_fractaldimension)
        st.success('')

        if output ==1:
            st.markdown(danger_html,unsafe_allow_html=True)
        else:
            st.markdown(safe_html,unsafe_allow_html=True)
            st.balloons()

    if st.button("Model 3"):
        output=predict_cancer_rf(mean_radius,mean_texture,mean_perimeter,mean_area,mean_smoothness,mean_compactness,mean_concavity,mean_concavepoints,mean_symmetry,mean_fractaldimension)
        st.success('')

        if output ==1:
            st.markdown(danger_html,unsafe_allow_html=True)
        else:
            st.markdown(safe_html,unsafe_allow_html=True)
            st.balloons()

if __name__=='__main__':
    main()
