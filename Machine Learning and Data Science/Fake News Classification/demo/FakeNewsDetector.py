import streamlit as st
import tensorflow as tf
from tensorflow import keras
import tensorflow_datasets as tfds

model = tf.keras.models.load_model("my_model.h5")
encoder = tfds.features.text.SubwordTextEncoder.load_from_file("encoder")

def pad_to_size(vec, size):
  zero = [0] * (size - len(vec))
  vec.extend(zero)
  return vec


def sample_predict(sample_pred_text, pad):
  encoded_sample_pred_text = encoder.encode(sample_pred_text)

  if pad:
    encoded_sample_pred_text = pad_to_size(encoded_sample_pred_text, 64)
  encoded_sample_pred_text = tf.cast(encoded_sample_pred_text, tf.float32)
  predictions = model.predict(tf.expand_dims(encoded_sample_pred_text, 0))

  return (predictions)

st.title("Fake News Detector")
input_article = st.text_area("Enter test article for prediction")

if st.button("Submit"):
    predictions = sample_predict(input_article, pad=False)
    if predictions > 0.5 :
        st.text("The News is Real")
    else:
        st.text("The News is Fake")


