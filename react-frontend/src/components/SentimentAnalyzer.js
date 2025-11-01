import React, { useState } from 'react';
import { Brain, Heart, TrendingUp, TrendingDown } from 'lucide-react';
import { analyzeSentiment } from '../services/api';

const SentimentAnalyzer = () => {
  const [text, setText] = useState('');
  const [result, setResult] = useState(null);
  const [loading, setLoading] = useState(false);
  const [error, setError] = useState(null);
  const [history, setHistory] = useState([]);

  const handleAnalyze = async () => {
    if (!text.trim()) return;

    setLoading(true);
    setError(null);

    try {
      const data = await analyzeSentiment(text);
      const newResult = {
        text: text.trim(),
        sentiment: data.sentiment,
        confidence: data.confidence,
        timestamp: new Date().toLocaleString()
      };
      
      setResult(newResult);
      setHistory(prev => [newResult, ...prev.slice(0, 4)]);
      setText('');
    } catch (err) {
      setError(err.message);
    } finally {
      setLoading(false);
    }
  };

  const getSentimentIcon = (sentiment) => {
    return sentiment === 'POSITIVE' ? <TrendingUp size={20} /> : <TrendingDown size={20} />;
  };

  const getSentimentColor = (sentiment) => {
    return sentiment === 'POSITIVE' ? 'result-positive' : 'result-negative';
  };

  return (
    <div className="analyzer-container">
      <div className="container">
        <div className="header">
          <h1 className="title">
            <Brain size={40} style={{ display: 'inline', marginRight: '10px' }} />
            Mental Health Analyzer
          </h1>
          <p className="subtitle">Share your thoughts and get insights about your mental state</p>
        </div>

      <div className="input-section">
        <textarea
          className="textarea"
          value={text}
          onChange={(e) => setText(e.target.value)}
          placeholder="How are you feeling today? Share your thoughts..."
          maxLength={500}
        />
        <button
          className="button"
          onClick={handleAnalyze}
          disabled={loading || !text.trim()}
        >
          {loading ? (
            <>
              <div className="loading"></div>
              Analyzing...
            </>
          ) : (
            <>
              <Heart size={20} />
              Analyze Sentiment
            </>
          )}
        </button>
      </div>

      {error && (
        <div className="error">
          {error}
        </div>
      )}

      {result && (
        <div className={`result-card ${getSentimentColor(result.sentiment)}`}>
          <div className="result-header">
            {getSentimentIcon(result.sentiment)}
            <span className="result-sentiment">
              {result.sentiment === 'POSITIVE' ? 'Positive' : 'Negative'} Sentiment
            </span>
          </div>
          <div className="result-confidence">
            Confidence: {(result.confidence * 100).toFixed(1)}%
          </div>
        </div>
      )}

      {history.length > 0 && (
        <div className="history">
          <h3 className="history-title">Recent Analysis</h3>
          {history.map((item, index) => (
            <div key={index} className="history-item">
              <div className="history-text">"{item.text.substring(0, 100)}..."</div>
              <div className="history-result">
                {item.sentiment === 'POSITIVE' ? 'Positive' : 'Negative'} 
                ({(item.confidence * 100).toFixed(1)}%) - {item.timestamp}
              </div>
            </div>
          ))}
        </div>
      )}
      </div>
    </div>
  );
};

export default SentimentAnalyzer;