from flask import Flask, request, jsonify
from flask_cors import CORS
import numpy as np
import joblib
import tensorflow as tf
import io
from tensorflow.keras.utils import load_img, img_to_array

app = Flask(__name__)
CORS(app)  # to allow React frontend to access Flask backend

# ----- Load Model -----
model = tf.keras.models.load_model("models/brain_tumor_mobilenetv2_final.keras/")


# Class labels (make sure order matches your training)
class_labels = {0: 'glioma', 1: 'meningioma', 2: 'notumor', 3: 'pituitary'}

@app.route('/predict', methods=['POST'])
def predict():
    if 'image' not in request.files:
        return jsonify({"error": "No image uploaded"}), 400
    
    file = request.files['image']

    # Convert uploaded file to BytesIO and load
   
    img = load_img(io.BytesIO(file.read()), target_size=(224, 224))
    img_array = img_to_array(img) / 255.0
    img_array = np.expand_dims(img_array, axis=0)

    # Prediction
    preds = model.predict(img_array)
    predicted_class_index = np.argmax(preds)
    predicted_class = class_labels[predicted_class_index]
    confidence = float(preds[0][predicted_class_index])

    return jsonify({
        "predicted_class": predicted_class,
        "confidence": confidence,
        "all_probabilities": {label: float(preds[0][i]) for i, label in class_labels.items()}
    })


if __name__ == '__main__':
    app.run(debug=True)