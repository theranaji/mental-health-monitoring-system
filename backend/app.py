from flask import Flask, request, jsonify
from flask_cors import CORS
from transformers import pipeline

app = Flask(__name__)
CORS(app, resources={r"/*": {"origins": "*"}})  # allow all origins

# Load HuggingFace sentiment analysis pipeline
sentiment_pipeline = pipeline("sentiment-analysis")

@app.route('/analyze', methods=['POST'])
def analyze_sentiment():
    data = request.get_json()
    text = data.get('text', '')

    if not text:
        return jsonify({'error': 'Text is required'}), 400

    result = sentiment_pipeline(text)[0]
    label = result['label']
    score = result['score']

    return jsonify({'sentiment': label, 'confidence': score})

if __name__ == '__main__':
    app.run(debug=True)
