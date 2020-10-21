# Day and Night Image Classifier


The day/night image dataset consists of 200 RGB color images in two categories: day and night. There are equal numbers of each example: 100 day images and 100 night images.

We'd like to build a classifier that can accurately label these images as day or night, and that relies on finding distinguishing features between the two types of images!

Note: All images come from the AMOS dataset (Archive of Many Outdoor Scenes).

## Import resources
Before you get started on the project code, import the libraries and resources that you'll need.

```python
import cv2
import helpers
import numpy as np
import matplotlib.pyplot as plt
```

## Training and Testing data
From 200 images of day/night we will separate them for training and testing.

* 60% of them will be used for training images, for creating a classifier.
* 40% of them will be used for testing images, for calculating the accuracy of our classifier.

We set two variables to store the directory path for training images and test images.

```python
training_file = 'day_night_images/training/'
testing_file = 'day_night_images/test/'
```
## Load training images from path:'day_night_images/training/'

```python
IMAGE_LIST = helpers.load_dataset(training_file)
STANDARDIZE_IMAGE_LIST = helpers.standardize_list(IMAGE_LIST)
```
## Feature Extraction

Create a feature that represents the brightness in an image. We'll be extracting the average brightness using HSV colorspace. Specifically, we'll use the V channel (a measure of brightness), add up the pixel values in the V channel, then divide that sum by the area of the image to get the average Value of the image

### Function for calculating the average brightness of an image

```python
def avg_brightness(image):
  hsv = cv2.cvtColor(image,cv2.COLOR_BGR2HSV)
  sum_brightness = np.sum(hsv[:,:,:]
  area = 600*1100
  
  avg = sum_brightness/area
  
  return avg
```

## Classification and Visualizing Error
In this section, we'll turn our average brightness feature into a classifier that takes in a standardized image and returns a predicted_label for that image. This estimate_label function should return a value: 0 or 1 (night or day, respectively).

```python
# This function should take in RGB image input
def estimate_label(rgb_image):
    
    # Extract average brightness feature from an RGB image 
    avg = avg_brightness(rgb_image)
        
    # Use the avg brightness feature to predict a label (0, 1)
    predicted_label = 0
    threshold = 99
    if(avg > threshold):
        # if the average brightness is above the threshold value, we classify it as "day"
        predicted_label = 1
    # else, the predicted_label can stay 0 (it is predicted to be "night")
    
    return predicted_label    
  ```
  
## Testing the classifier
Here is where we test your classification algorithm using our test set of data that we set aside at the beginning of the notebook!

Since we are using a pretty simple brightess feature, we may not expect this classifier to be 100% accurate. We'll aim for around 75-85% accuracy using this one feature.

### Test dataset
Below, we load in the test dataset, standardize it using the standardize function you defined above, and then shuffle it; this ensures that order will not play a role in testing accuracy.Testing the classifier
Here is where we test your classification algorithm using our test set of data that we set aside at the beginning of the notebook!

Since we are using a pretty simple brightess feature, we may not expect this classifier to be 100% accurate. We'll aim for around 75-85% accuracy usin this one feature.

### Test dataset
Below, we load in the test dataset, standardize it using the standardize function you defined above, and then shuffle it; this ensures that order will not play a role in testing accuracy.

```python
import random

# Using the load_dataset function in helpers.py
# Load test data
TEST_IMAGE_LIST = helpers.load_dataset(image_dir_test)

# Standardize the test data
STANDARDIZED_TEST_LIST = helpers.standardize_list(TEST_IMAGE_LIST)

# Shuffle the standardized test data
random.shuffle(STANDARDIZED_TEST_LIST)
```

## Determine the Accuracy
Compare the output of your classification algorithm (a.k.a. your "model") with the true labels and determine the accuracy.

This code stores all the misclassified images, their predicted labels, and their true labels, in a list called misclassified.

```python
def get_misclassified_images(test_images):
    # Track misclassified images by placing them into a list
    misclassified_images_labels = []

    # Iterate through all the test images
    # Classify each image and compare to the true label
    for image in test_images:

        # Get true data
        im = image[0]
        true_label = image[1]

        # Get predicted label from your classifier
        predicted_label = estimate_label(im)

        # Compare true and predicted labels 
        if(predicted_label != true_label):
            # If these labels are not equal, the image has been misclassified
            misclassified_images_labels.append((im, predicted_label, true_label))
            
    # Return the list of misclassified [image, predicted_label, true_label] values
    return misclassified_images_labels
```

## Find all misclassified images in a given test set
```python
MISCLASSIFIED = get_misclassified_images(STANDARDIZED_TEST_LIST)
```

## Accuracy calculations
```python
total = len(STANDARDIZED_TEST_LIST)
num_correct = total - len(MISCLASSIFIED)
accuracy = num_correct/total

print('Accuracy: ' + str(accuracy))
print("Number of misclassified images = " + str(len(MISCLASSIFIED)) +' out of '+ str(total))
```
