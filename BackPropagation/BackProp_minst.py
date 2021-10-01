import tensorflow as tf
#import tensornetwork as tn
from tensorflow import math
import numpy as np
#import pandas as pd
from tensorflow.keras import layers
from tensorflow.keras import models
from tensorflow.keras import optimizers
from tensorflow.keras.datasets import mnist
from tensorflow.keras.utils import to_categorical
from tensorflow.keras.preprocessing.image import ImageDataGenerator

loss = 0
#activation functions
def sigmoid(x):
    return 1/(1+tf.math.exp(-x))
def Relu(x):
    if(x<=0):
        return 0
    if(x>0):
        return x
def tanh(x):
    return ((tf.math.exp(x)-tf.math.exp(-x))/(tf.math.exp(x)+tf.math.exp(-x)))
#dx activation functions
def Dtanh(x):
    return (1-(tanh(x))^2)
def Dsigmoid(x):
    return math.exp(x)/math.square(np.exp(x)+1)
def DRelu(x):
    if(x<=0):
        return 0
    if(x>0):
        return 1
def sum_inputs(x):
    size1 = len(x)
    size2 = len(x[1])
    out = tf.Variable(tf.zeros(size2, tf.float32))#tf.Variable(x[0:size1])
    #runs length-wise summing each input to the node
    for i in range(0, size2):
        #runs deph-wise summing each weight value.
        val = 0
        for j in range(0, size1):
            val = tf.add(x[j][i], val)
        out[i].assign(val)
    return out
def activate_fcn(X):
    #y = tf.Variable(len(inX), len(inX[0]), tf.float32))
    #for i in range(0, tf.size(Y)):
    Y = sigmoid(X)
        #for j in range(0, 10):
            #Y=activation
    #print(Y)
    return Y
def RMSE(y, y_hat):
    #preforms summation for root mean square error
    rmse=y
    n = len(y)
    for i in range(0, n):
        rmse+=tf.math.square(y[i]-y_hat[i])
    return tf.math.sqrt(rmse/n)
def weight_multiple(weights, scalar):
    #loops each line and scales them against the values vector.
    for i in range(0, len(scalar)):
        tf.scalar_mul(scalar[i], weights[i])
    return weights
#train on batch
def train_batch(size, batch_x, batch_y):
    # runs training function by batch using x
    y_hat = batch_y
    loss = []*len(batch_x)
    for i in range(0, size):
        y_hat[i], loss[i] = DenseNetwork_minst(batch_x[i], batch_y[i])
    # returns loss root mean square error
    print('fin2')
    return y_hat
def train(x, y, batch_size):
    for i in range(0, len(x)):
        # attempt to break up training into batches.
        if((i+batch_size)<len(x)):
            y_hat = train_batch(batch_size, x[i: batch_size], y[i:batch_size])
            i += i + batch_size
        else:
            y_hat = train_batch(batch_size, x[i: len(x)], y[i: len(x)])
            i = len(x)
    print('fin3')
    return y_hat
def RMS_loss(x, y):
    error_size=tf.size(x[0])
    #print(error_size)
    #print(x[[0]].shape)
    length=len(x)
    loss=[]
    for i in range(0, length):
        loss.append(x[i])
        loss[i]=tf.math.subtract(loss[i], y[i])
        loss[i]=tf.math.square(loss[i])
    for k in range(0, len(loss)):
        loss[k]=tf.sqrt(loss[k]/length)
    return loss

print(tf.version.VERSION)
(images_train, labels_train), (images_test, labels_test) = tf.keras.datasets.mnist.load_data()
#images_train = ImageDataGenerator(rescale=1./255)
images_train = images_train.astype('float32')
#images_train = images_train/255
#images_train = np.reshape(images_train/784, (60000, 28, 28, 1))
images_train = images_train.reshape((60000, 784))
images_train = tf.convert_to_tensor(images_train, tf.float32)
images_test = images_test.astype('float32')
#images_test = np.reshape(images_test/784, (10000, 28, 28, 1))
images_test = images_test.reshape((10000, 784))
images_test = tf.convert_to_tensor(images_test, tf.float32)
labels_train = to_categorical(labels_train)
labels_test = to_categorical(labels_test)

#for each in images_test:
#    print(each)

epochs=10
batch_size=100
display_freq=1000
learning_rate=0.001

weights={
    'w1': tf.random.normal([784, 32], 0, 1, tf.float32),
    'w2': tf.random.normal([32, 10], 0, 1, tf.float32)
}
bias={
    'b1': tf.zeros([784, 32], tf.float32),
    'b2': tf.zeros([32, 10], tf.float32)
}

def DenseNetwork_minst(x, y):
    #multiplies weights and adds bias for the input layer
    input_layer = weight_multiple(weights['w1'], x)
    input_layer = tf.add(input_layer, bias['b1'])
    node1 = sum_inputs(input_layer)
    #y = tf.Variable(node1.shape, 10, tf.float32)
    hidden_layer = activate_fcn(node1)
    hidden_layer = weight_multiple(weights['w2'], hidden_layer)
    hidden_layer = tf.add(hidden_layer, bias['b2'])
    output_layer = activate_fcn(hidden_layer)

    output_layer = sum_inputs(output_layer)
    output_layer = activate_fcn(output_layer)
    loss = RMS_loss(output_layer, y)
    print('fin')
    return output_layer, loss

network, loss = train(images_train, labels_train, batch_size)
print(network)
#network = DenseNetwork_minst(images_train)
#model = tf.keras.models.Sequential()
#model.add(layers.Flatten())
#model.add(layers.Dense(32, activation='sigmoid',
#                                 input_shape=(28, 28, 1)))
#model.add(layers.Dense(10, activation='tanh'))
#model.compile(optimizer='adam',
#              loss='categorical_crossentropy',
#              metrics=['accuracy'])
#model.fit(images_train, labels_train,
#          epochs=11,
#          batch_size=64,
#          validation_data=(images_test, labels_test))
#print(labels_train.shape)
#print(labels_test.shape)
#model.evaluate(images_test,  labels_test)
#train_datagen = ImageDataGenerator(
#    rescale=1./255,
#    rotation_range=40,
#    width_shift_range=0.2,
#    height_shift_range=0.2,
#   shear_range=0.2,
#    zoom_range=0.2,
#    horizontal_flip=True)
#test_datagen = ImageDataGenerator(rescale=1./255)
#train_generator=train_datagen(
#    tf.keras.datasets.mnist.load_data(),
#    target_size=(150, 150),
#    batch_size=32,
#    class_mode='categorical')
#validation_generator = test_datagen.flow_from_data(
#    (images_test, labels_test),
#    target_size=(150, 150),
#    batch_size=32,
#    class_mode='binary')
#labels_train = to_categorical(labels_train)
#labels_test = to_categorical(labels_test)
#input_shape = images_train.shape
#model.fit_generator((images_train, labels_train),
#          train_generator,
#          steps_per_epoch=100,
#          epochs=100,
#          validation_data=validation_generator,
#          validation_steps=50)
#results = model.evaluate(images_test, labels_test)
#print(results)

   # x_train = vectorizeSequences(train_data)
   # x_test = vectorizeSequences(test_data)
   # vectorize_sequences((x_train, y_train))
   #model.add(layers.Dense(1, activation = 'sigmoid'))